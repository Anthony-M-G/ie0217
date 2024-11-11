#include <chrono>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <semaphore>
#include <thread>
#include <vector>

const int BUFFER_SIZE = 10;
const int NUM_TASKS = 20;

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_client, cv_operator;
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
std::counting_semaphore<BUFFER_SIZE> full_slots(0);

int produced_count = 0;
int consumed_count = 0;
bool finished = false;

std::chrono::nanoseconds total_produce_time(0);
std::chrono::nanoseconds total_consume_time(0);
std::mutex metrics_mtx;

// Generador de pausas aleatorias
int random_pause(int min_ms, int max_ms) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min_ms, max_ms);
  return dist(gen);
}

// Función del productor
void producer(int id) {
  for (int i = 0; i < NUM_TASKS; ++i) {
    auto start_time = std::chrono::high_resolution_clock::now();

    empty_slots.acquire(); // Espera un espacio en el buffer
    {
      std::lock_guard<std::mutex> lock(mtx);
      buffer.push(i);
      std::cout << "Productor " << id << " produjo: " << i << std::endl;
      produced_count++;
    }
    full_slots.release(); // Notifica que hay un nuevo elemento en el buffer

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end_time -
                                                             start_time);

    // Agregar el tiempo de producción a la métrica total
    {
      std::lock_guard<std::mutex> lock(metrics_mtx);
      total_produce_time += duration;
    }

    std::this_thread::sleep_for(
        std::chrono::milliseconds(random_pause(100, 500)));
  }
}

// Función del consumidor
void consumer(int id) {
  while (true) {
    auto start_time = std::chrono::high_resolution_clock::now();

    full_slots.acquire(); // Espera hasta que haya un elemento en el buffer
    {
      std::lock_guard<std::mutex> lock(mtx);
      if (!buffer.empty()) {
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumidor " << id << " consumió: " << item << std::endl;
        consumed_count++;
      } else if (finished) {
        break;
      }
    }
    empty_slots.release(); // Notifica que hay espacio disponible en el buffer

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end_time -
                                                             start_time);

    // Agregar el tiempo de consumo a la métrica total
    {
      std::lock_guard<std::mutex> lock(metrics_mtx);
      total_consume_time += duration;
    }

    std::this_thread::sleep_for(
        std::chrono::milliseconds(random_pause(100, 500)));
  }
}

void run_test(int num_producers, int num_consumers) {
  std::vector<std::thread> producers;
  std::vector<std::thread> consumers;

  for (int i = 0; i < num_producers; ++i) {
    producers.emplace_back(producer, i + 1);
  }

  for (int i = 0; i < num_consumers; ++i) {
    consumers.emplace_back(consumer, i + 1);
  }

  for (auto &producer : producers) {
    producer.join();
  }

  {
    std::lock_guard<std::mutex> lock(mtx);
    finished = true;
  }

  for (int i = 0; i < num_consumers; ++i) {
    full_slots.release(); // Desbloquea a los consumidores
  }

  for (auto &consumer : consumers) {
    consumer.join();
  }

  std::cout << "Producción y consumo finalizados. Total producido: "
            << produced_count << ", Total consumido: " << consumed_count
            << std::endl;

  // Guardar métricas en un archivo
  std::ofstream metrics_file("metrics.txt", std::ios::app);
  metrics_file << "Test con " << num_producers << " productores y "
               << num_consumers << " consumidores:\n";
  metrics_file << "Total producido: " << produced_count
               << ", Total consumido: " << consumed_count << "\n";
  metrics_file << "Tiempo promedio de producción: "
               << (produced_count > 0
                       ? total_produce_time.count() / produced_count / 1'000'000
                       : 0)
               << " ms\n";
  metrics_file << "Tiempo promedio de consumo: "
               << (consumed_count > 0
                       ? total_consume_time.count() / consumed_count / 1'000'000
                       : 0)
               << " ms\n\n";
  metrics_file.close();

  // Reiniciar métricas para el siguiente test
  produced_count = 0;
  consumed_count = 0;
  total_produce_time = std::chrono::nanoseconds(0);
  total_consume_time = std::chrono::nanoseconds(0);
  finished = false;
}

int main() {
  run_test(2, 2);
  run_test(4, 2);
  run_test(2, 4);

  return 0;
}
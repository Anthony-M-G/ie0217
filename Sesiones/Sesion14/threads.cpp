#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <semaphore> // Disponible en C++20
#include <thread>
#include <vector>

namespace sc = std::chrono;
using namespace std;

constexpr int BUFFER_SIZE = 10;
int buffer[BUFFER_SIZE];
int counter = 0;

std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;
std::counting_semaphore<BUFFER_SIZE>
    empty_slots(BUFFER_SIZE); // Inicializado con BUFFER_SIZE
std::counting_semaphore<BUFFER_SIZE> full_slots(0); // Inicializado en 0

// Función del productor
void producer(int id, int num_tasks) {
  for (int i = 0; i < num_tasks; ++i) {
    empty_slots.acquire(); // Decrementa el contador de slots vacíos

    std::unique_lock<std::mutex> lock(mtx);
    buffer[counter++] = id * 100 + i; // Produce un ítem
    std::cout << "Producer " << id << " produced item: " << id * 100 + i
              << std::endl;

    lock.unlock();
    full_slots.release(); // Notifica al consumidor que hay un ítem lleno

    std::this_thread::sleep_for(sc::milliseconds(100)); // Simula la producción
  }
}

// Función del consumidor
void consumer(int id) {
  while (true) {
    full_slots.acquire(); // Decrementa el contador de ítems llenos

    std::unique_lock<std::mutex> lock(mtx);
    if (counter == 0)
      break; // Salir si el buffer está vacío y no hay más ítems
    int item = buffer[--counter];
    std::cout << "Consumer " << id << " consumed item: " << item << std::endl;

    lock.unlock();
    empty_slots.release(); // Notifica al productor que hay un slot vacío

    std::this_thread::sleep_for(sc::milliseconds(150)); // Simula el consumo
  }
}

int main() {
  const int num_producers = 2;
  const int num_consumers = 2;
  const int total_tasks_per_producer = 10;
  const int total_tasks = num_producers * total_tasks_per_producer;

  std::vector<std::thread> producers, consumers;

  // Crear hilos productores
  for (int i = 0; i < num_producers; ++i) {
    producers.emplace_back(producer, i, total_tasks_per_producer);
  }

  // Crear hilos consumidores
  for (int i = 0; i < num_consumers; ++i) {
    consumers.emplace_back(consumer, i);
  }

  // Esperar a que los productores terminen
  for (auto &producer_thread : producers) {
    producer_thread.join();
  }

  // Permitir que los consumidores terminen
  for (int i = 0; i < num_consumers; ++i) {
    full_slots.release(); // Notifica para que el consumidor salga
  }

  for (auto &consumer_thread : consumers) {
    consumer_thread.join();
  }

  std::cout << "All producers have finished!" << std::endl;
  return 0;
}

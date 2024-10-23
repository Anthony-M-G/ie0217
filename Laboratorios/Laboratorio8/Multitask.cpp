
#include <barrier> // Permite sincronizar múltiples hilos en un punto específico
#include <chrono>   // Manejo de tiempo y duraciones
#include <iostream> // E/S estándar
#include <mutex>    // Mecanismo de exclusión mutua
#include <thread>   // Manejo de hilos
#include <vector>   // Contenedor para los hilos

// Mutex global: Mecanismo de exclusión mutua
// Previene condiciones de carrera al acceder a recursos compartidos (en este
// caso, cout)
std::mutex console_mutex;

// Barrera: Punto de sincronización para 3 hilos
// Los hilos se detendrán aquí hasta que los 3 hayan llegado
std::barrier sync_point(3);

// Función que ejecutará cada hilo
// Demuestra conceptos básicos de sincronización y exclusión mutua
void perform_task(int id) {
  {
    // Sección crítica #1: Acceso al cout
    // lock_guard implementa el patrón RAII para el mutex:
    // - Se bloquea automáticamente al construirse
    // - Se desbloquea automáticamente al destruirse (al salir del scope)
    std::lock_guard<std::mutex> lock(console_mutex);
    std::cout << "Tarea " << id << " está realizando trabajo inicial...\n";
  } // El mutex se libera automáticamente aquí

  // Simula trabajo computacional
  // sleep_for es solo para demostración; en código real habría trabajo real
  std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

  {
    // Sección crítica #2
    std::lock_guard<std::mutex> lock(console_mutex);
    std::cout << "Tarea " << id << " alcanzó el punto de sincronización.\n";
  }

  // Punto de sincronización usando barrera
  // - arrive_and_wait(): incrementa el contador de la barrera
  // - Si no es el último hilo, se bloquea
  // - Si es el último, desbloquea a todos los hilos
  sync_point.arrive_and_wait();

  {
    // Sección crítica #3
    std::lock_guard<std::mutex> lock(console_mutex);
    std::cout << "Tarea " << id << " continúa con el trabajo final.\n";
  }

  // Más trabajo simulado
  std::this_thread::sleep_for(std::chrono::milliseconds(50 * id));

  {
    // Sección crítica #4
    std::lock_guard<std::mutex> lock(console_mutex);
    std::cout << "Tarea " << id << " ha completado el trabajo.\n";
  }
}

int main() {
  const int NUM_TASKS = 3;

  // Vector para almacenar los hilos
  // Cada hilo es un flujo de ejecución independiente
  std::vector<std::thread> threads;

  // Creación y lanzamiento de hilos
  // Cada thread ejecutará perform_task con un id diferente
  for (int i = 1; i <= NUM_TASKS; ++i) {
    threads.push_back(std::thread(perform_task, i));
  }

  // join(): Espera a que cada hilo termine
  // Es importante hacer join de todos los hilos para:
  // 1. Evitar que terminen abruptamente si main() termina antes
  // 2. Liberar los recursos del sistema correctamente
  for (auto &th : threads) {
    th.join();
  }

  std::cout << "Todas las tareas han completado su ejecución.\n";
  return 0;
}

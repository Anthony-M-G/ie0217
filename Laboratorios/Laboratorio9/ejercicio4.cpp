#include <iostream>
#include <mutex>
#include <thread>

int contador = 0;
std::mutex mtx;

void incrementar() {
  for (int i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock(mtx);
    contador++;
  }
}

int main() {
  std::thread hilo1(incrementar);
  std::thread hilo2(incrementar);

  hilo1.join();
  hilo2.join();

  std::cout << "Valor final del contador: " << contador << std::endl;
  return 0;
}

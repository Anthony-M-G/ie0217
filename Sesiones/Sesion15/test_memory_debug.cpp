#include <iostream>

void funcion1() {
  int *p = new int[10];           // Perdida de memoria: no se libera la memoria
  std::cout << p[0] << std::endl; // Uso de memoria no inicializada

  int array[5];
  array[5] = 10; // Acceso fuera de los limites del array
}

int main() {
  funcion1();
  return 0;
}
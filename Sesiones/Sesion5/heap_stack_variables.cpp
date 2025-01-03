#include <iostream>

/* Se almacena en el segmento de data. */
int globalVariable = 42;

int main()
{
  /* Se almacena en el stack. */
  int stackVariable = 10;

  /* Se almacena en el heap. */
  // New me devuelve un puntero al espacio de memoria asignado en el heap
  int *heapVariable = new int(20);

  std::cout << "Valor de globalVariable: " << globalVariable << std::endl;
  std::cout << "Valor de stackVariable: " << stackVariable << std::endl;
  std::cout << "Valor de heapVariable: " << *heapVariable << std::endl;

  // Liberar la memoria asignada en el heap, necesario para evitar fugas de memoria.
  // Cuando usamos new, debemos liberar la memoria con delete
  delete heapVariable;

  return 0;
}

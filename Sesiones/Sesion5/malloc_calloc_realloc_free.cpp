#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

  // Ejemplo de malloc
  cout << "----Ejemplo de malloc----" << endl;
  int *arr = (int *)malloc(5 * sizeof(int));
  if (arr == NULL)
  {
    cout << "No se pudo asignar memoria en el heap" << endl;
    exit(1);
  }

  // Asignar valores a los elementos del arreglo usando aritmética de punteros
  *(arr + 0) = 10;
  *(arr + 1) = 20;
  *(arr + 2) = 30;
  *(arr + 3) = 40;
  *(arr + 4) = 50;

  // Imprimir los valores de los elementos del arreglo
  for (int i = 0; i < 5; i++)
  {
    cout << "Dirección de memoria de la nota del estudiante " << i + 1 << ": " << (arr + i) << endl;
    cout << "Nota del estudiante " << i + 1 << ": " << *(arr + i) << endl;
  }

  // Liberar la memoria asignada en el heap
  free(arr);

  // Ejemplo de calloc

  // Asignar memoria para 5 elementos de tipo int
  cout << "-----Ejemplo de calloc-----" << endl;
  int *arr2 = (int *)calloc(5, sizeof(int));

  if (arr2 == NULL)
  {
    cout << "No se pudo asignar memoria en el heap" << endl;
    exit(1);
  }

  // Calloc inicializa la memoria asignada a 0
  for (int i = 0; i < 5; i++)
  {
    cout << "Dirección de memoria de la nota del estudiante " << i + 1 << ": " << (arr2 + i) << endl;
    cout << "Nota del estudiante " << i + 1 << ": " << *(arr2 + i) << endl;
  }

  // Liberar la memoria asignada en el heap
  free(arr2);

  // Ejemplo de realloc

  // Asignar memoria para 5 elementos de tipo int
  cout << "------antes de realloc------" << endl;
  int *num = (int *)malloc(sizeof(int));
  if (num == NULL)
  {
    cout << "No se pudo asignar memoria en el heap" << endl;
    exit(1);
  }
  *num = 10;
  cout << "Valor de num: " << *num << endl;

  // Reasignar memoria para 2 elementos de tipo int

  num = (int *)realloc(num, 2 * sizeof(int)); // num ahora apunta a un bloque de memoria de 2 elementos
  if (num == NULL)
  {
    cout << "No se pudo asignar memoria en el heap" << endl;
    exit(1);
  }
  *(num + 1) = 20;
  cout << "----despues de realloc------" << endl;
  cout << "Valor de num: " << *num << endl;
  cout << "Valor de num + 1: " << *(num + 1) << endl;

  // Liberar la memoria asignada en el heap
  free(num);

  return 0;
}

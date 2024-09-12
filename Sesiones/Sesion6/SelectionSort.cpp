#include <iostream>

// Declaración de la función de ordenamiento por selección
void selectionSort(int array[], int size);

// Declaración de la función para intercambiar dos valores
void swap(int *val1, int *val2);

int main(int argc, char const *argv[])
{
  // Definir un arreglo de enteros
  int data[] = {9, 5, 1, 2, 3};
  // Calcular el tamaño del arreglo
  int size = sizeof(data) / sizeof(data[0]);

  // Llamar a la función de ordenamiento por selección
  selectionSort(data, size);

  // Imprimir el arreglo ordenado
  std::cout << "Ordenado ascendente:\n"
            << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cout << data[i] << std::endl;
  }

  return 0;
}

// Implementación de la función de ordenamiento por selección
void selectionSort(int array[], int size)
{
  // Iterar sobre cada elemento del arreglo
  for (int step = 0; step < size - 1; step++)
  {
    // Encontrar el índice del elemento mínimo en el subarreglo no ordenado
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {
      // Actualizar el índice del mínimo si se encuentra un elemento menor
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    // Intercambiar el elemento mínimo encontrado con el primer elemento del subarreglo no ordenado
    swap(&array[min_idx], &array[step]);
  }
}

// Implementación de la función para intercambiar dos valores
void swap(int *val1, int *val2)
{
  int tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}
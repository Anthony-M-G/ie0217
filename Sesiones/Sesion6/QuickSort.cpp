#include <iostream>

using namespace std;

// Función para intercambiar dos valores
void swap(int *val1, int *val2)
{
  int tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}

// Función para realizar la partición del arreglo
int partition(int vec[], int low, int high)
{
  // Seleccionar el último elemento como pivote
  int pivot = vec[high];

  // Índice del elemento justo antes del último elemento
  // Se utiliza para realizar el intercambio
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    // Si el elemento actual es menor o igual al pivote
    if (vec[j] <= pivot)
    {
      i++;
      swap(&vec[i], &vec[j]);
    }
  }

  // Colocar el pivote en su posición correcta
  swap(&vec[i + 1], &vec[high]);

  // Devolver el punto de partición
  return (i + 1);
}

// Función para realizar el ordenamiento rápido (QuickSort)
void quickSort(int vec[], int low, int high)
{
  // Caso base: esta parte se ejecutará mientras el índice de inicio (low) sea menor que el índice de fin (high)
  if (low < high)
  {
    // partition_index es el índice de partición, vec[p] está ahora en el lugar correcto
    int partition_index = partition(vec, low, high);

    // Ordenar por separado los elementos antes y después del índice de partición (partition_index)
    quickSort(vec, low, partition_index - 1);
    quickSort(vec, partition_index + 1, high);
  }
}

int main(int argc, char const *argv[])
{
  int data[] = {9, 5, 1, 2, 3, 67, 0};
  int size = sizeof(data) / sizeof(data[0]);

  // Llamar a la función quickSort para ordenar el arreglo
  quickSort(data, 0, size - 1);

  cout << "Ordenado ascendente:\n"
       << endl;

  // Imprimir el arreglo ordenado
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << endl;
  }

  return 0;
}
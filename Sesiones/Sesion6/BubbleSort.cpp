#include <iostream>
using namespace std;
void bubbleSort(int array[], int size);

int main(int argc, char const *argv[])
{
  int data[] = {9, 5, 1, 2, 3};
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  std::cout << "Ordenado ascendente:\n"
            << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cout << data[i] << std::endl;
  }
  return 0;
}

void bubbleSort(int array[], int size)
{

  // Itera hasta longitud del array -1
  for (int step = 0; step < size; step++)
  {
    int swapped = 0;
    // Itera mientras j<tamaño del array - iteracion externa, 6, 5, 4, 3, 2, 1 veces son las iteraciones internas
    for (int j = 0; j < size - step; j++)
    {
      if (array[j] > array[j + 1])
      {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;

        swapped = 1;
        std::cout << j << ". swapped" << std::endl;
      }

      if (!swapped)
      {
        break;
      }
    }
  }
};

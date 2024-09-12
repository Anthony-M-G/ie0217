int main(int argc, char const *argv[])
{
  int data[] = {12, 25, 11, 2, 39};
  int size = sizeof(data) / sizeof(data[0]);

  insertionSort(data, size);
  std::cout << "Ordenado ascendente:\n"
            << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cout << data[i] << std::endl;
  }
  return 0;
}

void insertionSort(int array[], int size)
{
  for (int step = 1; step < size; step++)
  {
    int key = array[step]; // Define key como el valor de la posición actual
    int j = step - 1;      // Define j como la posición anterior a la actual

    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
};
#include <iostream>
using namespace std;

int main()
{
  // declaro el array que voy a usar y lo lleno en el ciclo for
  int array[5];
  for (int i = 0; i < 5; i++)
  {
    array[i] = i; // lleno el array con los valores de i
  }

  int j = 0;
  while (j < 5)
  {
    cout << array[j] << " " << endl; // imprimo los valores del array en cada iteración
    j++;
  }

  return 0;
}
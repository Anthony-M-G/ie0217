#include <iostream>
using namespace std;

int main()
{
  // Array de tipo float
  float arr[3];

  // puntero de tipo float
  float *ptr;

    cout << "Displaying address using arrays:" << endl;

  // imprime la direccion de cada elemento del array usando la notacion array[n]
  for (int i = 0; i < 3; ++i)
  {
    cout << "&arr[" << i << "] = " << &arr[i] << endl;
  }

  // El puntero apunta a la dirección del primer elemento del array
  ptr = arr;

  cout << "\nDisplaying address using pointers:" << endl;

  // imprime la direccion de cada elemento del array usando el puntero que al aumentarle cada byte recorre las direcciones de los elementos del array al que apunta
  for (int i = 0; i < 3; ++i)
  {
    cout << "ptr + " << i << " = " << ptr + i << endl;
  }

  return 0;
}

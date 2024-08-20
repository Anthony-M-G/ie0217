#include <iostream>
using namespace std;

// Al pasar las variables por referencia, se pasan las variables en sí
void swapWithReference(int &n1, int &n2)
{
  int temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
}
// Al pasar las variables por puntero, se pasan las direcciones de memoria de las variables
void swapWithReferencePointer(int *n1, int *n2)
{
  int temp;
  temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

int main()
{

  int a = 1, b = 2;

  cout << "Before swapping" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  // Pasando las variables por referencia
  swapWithReference(a, b);

  cout << "\nAfter swapping" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << "\n Usando punteros" << endl;
  // Pasando la dirección de memoria de las variables
  swapWithReferencePointer(&a, &b);

  cout << "\n Despues de intercambiar valores pasandole parémetros de tipo puntero" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  return 0;
}

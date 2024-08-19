// Sesión de c++ parte 1
#include <iostream>
using namespace std;

// Variable global, se puede usar desde cualquier parte
int g;
int main()
{
  /**
   * Declaraciín de variables y su tipo,
   * locales dentro de la función main */
  int a, b;
  int c;
  // Asignación de valores a las variables
  a = 10;
  b = 20;
  c = a + b;
  cout << c << endl;
  // Asignación de valor a la variable global
  g = b - a;
  cout << g << endl;
  return 0;
}
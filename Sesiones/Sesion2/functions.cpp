#include <iostream>
using namespace std;
void changeValue(int *x); // declaro la función changeValue

int main()
{
  int a = 5;
  cout << a << " " << &a << endl; // imprime el valor de a y la dirección de a
  changeValue(&a);
  cout << a << endl;
  return 0;
}

void changeValue(int *x) // paso de parámetros por referencia
{
  cout << *x << " " << x << " " << &x << endl; // diferencia entre *x y x, y &x. imprime el valor de x, la dirección de donde apunta x y la dirección de x misma, respectivamente
  *x -= 1;
}
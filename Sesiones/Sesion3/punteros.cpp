#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int var = 5;

  int *pointerVar = &var; // El puntero apunta a la direccion de memoria de var

  cout << "var = " << var << endl;

  cout << "Direccion de memoria de var = " << &var << endl; // El simbolo & me devuelve la direccion de memoria en la que se encuentra la variable var

  cout << "Direccion de memoria al que apunta pointerVar = " << pointerVar << endl; // El puntero me devuelve la direccion de memoria a la que apunta

  cout << "Valor de pointerVar = " << *pointerVar << endl; // El simbolo * me devuelve el valor al que apunta el puntero, en otras palabras lo que tiene dentro de la direccion de memoria

  // Cambiando el valor de var para ver el cambio en el puntero
  cout << "\nCambiando el valor de var para verlo reflejado al desreferenciar el puntero" << endl;
  var = 7;

  cout << "var = " << var << endl;

  cout << "Direccion de memoria de var = " << &var << endl;

  cout << "Direccion de memoria al que apunta pointerVar = " << pointerVar << endl;

  cout << "Valor de pointerVar = " << *pointerVar << endl;

  // Cambiando el valor de var a traves del puntero
  cout << "\nCambiando el valor de var a traves del puntero" << endl;
  *pointerVar = 10;

  cout << "var = " << var << endl;

  cout << "Direccion de memoria de var = " << &var << endl;

  cout << "Direccion de memoria al que apunta pointerVar = " << pointerVar << endl;

  cout << "Valor de pointerVar = " << *pointerVar << endl;
  return 0;
}

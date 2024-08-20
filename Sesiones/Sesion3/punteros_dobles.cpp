#include <iostream>
using namespace std;

int main()
{
  int var = 2050;
  int *ptr_var;

  ptr_var = &var; // Asigna al puntero 'ptr_var' la dirección en memoria de la variable 'var'. Ahora 'ptr_var' apunta a 'var'.

  // Muestra el valor de 'var' y la dirección almacenada en 'ptr_var'
  cout << "var: " << var << ", ptr_var: " << ptr_var << endl;

  int **ptr_ptr_var;      // Este puntero almacenará la dirección de un puntero a entero.
  ptr_ptr_var = &ptr_var; // le da a 'ptr_ptr_var' la dirección en memoria del puntero 'ptr_var'. Ahora 'ptr_ptr_var' apunta a 'ptr_var'.

  // Muestra la dirección almacenada en 'ptr_ptr_var', que es la dirección del puntero 'ptr_var'
  cout << "ptr_ptr_var: " << ptr_ptr_var << endl;

  // Muestra la dirección en memoria de 'ptr_var'
  cout << "&ptr_var: " << &ptr_var << endl;

  // Muestra la dirección en memoria de 'ptr_ptr_var'
  cout << "&ptr_ptr_var: " << &ptr_ptr_var << endl;

  return 0; // Termina la función 'main'
}

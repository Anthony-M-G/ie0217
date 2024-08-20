#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int var1 = 3;
  int var2 = 24;
  int var3 = 17;
  // El simbolo & me devuelve la direccion de memoria en la que se encuentra la variable
  cout << "var1: " << var1 << " Direccion de memoria: " << &var1 << endl;
  cout << "var2: " << var2 << " Direccion de memoria: " << &var2 << endl;
  cout << "var3: " << var3 << " Direccion de memoria: " << &var3 << endl;

  return 0;
}

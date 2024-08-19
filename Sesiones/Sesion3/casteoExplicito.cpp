#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  double num_double = 3.56;
  cout << "num_double: " << num_double << endl;

  int num_int = (int)num_double; // se realiza un casteo explicito de double a int
  cout << "num_int: " << num_int << endl;

  int num_int2 = int(num_double); // se realiza un casteo explicito de double a int usando la funcion int y pasarle el valor a castear como argumento
  cout << "num_int2: " << num_int2 << endl;

  return 0;
}
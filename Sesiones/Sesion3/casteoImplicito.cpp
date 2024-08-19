#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int num_int = 9;

  double num_double;

  num_double = num_int; // se realiza un casteo implicito de int a double

  cout << "num_int: " << num_int << endl;
  cout << "num_double: " << num_double << endl;
  return 0;
}

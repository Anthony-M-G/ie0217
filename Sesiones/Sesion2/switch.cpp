#include <iostream>
using namespace std;

int main()
{

  int var1 = 1;
  int var2 = 2;
  int var3 = 3;

  /**
   * el switch se usa para comparar una variable con varios valores y hacer lo que esté en el case que se cumpla
   */

  switch (var1)
  {
  case 1:
    cout << "var1 es 1" << endl;
    break;
  case 2:
    cout << "var1 es 2" << endl;
    break;
  case 3:
    cout << "var1 es 3" << endl;
    break;

  default: // este es el caso por defecto en el que si no hay un solo caso que se cumpla, el se ejecuta
    break;
  }

  return 0;
}
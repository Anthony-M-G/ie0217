#include <iostream>
using namespace std;
// Copial del ejemplo en que usa el operador ternario
int main()
{
  int var1 = 0;
  int var2;
  var2 = (var1 == 0) ? 15 : 27;

  cout << "var2:\t"
       << var2 << endl;

  return 0;
}
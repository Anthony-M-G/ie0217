#include <iostream>

using namespace std;

int factorial(int);

int main(int argc, char const *argv[])
{
  int n, resultado;

  cout << "Introduce un numero entero positivo: ";
  cin >> n;
  while (n < 0) // Validacion de que el numero sea positivo
  {
    cout << "Introduce un numero entero, debe ser positivo: ";
    cin >> n;
  }

  resultado = factorial(n);
  cout << "El factorial de " << n << " es " << resultado << endl;

  return 0;
}

int factorial(int n)
{
  if (n > 1) // condicion para que vuleva a llamarse a si misma o termine la recursion
  {
    return n * factorial(n - 1);
  }
  else
  {
    return 1;
  }
}

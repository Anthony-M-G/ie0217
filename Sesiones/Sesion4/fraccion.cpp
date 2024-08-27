#include <iostream>
using namespace std;
// sobre carga de operadores en C++
class Fraccion
{
  int numerador, denominador;

public:
  Fraccion(int n, int d) : numerador(n), denominador(d) {}

  Fraccion operator+(const Fraccion &f) // define la sobrecarga del operador + para la clase Fraccion y sus objetos
  {
    Fraccion resultado( // crea un objeto Fraccion llamado resultado con el numerador y denominador calculados
        numerador * f.denominador + f.numerador * denominador,
        denominador * f.denominador);
    return resultado;
  }

  void imprimir()
  {
    cout << numerador << "/" << denominador << endl;
  }
};

int main()
{
  Fraccion f1(2, 5);
  Fraccion f2(3, 4);

  Fraccion f3 = f1 + f2; // suma las fracciones f1 y f2 y guarda el resultado en f3
  f3.imprimir();

  return 0;
}

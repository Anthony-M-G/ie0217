#include <iostream>
using namespace std;

// Clase plantilla (template) con múltiples parámetros y valores por defecto
template <class T, class U,
          class V = char> // Parámetros de plantilla T, U y V (siendo V opcional
                          // con valor por defecto 'char')
class ClassTemplate {
private:
  T var1; // Variable de tipo T
  U var2; // Variable de tipo U
  V var3; // Variable de tipo V

public:
  // Constructor que inicializa las variables con los valores pasados
  ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}

  // Función para imprimir los valores de las variables
  void printVar() {
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;
    cout << "var3 = " << var3 << endl;
  }
};

int main() {
  // Crear objeto con tipos int, double y char
  ClassTemplate<int, double> obj1(
      7, 7.7,
      'c'); // Se infieren int y double, y char como valor por defecto para V
  cout << "obj1 values:" << endl;
  obj1.printVar(); // Imprimir valores del primer objeto

  // Crear objeto con tipos double, char y bool
  ClassTemplate<double, char, bool> obj2(3.14, 'a',
                                         true); // Especifica tipos explícitos
  cout << "obj2 values:" << endl;
  obj2.printVar(); // Imprimir valores del segundo objeto

  return 0;
}

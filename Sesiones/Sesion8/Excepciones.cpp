#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;
int main(int argc, char *argv[]) {
  double numerador, denominador, resultado;
  cout << "Ingrese el numerador: " << endl;
  cin >> numerador;

  cout << "Ingrese el denominador: " << endl;
  cin >> denominador;

  try { // Ingresa al código que me interesa ejecutar
    if (denominador == 0) // Si se cumple esta condición lanza la excepción
      throw runtime_error("Error: División por cero"); // Exceción de tipo runtime error
    resultado = numerador / denominador;
    cout << "Resultado: " << resultado << endl;
  } catch (const runtime_error &e) { // Atrapa la excepción, se pasa por referencia a esa excepción en específico
    cout << e.what() << endl; // e.what() obtiene el mensaje de la excepción que se lanzó
  }

  return 0;
}

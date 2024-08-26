#include "./includes/funciones_estadisticas.hpp"
#include "./includes/funcion_busqueda.hpp"
#include <iostream>
#include "string"

using namespace std;
enum class Opcion
{
  MostrarEstadisticas = 1,
  BuscarNumero = 2,
  Salir = 3
};

int main(int argc, char const *argv[])
{
  // Declara las variables necesarias en el programa
  enum Opcion opcionSeleccionada;
  int cantidad_numeros = argc - 1; // Cantidad de números que se ingresan por consola menos uno, ya que este es el nombre del programa
  int opcion;                      // Opción seleccionada por el usuario
  int numeros[cantidad_numeros];
  int *ptr = numeros;
  for (int i = 0; i < cantidad_numeros; i++)
  {
    *(ptr + i) = atoi(argv[i + 1]);
  }

  while (opcionSeleccionada != Opcion::Salir)
  {
    cout << "Selecciona una opción " << endl;
    cout << "1. Mostrar estadísticas" << endl;
    cout << "2. Buscar un numero en el arreglo" << endl;
    cout << "3. Salir" << endl;

    cin >> opcion;
    opcionSeleccionada = static_cast<Opcion>(opcion);
    switch (opcionSeleccionada)
    {
    case Opcion::MostrarEstadisticas:
      cout << "Estadísticas" << endl;
      suma(numeros, cantidad_numeros);
      promedio(numeros, cantidad_numeros);
      maximo(numeros, cantidad_numeros);
      minimo(numeros, cantidad_numeros);
      break;
    case Opcion::BuscarNumero:
      cout << "Buscar número" << endl;
      int numero_a_buscar;
      cout << "Ingresa el número a buscar" << endl;
      cin >> numero_a_buscar;
      busqueda(numeros, cantidad_numeros, numero_a_buscar);
      break;
    case Opcion::Salir:
      cout << "Saliendo del programa dos" << endl;
      break;
    }
  }
  return 0;
}

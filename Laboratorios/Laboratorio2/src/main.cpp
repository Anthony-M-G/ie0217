#include <iostream>
#include "funciones.hpp"

using namespace std;

const int MAX_LIBROS = 100;

enum class Opciones
{
  AgregarLibro = 1,
  MostrarLibros = 2,
  BuscarLibroPorTitulo = 3,
  BuscarLibroPorISBN = 4,
  EliminarLibro = 5,
  Salir = 6
};

int main()
{
  Libro libro[MAX_LIBROS];
  int cantidadLibros = 0;
  int opcion;
  Opciones opcionSeleccionada;

  do
  {
    cout << "Sistema de gestión de libros" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Mostrar libros" << endl;
    cout << "3. Buscar libro por título" << endl;
    cout << "4. Buscar libro por ISBN" << endl;
    cout << "5. Eliminar libro" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: " << endl;
    cin >> opcion;
    opcionSeleccionada = static_cast<Opciones>(opcion);
    switch (opcionSeleccionada)
    {
    case Opciones::AgregarLibro:
      agregarLibro(libro, cantidadLibros);
      break;
    case Opciones::MostrarLibros:
      mostrarLibros(libro, cantidadLibros);
      break;
    case Opciones::BuscarLibroPorTitulo:
      buscarLibroPorTitulo(libro, cantidadLibros);
      break;
    case Opciones::BuscarLibroPorISBN:
      buscarLibroPorISBN(libro, cantidadLibros);
      break;
    case Opciones::EliminarLibro:
      eliminarLibro(libro, cantidadLibros);
      break;
    case Opciones::Salir:
      cout << "Saliendo del sistema" << endl;
      break;

    default:
      cout << "Opción no válida" << endl;
      break;
    }
  } while (opcionSeleccionada != Opciones::Salir);
  return 0;
}
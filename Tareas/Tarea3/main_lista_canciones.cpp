#include <iostream>
#include <string>
#include "./GestionListaCanciones/includes/ListaCanciones.hpp"
#include <vector>

enum MenuOption
{
  AgregarInicio = 1,
  AgregarFinal,
  AgregarEnPosicion, // Nueva opción para insertar en una posición
  Listar,
  Eliminar,
  Modificar,
  Salir
};

void mostrarMenu()
{
  std::cout << "\n--- Menú de Lista de Canciones ---\n";
  std::cout << static_cast<int>(AgregarInicio) << "-> Agregar canción al inicio\n";
  std::cout << static_cast<int>(AgregarFinal) << "-> Agregar canción al final\n";
  std::cout << static_cast<int>(AgregarEnPosicion) << "-> Agregar canción en una posición específica\n"; // Nueva opción
  std::cout << static_cast<int>(Listar) << "-> Listar canciones\n";
  std::cout << static_cast<int>(Eliminar) << "-> Eliminar canción\n";
  std::cout << static_cast<int>(Modificar) << "-> Modificar canción\n";
  std::cout << static_cast<int>(Salir) << "-> Salir\n";
  std::cout << "Elige una opción: ";
}

Cancion *cancion_uno = new Cancion("Canción 1", "Artista 1", 3.5);
Cancion *cancion_dos = new Cancion("Canción 2", "Artista 2", 4.0);
Cancion *cancion_tres = new Cancion("Canción 3", "Artista 3", 3.0);

int main()
{
  ListaCanciones *lista = new ListaCanciones();
  lista->insertarAlInicio(cancion_uno);
  lista->insertarAlFinal(cancion_dos);
  lista->insertarAlFinal(cancion_tres);

  int opcion;

  do
  {
    mostrarMenu();
    std::cin >> opcion;
    opcion = static_cast<MenuOption>(opcion);

    switch (opcion)
    {
    case AgregarInicio:
    {
      std::string nombre, artista;
      double duracion;
      std::cout << "Nombre de la canción: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      std::cout << "Artista: ";
      std::getline(std::cin, artista);
      std::cout << "Duración (minutos): ";
      std::cin >> duracion;

      Cancion *nuevaCancion = new Cancion(nombre, artista, duracion);
      lista->insertarAlInicio(nuevaCancion);
      break;
    }
    case AgregarFinal:
    {
      std::string nombre, artista;
      double duracion;
      std::cout << "Nombre de la canción: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      std::cout << "Artista: ";
      std::getline(std::cin, artista);
      std::cout << "Duración (minutos): ";
      std::cin >> duracion;

      Cancion *nuevaCancion = new Cancion(nombre, artista, duracion);
      lista->insertarAlFinal(nuevaCancion);
      break;
    }
    case AgregarEnPosicion:
    {
      std::string nombre, artista;
      double duracion;
      int posicion;

      std::cout << "Nombre de la canción: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      std::cout << "Artista: ";
      std::getline(std::cin, artista);
      std::cout << "Duración (minutos): ";
      std::cin >> duracion;
      std::cout << "Posición en la que desea insertar (empezando desde 1): ";
      std::cin >> posicion;

      Cancion *nuevaCancion = new Cancion(nombre, artista, duracion);
      lista->insertarEn(nuevaCancion, posicion); // Utilizamos la función insertarEn
      break;
    }
    case Listar:
      lista->listarCanciones();
      break;
    case Eliminar:
    {
      std::string nombre;
      std::cout << "Nombre de la canción a eliminar debe ser exacto: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      lista->eliminarCancion(nombre);
      break;
    }
    case Modificar:
    {
      std::string nombreBusqueda, nuevoNombre, nuevoArtista;
      double nuevaDuracion;
      std::cout << "Nombre de la canción a modificar debe ser exacto: ";
      std::cin.ignore();
      std::getline(std::cin, nombreBusqueda);
      std::cout << "Nuevo nombre: ";
      std::getline(std::cin, nuevoNombre);
      std::cout << "Nuevo artista: ";
      std::getline(std::cin, nuevoArtista);
      std::cout << "Nueva duración (minutos): ";
      std::cin >> nuevaDuracion;

      lista->modificar(nombreBusqueda, nuevoNombre, nuevoArtista, nuevaDuracion);
      break;
    }
    case Salir:
      std::cout << "Saliendo del programa->\n";
      break;
    default:
      std::cout << "Opción inválida, por favor elige una opción válida->\n";
      break;
    }
  } while (opcion != Salir);

  delete lista; // Liberar la memoria de la lista de canciones

  delete cancion_uno;
  delete cancion_dos;
  delete cancion_tres;

  return 0;
}

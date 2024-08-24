#include <iostream>
#include "./funciones.hpp"
#include <cstring>

using namespace std;

void agregarLibro(Libro libro[], int &cantidadLibros)
{
  cout << "Ingrese el titulo del libro: ";
  cin.ignore();
  cin.getline(libro[cantidadLibros].titulo, 100);
  cout << "Ingrese el autor del libro: ";
  cin.getline(libro[cantidadLibros].autor, 100);
  cout << "Ingrese el ISBN del libro: ";
  cin.getline(libro[cantidadLibros].ISBN, 13);
  cout << "Ingrese el anio del libro: ";
  cin >> libro[cantidadLibros].anio;

  cantidadLibros++;
}

void mostrarLibros(Libro libros[], int cantidadLibros)
{
  for (int i = 0; i < cantidadLibros; i++)
  {
    if (cantidadLibros == 0)
    {
      cout << "No hay libros registrados" << endl;
      return;
    }
    for (int i = 0; i < cantidadLibros; i++)
    {
      cout << cantidadLibros << ".Titulo: " << libros[i].titulo << endl;
      cout << "Autor: " << libros[i].autor << endl;
      cout << "ISBN: " << libros[i].ISBN << endl;
      cout << "Anio: " << libros[i].anio << endl;
      cout << endl;
    }
  }
}

void buscarLibroPorTitulo(Libro libros[], int cantidadLibros)
{
  char titulo[100];
  cout << "Ingrese el título del libro que desea buscar: " << endl;
  cin.getline(titulo, 100);
  bool encontrado = false;
  for (int i = 0; i < cantidadLibros; i++)
  {
    if (strcmp(libros[i].titulo, titulo) == 0)
    {
      cout << "Libro encontrado" << endl;
      cout << "Titulo: " << libros[i].titulo << endl;
      cout << "Autor: " << libros[i].autor << endl;
      cout << "ISBN: " << libros[i].ISBN << endl;
      cout << "Anio: " << libros[i].anio << endl;
      cout << endl;
      encontrado = true;
      break;
    }
  }

  if (!encontrado)
  {
    cout << "El libro no fue encontrado" << endl;
  }
};

void buscarLibroPorISBN(Libro libros[], int cantidadLibros)
{
  char ISBN[13];
  cout << "Ingrese el ISBN del libro que desea buscar: ";
  cin.ignore();
  cin.getline(ISBN, 13);
  bool encontrado = false;
  for (int i = 0; i < cantidadLibros; i++)
  {
    if (strcmp(libros[i].ISBN, ISBN) == 0)
    {
      cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
      encontrado = true;
      break;
    }
  }
  if (!encontrado)
  {
    cout << "Libro no encontrado." << endl;
  }
}

void eliminarLibro(Libro libro[], int &cantidadLibros)
{
  char ISBN[13];
  cout << "Ingrese el ISBN del libro que desea eliminar: ";
  cin.ignore();
  cin.getline(ISBN, 13);
  cout << ISBN << endl;
  for (int i = 0; i < cantidadLibros; i++)
  {
    if (strcmp(libro[i].ISBN, ISBN) == 0)
    {
      for (int j = i; j < cantidadLibros - 1; j++)
      {
        libro[j] = libro[j + 1];
        cantidadLibros--;
        cout << "Libro eliminado" << endl;
        return;
      }
    }
  }
  cout << "Libro no encontrado." << endl;
};
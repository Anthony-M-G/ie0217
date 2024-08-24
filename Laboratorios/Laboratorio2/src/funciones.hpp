#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "./libro.hpp"

void agregarLibro(Libro libros[], int &cantidadLibros);
void buscarLibroPorTitulo(Libro libro[], int cantidadLibros);
void buscarLibroPorISBN(Libro libro[], int cantidadLibros);
void mostrarLibros(Libro libros[], int cantidadLibros);
void eliminarLibro(Libro libro[], int &cantidadLibros);

#endif

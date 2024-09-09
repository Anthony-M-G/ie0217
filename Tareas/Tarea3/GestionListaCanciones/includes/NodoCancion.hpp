#ifndef NODOCANCION_HPP
#define NODOCANCION_HPP
#include "Cancion.hpp"
// Nodo de la lista de canciones que contiene un puntero a la siguiente canción y la canción que aloja
typedef struct NodoCancion
{
  Cancion cancion;
  NodoCancion *siguiente;

  NodoCancion(Cancion t_cancion) : cancion(t_cancion), siguiente(nullptr) {};
} NodoCancion;

#endif
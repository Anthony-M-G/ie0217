#ifndef NODOCANCION_HPP
#define NODOCANCION_HPP
#include "Cancion.hpp"

typedef struct NodoCancion
{
  Cancion cancion;
  NodoCancion *siguiente;

  NodoCancion(Cancion t_cancion) : cancion(t_cancion), siguiente(nullptr) {};
} NodoCancion;

#endif
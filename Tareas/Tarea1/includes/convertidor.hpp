#ifndef UNIDAD_HPP

#define UNIDAD_HPP
// Struct que tiene un puntero a una función que convierte una unidad a otra
typedef struct
{
  double (*func_conversion)(double);
} Convertidor;

#endif

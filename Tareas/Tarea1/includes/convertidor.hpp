#ifndef UNIDAD_HPP

#define UNIDAD_HPP
// Struct que tiene un puntero a una función que convierte una unidad a otra
/**
 * @brief Estructura que representa un convertidor.
 *
 * Esta estructura contiene un puntero a una función de conversión.
 * La función de conversión toma un parámetro de tipo double y devuelve un double.
 */
typedef struct
{
  double (*func_conversion)(double);
} Convertidor;

#endif

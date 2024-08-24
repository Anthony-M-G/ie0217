#ifndef LIBRO_HPP
#define LIBRO_HPP
typedef struct
{
  char titulo[100];
  char autor[100];
  char ISBN[13];
  int anio;
} Libro;
#endif

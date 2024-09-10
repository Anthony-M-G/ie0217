#ifndef NODO_HPP
#define NODO_HPP
typedef struct Nodo
{
  int dato;
  Nodo *izquierdo;
  Nodo *derecho;

  Nodo(int t_valor) : dato(t_valor), izquierdo(nullptr), derecho(nullptr) {}

} Nodo;
#endif
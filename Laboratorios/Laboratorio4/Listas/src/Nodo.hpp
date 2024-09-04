#ifndef NODO_HPP
#define NODO_HPP

struct Nodo
{
  // Atributos de la estructura Nodo, su valor y un puntero al siguiente nodo que es de su mismo tipo
  int dato;
  Nodo *siguiente;

  Nodo(int valor) : dato(valor), siguiente(nullptr) {} // Constructor que al inicializar el nodo, le asigna un valor y el siguiente nodo es nulo
};

#endif
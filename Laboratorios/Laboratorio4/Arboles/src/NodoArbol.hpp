#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
// Estructura de un nodo de un árbol binario de búsqueda
struct NodoArbol
{
  int dato;             // Valor del nodo
  NodoArbol *izquierdo; // Puntero al nodo izquierdo
  NodoArbol *derecho;   // Puntero al nodo derecho

  NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {} // Constructor que inicializa el nodo con un valor y los punteros nulos
};

#endif

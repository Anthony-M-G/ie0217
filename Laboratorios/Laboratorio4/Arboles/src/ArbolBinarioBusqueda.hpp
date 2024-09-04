#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

#include "NodoArbol.hpp"
#include <iostream>
#include <algorithm>

class ArbolBinarioBusqueda
{
  // Atributo de la clase ArbolBinarioBusqueda, que es un puntero a la raíz del árbol
private:
  NodoArbol *raiz;

  void insertarNodo(NodoArbol *&nodo, int valor)
  {
    if (nodo == nullptr) // Si el nodo es nulo, crea un nuevo nodo con el valor ingresado
    {
      nodo = new NodoArbol(valor);
    }
    else if (valor < nodo->dato) // Si el valor es menor al valor del nodo actual, se inserta en el subárbol izquierdo
    {
      insertarNodo(nodo->izquierdo, valor); // Llamada recursiva con el subárbol izquierdo
    }
    else
    {
      // Si el valor es mayor o igual al valor del nodo actual, se inserta en el subárbol derecho
      insertarNodo(nodo->derecho, valor);
    }
  }
  // Recorrido en preorden del árbol
  void preOrden(NodoArbol *nodo) const
  {
    if (nodo != nullptr)
    {
      std::cout << nodo->dato << " ";
      // Llamada recursiva con el subárbol izquierdo
      preOrden(nodo->izquierdo);
      preOrden(nodo->derecho);
    }
  }
  // Recorrido en inorden del árbol
  void inOrden(NodoArbol *nodo) const
  {
    if (nodo != nullptr)
    {
      // Llamada recursiva con el subárbol izquierdo
      inOrden(nodo->izquierdo);
      std::cout << nodo->dato << " ";
      // Llamada recursiva con el subárbol derecho
      inOrden(nodo->derecho);
    }
  }
  // Recorrido en postorden del árbol
  void postOrden(NodoArbol *nodo) const
  {
    if (nodo != nullptr)
    {
      // Llamada recursiva con el subárbol izquierdo
      postOrden(nodo->izquierdo);
      // Llamada recursiva con el subárbol derecho
      postOrden(nodo->derecho);
      std::cout << nodo->dato << " ";
    }
  }
  // Busca un nodo con un valor específico en el árbol
  bool buscarNodo(NodoArbol *nodo, int valor) const
  {
    if (nodo == nullptr)
      return false; // Si el nodo es nulo, retorna falso
    if (nodo->dato == valor)
      return true;          // Si el valor del nodo es igual al valor buscado, retorna verdadero
    if (valor < nodo->dato) // Si el valor es menor al valor del nodo actual, busca en el subárbol izquierdo
      return buscarNodo(nodo->izquierdo, valor);
    return buscarNodo(nodo->derecho, valor); // Si el valor es mayor o igual al valor del nodo actual, busca en el subárbol derecho
  }

  // Calcula la altura de un nodo del árbol
  int altura(NodoArbol *nodo) const
  {
    if (nodo == nullptr)
      return 0;
    return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));
  }
  // Verifica si el árbol está balanceado
  bool estaBalanceado(NodoArbol *nodo) const
  {
    if (nodo == nullptr)
      return true;

    int alturaIzquierda = altura(nodo->izquierdo);
    int alturaDerecha = altura(nodo->derecho);

    return std::abs(alturaIzquierda - alturaDerecha) <= 1 &&
           estaBalanceado(nodo->izquierdo) &&
           estaBalanceado(nodo->derecho);
  }

public:
  ArbolBinarioBusqueda() : raiz(nullptr) {}

  void insertar(int valor)
  {
    // Llama a la función privada insertarNodo con la raíz del árbol y el valor a insertar
    insertarNodo(raiz, valor);
  }

  void preOrden() const
  {
    preOrden(raiz);
    std::cout << std::endl;
  }

  void inOrden() const
  {
    inOrden(raiz);
    std::cout << std::endl;
  }

  void postOrden() const
  {
    postOrden(raiz);
    std::cout << std::endl;
  }

  bool buscar(int valor) const
  {
    return buscarNodo(raiz, valor);
  }

  int altura() const
  {
    return altura(raiz);
  }

  bool estaBalanceado() const
  {
    return estaBalanceado(raiz);
  }
};

#endif
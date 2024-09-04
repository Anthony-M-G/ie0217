#ifndef LISTAENLAZADA_HPP
#define LISTAENLAZADA_HPP

#include "Nodo.hpp"
#include <iostream>

class ListaEnlazada
{
  // Atributo de la clase ListaEnlazada, que es un puntero al primer nodo de la lista
private:
  Nodo *cabeza;

public:
  // Constructor de la clase ListaEnlazada, inicializa la cabeza de la lista como un puntero nulo
  ListaEnlazada() : cabeza(nullptr) {}

  // Destructor de la clase ListaEnlazada, libera la memoria de todos los nodos de la lista
  ~ListaEnlazada()
  {
    // Mientras la cabeza no sea nula (que significa que la lista no está vacía) se libera la memoria de cada nodo, asignando la cabeza al siguiente nodo y eliminando el nodo actual
    while (cabeza != nullptr)
    {
      Nodo *temp = cabeza;
      cabeza = cabeza->siguiente;
      delete temp;
    }
  }

  void insertarInicio(int valor)
  {
    // Crea un nuevo nodo con el valor ingresado, hace que el nuevo nodo apunte al nodo que era la cabeza y asigna el nuevo nodo como la cabeza
    Nodo *nuevoNodo = new Nodo(valor);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
  }

  void insertarFinal(int valor)
  {
    // Crea un nuevo nodo con el valor que le pase
    Nodo *nuevoNodo = new Nodo(valor);
    if (cabeza == nullptr) // si la cabeza es nula (significa que la lista está vacía) entonces asigna el nuevo nodo como el primer elemento de la lista
    {
      cabeza = nuevoNodo;
    }
    else
    {
      // Si la lista no está vacía, recorre la lista hasta llegar al último nodo y asigna el nuevo nodo como el siguiente del último nodo
      Nodo *temp = cabeza;
      while (temp->siguiente != nullptr)
      {
        temp = temp->siguiente;
      }
      // acá se asigna el nuevo nodo como el siguiente del último nodo
      temp->siguiente = nuevoNodo;
    }
  }

  void eliminar(int valor)
  {
    // Si el primer nodo de la lista es nulo significa que la lista está vacía, entonces no se hace nada
    if (cabeza == nullptr)
      return;
    // Si el valor a eliminar es el de la cabeza, se elimina la cabeza(primer elemento) y se asigna el siguiente nodo como la nueva cabeza
    if (cabeza->dato == valor)
    {
      Nodo *temp = cabeza;
      cabeza = cabeza->siguiente;
      delete temp;
      return;
    }
    // Si el valor a eliminar no es la cabeza recorre la lista hasta encontrar el nodo anterior al nodo que se quiere eliminar
    Nodo *temp = cabeza;
    while (temp->siguiente != nullptr && temp->siguiente->dato != valor)
    {
      temp = temp->siguiente;
    }
    // Si el nodo siguiente al nodo actual no es nulo, significa que el nodo a eliminar es el siguiente al nodo actual
    if (temp->siguiente != nullptr)
    {
      // El nodo a eliminar es el siguiente al nodo actual
      Nodo *nodoAEliminar = temp->siguiente;
      temp->siguiente = temp->siguiente->siguiente; // El siguiente del nodo actual es el siguiente del nodo a eliminar
      delete nodoAEliminar;
    }
  }

  void imprimir() const
  {
    Nodo *temp = cabeza;
    // Recorre la lista e imprime el valor de cada nodo asignando el nodo siguiente al nodo actual
    while (temp != nullptr)
    {
      std::cout << temp->dato << " -> ";
      temp = temp->siguiente;
    }
    std::cout << "null" << std::endl;
  }

  // Busca el nodo con el valor que le pase, si lo encuentra retorna verdadero, si no lo encuentra retorna falso
  bool buscar(int valor) const
  {
    Nodo *temp = cabeza;
    while (temp != nullptr)
    {
      if (temp->dato == valor)
        return true;
      temp = temp->siguiente;
    }
    return false;
  }
};

#endif
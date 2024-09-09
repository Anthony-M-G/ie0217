#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

#include "Nodo.hpp"
#include <iostream>

class ArbolBS
{
private:
  Nodo *raiz;

  void insertarNodo(Nodo *&nodo, int valor);
  void inOrden(Nodo *nodo) const;
  bool buscarNodo(Nodo *nodo, int valor) const;
  int altura(Nodo *nodo) const;
  bool estaBalanceado(Nodo *nodo) const;
  Nodo *obtenerSucesor(Nodo *nodo);
  Nodo *eliminarNodo(Nodo *nodo, int valor);

public:
  ArbolBS();
  void insertar(int valor);
  void imprimir() const;
  bool buscar(int valor) const;
  int altura() const;
  bool estaBalanceado() const;
  void eliminar(int valor);
};

#endif

#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

#include "Nodo.hpp"
#include <iostream>

/**
 * @class ArbolBS
 * @brief Clase que representa un Árbol Binario de Búsqueda (ABB).
 *
 * La clase ArbolBS proporciona operaciones comunes para un Árbol Binario de Búsqueda,
 * como la inserción, eliminación, búsqueda, recorrido en orden, cálculo de la altura
 * y verificación de balance del árbol.
 */
class ArbolBS
{
private:
  Nodo *raiz; ///< Puntero al nodo raíz del Árbol Binario de Búsqueda.

  /**
   * @brief Inserta un nuevo nodo en el árbol.
   *
   * @param nodo Referencia al puntero del nodo actual.
   * @param valor Valor entero a insertar en el árbol.
   */
  void insertarNodo(Nodo *&nodo, int valor);

  /**
   * @brief Realiza un recorrido in-order del árbol e imprime los valores de los nodos.
   *
   * @param nodo Puntero al nodo actual del árbol.
   */
  void inOrden(Nodo *nodo) const;

  /**
   * @brief Busca un valor en el árbol.
   *
   * @param nodo Puntero al nodo actual del árbol.
   * @param valor Valor entero a buscar en el árbol.
   * @return `true` si el valor se encuentra en el árbol, `false` en caso contrario.
   */
  bool buscarNodo(Nodo *nodo, int valor) const;

  /**
   * @brief Calcula la altura del árbol a partir de un nodo dado.
   *
   * @param nodo Puntero al nodo actual del árbol.
   * @return Altura del árbol.
   */
  int altura(Nodo *nodo) const;

  /**
   * @brief Verifica si el árbol está balanceado.
   *
   * @param nodo Puntero al nodo actual del árbol.
   * @return `true` si el árbol está balanceado, `false` en caso contrario.
   */
  bool estaBalanceado(Nodo *nodo) const;

  /**
   * @brief Obtiene el sucesor in-order de un nodo dado.
   *
   * @param nodo Puntero al nodo del cual se desea obtener el sucesor.
   * @return Puntero al nodo sucesor.
   */
  Nodo *obtenerSucesor(Nodo *nodo);

  /**
   * @brief Elimina un nodo del árbol.
   *
   * @param nodo Puntero al nodo actual del árbol.
   * @param valor Valor entero del nodo a eliminar.
   * @return Puntero al nodo modificado después de la eliminación.
   */
  Nodo *eliminarNodo(Nodo *nodo, int valor);

public:
  /**
   * @brief Constructor de la clase ArbolBS.
   *
   * Inicializa un nuevo Árbol Binario de Búsqueda vacío.
   */
  ArbolBS();

  /**
   * @brief Inserta un valor en el árbol.
   *
   * @param valor Valor entero a insertar en el árbol.
   */
  void insertar(int valor);

  /**
   * @brief Imprime los valores del árbol en orden ascendente.
   */
  void imprimir() const;

  /**
   * @brief Busca un valor en el árbol.
   *
   * @param valor Valor entero a buscar en el árbol.
   * @return `true` si el valor se encuentra en el árbol, `false` en caso contrario.
   */
  bool buscar(int valor) const;

  /**
   * @brief Calcula la altura del árbol.
   *
   * @return Altura del árbol.
   */
  int altura() const;

  /**
   * @brief Verifica si el árbol está balanceado.
   *
   * @return `true` si el árbol está balanceado, `false` en caso contrario.
   */
  bool estaBalanceado() const;

  /**
   * @brief Elimina un valor del árbol.
   *
   * @param valor Valor entero a eliminar del árbol.
   */
  void eliminar(int valor);
};

#endif // ARBOLBINARIOBUSQUEDA_HPP

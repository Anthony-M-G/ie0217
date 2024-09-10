#ifndef NODO_HPP
#define NODO_HPP

/**
 * @struct Nodo
 * @brief Nodo que representa un elemento de un Árbol Binario de Búsqueda (ABB).
 *
 * La estructura Nodo contiene un valor entero, así como punteros a los nodos hijos izquierdo y derecho.
 */
typedef struct Nodo
{
  int dato;        ///< Valor almacenado en el nodo.
  Nodo *izquierdo; ///< Puntero al nodo hijo izquierdo.
  Nodo *derecho;   ///< Puntero al nodo hijo derecho.

  /**
   * @brief Constructor del nodo que inicializa su valor y establece los punteros a los nodos hijos como nulos.
   *
   * @param t_valor Valor entero que se almacenará en el nodo.
   */
  Nodo(int t_valor) : dato(t_valor), izquierdo(nullptr), derecho(nullptr) {}

} Nodo;

#endif // NODO_HPP

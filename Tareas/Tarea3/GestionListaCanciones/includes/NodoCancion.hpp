#ifndef NODOCANCION_HPP
#define NODOCANCION_HPP

#include "Cancion.hpp"

/**
 * @struct NodoCancion
 * @brief Nodo que representa un elemento de la lista enlazada de canciones.
 *
 * La estructura NodoCancion contiene un objeto de la clase `Cancion` y un puntero al siguiente nodo de la lista.
 */
typedef struct NodoCancion
{
  Cancion cancion;        ///< Objeto Cancion que almacena la información de una canción.
  NodoCancion *siguiente; ///< Puntero al siguiente nodo en la lista enlazada.

  /**
   * @brief Constructor del nodo que inicializa la canción y establece el puntero al siguiente nodo como nulo.
   *
   * @param t_cancion Objeto Cancion que se almacenará en el nodo.
   */
  NodoCancion(Cancion t_cancion) : cancion(t_cancion), siguiente(nullptr) {};

} NodoCancion;

#endif // NODOCANCION_HPP

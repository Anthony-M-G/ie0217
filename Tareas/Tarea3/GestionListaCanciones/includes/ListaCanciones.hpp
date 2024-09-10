#ifndef LISTA_CANCIONES_HPP
#define LISTA_CANCIONES_HPP

#include "NodoCancion.hpp"
#include "Cancion.hpp"

/**
 * @class ListaCanciones
 * @brief Clase que representa una lista enlazada de canciones.
 *
 * La clase ListaCanciones gestiona una colección de canciones usando una lista enlazada.
 * Proporciona métodos para insertar, eliminar, modificar y listar canciones.
 */
class ListaCanciones
{
private:
  NodoCancion *nodoCabeza; ///< Puntero al nodo cabeza de la lista enlazada.

public:
  /**
   * @brief Constructor de la clase ListaCanciones.
   *
   * Inicializa una nueva lista enlazada vacía de canciones.
   */
  ListaCanciones();

  /**
   * @brief Destructor de la clase ListaCanciones.
   *
   * Libera todos los recursos utilizados por la lista enlazada, incluyendo la liberación de la memoria de cada nodo.
   */
  ~ListaCanciones();

  /**
   * @brief Inserta una canción al inicio de la lista.
   * @param cancion Puntero a la canción a insertar.
   */
  void insertarAlInicio(Cancion *&cancion);

  /**
   * @brief Inserta una canción al final de la lista.
   * @param cancion Puntero a la canción a insertar.
   */
  void insertarAlFinal(Cancion *&cancion);

  /**
   * @brief Inserta una canción en una posición específica de la lista.
   * @param cancion Puntero a la canción a insertar.
   * @param pos Posición en la que se desea insertar la canción.
   */
  void insertarEn(Cancion *&cancion, int pos);

  /**
   * @brief Muestra todas las canciones en la lista.
   *
   * Imprime en consola la lista completa de canciones, mostrando su nombre, artista y duración.
   */
  void listarCanciones() const;

  /**
   * @brief Elimina una canción de la lista.
   * @param nombre Nombre de la canción que se desea eliminar.
   */
  void eliminarCancion(const std::string &nombre);

  /**
   * @brief Modifica los detalles de una canción existente en la lista.
   * @param nombreBusqueda Nombre de la canción a buscar.
   * @param nuevo_nombre Nuevo nombre de la canción.
   * @param artista Nombre del nuevo artista.
   * @param nuevaDuración Nueva duración de la canción.
   */
  void modificar(const std::string &nombreBusqueda, const std::string &nuevo_nombre, const std::string &artista, double nuevaDuración);
};

#endif // LISTA_CANCIONES_HPP

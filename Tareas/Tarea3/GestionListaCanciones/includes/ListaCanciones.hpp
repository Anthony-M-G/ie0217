#ifndef LISTA_CANCIONES_HPP
#define LISTA_CANCIONES_HPP
#include "NodoCancion.hpp"
#include "Cancion.hpp"
class ListaCanciones
{
private:
  NodoCancion *nodoCabeza;

public:
  ListaCanciones(/* args */);
  ~ListaCanciones();

  // Inserta Nodo al inicio de la lista
  void insertarAlInicio(Cancion *&cancion);
  // Inserta Nodo al final de la lista
  void insertarAlFinal(Cancion *&cancion);
  // Inserta Nodo en una posición específica
  void insertarEn(Cancion *&cancion, int pos);
  // Lista las canciones
  void listarCanciones() const;
  // Elimina una canción
  void eliminarCancion(const std::string &nombre);
  // Modifica una canción
  void modificar(const std::string &nombreBusqueda, const std::string &nuevo_nombre, const std::string &artista, double nuevaDuración);
};

#endif
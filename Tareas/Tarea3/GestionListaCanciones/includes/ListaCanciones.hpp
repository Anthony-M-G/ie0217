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

  void insertarAlInicio(Cancion *&cancion);
  void insertarAlFinal(Cancion *&cancion);
  void insertarEn(Cancion *&cancion, int pos);
  void listarCanciones() const;
  void eliminarCancion(const std::string &nombre);
  void modificar(const std::string &nombreBusqueda, const std::string &nuevo_nombre, const std::string &artista, double nuevaDuración);
};

#endif
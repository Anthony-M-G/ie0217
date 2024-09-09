#include "../includes/ListaCanciones.hpp"
#include <iostream>
ListaCanciones::ListaCanciones() : nodoCabeza(nullptr) {}

void ListaCanciones::insertarAlInicio(Cancion *&cancion)
{
  NodoCancion *nuevoNodo = new NodoCancion(*cancion);
  nuevoNodo->siguiente = nodoCabeza;
  nodoCabeza = nuevoNodo;
  std::cout << "Nueva canción agregada al inicio correctamente" << std::endl;
};

void ListaCanciones::insertarAlFinal(Cancion *&cancion)
{
  NodoCancion *nuevoNodo = new NodoCancion(*cancion);
  NodoCancion *tmp = nodoCabeza;
  if (nodoCabeza == nullptr)
  {
    nodoCabeza = nuevoNodo;
    nodoCabeza->siguiente = nullptr;
    std::cout << "La lista estaba vacía por lo cual se agregó como la primera en la lista" << std::endl;
    return;
  }
  while (tmp->siguiente != nullptr)
  {
    tmp = tmp->siguiente;
  }
  tmp->siguiente = nuevoNodo;
  nuevoNodo->siguiente = nullptr;
};

void ListaCanciones::insertarEn(Cancion *&cancion, int pos) {

};

void ListaCanciones::listarCanciones() const
{
  if (nodoCabeza == nullptr)
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  NodoCancion *tmp = nodoCabeza;
  while (tmp != nullptr)
  {
    std::cout << "Canción: " << tmp->cancion.getNombre() << " Artista: " << tmp->cancion.getArtista() << " Duración: " << tmp->cancion.getDuracion() << std::endl;
    tmp = tmp->siguiente;
  }
};

void ListaCanciones::eliminarCancion(const std::string &nombre)
{
  if (nodoCabeza == nullptr)
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  if (nodoCabeza->cancion.getNombre() == nombre)
  {
    NodoCancion *tmp = nodoCabeza;
    nodoCabeza = nodoCabeza->siguiente;
    delete tmp;
    return;
  }
  NodoCancion **tmp = &nodoCabeza;
  while ((*tmp)->siguiente != nullptr && (*tmp)->siguiente->cancion.getNombre() != nombre)
  {
    tmp = &(*tmp)->siguiente;
  }
  if ((*tmp)->siguiente == nullptr)
  {
    std::cout << "No se encontró la canción" << std::endl;
    return;
  }
  NodoCancion *tmp2 = (*tmp)->siguiente;
  (*tmp)->siguiente = (*tmp)->siguiente->siguiente;
  delete tmp2;
};

void ListaCanciones::modificar(const std::string &nombreBusqueda,
                               const std::string &nuevo_nombre,
                               const std::string &artista,
                               double nuevaDuracion)
{
  NodoCancion *tmp = nodoCabeza;
  if (nodoCabeza == nullptr)
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  while (tmp != nullptr && tmp->cancion.getNombre() != nombreBusqueda)
  {
    tmp = tmp->siguiente;
  }
  if (tmp == nullptr)
  {
    std::cout << "No se encontró la canción" << std::endl;
    return;
  }
  if (nuevo_nombre != "")
    tmp->cancion.setNombre(nuevo_nombre);
  if (artista != "")
    tmp->cancion.setArtista(artista);
  if (nuevaDuracion != 0)
    tmp->cancion.setDuracion(nuevaDuracion);
};

ListaCanciones::~ListaCanciones()
{
  NodoCancion *tmp;
  while (nodoCabeza != nullptr)
  {
    tmp = nodoCabeza;                   // Almacena el nodo actual
    nodoCabeza = nodoCabeza->siguiente; // Avanza al siguiente nodo
    delete tmp;                         // Elimina el nodo actual
  }
};

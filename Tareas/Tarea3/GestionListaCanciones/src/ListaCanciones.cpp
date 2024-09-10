#include "../includes/ListaCanciones.hpp"
#include <iostream>
ListaCanciones::ListaCanciones() : nodoCabeza(nullptr) {}

void ListaCanciones::insertarAlInicio(Cancion *&cancion)
{
  NodoCancion *nuevoNodo = new NodoCancion(*cancion); // Creamos un nuevo nodo con la canción
  nuevoNodo->siguiente = nodoCabeza;                  // El siguiente del nuevo nodo es la cabeza de la lista
  nodoCabeza = nuevoNodo;                             // La cabeza de la lista es el nuevo nodo
  std::cout << "Nueva canción agregada al inicio correctamente" << std::endl;
};

void ListaCanciones::insertarAlFinal(Cancion *&cancion)
{
  NodoCancion *nuevoNodo = new NodoCancion(*cancion);
  NodoCancion *tmp = nodoCabeza;
  if (nodoCabeza == nullptr) // Si la lista está vacía se agrega como la primera
  {
    nodoCabeza = nuevoNodo;
    nodoCabeza->siguiente = nullptr;
    std::cout << "La lista estaba vacía por lo cual se agregó como la primera en la lista" << std::endl;
    return;
  }
  while (tmp->siguiente != nullptr) // Se recorre la lista hasta llegar al último nodo
  {
    tmp = tmp->siguiente; // Se avanza al siguiente nodo
  }
  tmp->siguiente = nuevoNodo;     // Se agrega el nuevo nodo al final
  nuevoNodo->siguiente = nullptr; // El siguiente del nuevo nodo es nulo
};

void ListaCanciones::insertarEn(Cancion *&cancion, int pos)
{
  NodoCancion *nuevoNodo = new NodoCancion(*cancion);
  NodoCancion *tmp = nodoCabeza;
  int posicionCancion = 0;
  if (nodoCabeza == nullptr) // Si la lista está vacía se agrega como la primera
  {
    nodoCabeza = nuevoNodo;
    nodoCabeza->siguiente = nullptr;
    std::cout << "La lista estaba vacía por lo cual se agregó como la primera en la lista" << std::endl;
    return;
  }
  if (pos == 0) // Si la posición es 0 se agrega como la primera
  {
    nuevoNodo->siguiente = nodoCabeza;
    nodoCabeza = nuevoNodo;
    return;
  }
  while (tmp != nullptr && posicionCancion < pos - 2) // Se recorre la lista hasta llegar a la posición n-1
  {
    tmp = tmp->siguiente;
    posicionCancion++;
  }
  if (tmp == nullptr) // Si no encontramos el nodo en la posición n-1
  {
    // Si no encontramos el nodo en la posición n-1
    std::cout << "La posición es mayor que el tamaño de la lista" << std::endl;
    delete nuevoNodo; // Liberar la memoria del nodo si no se va a usar
    return;
  }
  nuevoNodo->siguiente = tmp->siguiente; // El siguiente del nuevo nodo es el siguiente del nodo en la posición n-1
  tmp->siguiente = nuevoNodo;            // El siguiente del nodo en la posición n-1 es el nuevo nodo
};

void ListaCanciones::listarCanciones() const
{
  int numeroCancion = 1;
  if (nodoCabeza == nullptr) // Si la lista está vacía se imprime un mensaje
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  NodoCancion *tmp = nodoCabeza;
  while (tmp != nullptr) // Se recorre la lista imprimiendo las canciones
  {
    std::cout << numeroCancion << "." << " Canción: " << tmp->cancion.getNombre() << " Artista: " << tmp->cancion.getArtista() << " Duración: " << tmp->cancion.getDuracion() << " minutos" << std::endl;
    tmp = tmp->siguiente;
    numeroCancion++;
  }
};

void ListaCanciones::eliminarCancion(const std::string &nombre)
{
  if (nodoCabeza == nullptr) // Si la lista está vacía se imprime un mensaje
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  if (nodoCabeza->cancion.getNombre() == nombre) // Si la canción a eliminar es la primera
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
                               double nuevaDuracion) // Modifica una canción
{
  NodoCancion *tmp = nodoCabeza;
  if (nodoCabeza == nullptr) // Si la lista está vacía se imprime un mensaje
  {
    std::cout << "La lista esta vacía" << std::endl;
  }
  while (tmp != nullptr && tmp->cancion.getNombre() != nombreBusqueda) // Se recorre la lista hasta encontrar la canción
  {
    tmp = tmp->siguiente;
  }
  if (tmp == nullptr) // Si no se encontró la canción se imprime un mensaje
  {
    std::cout << "No se encontró la canción" << std::endl;
    return;
  }

  tmp->cancion.setNombre(nuevo_nombre);

  tmp->cancion.setArtista(artista);

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

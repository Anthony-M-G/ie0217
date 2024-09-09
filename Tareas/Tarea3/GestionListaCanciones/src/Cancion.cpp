#include "../includes/Cancion.hpp"
#include <string>
Cancion::Cancion(const std::string &nombre, const std::string &artista, double duracion) : nombre(nombre), artista(artista), duracion(duracion) {};

void Cancion::setNombre(const std::string &nombre)
{
  this->nombre = nombre;
}

void Cancion::setArtista(const std::string &artista)
{
  this->artista = artista;
}

void Cancion::setDuracion(double duracion)
{
  this->duracion = duracion;
}

std::string Cancion::getArtista() const
{
  return this->artista;
}

std::string Cancion::getNombre() const
{
  return this->nombre;
}

double Cancion::getDuracion() const
{
  return this->duracion;
}

Cancion::~Cancion() {}

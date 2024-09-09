#ifndef CANCION_HPP
#define CANCION_HPP
#include <string>
class Cancion
{
private:
  std::string nombre;
  std::string artista;
  double duracion;

public:
  Cancion(const std::string &nombre, const std::string &artista, double duracion);
  ~Cancion();
  // Setters y Getters
  void setNombre(const std::string &nombre);
  void setArtista(const std::string &artista);
  void setDuracion(double duracion);

  std::string getArtista() const;
  std::string getNombre() const;
  double getDuracion() const;
};

#endif
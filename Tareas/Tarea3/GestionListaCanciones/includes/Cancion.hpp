#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>

/**
 * @class Cancion
 * @brief Clase que representa una canción con su nombre, artista y duración.
 *
 * La clase Cancion contiene la información básica de una canción, como su nombre,
 * el nombre del artista y la duración de la canción en minutos. Proporciona métodos
 * para establecer y obtener estos atributos.
 */
class Cancion
{
private:
  std::string nombre;  ///< Nombre de la canción.
  std::string artista; ///< Nombre del artista de la canción.
  double duracion;     ///< Duración de la canción en minutos.

public:
  /**
   * @brief Constructor de la clase Cancion.
   *
   * Inicializa una nueva instancia de la clase Cancion con los valores proporcionados.
   *
   * @param nombre Nombre de la canción.
   * @param artista Nombre del artista.
   * @param duracion Duración de la canción en minutos.
   */
  Cancion(const std::string &nombre, const std::string &artista, double duracion);

  /**
   * @brief Destructor de la clase Cancion.
   *
   * Libera los recursos utilizados por la instancia de Cancion.
   */
  ~Cancion();

  // Setters y Getters

  /**
   * @brief Establece el nombre de la canción.
   * @param nombre Nombre de la canción.
   */
  void setNombre(const std::string &nombre);

  /**
   * @brief Establece el nombre del artista de la canción.
   * @param artista Nombre del artista.
   */
  void setArtista(const std::string &artista);

  /**
   * @brief Establece la duración de la canción.
   * @param duracion Duración de la canción en minutos.
   */
  void setDuracion(double duracion);

  /**
   * @brief Obtiene el nombre de la canción.
   * @return El nombre de la canción.
   */
  std::string getNombre() const;

  /**
   * @brief Obtiene el nombre del artista de la canción.
   * @return El nombre del artista.
   */
  std::string getArtista() const;

  /**
   * @brief Obtiene la duración de la canción.
   * @return La duración de la canción en minutos.
   */
  double getDuracion() const;
};

#endif // CANCION_HPP

/**
 * @file ResenaServicio.h
 * @brief Clase de servicio para gestionar operaciones de reseñas en la base de
 * datos.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef RESENA_SERVICIO_H_
#define RESENA_SERVICIO_H_

#include "../database/MySqlConnector.h"
#include "../entidades/Resena.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <string>
#include <vector>

/**
 * @class ResenaServicio
 * @brief Clase que proporciona servicios de gestión de reseñas en la base de
 * datos.
 *
 * Esta clase implementa la capa de servicio para manejar todas las operaciones
 * relacionadas con reseñas, incluyendo la gestión de estados, consultas de
 * calificaciones y eliminación de reseñas.
 */
class ResenaServicio {
private:
  MySQLConnector *connector;   /**< Conector a la base de datos MySQL */
  std::vector<Resena> resenas; /**< Cache de reseñas consultadas */

public:
  /**
   * @brief Constructor por defecto
   *
   * Inicializa la conexión a la base de datos y prepara el servicio
   * para realizar operaciones con reseñas.
   */
  ResenaServicio();

  /**
   * @brief Destructor de la clase
   *
   * Libera los recursos utilizados y cierra la conexión a la base de datos.
   */
  ~ResenaServicio();

  /**
   * @brief Consulta las reseñas que aún no han sido revisadas
   * @throws sql::SQLException en caso de error en la consulta
   *
   * Este método recupera todas las reseñas que tienen el estado
   * de revisión en falso, útil para moderación de contenido.
   */
  void resenasNoRevisadas() const;

  /**
   * @brief Actualiza el estado de revisión de una reseña
   * @param id_resena Identificador de la reseña a actualizar
   * @throws sql::SQLException si la reseña no existe o hay error en la
   * actualización
   *
   * Cambia el estado de una reseña a revisada, típicamente usado
   * después de que un moderador ha verificado su contenido.
   */
  void actualizarEstadoResena(int id_resena);

  /**
   * @brief Elimina una reseña de la base de datos
   * @param id_resena Identificador de la reseña a eliminar
   * @throws sql::SQLException si la reseña no existe o hay error en la
   * eliminación
   *
   * Elimina permanentemente una reseña del sistema, útil para
   * moderar contenido inapropiado o spam.
   */
  void eliminarResena(int id_resena);

  /**
   * @brief Consulta estadísticas de calificaciones y niveles de dificultad
   * @throws sql::SQLException en caso de error en la consulta
   *
   * Obtiene y analiza las calificaciones y niveles de dificultad
   * registrados en las reseñas, útil para análisis y reportes.
   */
  void calificacionYDificultad() const;

  void verTodasResenas() const;
};

#endif // RESENA_SERVICIO_H_
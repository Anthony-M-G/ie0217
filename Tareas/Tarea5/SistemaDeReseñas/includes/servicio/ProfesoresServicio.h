/**
 * @file ProfesoresServicio.h
 * @brief Clase de servicio para gestionar operaciones de profesores en la base
 * de datos.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef PROFESORES_SERVICIO_H_
#define PROFESORES_SERVICIO_H_

#include "../database/MySqlConnector.h"
#include "../entidades/Profesor.h"
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <string>
#include <vector>

/**
 * @class ProfesoresServicio
 * @brief Clase que proporciona servicios de acceso y consulta de datos de
 * profesores.
 *
 * Esta clase implementa la capa de servicio para gestionar todas las
 * operaciones relacionadas con profesores en la base de datos, principalmente
 * enfocada en consultas y filtrado de información.
 */
class ProfesoresServicio {
private:
  MySQLConnector *connector;        /**< Conector a la base de datos MySQL */
  std::vector<Profesor> profesores; /**< Cache de profesores consultados */

public:
  /**
   * @brief Constructor por defecto
   *
   * Inicializa la conexión a la base de datos y prepara el servicio
   * para realizar operaciones con la información de profesores.
   */
  ProfesoresServicio();

  /**
   * @brief Destructor de la clase
   *
   * Libera los recursos utilizados y cierra la conexión a la base de datos.
   */
  ~ProfesoresServicio();

  /**
   * @brief Obtiene todos los profesores registrados en el sistema
   * @return Vector con todos los profesores en la base de datos
   * @throws sql::SQLException en caso de error en la consulta a la base de
   * datos
   */
  void todosLosProfesores() const;

  /**
   * @brief Busca profesores filtrados por curso y escuela
   * @param curso Nombre del curso para filtrar
   * @param escuela Nombre de la escuela para filtrar
   * @throws sql::SQLException en caso de error en la consulta
   *
   * Este método permite encontrar profesores que imparten un curso específico
   * en una escuela determinada. Es útil para búsquedas específicas y
   * reportes filtrados.
   */
  void profesorPorCursoYEscuela(const std::string &curso,
                                const std::string &escuela) const;

  /**
   * @brief Obtiene los profesores almacenados en cache
   * @return Vector con los profesores actualmente en cache
   *
   * Este método retorna los profesores que han sido previamente
   * cargados en memoria, útil para acceso rápido a datos
   * frecuentemente consultados.
   */
  std::vector<Profesor> getProfesores() const;
};

#endif // PROFESORES_SERVICIO_H_
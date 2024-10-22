/**
 * @file CursoServicio.h
 * @brief Clase de servicio para gestionar operaciones de cursos en la base de
 * datos.
 * @author Antony Medina García
 * @date 21/10/2024
 */

#ifndef CURSO_SERVICIO_H_
#define CURSO_SERVICIO_H_

#include "../database/MySqlConnector.h"
#include "../entidades/Curso.h"
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
 * @class CursoServicio
 * @brief Clase que proporciona servicios de acceso y manipulación de datos de
 * cursos.
 *
 * Esta clase implementa la capa de servicio para gestionar todas las
 * operaciones relacionadas con cursos en la base de datos, incluyendo
 * consultas, inserciones, actualizaciones y eliminaciones.
 */
class CursoServicio {
private:
  MySQLConnector *connector; /**< Conector a la base de datos MySQL */
  std::vector<Curso> cursos; /**< Cache de cursos consultados */

public:
  /**
   * @brief Constructor por defecto
   *
   * Inicializa la conexión a la base de datos y prepara el servicio
   * para realizar operaciones.
   */
  CursoServicio();

  /**
   * @brief Destructor de la clase
   *
   * Libera los recursos y cierra la conexión a la base de datos.
   */
  ~CursoServicio();

  /**
   * @brief Obtiene todos los cursos disponibles
   * @return Vector con todos los cursos en la base de datos
   * @throws sql::SQLException en caso de error en la base de datos
   */
  void todosLosCursos() const;

  /**
   * @brief Obtiene información detallada de un curso específico
   * @param id_curso Identificador del curso a consultar
   * @return Objeto Curso con la información completa
   * @throws sql::SQLException si el curso no existe o hay error en la consulta
   */
  Curso infoCurso(int id_curso) const;

  /**
   * @brief Añade un nuevo curso a la base de datos
   * @param curso Objeto Curso con la información a insertar
   * @throws sql::SQLException en caso de error en la inserción
   */
  void anhadirCurso(Curso curso);

  /**
   * @brief Actualiza la información de un curso existente
   * @param curso Objeto Curso con la información actualizada
   * @throws sql::SQLException si el curso no existe o hay error en la
   * actualización
   */
  void actualizarCurso(Curso curso);

  /**
   * @brief Elimina un curso de la base de datos
   * @param id_curso Identificador del curso a eliminar
   * @throws sql::SQLException si el curso no existe o hay error en la
   * eliminación
   */
  void eliminarCurso(int id_curso);

  /**
   * @brief Consulta cursos filtrados por dificultad y calificación para una
   * escuela
   * @param escuela Nombre de la escuela para filtrar los cursos
   * @throws sql::SQLException en caso de error en la consulta
   */
  void cursosPorDificultadYCalificacion(const std::string &escuela) const;

  /**
   * @brief Obtiene los cursos almacenados en cache
   * @return Vector con los cursos actualmente en cache
   */
  std::vector<Curso> getCursos() const;
};

#endif // CURSO_SERVICIO_H_
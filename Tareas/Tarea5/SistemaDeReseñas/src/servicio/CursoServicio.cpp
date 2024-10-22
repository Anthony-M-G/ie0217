#include "../../includes/servicio/CursoServicio.h"
#include <cppconn/connection.h>
#include <iostream>
#include <mysql_connection.h>

CursoServicio::CursoServicio() { this->connector = new MySQLConnector(); }

CursoServicio::~CursoServicio() { delete this->connector; }

void CursoServicio::todosLosCursos() const {
  std::vector<Curso> cursos;
  std::string query = "SELECT * FROM Cursos";
  sql::Statement *stmt;
  sql::ResultSet *res;
  try {
    stmt = this->connector->getConnection()->createStatement();
    res = stmt->executeQuery(query);
    while (res->next()) {
      Curso curso(res->getInt("id_curso"), res->getString("nombre_curso"),
                  res->getInt("id_profesor"));
      cursos.push_back(curso);
    }
    delete res;
    delete stmt;
  } catch (sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  }
  for (const Curso &curso : cursos) {
    std::cout << curso << std::endl;
  }

  return;
}

void CursoServicio::cursosPorDificultadYCalificacion(
    const std::string &escuela) const {
  if (escuela.empty()) {
    throw std::runtime_error("El nombre de la escuela no puede estar vacío.");
    return;
  }

  std::vector<Curso> cursos;
  std::string query =
      "SELECT "
      "c.nombre_curso AS 'Nombre del Curso', "
      "ROUND(AVG(r.calificacion_general), 2) AS 'Promedio Calificación', "
      "ROUND(AVG(r.nivel_dificultad), 2) AS 'Promedio Dificultad' "
      "FROM Cursos c INNER JOIN Resenas r ON c.id_curso = r.id_curso "
      "INNER JOIN Profesores p ON c.id_profesor = p.id_profesor "
      "WHERE p.escuela = ? "
      "GROUP BY c.nombre_curso "
      "ORDER BY AVG(r.calificacion_general) DESC, "
      "AVG(r.nivel_dificultad) ASC;";
  sql::PreparedStatement *pstmt;
  sql::ResultSet *res;
  try {
    pstmt = this->connector->getConnection()->prepareStatement(query);
    pstmt->setString(1, escuela);
    res = pstmt->executeQuery();
    std::cout << "Promedio de calificación y dificultad de los cursos de la "
                 "escuela "
              << escuela << std::endl;
    while (res->next()) {
      std::cout << "Nombre del Curso: " << res->getString("Nombre del Curso")
                << std::endl;
      std::cout << "Promedio Calificación: "
                << res->getDouble("Promedio Calificación") << std::endl;
      std::cout << "Promedio Dificultad: "
                << res->getDouble("Promedio Dificultad") << std::endl;
    }
    delete res;
    delete pstmt;
  } catch (sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

std::vector<Curso> CursoServicio::getCursos() const { return this->cursos; }
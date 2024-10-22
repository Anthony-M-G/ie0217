#include "../../includes/servicio/ProfesoresServicio.h"
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

ProfesoresServicio::ProfesoresServicio() {
  this->connector = new MySQLConnector();
}

ProfesoresServicio::~ProfesoresServicio() { delete this->connector; }

void ProfesoresServicio::todosLosProfesores() const {
  std::vector<Profesor> profesores;
  std::string query = "SELECT * FROM Profesores";
  sql::Statement *stmt = nullptr;
  sql::ResultSet *res = nullptr;
  try {
    sql::Connection *conn = this->connector->getConnection();
    if (!conn) {
      throw std::runtime_error(
          "No se pudo obtener la conexión a la base de datos.");
    }
    stmt = conn->createStatement();
    if (!stmt) {
      throw std::runtime_error("No se pudo crear el statement.");
    }
    res = stmt->executeQuery(query);
    if (!res) {
      throw std::runtime_error("No se pudo ejecutar la consulta.");
    }
    while (res->next()) {
      Profesor profesor(res->getInt("id_profesor"), res->getString("nombre"),
                        res->getString("escuela"));
      profesores.push_back(profesor);
    }
  } catch (sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  delete res;
  delete stmt;
  for (const Profesor &profesor : profesores) {
    std::cout << profesor << std::endl;
  }

  return;
}

void ProfesoresServicio::profesorPorCursoYEscuela(
    const std::string &curso, const std::string &escuela) const {
  if (curso.empty() || escuela.empty()) {
    throw std::runtime_error(
        "El nombre del curso y la escuela no pueden estar vacíos.");
  }
  std::string query =
      "SELECT p.nombre, AVG(r.calificacion_general) AS promedio_calificacion"
      " FROM Profesores p JOIN Resenas r ON p.id_profesor ="
      " r.id_profesor JOIN Cursos c ON c.id_curso ="
      " r.id_curso WHERE c.nombre_curso = ? AND p.escuela ="
      " ? GROUP BY p.nombre;";

  sql::PreparedStatement *pstm = nullptr;
  sql::ResultSet *res = nullptr;
  try {
    sql::Connection *conn = this->connector->getConnection();
    if (!conn) {
      throw std::runtime_error(
          "No se pudo obtener la conexión a la base de datos.");
    }
    pstm = conn->prepareStatement(query);
    if (!pstm) {
      throw std::runtime_error("No se pudo preparar el statement.");
    }
    pstm->setString(1, curso);
    pstm->setString(2, escuela);
    res = pstm->executeQuery();
    if (!res) {
      throw std::runtime_error("No se pudo ejecutar la consulta.");
    }
    while (res->next()) {
      std::cout << "Profesor: " << res->getString("nombre") << std::endl;
      std::cout << "Promedio de calificación: "
                << res->getDouble("promedio_calificacion") << std::endl;
    }
  } catch (sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  delete res;
  delete pstm;
}
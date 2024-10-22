#include "../../includes/servicio/ResenaServicio.h"
#include <cppconn/exception.h>
#include <iostream>
#include <string>

ResenaServicio::ResenaServicio() {
  this->connector = new MySQLConnector();
} // Cobnstructor que inicializa la conexión a la base de datos

ResenaServicio::~ResenaServicio() { delete this->connector; }

void ResenaServicio::actualizarEstadoResena(int id_resena) {
  if (id_resena <=
      0) { // Validación para asegurar que el ID de la reseña sea mayor a 0
    throw std::runtime_error("El ID de la reseña debe ser mayor a 0.");
  }
  std::string query =
      "UPDATE Resenas SET revisado = 1 WHERE id_resena = ?"; // Query para
                                                             // actualizar el
                                                             // estado de la
                                                             // reseña
  sql::PreparedStatement *pstmt =
      nullptr; // Se inicializa el objeto PreparedStatement para evitar errores
               // de puntero no inicializado y sql injection
  try {
    pstmt = this->connector->getConnection()->prepareStatement(
        query);                  // Se prepara el statement con la query
    pstmt->setInt(1, id_resena); // Se establece el ID de la reseña a actualizar
    int filaActualizada =
        pstmt->executeUpdate(); // Se ejecuta la actualización y se guarda el
                                // número de filas actualizadas
    if (filaActualizada <= 0) {
      std::string razon = " No se pudo actualizar la resena con id=" +
                          std::to_string(id_resena);
      throw sql::SQLException(razon, "0000");
    }
    std::cout << "Resena actualizada correctamente" << std::endl;
  } catch (const sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  delete pstmt;
}

void ResenaServicio::resenasNoRevisadas()
    const { // Método para obtener las reseñas no revisadas
  std::string query = "SELECT * FROM Resenas WHERE revisado=0";
  sql::Statement *stmt = nullptr;
  sql::ResultSet *res = nullptr;
  try {
    stmt =
        this->connector->getConnection()
            ->createStatement(); // Se crea un statement para ejecutar la query
    res = stmt->executeQuery(
        query); // Se ejecuta la query y se guarda el resultado en un ResultSet
    while (res->next()) {
      Resena resena(
          res->getInt("id_profesor"),
          res->getInt(
              "id_curso"), // Se crea un objeto Resena con los datos obtenidos
          res->getInt("calificacion_general"), res->getInt("nivel_dificultad"),
          res->getString("comentario"));
      resena.setRevisado(res->getBoolean("revisado"));
      resena.setIdResena(res->getInt("id_resena"));
      std::cout << std::boolalpha; // Se usa para imprimer los booleanos como
                                   // "true" o "false" en lugar de 1 o 0
      std::cout << resena << std::endl;
    }
  } catch (const sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  }
  delete res;
  delete stmt;
}

void ResenaServicio::eliminarResena(int id_resena) {
  if (id_resena <= 0) {
    throw std::runtime_error("El ID de la reseña debe ser mayor a 0.");
  }
  sql::PreparedStatement *pstmt = nullptr;
  sql::ResultSet *resCurso = nullptr;
  sql::ResultSet *resCount = nullptr;

  try {
    // Obtener el nombre del curso asociado a la reseña que se va a
    // eliminar
    std::string queryCurso = "SELECT c.nombre_curso FROM Resenas r "
                             "JOIN Cursos c ON r.id_curso = c.id_curso "
                             "WHERE r.id_resena = ?";
    pstmt = this->connector->getConnection()->prepareStatement(queryCurso);
    pstmt->setInt(1, id_resena);
    resCurso = pstmt->executeQuery();

    std::string curso;
    if (resCurso->next()) {
      curso = resCurso->getString("nombre_curso");
    } else {
      throw std::runtime_error("No se encontró el curso asociado a la reseña.");
    }

    // Liberar pstmt y resCurso antes de la siguiente operación
    delete resCurso;
    resCurso = nullptr;
    delete pstmt;
    pstmt = nullptr;

    // Eliminar la reseña con el id_resena proporcionado
    std::string queryDelete = "DELETE FROM Resenas WHERE id_resena = ?";
    pstmt = this->connector->getConnection()->prepareStatement(queryDelete);
    pstmt->setInt(1, id_resena);
    int filaEliminada = pstmt->executeUpdate();

    if (filaEliminada <= 0) {
      throw sql::SQLException("No se pudo eliminar la reseña con id=" +
                                  std::to_string(id_resena),
                              "0000");
    }
    std::cout << "Reseña eliminada correctamente" << std::endl;

    // Liberar pstmt antes de la siguiente operación
    delete pstmt;
    pstmt = nullptr;

    // Contar cuántas reseñas quedan para el curso asociado
    std::string queryCount =
        "SELECT COUNT(*) AS resenas_restantes FROM Resenas r "
        "JOIN Cursos c ON r.id_curso = c.id_curso "
        "WHERE c.nombre_curso = ?";
    pstmt = this->connector->getConnection()->prepareStatement(queryCount);
    pstmt->setString(1, curso);
    resCount = pstmt->executeQuery();

    if (resCount->next()) {
      int count = resCount->getInt("resenas_restantes");
      std::cout << "Reseñas restantes para el curso " << curso << ": " << count
                << std::endl;
    }

    // Liberar recursos
    delete resCount;
    resCount = nullptr;
    delete pstmt;
    pstmt = nullptr;

  } catch (const sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Asegurarse de que todos los punteros estén liberados
  delete pstmt;
  delete resCurso;
  delete resCount;
}

void ResenaServicio::calificacionYDificultad()
    const { // Método para obtener las reseñas con calificación mayor o igual a
            // 4 y dificultad menor a 3
  std::string query = "SELECT "
                      "p.nombre AS 'Profesor', "
                      "c.nombre_curso AS 'Curso', "
                      "r.comentario AS 'Comentario', "
                      "r.calificacion_general AS 'Calificación', "
                      "r.nivel_dificultad AS 'Dificultad' "
                      "FROM Resenas r "
                      "JOIN Profesores p ON r.id_profesor = p.id_profesor "
                      "JOIN Cursos c ON r.id_curso = c.id_curso "
                      "WHERE r.calificacion_general >= 4 "
                      "AND r.nivel_dificultad < 3;";
  sql::Statement *stmt = nullptr;
  sql::ResultSet *res = nullptr;
  try {
    stmt =
        this->connector->getConnection()
            ->createStatement(); // Se crea un statement para ejecutar la query
    res = stmt->executeQuery(
        query); // Se ejecuta la query y se guarda el resultado en un ResultSet
    while (
        res->next()) { // Se recorre el ResultSet para imprimir los resultados
      std::cout << "Profesor: " << res->getString("Profesor") << std::endl;
      std::cout << "Curso: " << res->getString("Curso") << std::endl;
      std::cout << "Comentario: " << res->getString("Comentario") << std::endl;
      std::cout << "Calificación: " << res->getInt("Calificación") << std::endl;
      std::cout << "Dificultad: " << res->getInt("Dificultad") << std::endl;
      std::cout << std::endl;
    }
  } catch (const sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  }

  delete res;
  delete stmt;
  return;
}

void ResenaServicio::verTodasResenas() const {
  std::string query = "SELECT * FROM Resenas";
  sql::Statement *stmt = nullptr;
  sql::ResultSet *res = nullptr;
  try {
    stmt = this->connector->getConnection()->createStatement();
    res = stmt->executeQuery(query);
    while (res->next()) {
      Resena resena(res->getInt("id_profesor"), res->getInt("id_curso"),
                    res->getInt("calificacion_general"),
                    res->getInt("nivel_dificultad"),
                    res->getString("comentario"));
      resena.setRevisado(res->getBoolean("revisado"));
      resena.setIdResena(res->getInt("id_resena"));
      std::cout << std::boolalpha;
      std::cout << resena << std::endl;
    }
  } catch (const sql::SQLException &e) {
    std::cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what()
              << std::endl;
  }
  delete res;
  delete stmt;
  return;
}
#include "includes/controlador/Controlador.h"
#include <iostream>

void mostrarMenu() {
  std::cout << "====== Menu de Consultas ======\n";
  std::cout << "1. Filtrar profesores por curso y escuela\n";
  std::cout << "2. Consulta y ordenación por calificación y dificultad\n";
  std::cout << "3. Ver reseñas no revisadas\n";
  std::cout << "4. Actualizar estado de una reseña\n";
  std::cout << "5. Filtrar reseñas por calificación y dificultad\n";
  std::cout << "6. Eliminar reseña\n";
  std::cout << "7. Ver todos los profesores\n";
  std::cout << "8. Ver todos los cursos\n";
  std::cout << "9. Ver todas las resenas\n";
  std::cout << "0. Salir\n";
}

int main() {
  Controlador controlador;

  int opcion;
  do {
    mostrarMenu();
    std::cin >> opcion;

    switch (opcion) {
    case 1: {
      std::string curso, escuela;
      std::cout << "Ingrese el nombre del curso: ";
      std::cin.ignore();
      std::getline(std::cin, curso);
      std::cout << "Ingrese la escuela: ";
      std::getline(std::cin, escuela);
      controlador.profesoresPorCursoYEscuela(curso, escuela);
      break;
    }
    case 2: {
      std::string escuela;
      std::cout << "Ingrese la escuela: ";
      std::cin.ignore();
      std::getline(std::cin, escuela);
      controlador.cursosPorCalificacionYDificultad(escuela);
    }
    case 3: {
      controlador.resenasNoRevisadas();
      break;
    }
    case 4: {
      int idResena;
      std::cout << "Ingrese el ID de la reseña a actualizar: ";
      std::cin >> idResena;
      controlador.actualizarEstadoDeUnaResena(idResena);
      break;
    }
    case 5: {
      controlador.resenasPorCalificacionYDificultad();
      break;
    }
    case 6: {
      int idResena;
      std::cout << "Ingrese el ID de la reseña a eliminar: ";
      std::cin >> idResena;
      controlador.eliminarResena(idResena);
      break;
    }

    case 7:
      controlador.verTodosLosProfesores();
      break;

    case 8: {
      controlador.verTodosLosCursos();
      break;
    }
    case 9: {
      controlador.verTodasLasResenas();
      break;
    }
    case 0: {
      std::cout << "Saliendo...\n";
      break;
    }
    default:
      std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
      break;
    }
  } while (opcion != 0);

  return 0;
}

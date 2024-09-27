#include "includes/BaseTarea.hpp"
#include "includes/GestorDeProyectos.hpp"
#include "includes/NotFoundException.hpp"
#include "includes/Proyecto.hpp"
#include "includes/Tarea.hpp"
#include <iostream>

enum class OpcionMenu {
  AGREGAR_PROYECTO = 1,
  AGREGAR_TAREA = 2,
  ELIMINAR_TAREA = 3,
  ORDENAR_TAREAS = 4,
  MOSTRAR_RESUMEN = 5,
  ELIMINAR_PROYECTO = 6,
  SALIR = 7
};

void mostrarMenu() {
  std::cout << "\n--- Menú de Gestión de Proyectos ---\n";
  std::cout << "1. Agregar un nuevo proyecto.\n";
  std::cout << "2. Agregar una tarea a un proyecto existente.\n";
  std::cout << "3. Eliminar una tarea de un proyecto.\n";
  std::cout << "4. Ordenar tareas por costo, tiempo o prioridad.\n";
  std::cout << "5. Mostrar el resumen de un proyecto (número de tareas, costo "
               "total y tiempo total).\n";
  std::cout << "6. Eliminar un proyecto.\n";
  std::cout << "7. Salir del programa.\n";
  std::cout << "Seleccione una opción: ";
}

int main() {
  GestorDeProyectos gestor;
  int opcionInt;
  OpcionMenu opcion;
  std::string nombreProyecto;

  do {
    mostrarMenu();
    std::cin >> opcionInt;
    opcion = static_cast<OpcionMenu>(opcionInt);

    switch (opcion) {
    case OpcionMenu::AGREGAR_PROYECTO: {
      std::cout << "Ingrese el nombre del nuevo proyecto: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);
      Proyecto nuevoProyecto(nombreProyecto);
      gestor.agregarProyecto(nuevoProyecto);
      break;
    }

    case OpcionMenu::AGREGAR_TAREA: {
      std::string nombreTarea;
      double costo, tiempo;
      int prioridadInt;
      Prioridad prioridad;
      std::cout << "Ingrese el nombre del proyecto donde agregar la tarea: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);
      std::cout << "Ingrese el nombre de la tarea: ";
      std::getline(std::cin, nombreTarea);
      std::cout << "Ingrese el costo de la tarea: ";
      std::cin >> costo;
      std::cout << "Ingrese el tiempo estimado (en semanas): ";
      std::cin >> tiempo;
      std::cout << "Ingrese la prioridad (1=Alta, 2=Media, 3=Baja): ";
      std::cin >> prioridadInt;

      if (prioridadInt == 1) {
        prioridad = Prioridad::ALTA;
      } else if (prioridadInt == 2) {
        prioridad = Prioridad::MEDIA;
      } else {
        prioridad = Prioridad::BAJA;
      }

      std::string recurso = "Recurso genérico";
      BaseTarea *nuevaTarea = new Tarea<std::string>(nombreTarea, costo, tiempo,
                                                     prioridad, recurso);

      try {
        gestor.agregarTareaAProyecto(nombreProyecto, nuevaTarea);
      } catch (const NotFoundException &e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }

    case OpcionMenu::ELIMINAR_TAREA: {
      std::string nombreTarea;
      std::cout << "Ingrese el nombre del proyecto donde eliminar la tarea: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);
      std::cout << "Ingrese el nombre de la tarea a eliminar: ";
      std::getline(std::cin, nombreTarea);

      try {
        gestor.eliminarTareaDeProyecto(nombreProyecto, nombreTarea);
      } catch (const NotFoundException &e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }

    case OpcionMenu::ORDENAR_TAREAS: {
      std::cout << "Ingrese el nombre del proyecto para ordenar sus tareas: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);

      std::cout << "Seleccione el criterio de ordenación: \n";
      std::cout << "1. Costo\n";
      std::cout << "2. Tiempo estimado\n";
      std::cout << "3. Prioridad\n";
      int criterio;
      std::cin >> criterio;

      try {
        switch (criterio) {
        case 1:
          gestor.ordenarTareasDeProyectoPorCosto(nombreProyecto);
          break;
        case 2:
          gestor.getListaDeProyectos()[nombreProyecto]
              .ordenarTareasPorTiempoEstimado();
          break;
        case 3:
          gestor.ordenarTareasDeProyectoPorPrioridad(nombreProyecto);
          break;
        default:
          std::cout << "Criterio inválido.\n";
        }
      } catch (const NotFoundException &e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }

    case OpcionMenu::MOSTRAR_RESUMEN: {
      std::cout << "Ingrese el nombre del proyecto para ver su resumen: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);

      try {
        gestor.mostrarResumenTareas(nombreProyecto);
      } catch (const NotFoundException &e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }

    case OpcionMenu::ELIMINAR_PROYECTO: {
      std::cout << "Ingrese el nombre del proyecto a eliminar: ";
      std::cin.ignore();
      std::getline(std::cin, nombreProyecto);

      try {
        gestor.eliminarProyecto(nombreProyecto);
      } catch (const NotFoundException &e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }

    case OpcionMenu::SALIR:
      std::cout << "Saliendo del programa...\n";
      break;

    default:
      std::cout << "Opción inválida, intente nuevamente.\n";
    }
  } while (opcion != OpcionMenu::SALIR);

  return 0;
}

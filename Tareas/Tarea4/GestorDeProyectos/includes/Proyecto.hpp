#ifndef PROYECTO_HPP
#define PROYECTO_HPP

#include "BaseTarea.hpp"
#include <string>
#include <vector>

class Proyecto {
private:
  std::string nombreDelProyecto;
  std::vector<BaseTarea *>
      listaDeTareas; // Vector de punteros a BaseTarea para almacenar tareas con
                     // diferentes tipos de recursos

public:
  Proyecto(const std::string &nombre = "Proyecto sin nombre"); // Constructor
  ~Proyecto();                                                 // Destructor

  void agregarTarea(BaseTarea *&tarea);
  void eliminarTarea(const std::string &nombre);
  void mostrarResumen() const;
  void ordenarTareasPorCosto() const;
  void ordenarTareasPorTiempoEstimado() const;
  void ordenarTareasPorPrioridad() const;
};

#endif // !PROYECTO_HPP

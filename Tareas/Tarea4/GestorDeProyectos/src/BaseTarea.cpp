#include "../includes/BaseTarea.hpp"

BaseTarea::BaseTarea(const std::string &t_nombre, double costo,
                     double tiempo_estimado, Prioridad prioridad)
    : nombre(t_nombre), costo(costo), tiempoEstimado(tiempo_estimado),
      prioridad(prioridad) {

  if (costo < 0) {
    throw std::invalid_argument("El costo no puede ser negativo");
  }
  if (tiempo_estimado < 0 || tiempo_estimado > 100) {
    throw std::invalid_argument("El tiempo estimado no puede ser negativo");
  }
  if (prioridad < 1 && prioridad > 3) {
    throw std::invalid_argument("La prioridad no es válida");
  }
};

void BaseTarea::setNombre(const std::string t_nombre) {
  this->nombre = t_nombre;
};

void BaseTarea::setCosto(double costo) {
  if (costo < 0) {
    throw std::invalid_argument("El costo no puede ser negativo");
  }
  this->costo = costo;
};

void BaseTarea::setTiempoEstimado(double tiempo_estimado) {
  if (tiempo_estimado < 0) {
    throw std::invalid_argument("El tiempo estimado no puede ser negativo");
  }
  this->tiempoEstimado = tiempo_estimado;
};

void BaseTarea::setPrioridad(Prioridad prioridad) {
  if (prioridad < 1 && prioridad > 3) {
    throw std::invalid_argument("La prioridad no es válida");
  }
  this->prioridad = prioridad;
};

std::string BaseTarea::getNombre() const { return this->nombre; };

double BaseTarea::getCosto() const { return this->costo; };

double BaseTarea::getTiempoEstimado() const { return this->tiempoEstimado; };

Prioridad BaseTarea::getPrioridad() const { return this->prioridad; };

std::string BaseTarea::getPrioridadStr() const {
  switch (this->prioridad) {
  case Prioridad::BAJA:
    return "Baja";
  case Prioridad::MEDIA:
    return "Media";
  case Prioridad::ALTA:
    return "Alta";
  default:
    return "Prioridad no definida";
  }
};

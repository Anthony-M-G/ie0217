#include "../../includes/validadores/Validadores.h"
// Validar solo letras para autor y usuario
bool validarSoloLetras(const std::string &entrada) {
  std::regex regex("^[a-zA-Z]+$");
  return std::regex_match(entrada, regex);
}

// Validar contenido (permite letras, espacios y caracteres especiales básicos)
bool validarContenido(const std::string &entrada) {
  std::regex regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ,.!?\\s]+$");
  return std::regex_match(entrada, regex);
}

// Validar fecha en formato dd/mm/yyyy
bool validarFecha(const std::string &fecha) {
  std::regex regex("^([0-2][0-9]|(3)[0-1])/(0[1-9]|1[0-2])/\\d{4}$");
  return std::regex_match(fecha, regex);
}

// Validar un comentario (usuario, contenido y fecha)
bool validarComentario(const std::map<std::string, std::string> &comentario) {
  return validarSoloLetras(comentario.at("Usuario")) &&
         validarContenido(comentario.at("Contenido")) &&
         validarFecha(comentario.at("Fecha"));
}

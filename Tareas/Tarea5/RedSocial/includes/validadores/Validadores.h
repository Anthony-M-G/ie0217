#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <map>
#include <regex>
#include <string>

// Declaraciones de funciones
bool validarSoloLetras(const std::string &entrada);
bool validarContenido(const std::string &entrada);
bool validarFecha(const std::string &fecha);
bool validarComentario(const std::map<std::string, std::string> &comentario);

#endif // VALIDACIONES_H

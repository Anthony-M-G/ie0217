#ifndef REGEXUTILS_HPP
#define REGEXUTILS_HPP

#include "Exceptions.hpp"
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
// Se comentó esta clase porque ya se encuentra definida en el archivo
// Exceptions.hpp, que es el encargado de manejar las excepciones y dejandole a
// este archivo la implementación de las funciones que utilizan expresiones
// regulares solamente. class RegexException : public std::runtime_error {
// public:
//     explicit RegexException(const std::string& message)
//         : std::runtime_error(message) {}
// };

std::vector<std::string> regexSearch(
    const std::vector<std::string> &lines,
    const std::string
        &pattern) { // Función que busca un patrón en las líneas de un archivo
  std::vector<std::string> matches;
  std::regex regexPattern;

  try {
    regexPattern = std::regex(pattern);
  } catch (const std::regex_error &) {
    throw RegexException(
        "Error: Patrón de expresión regular inválido."); // Lanzar una excepción
                                                         // si el patrón es
                                                         // inválido
  }

  for (const auto &line : lines) {
    if (std::regex_search(line, regexPattern)) {
      matches.push_back(line);
    }
  }

  return matches;
}

void regexReplace(
    std::vector<std::string> &lines, const std::string &pattern,
    const std::string &replacement) { // Función que reemplaza un patrón en las
                                      // líneas de un archivo
  std::regex regexPattern;

  try {
    regexPattern = std::regex(pattern);
  } catch (const std::regex_error &) {
    throw RegexException("Error: Patrón de expresión regular inválido.");
  }

  for (auto &line : lines) {
    line = std::regex_replace(
        line, regexPattern,
        replacement); // Reemplaza el patrón en la línea usando la función
                      // regex_replace de std::regex
  }
}

#endif // REGEXUTILS_HPP

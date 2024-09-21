#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include "Exceptions.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
// Se comentó esta clase porque ya se encuentra definida en el archivo

// Exceptions.hpp, que es el encargado de manejar las excepciones y dejandole a
// este archivo la implementación de las funciones que utilizan expresiones
// regulares solamente. class FileNotFoundException : public std::runtime_error
// { public:
//     explicit FileNotFoundException(const std::string& message)
//         : std::runtime_error(message) {}
// };

template <typename Container>
class FileReader { // Plantilla de clase que recibe un contenedor y un archivo
                   // como argumentos

public:
  FileReader(const std::string &filePath)
      : filePath(filePath) {} // Constructor que recibe la ruta del archivo

  void readFile(Container &container) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
      throw FileNotFoundException("Error: No se pudo abrir el archivo " +
                                  filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
      container.push_back(line);
    }

    file.close();
  }

private:
  std::string filePath; // Ruta del archivo
};

#endif // FILEREADER_HPP

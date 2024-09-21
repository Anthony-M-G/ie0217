#include "FileReader.hpp"
#include "RegexUtils.hpp"
#include "TextProcessor.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) { // Verificar que se haya pasado un argumento a parte del
                   // nombre del programa
    std::cerr << "Uso: " << argv[0] << " <archivo_texto>" << std::endl;
    return 1;
  }

  std::string filePath = argv[1]; // Obtener la ruta del archivo
  std::vector<std::string>
      lines; // Vector para almacenar las líneas del archivo

  try { // Intentar leer el archivo
    FileReader<std::vector<std::string>> fileReader(
        filePath); // Crear un objeto FileReader y le pasamos la ruta del
                   // archivo
    fileReader.readFile(
        lines); // Leer el archivo y almacenar las líneas en el vector

    std::cout << "Archivo leído correctamente. Total de líneas: "
              << lines.size() << std::endl; // Imprimir el total de líneas

    // Procesar el texto utilizando una lambda que cuenta las líneas
    int lineCount = 0; // Contador de líneas no vacías
    processText(
        lines,
        [&](const std::string &line) { // Función lambda definida
                                       // en el lugar del segundo argumento
          if (!line.empty()) {
            lineCount++;
          }
        });
    std::cout << "Líneas no vacías: " << lineCount << std::endl;

    // Buscar un patrón con expresiones regulares
    std::string pattern = "\\d+"; // Busca cualquier número en las líneas
    std::vector<std::string> matchedLines = regexSearch(lines, pattern);
    std::cout << "Líneas que contienen números: " << matchedLines.size()
              << std::endl;

    // Reemplazar los números con una etiqueta
    regexReplace(lines, pattern, "[Número]");
    std::cout << "Números reemplazados en las líneas." << std::endl;

  } catch (const FileNotFoundException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (const RegexException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}

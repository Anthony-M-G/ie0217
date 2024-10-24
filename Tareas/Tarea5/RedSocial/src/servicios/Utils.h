#ifndef UTILS_H
#define UTILS_H
// Archivo de cabecera para funciones de utilidad en la aplicación
#include <bsoncxx/builder/stream/document.hpp>
#include <ctime>
#include <iostream>
#include <mongocxx/cursor.hpp>
#include <string>

// Función para obtener la fecha actual en formato dd/mm/yyyy

inline std::string getCurrentDate() {
  time_t fecha = time(NULL); // Obtener la fecha actual
  char buffer[26];           // Buffer para almacenar la fecha formateada
  struct tm *tm_info;        // Estructura para almacenar la fecha

  tm_info = localtime(&fecha); // Obtener la fecha local

  strftime(buffer, 26, "%d/%m/%Y", tm_info); // Formatear la fecha
  return buffer;                             // Retornar la fecha formateada
};

// Función para mostrar las publicaciones
inline void postsView(mongocxx::cursor &posts) {

  for (auto &&post : posts) { // Recorrer el cursor de publicaciones
    bsoncxx::document::view post_view =
        post; // Se usa una view para acceder a los campos del documento y no el
              // documento completo en memoria
    std::cout << "{\nAutor: " << post_view["autor"].get_string().value
              << std::endl;
    std::cout << "Contenido: " << post_view["contenido"].get_string().value
              << std::endl;
    std::cout << "Fecha: " << post_view["fecha"].get_string().value
              << std::endl;
    std::cout << "Comentarios:[ " << std::endl;
    for (auto &&comment :
         post_view["comentarios"]
             .get_array()
             .value) { // Recorrer los comentarios de la publicación
      bsoncxx::document::view comment_view = comment.get_document().value;
      std::cout << "{\tUsuario: " << comment_view["username"].get_string().value
                << std::endl;
      std::cout << " \tContenido: "
                << comment_view["content"].get_string().value << std::endl;
      std::cout << "\tFecha: " << comment_view["date"].get_string().value
                << "\n}, " << std::endl;
    }
    std::cout << "]}" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
  }
}

#endif // UTILS_H
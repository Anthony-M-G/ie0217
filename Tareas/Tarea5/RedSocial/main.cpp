#include "includes/controlador/PostsController.h"
#include <iostream>
#include <string>

void mostrarMenu() {
  std::cout << "----- MENU RED SOCIAL -----\n";
  std::cout << "1. Ver todas las publicaciones\n";
  std::cout << "2. Insertar una nueva publicación\n";
  std::cout << "3. Ver publicaciones por autor\n";
  std::cout << "4. Ver publicaciones ordenadas por fecha\n";
  std::cout << "5. Agregar un comentario a una publicación\n";
  std::cout << "6. Actualizar el contenido de una publicación\n";
  std::cout << "7. Eliminar una publicación por autor y fecha\n";
  std::cout << "8. Marcar una publicación como destacada\n";
  std::cout << "9. Salir\n";
  std::cout << "Seleccione una opción: ";
}

int main() {
  PostsController postsController; // Instancia del controlador de publicaciones
  int opcion;
  std::string author, content, date, username, newContent;

  do {
    mostrarMenu();
    std::cin >> opcion;

    switch (opcion) {
    case 1:
      postsController.getPosts();
      std::cout << "Mostrando todas las publicaciones...\n";
      break;
    case 2:
      std::cout << "Ingrese el autor: ";
      std::cin >> author;
      std::cout << "Ingrese el contenido: ";
      std::cin.ignore();
      std::getline(std::cin, content);
      postsController.insertPost(author, content);
      std::cout << "Publicación agregada por " << author << "\n";
      break;
    case 3:
      std::cout << "Ingrese el autor: ";
      std::cin >> author;
      postsController.getPostsByAuthor(author);
      std::cout << "Mostrando publicaciones de " << author << "\n";
      break;
    case 4:
      std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
      std::cin >> date;
      postsController.getPostsOrderedByDate(date);
      std::cout << "Mostrando publicaciones ordenadas por la fecha " << date
                << "\n";
      break;
    case 5:
      std::cout << "Ingrese el autor de la publicación: ";
      std::cin >> author;
      std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
      std::cin >> date;
      std::cout << "Ingrese su nombre de usuario: ";
      std::cin >> username;
      std::cout << "Ingrese el comentario: ";
      std::cin.ignore();
      std::getline(std::cin, content);
      postsController.addCommentToPost(author, date, username, content);
      std::cout << "Comentario agregado por " << username << "\n";
      break;
    case 6:
      std::cout << "Ingrese el autor de la publicación: ";
      std::cin >> author;
      std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
      std::cin >> date;
      std::cout << "Ingrese el nuevo contenido: ";
      std::cin.ignore();
      std::getline(std::cin, newContent);
      postsController.updatePostContent(author, date, newContent);
      std::cout << "Contenido de la publicación actualizado\n";
      break;
    case 7:
      std::cout << "Ingrese el autor de la publicación: ";
      std::cin >> author;
      std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
      std::cin >> date;
      postsController.deletePostByAuthorAndDate(author, date);
      std::cout << "Publicación eliminada\n";
      break;
    case 8:
      std::cout << "Ingrese el autor de la publicación: ";
      std::cin >> author;
      std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
      std::cin >> date;
      postsController.markPostAsFeatured(author, date);
      std::cout << "Publicación marcada como destacada\n";
      break;
    case 9:
      std::cout << "Saliendo...\n";
      break;
    default:
      std::cout << "Opción no válida, intente de nuevo.\n";
    }
  } while (opcion != 9);

  return 0;
}

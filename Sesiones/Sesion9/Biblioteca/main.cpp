#include "./includes/Biblioteca.hpp"
#include "./includes/Libro.hpp"

int main (int argc, char *argv[]) {
  Biblioteca biblioteca;
  biblioteca.agregarLibro("100 años de soledad", "Gabriel García Márquez");
  biblioteca.mostrarCatalogo();
  return 0;
}

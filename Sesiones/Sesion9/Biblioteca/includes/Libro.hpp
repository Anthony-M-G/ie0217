#ifndef LIBRO_HPP
#define LIBRO_HPP
#include <string>
class Libro {
private:
  std::string titulo;
  std::string autor;

public:
  Libro(const std::string &t_titulo, const std::string &t_autor);
  void mostrarInfo() const;
  ~Libro() = default;
};

#endif // !LIBRO_HPP

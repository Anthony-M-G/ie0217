#ifndef COMPONENTE_HPP
#define COMPONENTE_HPP

#include <map>
#include <string>

class Componente { // Clase Componente
private:
  std::string nombre;
  std::string categoria;
  int cantidad;
  std::string descripcion;

public:
  // Constructor
  Componente(std::string nombre, std::string categoria, int cantidad,
             std::string descripcion);

  Componente() = default;

  // Getters
  std::string getNombre() const;
  std::string getCategoria() const;
  int getCantidad() const;
  std::string getDescripcion() const;

  // Setters
  void setCantidad(int nuevaCantidad);

  // Métodos
  bool agregarComponente(std::map<std::string, Componente> &inventario,
                         const std::string &nombre,
                         const std::string &categoria, int cantidad,
                         const std::string &descripcion);
  bool reducirComponente(std::map<std::string, Componente> &inventario,
                         const std::string &nombre,
                         int cantidad); // Reduce la cantidad de un componente
  bool
  listarComponentes(const std::map<std::string, Componente>
                        &inventario); // Lista los componentes del inventario
  bool buscarComponente(const std::map<std::string, Componente>
                            &inventario, // Busca un componente en el inventario
                        const std::string &nombre);
};

#endif // COMPONENTE_HPP

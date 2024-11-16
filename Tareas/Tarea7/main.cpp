#include "src/CalculoCircuitos.hpp"
#include "src/Componente.hpp"
#include <iostream>

int main() {
  Componente com;
  std::map<std::string, Componente> inventario;

  try {

    com.agregarComponente(inventario, "Resistencia 1k", "Resistencia", 10,
                          "Resistencia básica de 1k Ohm");
    com.listarComponentes(inventario);

    std::vector<double> resistencias = {1000, 2000, 3000};
    std::cout << "Resistencia en serie: "
              << CalculosCircuitos::resistenciaSerie(resistencias) << " Ohm\n";
    std::cout << "Resistencia en paralelo: "
              << CalculosCircuitos::resistenciaParalelo(resistencias)
              << " Ohm\n";
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}

#include "CalculoCircuitos.hpp"
#include <numeric>
#include <stdexcept>

double
CalculosCircuitos::resistenciaSerie(const std::vector<double> &resistencias) {
  if (resistencias.empty())
    throw std::invalid_argument("La lista de resistencias está vacía.");
  return std::accumulate(resistencias.begin(), resistencias.end(), 0.0);
}

double CalculosCircuitos::resistenciaParalelo(
    const std::vector<double> &resistencias) {
  if (resistencias.empty())
    throw std::invalid_argument("La lista de resistencias está vacía.");
  double sumaInversa = 0.0;
  for (double R : resistencias) {
    if (R <= 0)
      throw std::invalid_argument(
          "Todas las resistencias deben ser mayores a cero.");
    sumaInversa += 1.0 / R;
  }
  return 1.0 / sumaInversa;
}

// Función combinada para calcular capacitancia equivalente en serie y paralelo
double CalculosCircuitos::capacitanciaEquivalenteSerieParalelo(
    const std::vector<double> &serie, const std::vector<double> &paralelo) {
  double capacitanciaSerie = 0.0;
  double capacitanciaParalelo = 0.0;

  // Validación de valores
  for (double C : serie) {
    if (C <= 0)
      throw std::invalid_argument(
          "Las capacitancias deben ser mayores a cero.");
  }
  for (double C : paralelo) {
    if (C <= 0)
      throw std::invalid_argument(
          "Las capacitancias deben ser mayores a cero.");
  }

  // Cálculo de capacitancia en serie
  if (!serie.empty()) {
    double sumaInversa = 0.0;
    for (double C : serie) {
      sumaInversa += 1.0 / C;
    }
    capacitanciaSerie = 1.0 / sumaInversa;
  }

  // Cálculo de capacitancia en paralelo
  if (!paralelo.empty()) {
    capacitanciaParalelo =
        std::accumulate(paralelo.begin(), paralelo.end(), 0.0);
  }

  // Resultado combinado
  return capacitanciaSerie + capacitanciaParalelo;
}

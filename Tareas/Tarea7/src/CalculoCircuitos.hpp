#ifndef CALCULOSCIRCUITOS_HPP
#define CALCULOSCIRCUITOS_HPP

#include <vector>

class CalculosCircuitos { // Clase CalculosCircuitos
public:
  static double resistenciaSerie(const std::vector<double> &resistencias);
  static double resistenciaParalelo(const std::vector<double> &resistencias);
  static double
  capacitanciaEquivalenteSerieParalelo(const std::vector<double> &serie,
                                       const std::vector<double> &paralelo);
  // Similar para capacitancias e inductancias.
};

#endif // CALCULOSCIRCUITOS_HPP

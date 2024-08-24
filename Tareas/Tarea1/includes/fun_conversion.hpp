#ifndef CONTROLADORCONVERTIDOR_HPP
#define CONTROLADORCONVERTIDOR_HPP

#include "unidades_de_conversion.hpp"
// Funciones que convierten una unidad a otra usando los enums de unidades de conversion
// sobrecarga de funciones para cada tipo de conversion
void conversor(UnidadesDeLongitud conversion, double valor);
void conversor(UnidadesDeMasa conversion, double valor);
void conversor(UnidadesDeTemperatura conversion, double valor);

#endif

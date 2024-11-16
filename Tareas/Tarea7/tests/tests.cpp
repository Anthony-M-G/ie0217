#include "../src/CalculoCircuitos.hpp"
#include "../src/Componente.hpp"
#include <gtest/gtest.h>
#include <map>

class ComponenteTest : public ::testing::Test {
protected:
  std::map<std::string, Componente> inventario;

  void SetUp() override { inventario.clear(); }
};

TEST_F(ComponenteTest, AgregarComponenteNuevo) { // Prueba de agregar componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  EXPECT_TRUE(comp.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                                     "Resistor de 10k ohm"));
  EXPECT_EQ(inventario["Resistor"].getCantidad(), 10);
}

TEST_F(ComponenteTest,
       AgregarComponenteExistente) { // Prueba de agregar componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  comp.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                         "Resistor de 10k ohm");
  EXPECT_TRUE(comp.agregarComponente(inventario, "Resistor", "Electrónico", 5,
                                     "Resistor de 10k ohm"));
  EXPECT_EQ(inventario["Resistor"].getCantidad(), 15);
}

TEST_F(ComponenteTest,
       ReducirComponenteExistente) { // Prueba de reducir componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  comp.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                         "Resistor de 10k ohm");
  EXPECT_TRUE(comp.reducirComponente(inventario, "Resistor", 5));
  EXPECT_EQ(inventario["Resistor"].getCantidad(), 5);
}

TEST_F(ComponenteTest,
       ReducirComponenteInsuficiente) { // Prueba de reducir componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  comp.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                         "Resistor de 10k ohm");
  EXPECT_THROW(comp.reducirComponente(inventario, "Resistor", 15),
               std::runtime_error);
}

TEST_F(ComponenteTest, ListarComponentes) { // Prueba de listar componentes
  Componente comp1("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  Componente comp2("Capacitor", "Electrónico", 5, "Capacitor de 100uF");
  comp1.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                          "Resistor de 10k ohm");
  comp2.agregarComponente(inventario, "Capacitor", "Electrónico", 5,
                          "Capacitor de 100uF");
  EXPECT_NO_THROW(comp1.listarComponentes(inventario));
}

TEST_F(ComponenteTest,
       BuscarComponenteExistente) { // Prueba de buscar componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  comp.agregarComponente(inventario, "Resistor", "Electrónico", 10,
                         "Resistor de 10k ohm");
  EXPECT_TRUE(comp.buscarComponente(inventario, "Resistor"));
}

TEST_F(ComponenteTest,
       BuscarComponenteNoExistente) { // Prueba de buscar componente
  Componente comp("Resistor", "Electrónico", 10, "Resistor de 10k ohm");
  EXPECT_THROW(comp.buscarComponente(inventario, "Capacitor"),
               std::runtime_error);
}

// Prueba: combinación de capacitancias en serie y paralelo
TEST(CalculosCircuitosTest, CapacitanciaEquivalenteSerieParalelo) {
  // Capacitancias de prueba
  std::vector<double> capacitanciasSerie = {10.0, 20.0, 30.0};
  std::vector<double> capacitanciasParalelo = {40.0, 50.0};

  // Resultado esperado
  double esperado =
      1.0 / ((1.0 / 10.0) + (1.0 / 20.0) + (1.0 / 30.0)) + 40.0 + 50.0;

  // Llamada a la función
  double resultado = CalculosCircuitos::capacitanciaEquivalenteSerieParalelo(
      capacitanciasSerie, capacitanciasParalelo);

  // Verificación del resultado
  EXPECT_NEAR(resultado, esperado,
              1e-5); // Tolerancia por posibles imprecisiones
}

// Prueba: listas vacías
TEST(CalculosCircuitosTest, CapacitanciaEquivalenteConListasVacias) {
  std::vector<double> capacitanciasSerie = {};
  std::vector<double> capacitanciasParalelo = {};

  // Resultado esperado: 0
  double esperado = 0.0;

  // Llamada a la función
  double resultado = CalculosCircuitos::capacitanciaEquivalenteSerieParalelo(
      capacitanciasSerie, capacitanciasParalelo);

  // Verificación del resultado
  EXPECT_EQ(resultado, esperado);
}

// Prueba: valores negativos (debe lanzar excepción)
TEST(CalculosCircuitosTest, CapacitanciaEquivalenteConValoresNegativos) {
  std::vector<double> capacitanciasSerie = {-10.0, 20.0};
  std::vector<double> capacitanciasParalelo = {30.0};

  // Verificación de excepción
  EXPECT_THROW(CalculosCircuitos::capacitanciaEquivalenteSerieParalelo(
                   capacitanciasSerie, capacitanciasParalelo),
               std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
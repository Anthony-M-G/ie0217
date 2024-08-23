#include "./includes/unidades_de_conversion.hpp"
#include "./includes/conversiones.hpp"
#include "./includes/convertidor.hpp"
#include "./includes/fun_conversion.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  enum UnidadesDeLongitud conversionMetrica;
  enum UnidadesDeMasa conversionMasa;
  enum UnidadesDeTemperatura conversionTemperatura;
  double valor;
  int opcion;
  int opcion2;
  while (opcion != 4)
  {
    cout << "Conversor de unidades" << endl;
    cout << "Seleccione la conversion que desea realizar:" << endl;
    cout << "1. Conversion de unidades de longitud" << endl;
    cout << "2. Conversion de unidades de masa" << endl;
    cout << "3. Conversion de unidades de temperatura" << endl;
    cout << "4. Salir del programa" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      cout << "Seleccione la conversionMetrica que desea realizar:" << endl;
      cout << "1. Metros a kilometros" << endl;
      cout << "2. Kilometros a metros" << endl;
      cout << "3. Centimetros a metros" << endl;
      cout << "4. Milimetros a metros" << endl;
      cout << "5. Metros a centimetros" << endl;
      cout << "6. Metros a milimetros" << endl;
      cin >> opcion2;
      switch (opcion2)
      {
      case 1:
        conversionMetrica = UnidadesDeLongitud::metros_a_kilometros;
        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case 2:
        conversionMetrica = UnidadesDeLongitud::kilometros_a_metros;
        cout << "Ingrese el valor en kilometros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case 3:
        conversionMetrica = UnidadesDeLongitud::centimetros_a_metros;
        cout << "Ingrese el valor en centimetros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case 4:
        conversionMetrica = UnidadesDeLongitud::milimetros_a_metros;
        cout << "Ingrese el valor en milimetros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case 5:
        conversionMetrica = UnidadesDeLongitud::metros_a_centimetros;
        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case 6:
        conversionMetrica = UnidadesDeLongitud::metros_a_milimetros;
        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      default:
        break;
      }
      break;
    case 2:
      cout << "Seleccione la conversionMetrica que desea realizar:" << endl;
      cout << "1. Kilogramos a gramos" << endl;
      cout << "2. Gramos a kilogramos" << endl;
      cout << "3. Miligramos a kilogramos" << endl;
      cout << "4. Kilogramos a miligramos" << endl;
      cout << "5. Gramos a miligramos" << endl;
      cout << "6. Miligramos a gramos" << endl;

      cin >> opcion2;

      switch (opcion2)
      {
      case 1:
        conversionMasa = UnidadesDeMasa::kilogramos_a_gramos;
        cout << "Ingrese el valor en kilogramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case 2:
        conversionMasa = UnidadesDeMasa::gramos_a_kilogramos;
        cout << "Ingrese el valor en gramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case 3:
        conversionMasa = UnidadesDeMasa::miligramos_a_kilogramos;
        cout << "Ingrese el valor en miligramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case 4:
        conversionMasa = UnidadesDeMasa::kilogramos_a_miligramos;
        cout << "Ingrese el valor en kilogramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case 5:
        conversionMasa = UnidadesDeMasa::gramos_a_miligramos;
        cout << "Ingrese el valor en gramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case 6:
        conversionMasa = UnidadesDeMasa::miligramos_a_gramos;
        cout << "Ingrese el valor en miligramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      default:

        break;
      }
    }
  }
  return 0;
}

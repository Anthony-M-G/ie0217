#include "./includes/unidades_de_conversion.hpp"
#include "./includes/conversiones.hpp"
#include "./includes/convertidor.hpp"
#include "./includes/fun_conversion.hpp"
#include "./includes/enums_opciones_p1.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Declara las variables necesarias
  enum Opciones opcionSeleccionada;
  enum UnidadesDeLongitud conversionMetrica;
  enum UnidadesDeMasa conversionMasa;
  enum UnidadesDeTemperatura conversionTemperatura;
  double valor;
  int opcion;
  int opcion2;
  do
  {
    cout << "Conversor de unidades" << endl;
    cout << "Seleccione la conversion que desea realizar:" << endl;
    cout << "1. Conversion de unidades de longitud" << endl;
    cout << "2. Conversion de unidades de masa" << endl;
    cout << "3. Conversion de unidades de temperatura" << endl;
    cout << "4. Salir del programa" << endl;
    cin >> opcion;
    opcionSeleccionada = static_cast<Opciones>(opcion); // Convierte el entero a un enum Opciones
    switch (opcionSeleccionada)
    {
    case Opciones::longitud:
      cout << "Seleccione la conversion que desea realizar:" << endl;
      cout << "1. Metros a kilometros" << endl;
      cout << "2. Kilometros a metros" << endl;
      cout << "3. Centimetros a metros" << endl;
      cout << "4. Milimetros a metros" << endl;
      cout << "5. Metros a centimetros" << endl;
      cout << "6. Metros a milimetros" << endl;
      cin >> opcion2;
      conversionMetrica = static_cast<UnidadesDeLongitud>(opcion2); // Convierte el entero a un enum UnidadesDeLongitud
      switch (conversionMetrica)
      {
      case UnidadesDeLongitud::metros_a_kilometros:

        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case UnidadesDeLongitud::kilometros_a_metros:

        cout << "Ingrese el valor en kilometros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case UnidadesDeLongitud::centimetros_a_metros:

        cout << "Ingrese el valor en centimetros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case UnidadesDeLongitud::milimetros_a_metros:

        cout << "Ingrese el valor en milimetros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case UnidadesDeLongitud::metros_a_centimetros:

        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      case UnidadesDeLongitud::metros_a_milimetros:

        cout << "Ingrese el valor en metros: ";
        cin >> valor;
        conversor(conversionMetrica, valor);
        break;
      default:
        break;
      }
      break;
    case Opciones::masa:
      cout << "Seleccione la conversion que desea realizar:" << endl;
      cout << "1. Kilogramos a gramos" << endl;
      cout << "2. Gramos a kilogramos" << endl;
      cout << "3. Miligramos a kilogramos" << endl;
      cout << "4. Kilogramos a miligramos" << endl;
      cout << "5. Gramos a miligramos" << endl;
      cout << "6. Miligramos a gramos" << endl;

      cin >> opcion2;
      conversionMasa = static_cast<UnidadesDeMasa>(opcion2);
      switch (conversionMasa)
      {
      case UnidadesDeMasa::kilogramos_a_gramos:

        cout << "Ingrese el valor en kilogramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case UnidadesDeMasa::gramos_a_kilogramos:

        cout << "Ingrese el valor en gramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case UnidadesDeMasa::miligramos_a_kilogramos:

        cout << "Ingrese el valor en miligramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case UnidadesDeMasa::kilogramos_a_miligramos:

        cout << "Ingrese el valor en kilogramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case UnidadesDeMasa::gramos_a_miligramos:

        cout << "Ingrese el valor en gramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      case UnidadesDeMasa::miligramos_a_gramos:

        cout << "Ingrese el valor en miligramos: ";
        cin >> valor;
        conversor(conversionMasa, valor);
        break;
      default:

        break;
      }
      break;
    case Opciones::temperatura:
      cout << "Seleccione la conversion que desea realizar:" << endl;
      cout << "1. Celsius a Fahrenheit" << endl;
      cout << "2. Fahrenheit a Celsius" << endl;
      cout << "3. Kelvin a Celsius" << endl;
      cout << "4. Celsius a Kelvin" << endl;
      cout << "5. Fahrenheit a Kelvin" << endl;
      cout << "6. Kelvin a Fahrenheit" << endl;
      cin >> opcion2;
      conversionTemperatura = static_cast<UnidadesDeTemperatura>(opcion2);
      switch (conversionTemperatura)
      {
      case UnidadesDeTemperatura::celsius_a_fahrenheit:

        cout << "Ingrese el valor en grados Celsius: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      case UnidadesDeTemperatura::fahrenheit_a_celsius:

        cout << "Ingrese el valor en grados Fahrenheit: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      case UnidadesDeTemperatura::kelvin_a_celsius:

        cout << "Ingrese el valor en grados Kelvin: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      case UnidadesDeTemperatura::celsius_a_kelvin:

        cout << "Ingrese el valor en grados Celsius: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      case UnidadesDeTemperatura::fahrenheit_a_kelvin:

        cout << "Ingrese el valor en grados Fahrenheit: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      case UnidadesDeTemperatura::kelvin_a_fahrenheit:

        cout << "Ingrese el valor en grados Kelvin: ";
        cin >> valor;
        conversor(conversionTemperatura, valor);
        break;
      default:
        break;
      }
      break;
    case Opciones::salir:
      cout << "Saliendo del programa uno" << endl;
      break;
    default:
      cout << "Entrada inválida" << endl;
      break;
    }
  } while (opcionSeleccionada != Opciones::salir);
  return 0;
}

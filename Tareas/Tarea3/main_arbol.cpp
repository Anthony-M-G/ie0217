#include "./includes/Arbol.hpp"
#include "./includes/Nodo.hpp"
#include <iostream>

enum Opcion
{ // Enum de opciones para el menú.
  INSERTAR = 1,
  IMPRIMIR,
  BUSCAR,
  ALTURA,
  VERIFICAR_BALANCE,
  ELIMINAR,
  SALIR
};

const int valoresDefault[7] = {15, 10, 20, 8, 12, 17, 25}; // Valores por defecto para el árbol.

int main()
{
  ArbolBS arbol;
  int opcion, valor;
  for (auto &&i : valoresDefault)
  {
    arbol.insertar(i);
  }

  do
  {
    std::cout << "1. Insertar un nodo\n";
    std::cout << "2. Imprimir\n";
    std::cout << "3. Buscar un valor\n";
    std::cout << "4. Altura del árbol\n";
    std::cout << "5. Verificar si el árbol está balanceado\n";
    std::cout << "6. Eliminar\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    switch (static_cast<Opcion>(opcion))
    {
    case INSERTAR:
      std::cout << "Ingrese un valor: ";
      std::cin >> valor;
      arbol.insertar(valor);
      break;

    case IMPRIMIR:
      arbol.imprimir();
      break;

    case BUSCAR:
      std::cout << "Ingrese un valor a buscar: ";
      std::cin >> valor;
      if (arbol.buscar(valor))
      {
        std::cout << "Valor encontrado.\n";
      }
      else
      {
        std::cout << "Valor no encontrado.\n";
      }
      break;

    case ALTURA:
      std::cout << "Altura del árbol: " << arbol.altura() << std::endl;
      break;

    case VERIFICAR_BALANCE:
      if (arbol.estaBalanceado())
      {
        std::cout << "El árbol está balanceado.\n";
      }
      else
      {
        std::cout << "El árbol no está balanceado.\n";
      }
      break;

    case ELIMINAR:
      std::cin >> valor;
      arbol.eliminar(valor);
      break;

    case SALIR:
      std::cout << "Saliendo...\n";
      break;

    default:
      std::cout << "Opción inválida.\n";
    }
  } while (opcion != SALIR);

  return 0;
}

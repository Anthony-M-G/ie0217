#include <iostream>
#include <algorithm> // Para std::sort
#include <vector>    // Para std::vector

// Función de comparación personalizada
bool myFunction(int i, int j) { return (i < j); }

// Clase con operador de comparación sobrecargado
struct myClass
{
  bool operator()(int i, int j) { return (i < j); }
} myObject;

int main()
{
  // Inicialización de un vector con valores desordenados
  int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
  std::vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33

  // Ordenamiento usando el operador de comparación por defecto (<)
  std::sort(myvector.begin(), myvector.begin() + 4); // (12 32 45 71) 26 80 53 33

  // Ordenamiento usando una función como criterio de comparación
  std::sort(myvector.begin() + 4, myvector.end(), myFunction); // 12 32 45 71 (26 33 53 80)

  // Ordenamiento usando un objeto función (functor) como criterio
  std::sort(myvector.begin(), myvector.end(), myObject); // (12 26 32 33 45 53 71 80)

  // Impresión del vector ordenado
  std::cout << "Ordenado:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
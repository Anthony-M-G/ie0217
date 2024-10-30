#include <algorithm>
#include <iostream>
#include <vector>

double calcularMedia(const std::vector<int> &numeros) {
  int suma = 0; // inicializa la suma en 0
  for (int i = 0; i < numeros.size(); i++) {
    suma += numeros[i]; // suma cada elemento del vector
  }
  return (double)suma / numeros.size(); // retorna la media casteada a double
}

double calcularMediana(std::vector<int> numeros) {
  std::sort(numeros.begin(), numeros.end()); // ordena el vector

  int tam = numeros.size(); // obtiene el tamaño del vector
  if (tam % 2 == 0) {       // si el tamaño es par
    return double(numeros[(tam / 2) - 1] + numeros[tam / 2]) /
           2; // retorna la mediana
  } else {
    return numeros[tam /
                   2]; // si el tamaño es impar, retorna el elemento del medio
  }
}

int main() {
  std::vector<int> numeros = {1, 4, 8, 110, 33, 49};

  double media = calcularMedia(numeros);
  double mediana = calcularMediana(numeros);

  std::cout << "Media: " << media << std::endl;
  std::cout << "Mediana: " << mediana << std::endl;

  return 0;
}

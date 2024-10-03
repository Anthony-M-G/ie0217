#ifndef ALGORITMOSDEORDENAMIENTO_HPP
#define ALGORITMOSDEORDENAMIENTO_HPP

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class AlgoritmosDeOrdenamiento {
private:
  std::vector<T> datos;

  // Método recursivo privado para QuickSort
  void privateQuickSort(int inicio, int fin) {
    if (inicio < fin) {
      int pivote = particion(inicio, fin);
      privateQuickSort(inicio, pivote - 1); // Llamada recursiva a la izquierda
      privateQuickSort(pivote + 1, fin);    // Llamada recursiva a la derecha
    }
  }

  // Función para particionar el array
  int particion(int inicio, int fin) {
    T pivote = datos[fin]; // Tomamos el último elemento como pivote
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
      if (datos[j] < pivote) {
        i++;
        std::swap(datos[i], datos[j]);
      }
    }
    std::swap(datos[i + 1], datos[fin]);
    return i + 1;
  }

public:
  AlgoritmosDeOrdenamiento(){};

  // Método para asignar datos al vector
  void setDatos(std::vector<T> datos) { this->datos = datos; }

  // Bubble Sort
  void bubbleSort() {
    for (size_t i = 0; i < datos.size(); i++) {
      for (size_t j = 0; j < datos.size() - 1; j++) {
        if (datos[j] > datos[j + 1]) {
          std::swap(datos[j], datos[j + 1]);
        }
      }
    }
  }

  // Insertion Sort
  void insertionSort() {
    for (size_t i = 1; i < datos.size(); i++) {
      T temp = datos[i];
      int j = i - 1;
      while (j >= 0 && datos[j] > temp) {
        datos[j + 1] = datos[j];
        j--;
      }
      datos[j + 1] = temp;
    }
  }

  // Selection Sort
  void selectionSort() {
    for (size_t i = 0; i < datos.size(); i++) {
      size_t min = i;
      for (size_t j = i + 1; j < datos.size(); j++) {
        if (datos[j] < datos[min]) {
          min = j;
        }
      }
      std::swap(datos[i], datos[min]);
    }
  }

  // Quick Sort
  void quickSort() {
    privateQuickSort(0, this->datos.size() - 1); // Llamar al método privado
  }

  // Método para imprimir los datos
  void imprimirDatos() const {
    for (const auto &dato : datos) {
      std::cout << dato << " ";
    }
    std::cout << std::endl;
  }

  // Obtener los datos
  std::vector<T> getDatos() const { return datos; }

  // Usar el sort de la STL
  void STLsort() { std::sort(datos.begin(), datos.end()); }

  ~AlgoritmosDeOrdenamiento(){};
};

#endif // ALGORITMOSDEORDENAMIENTO_HPP

#include "./includes/AlgoritmosDeOrdenamiento.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric> // Para std::accumulate
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int>
generate_random_vector(size_t size,
                       unsigned seed) { // Función que genera un vector de
                                        // tamaño size con números aleatorios
  vector<int> vec(size);
  mt19937 gen(seed);
  uniform_int_distribution<> dist(1, 10000);

  for (size_t i = 0; i < size; ++i) {
    vec[i] = dist(gen);
  }
  return vec;
}

template <typename W>
long long measure_sort_time(
    void (AlgoritmosDeOrdenamiento<W>::*
              callback)(), // Recibe un puntero a función miembro de la clase
                           // AlgoritmosDeOrdenamiento como primer argumento
    AlgoritmosDeOrdenamiento<W>
        &instancia) { // Recibe una instancia de la clase
                      // AlgoritmosDeOrdenamiento como segundo argumento
  auto start = chrono::high_resolution_clock::now();
  (instancia.*callback)(); // Llamada a la función miembro de la instancia
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration_cast<chrono::milliseconds>(end - start)
      .count(); // Medir en milisegundos
}

void escribirArchivo(vector<long long> &vec,
                     fstream &file) { // Función que escribe en un archivo los
                                      // tiempos de ejecución
  for (auto &i : vec) {
    file << i << " ";
  }
  file << " \n" << endl;
}

int main() {
  AlgoritmosDeOrdenamiento<int> algoritmosDeOrdenamiento;
  vector<size_t> sizes = {5000,   10000,  50000,
                          100000, 200000, 500000}; // Tamaños de prueba
  int num_runs = 10; // Número de ejecuciones por tamaño
  vector<long long> bubble_times, selection_times, insertion_times, quick_times,
      stl_times;
  // Crear archivo de salida
  fstream file("./data/resultados.txt", ios::trunc | ios::out);

  // Comparación de tiempos promediados
  for (auto size : sizes) {

    for (int run = 0; run < num_runs; ++run) {
      unsigned seed = chrono::system_clock::now().time_since_epoch().count() +
                      run; // Semilla diferente

      vector<int> originalVec = generate_random_vector(size, seed);

      algoritmosDeOrdenamiento.setDatos(originalVec);
      bubble_times.push_back(
          measure_sort_time(&AlgoritmosDeOrdenamiento<int>::bubbleSort,
                            algoritmosDeOrdenamiento));

      algoritmosDeOrdenamiento.setDatos(originalVec);
      selection_times.push_back(
          measure_sort_time(&AlgoritmosDeOrdenamiento<int>::selectionSort,
                            algoritmosDeOrdenamiento));

      algoritmosDeOrdenamiento.setDatos(originalVec);
      insertion_times.push_back(
          measure_sort_time(&AlgoritmosDeOrdenamiento<int>::insertionSort,
                            algoritmosDeOrdenamiento));

      algoritmosDeOrdenamiento.setDatos(originalVec);
      quick_times.push_back(measure_sort_time(
          &AlgoritmosDeOrdenamiento<int>::quickSort, algoritmosDeOrdenamiento));

      algoritmosDeOrdenamiento.setDatos(originalVec);
      stl_times.push_back(measure_sort_time(
          &AlgoritmosDeOrdenamiento<int>::STLsort, algoritmosDeOrdenamiento));
    }

    // Calcular promedios
    auto promedio = [](const vector<long long> &times) {
      return accumulate(times.begin(), times.end(), 0LL) / times.size();
    };

    cout << "Tamaño del conjunto de datos: " << size << "\n";
    cout << "Bubble Sort: " << promedio(bubble_times) << " milisegundos\n";
    cout << "Insertion Sort: " << promedio(insertion_times)
         << " milisegundos\n";
    cout << "Quick Sort: " << promedio(quick_times) << " milisegundos\n";
    cout << "Selection Sort: " << promedio(selection_times)
         << " milisegundos\n";
    cout << "STL Sort: " << promedio(stl_times) << " milisegundos\n";
    cout << "---------------------------------------------\n";
  }

  try { // Manejo de excepciones para la apertura del archivo
    if (!file.is_open()) {
      cerr << "Error al abrir el archivo\n";
      throw runtime_error("Error al abrir el archivo");
    }
  } catch (const runtime_error &e) {
    cerr << e.what() << endl;
  }

  escribirArchivo(bubble_times,
                  file); // Escribir en el archivo los tiempos de ejecución
  escribirArchivo(insertion_times,
                  file); // Escribir en el archivo los tiempos de ejecución
  escribirArchivo(quick_times,
                  file); // Escribir en el archivo los tiempos de ejecución
  escribirArchivo(selection_times,
                  file); // Escribir en el archivo los tiempos de ejecución
  escribirArchivo(stl_times,
                  file); // Escribir en el archivo los tiempos de ejecución

  file.close(); // Cerrar archivo

  return 0;
}

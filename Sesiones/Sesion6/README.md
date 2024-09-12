# Sesión 6: Algoritmos de Ordenación

En esta sesión se presentan ejemplos de implementación de varios algoritmos de ordenación en C++: `InsertionSort`, `BubbleSort`, `QuickSort` y `SelectionSort`. Se incluyen explicaciones detalladas de cada algoritmo, mostrando cómo funcionan y cuándo es más conveniente usarlos.

## Contenidos

- **Insertion Sort**: Implementación y explicación del algoritmo de ordenación por inserción.
- **Bubble Sort**: Implementación y explicación del algoritmo de ordenación burbuja.
- **QuickSort**: Implementación y explicación del algoritmo de ordenación rápida.
- **Selection Sort**: Implementación y explicación del algoritmo de ordenación por selección.

## Algoritmos de Ordenación

### Insertion Sort

El **Insertion Sort** es un algoritmo de ordenación que construye la lista ordenada de forma incremental, tomando un elemento de la lista original y ubicándolo en la posición correcta. Es sencillo de implementar y eficiente para listas pequeñas o casi ordenadas, con una complejidad de O(n²) en el peor de los casos.

### Bubble Sort

El **Bubble Sort** es un algoritmo simple que repetidamente recorre la lista, compara elementos adyacentes y los intercambia si están en el orden incorrecto. Este proceso se repite hasta que la lista está ordenada. Es fácil de entender e implementar, pero no es eficiente para listas grandes, ya que su complejidad es O(n²).

### QuickSort

**QuickSort** es un algoritmo de ordenación eficiente que utiliza el principio de "divide y vencerás". Selecciona un pivote y particiona la lista en elementos menores o iguales al pivote y elementos mayores, luego ordena recursivamente cada partición. Tiene una complejidad promedio de O(n log n), aunque en el peor caso puede ser O(n²).

### Selection Sort

El **Selection Sort** es un algoritmo de ordenación que divide la lista en una parte ordenada y otra desordenada. Encuentra el elemento mínimo de la parte desordenada y lo intercambia con el primer elemento de la parte desordenada, moviendo el límite de la parte ordenada una posición. Su complejidad es O(n²), y es ineficiente para listas grandes.

## Requisitos

- Un compilador de C++ (como `g++` en Linux o `g++` en MinGW para Windows).
- Conocimientos básicos de la terminal en Linux o del Símbolo del sistema en Windows.

## Instrucciones de Compilación

### En Linux

1. Abre una terminal.
2. Navega al directorio donde se encuentran los archivos `.cpp` del proyecto.
3. Compila el código usando `g++`:

   ```bash
   g++ -o nombre_ejecutable archivo.cpp
   ```

4. Para ejecutar:

   ```bash
   ./nombre_ejecutable
   ```

### En Windows

1. Abre una terminal.
2. Navega al directorio donde se encuentran los archivos `.cpp` del proyecto.
3. Compila el código usando `g++`:

   ```bash
   g++ -o programa.exe <nombredelprograma>.cpp
   ```

4. Para ejecutarlo:

   ```bash
   .\programa.exe
   ```

5. Asegúrate de tener MinGW o algún entorno que permita compilar y ejecutar programas en C/C++.

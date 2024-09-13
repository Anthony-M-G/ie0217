# Sesión 7: STL en C++: Map, Set, List, Iteradores y Algoritmos

En esta sesión se explican las estructuras de datos proporcionadas por la STL (Standard Template Library) de C++, como `map`, `set`, `list`, junto con el uso de iteradores y algoritmos como `sort`. Estos componentes permiten manejar datos de forma eficiente y flexible.

## Contenidos

- **Map**: Contenedor asociativo para almacenar pares clave-valor.
- **Set**: Contenedor para almacenar elementos únicos.
- **List**: Lista enlazada doble para manipular secuencias de datos.
- **Iteradores**: Objetos que permiten recorrer los elementos de los contenedores de STL.
- **Algoritmos**: Operaciones genéricas como `sort`, que se pueden aplicar a contenedores.

## Map

Un **map** en C++ es un contenedor asociativo que almacena pares de clave-valor. Cada clave es única y está asociada con un valor. Se utiliza cuando necesitas buscar datos de manera rápida en función de una clave, con una complejidad promedio de O(log n) para las operaciones de inserción, eliminación y búsqueda, gracias a su implementación como un árbol binario balanceado (generalmente un árbol rojo-negro).

### Características:

- Las claves en `std::map` son únicas.
- Mantiene los elementos ordenados según las claves.
- Acceso eficiente a valores a través de claves.

## Set

Un **set** es un contenedor que almacena elementos únicos y ordenados automáticamente. Los elementos no se repiten y las operaciones básicas, como inserción, eliminación y búsqueda, tienen una complejidad de O(log n).

### Características:

- Almacena solo elementos únicos.
- Mantiene los elementos ordenados automáticamente.
- No permite la modificación directa de elementos; solo se pueden agregar o eliminar.

## List

Una **list** es un contenedor que implementa una lista doblemente enlazada. Permite una inserción y eliminación eficiente en cualquier parte de la secuencia, aunque el acceso a los elementos es lineal (O(n)).

### Características:

- Soporta inserción y eliminación en cualquier posición en O(1).
- No ofrece acceso aleatorio (a diferencia de un vector).
- Útil cuando necesitas manipular frecuentemente los extremos de la lista o hacer inserciones en el medio.

## Iteradores

Los **iteradores** son objetos que actúan como punteros para acceder a los elementos de los contenedores de STL. Permiten recorrer contenedores de manera genérica, sin preocuparse por la implementación interna. Hay varios tipos de iteradores (bidireccionales, aleatorios, etc.) según el contenedor que los soporte.

### Tipos de iteradores:

- **Bidireccionales**: Pueden moverse hacia adelante y hacia atrás (por ejemplo, en `list`, `set`).
- **Aleatorios**: Pueden saltar a cualquier posición en tiempo constante (por ejemplo, en `vector`).

## Algoritmos

La STL proporciona una serie de algoritmos genéricos que se pueden aplicar a los contenedores mediante iteradores. El algoritmo **sort** es uno de los más utilizados y ordena los elementos en un rango definido por dos iteradores.

### Características de `std::sort`:

- Requiere acceso aleatorio a los elementos (por ejemplo, contenedores como `vector` o arreglos).
- Ordena los elementos en orden ascendente por defecto.
- Tiene una complejidad O(n log n).

## Requisitos

- Compilador de C++ (como `g++` en Linux o `g++` en MinGW para Windows).
- Conocimientos básicos de C++ y de la terminal (Linux) o el símbolo del sistema (Windows).

## Instrucciones de Compilación

### En Linux

1. Abre una terminal.
2. Navega al directorio donde se encuentran los archivos `.cpp` del proyecto.
3. Compila el código usando `g++`:

   ```bash
   g++ -o nombre_ejecutable archivo.cpp
   ```

4. Ejecuta el programa:

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

4. Ejecuta el programa:

   ```bash
   .\programa.exe
   ```

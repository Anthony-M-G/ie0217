# Sesión 4 : Memoria dinámica y algunas estructuras de datos

En esta sesión se presentan ejemplos de implementación de estructuras de datos en C++ usando memoria dinámica. Se incluyen estructuras de datos como pilas, colas y listas enlazadas, demostrando cómo gestionar la memoria en tiempo de ejecución utilizando funciones como `new`, `delete`, `malloc` y `free`.

## Contenidos

- **Pilas (Stacks)**: Implementación de una pila con memoria dinámica.
- **Colas (Queues)**: Implementación de una cola con memoria dinámica.
- **Listas Enlazadas (Linked Lists)**: Implementación de una lista enlazada simple y doblemente enlazada.
- **Memoria Dinámica**: Ejemplos de uso de `new`, `delete`, `malloc`, `calloc` y `free` para la gestión manual de la memoria.

## Memoria Dinámica en C++

La memoria dinámica permite reservar y liberar memoria en tiempo de ejecución, lo que es útil cuando no se conoce de antemano cuánta memoria será necesaria. En C++, existen dos formas principales de gestionar la memoria dinámica:

1. **Operadores `new` y `delete`**:
   - `new`: Reserva memoria para un tipo de dato o un arreglo.
   - `delete`: Libera la memoria reservada por `new`.
2. **Funciones `malloc`, `calloc` y `free`**:
   - `malloc`: Reserva un bloque de memoria de tamaño especificado (en bytes).
   - `calloc`: Similar a `malloc`, pero también inicializa la memoria a cero.
   - `free`: Libera la memoria reservada por `malloc` o `calloc`.

## Estructuras de Datos

### Pila (Stack)

Una pila es una estructura de datos que sigue el principio LIFO (Last In, First Out), donde el último elemento insertado es el primero en ser eliminado. Las operaciones básicas son `push` (inserción) y `pop` (eliminación).

### Cola (Queue)

Una cola es una estructura de datos que sigue el principio FIFO (First In, First Out), donde el primer elemento insertado es el primero en ser eliminado. Las operaciones básicas son `enQueue` (inserción) y `deQueue` (eliminación).

### Lista Enlazada (Linked List)

Una lista enlazada es una colección de nodos donde cada nodo contiene un dato y un puntero al siguiente nodo en la secuencia. Puede ser simple (enlace simple) o doble (enlace doble, donde cada nodo tiene un puntero al nodo anterior y al siguiente).

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
  ./nombredelejecutable
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

5. Recuerda que en Windows debes tener Mingw o algún entorno que permita compilar y ejecutar programas c o c++

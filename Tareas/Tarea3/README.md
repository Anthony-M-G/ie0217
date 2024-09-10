# Tarea 3 - Universidad de Costa Rica

## Descripción

### 1. Árbol Binario de Búsqueda con Verificación y Balance

Este programa implementa un Árbol Binario de Búsqueda (ABB) en C++. El árbol inicial se crea automáticamente con una estructura predefinida de nodos. El programa permite:

- Inserción y eliminación de nodos.
- Verificación de que el árbol sigue siendo un ABB válido.
- Cálculo de la altura del árbol.
- Determinación de si el árbol está balanceado.
- Recorrido e impresión del árbol en orden ascendente.

#### Operaciones Disponibles:

1. Insertar un nodo.
2. Eliminar un nodo.
3. Imprimir el árbol.
4. Calcular la altura del árbol.
5. Verificar si el árbol está balanceado.
6. Salir del programa.

### 2. Gestión de una Lista Enlazada Dinámica de Canciones

Este programa implementa una lista enlazada dinámica para gestionar una colección de canciones. Cada nodo de la lista almacena un objeto de la clase `Cancion`, que contiene información básica sobre la canción (nombre, artista, duración). El programa permite:

- Inicializar una lista con 3 canciones predefinidas.
- Insertar nuevas canciones al inicio, final o en posiciones intermedias.
- Eliminar canciones de la lista.
- Modificar los datos de una canción existente.
- Imprimir la lista completa de canciones.

#### Operaciones Disponibles:

1. Insertar una nueva canción.
2. Eliminar una canción.
3. Modificar los datos de una canción existente.
4. Imprimir la lista de canciones.
5. Salir del programa (liberando toda la memoria dinámica).

## Instrucciones de Ejecución

### Requisitos

- **Windows:** MinGW instalado y configurado.
- **Linux:** Compilador `g++` instalado.

### Ejecución con Makefile

Para compilar y ejecutar los programas, utilice el `Makefile` proporcionado. Este `Makefile` es compatible con Windows (usando MinGW) y Linux.

#### Compilación y Ejecución

1. **Clonar el repositorio**:

   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd Tarea3
   ```

2. **Compilar y Ejecutar**:

   En Windows:

   ```bash
   mingw32-make
   ```

   En Linux:

   ```bash
   make
   ```

3. **Ejecutar los programas**:

   - Para ejecutar el programa del Árbol Binario de Búsqueda:

   Linux:

   ```bash
   ./main_arbol
   ```

   Windows:

   ```bash
     .\main_arbol.exe
   ```

- Para ejecutar el programa de Gestión de Lista Enlazada:

  Linux:

  ```bash
  ./main_lista_canciones
  ```

  Windows:

  ```bash
  .\main_lista_canciones.exe
  ```

#### Limpiar Archivos Compilados

Para limpiar los archivos compilados, ejecute:

Linux:

```bash
make clean
```

Windows:

```bash
mingw32-make clean
```

## Respuestas Parte Teórica

Aquí tienes las respuestas para la parte teórica de la tarea:

### Parte Teórica

1. **Explique cada sección del nivel de usuario de la memoria (Text, Heap, Stack, etc.). ¿Cuáles de estas secciones son de memoria dinámica?**

   - **Text**: Contiene el código ejecutable del programa. Es una región de solo lectura y generalmente se carga en la memoria cuando el programa se ejecuta.
   - **Data**: Se divide en dos partes: `Data Segment` (para variables globales y estáticas inicializadas) y `BSS Segment` (para variables globales y estáticas no inicializadas).
   - **Heap**: Utilizado para la memoria dinámica, donde se almacenan los datos asignados en tiempo de ejecución con funciones como `malloc` en C o `new` en C++. Esta memoria no se libera automáticamente; el programador debe liberarla usando `free` o `delete`.
   - **Stack**: Utilizado para almacenar variables locales, direcciones de retorno y registros de funciones. La memoria en el stack se gestiona automáticamente, liberándose cuando se sale del ámbito de la función.
   - **Memoria dinámica**: El `Heap` es la región de memoria dinámica, ya que permite la asignación y liberación de memoria durante la ejecución del programa.

2. **Variables y su ubicación en la memoria:**

   - **`globalVar`**: Se almacena en la sección de `Data Segment` ya que está inicializada
   - **`staticVar`**: Se almacena en la sección de `Data Segment` ya que está inicializada.
   - **`localVar`**: Se almacena en el `Stack`, ya que es una variable local a una función.
   - **`dynamicVar`**: Se almacena en el `Heap`, porque es una variable asignada dinámicamente

3. **Diferencia entre memoria dinámica y memoria estática:**

   - **Memoria dinámica**: Se asigna durante la ejecución del programa. Ejemplo: usar `malloc` en C o `new` en C++ para asignar memoria.
   - **Memoria estática**: Se asigna en tiempo de compilación. Ejemplo: variables globales o locales dentro de funciones, como `int x = 5;`.

4. **Acceso a la memoria dinámica del heap y ejemplo de código:**

   - Se accede a la memoria dinámica utilizando punteros. Ejemplo en C++:
     ```cpp
     int* ptr = new int; // Asignar memoria para un entero
     *ptr = 10; // Asignar valor a esa memoria
     delete ptr; // Liberar la memoria asignada
     ```

5. **Importancia de liberar la memoria asignada dinámicamente:**

   - Es importante liberar la memoria para evitar fugas de memoria (memory leaks), que pueden agotar los recursos del sistema y causar que el programa o el sistema operativo se vuelvan inestables o se bloqueen.

6. **Uso de las funciones `malloc`, `calloc` y `realloc`:**

   - **`malloc(size_t size)`**: Asigna un bloque de memoria de `size` bytes.
   - **`calloc(size_t num, size_t size)`**: Asigna un bloque de memoria para un array de `num` elementos, cada uno de `size` bytes, y lo inicializa a cero.
   - **`realloc(void* ptr, size_t size)`**: Cambia el tamaño del bloque de memoria previamente asignado por `ptr` a `size` bytes.

7. **Diferencias entre `free` y `delete`:**

   - **`free`**: Se utiliza en C para liberar memoria asignada por `malloc`, `calloc`, o `realloc`.
   - **`delete`**: Se utiliza en C++ para liberar memoria asignada por `new`. Además, `delete` llama al destructor del objeto si es necesario.

8. **Diferencia entre `new` y `malloc` en C++:**

   - **`new`**: Asigna memoria y llama al constructor del objeto. Se utiliza en C++.
   - **`malloc`**: Solo asigna memoria sin inicializarla, y no llama al constructor. Se utiliza en C.
   - Se debería usar `new` en C++ para crear objetos y `malloc` en C para asignación de memoria sin constructor.

9. **Concepto de punteros inteligentes (smart pointers) y ejemplos de uso:**

   - **Punteros inteligentes**: Son clases que administran automáticamente la memoria dinámica. Ejemplos en C++:
     - **`std::unique_ptr`**: Puntero único, no puede haber dos `unique_ptr` apuntando al mismo objeto.
     - **`std::shared_ptr`**: Puntero compartido, puede haber múltiples `shared_ptr` apuntando al mismo objeto. La memoria se libera cuando el último `shared_ptr` es destruido.
     - **`std::weak_ptr`**: Puntero débil, no incrementa el conteo de referencias.

10. **¿Qué es un algoritmo y qué características básicas debería tener?**

    - Un algoritmo es una secuencia finita de pasos o instrucciones bien definidas que resuelven un problema o realizan una tarea. Debe ser correcto, finito, claro y eficiente.

11. **¿Qué es la complejidad y eficiencia de un algoritmo? ¿De qué manera se miden?**

    - **Complejidad**: Medida del rendimiento de un algoritmo, puede ser de tiempo (cuánto tarda en ejecutarse) o de espacio (cuánta memoria utiliza).
    - **Eficiencia**: Determina qué tan óptimo es un algoritmo en términos de tiempo y espacio.
    - Se miden usando notaciones como O(n) (complejidad temporal) y O(1) (complejidad espacial).

12. **Diferencia entre estructuras de datos lineales y no-lineales:**

    - **Lineales**: Los elementos están en una secuencia. Ejemplos: Array, Listas enlazadas.
    - **No-lineales**: Los elementos no tienen un orden secuencial. Ejemplos: Árboles, Grafos.

13. **Funcionamiento de la estructura Stack:**

    - Es una estructura LIFO (Last In, First Out). El último elemento que se inserta es el primero en ser eliminado.

14. **Funcionamiento de la estructura Queue:**

    - Es una estructura FIFO (First In, First Out). El primer elemento que se inserta es el primero en ser eliminado.

15. **Funcionamiento de la estructura Lista Enlazada:**

    - Es una colección de nodos donde cada nodo contiene un dato y un puntero al siguiente nodo. Permite inserciones y eliminaciones dinámicas.

16. **Funcionamiento de la estructura Árbol:**

    - Es una estructura jerárquica con un nodo raíz y subnodos que representan relaciones de jerarquía. Cada nodo tiene un padre y puede tener varios hijos.

17. **Tipos de recorridos de un árbol:**

    - **Preorden**: Visita la raíz, luego el subárbol izquierdo, y finalmente el subárbol derecho.
    - **Inorden**: Visita el subárbol izquierdo, luego la raíz, y finalmente el subárbol derecho.
    - **Postorden**: Visita el subárbol izquierdo, luego el subárbol derecho, y finalmente la raíz.

18. **Diferencia entre un árbol y un árbol binario y tipos de árboles binarios:**
    - Un **árbol** es una estructura jerárquica con nodos y un nodo raíz.
    - Un **árbol binario** es un árbol donde cada nodo tiene como máximo dos hijos (izquierdo y derecho).
    - **Tipos de árboles binarios**:
      - **Árbol Binario Completo**: Todos los niveles están completamente llenos excepto posiblemente el último.
      - **Árbol Binario Perfecto**: Todos los niveles están completamente llenos.
      - **Árbol Binario de Búsqueda (ABB)**: Para cada nodo, todos los nodos del subárbol izquierdo son menores y todos los del subárbol derecho son mayores.

## Documentación

Todos los archivos de código están documentados en formato Doxygen. La documentación generada se encuentra publicada en Vercel:

Árbol binario [aquí](https://ie0217-tarea03-p1.vercel.app/).

Gestión de lista enlazada dinámica de canciones [aquí](https://ie0217-tarea03-p2.vercel.app/).

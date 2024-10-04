# Tarea 4 - IE-0217

Este repositorio contiene la implementación de la Tarea 4 del curso **Estructuras Abstractas de Datos y Algoritmos para Ingeniería (IE-0217)** de la Universidad de Costa Rica.

## Estructura del Proyecto

```
.
├── BenchMarks
│   ├── includes
│   └── src
└── GestorDeProyectos
    ├── Doxyfile
    ├── Makefile
    ├── README.md
    ├── doxydoc
    ├── includes
    ├── main.cpp
    └── src
```

Cada subcarpeta incluye su propio archivo `README.md` con instrucciones específicas para ejecutar los programas y el manejo de la documentación y compilación.

## Requerimientos

- GCC (versión 11.4.0 o superior)
- Make
- C++17 o superior
- Doxygen (para generar la documentación)

## Instrucciones Generales de Compilación

1. Clona el repositorio:

   ```bash
   git clone https://github.com/Anthony-M-G/ie0217.git
   cd tarea4
   ```

2. Navega a la carpeta del proyecto que deseas compilar:

   - Para los benchmarks de algoritmos de ordenamiento:
     ```bash
     cd BenchMarks
     ```
   - Para el simulador de gestión de proyectos:
     ```bash
     cd GestorDeProyectos
     ```

3. Compila el proyecto correspondiente utilizando Makefile:

   ```bash
   make
   ```

4. Ejecuta el programa generado:
   ```bash
   ./nombre_del_ejecutable
   ```

## Documentación

La documentación generada por Doxygen está ubicada en la carpeta `doxydoc/html`. Para visualizarla, visita el link [aquí](https://ie0217-tarea04-gestorproyectos.vercel.app/)https://ie0217-tarea04-gestorproyectos.vercel.app/

## Respuestas Parte Teórica

1. **¿Qué es un algoritmo de ordenamiento y por qué son importantes en programación?**
   Un algoritmo de ordenamiento organiza los elementos de una estructura de datos en un orden específico (ascendente o descendente). Son importantes porque facilitan la búsqueda eficiente, reducen la complejidad de otros algoritmos y mejoran el rendimiento en múltiples aplicaciones.

2. **Explique el funcionamiento del algoritmo de ordenamiento "Bubble Sort".**
   Compara pares de elementos adyacentes, intercambiándolos si están en el orden incorrecto. Este proceso se repite hasta que no se realicen más intercambios, lo que indica que la lista está ordenada.

3. **Explique el funcionamiento del algoritmo de ordenamiento "Selection Sort".**
   Encuentra el elemento más pequeño en cada iteración y lo coloca en su posición correcta. Repite este proceso para el resto de la lista.

4. **Describa el algoritmo de ordenamiento "QuickSort". ¿Cuál es su ventaja principal?**
   Divide y conquista: selecciona un pivote, reordena los elementos para que todos los menores estén antes del pivote y los mayores después. Luego aplica el mismo proceso a las sublistas. Su principal ventaja es la eficiencia con grandes conjuntos de datos y su complejidad promedio \(O(n \log n)\).

5. **Explique el concepto de complejidad temporal y cómo se aplica a los algoritmos de ordenamiento.**
   La complejidad temporal mide el tiempo que toma un algoritmo en función del tamaño de la entrada. Aplicada a algoritmos de ordenamiento, evalúa el número de comparaciones e intercambios necesarios.

   a. **Complejidad temporal de algunos algoritmos:**

   - **Bubble Sort**: \(O(n^2)\)
   - **Insertion Sort**: \(O(n^2)\)
   - **QuickSort**: \(O(n \log n)\) (promedio), \(O(n^2)\) (peor caso)
   - **Selection Sort**: \(O(n^2)\)
   - **std::sort**: \(O(n \log n)\)

6. **¿Cuál es la diferencia entre los algoritmos de ordenamiento estables e inestables?**
   Un algoritmo de ordenamiento es **estable** si mantiene el orden relativo de elementos iguales. Es **inestable** si no lo hace.

   a. Ejemplos:

   - **Estables**: Merge Sort, Bubble Sort.
   - **Inestables**: QuickSort, Selection Sort.
     La estabilidad es importante cuando el orden relativo de los elementos es significativo, como en la ordenación por múltiples criterios.

7. **¿Cómo funciona la función std::sort de la STL y qué algoritmo utiliza?**
   **std::sort** usa una versión híbrida de QuickSort e introsort, adaptándose a diferentes situaciones para mejorar la eficiencia.

   a. Su complejidad es \(O(n \log n)\), y es más eficiente porque se optimiza para casos específicos como arrays pequeños o parcialmente ordenados.

8. **Explique la importancia de hacer benchmarks en los algoritmos de ordenamiento.**
   Los benchmarks permiten comparar el rendimiento real de los algoritmos bajo diferentes condiciones, lo que es crucial para seleccionar el algoritmo adecuado.

   a. Factores a considerar: tamaño del conjunto de datos, orden inicial, estabilidad, uso de memoria, tiempo de ejecución.

9. **Compare el uso de memoria de diferentes algoritmos de ordenamiento.**
   a. **QuickSort** usa \(O(\log n)\) de memoria adicional debido a la recursión. **Merge Sort**, por otro lado, usa \(O(n)\) debido a la creación de subarrays.

10. **¿Cómo se elige el algoritmo de ordenamiento más adecuado?**
    a. Factores como el tamaño del conjunto, el orden inicial, la estabilidad y la eficiencia esperada (tiempo y memoria) determinan la elección del algoritmo.

11. **Cinco contenedores diferentes de la STL y sus usos:**

    - **std::vector**: para almacenamiento dinámico de datos.
    - **std::list**: para listas enlazadas.
    - **std::map**: para asociar claves y valores.
    - **std::set**: para almacenar elementos únicos en orden.
    - **std::deque**: para inserciones y eliminaciones rápidas en ambos extremos.

12. **Adaptadores de contenedores:**
    Son contenedores que proporcionan una interfaz diferente, como **std::stack**, que utiliza un contenedor subyacente como **std::deque** para implementar una pila.
    Continuando con las respuestas:

13. **Explique el concepto de iteradores en la STL y cómo se utilizan para acceder a elementos en contenedores.**
    Los iteradores son objetos que permiten recorrer elementos de un contenedor en la STL. Funcionan de manera similar a punteros y permiten acceder a los elementos de una colección, realizar modificaciones o iterar sobre ellos.

14. **Mencione y explique 3 diferentes operaciones soportadas por iteradores en STL. ¿Cómo se definen en el código?**
    a. **begin()**: Devuelve un iterador apuntando al primer elemento del contenedor.
    b. **end()**: Devuelve un iterador apuntando al "final" del contenedor (un lugar después del último elemento).
    c. **advance()**: Desplaza un iterador una cantidad específica de pasos hacia adelante.
    Se utilizan con notación de puntero: `*iter` para acceder al valor, `++iter` para avanzar, etc.

15. **¿Qué implementaciones se pueden hacer con iteradores de acceso aleatorio? ¿Cuál es la diferencia principal con los iteradores bidireccionales?**
    Los iteradores de acceso aleatorio permiten saltar a cualquier posición en el contenedor en constante tiempo \(O(1)\), como en `std::vector`. Los iteradores bidireccionales, como en `std::list`, solo permiten avanzar o retroceder en \(O(1)\), pero no saltar directamente a posiciones arbitrarias.

16. **Proporcione ejemplos de al menos tres algoritmos de la STL y describa sus funciones básicas.**

    - **std::sort**: Ordena los elementos de un contenedor en un rango específico.
    - **std::find**: Busca un elemento dentro de un rango de un contenedor.
    - **std::accumulate**: Suma los elementos de un rango y devuelve el resultado acumulado.

17. **¿Cómo podría utilizar un algoritmo personalizado con la STL?**
    Puedes definir un comparador personalizado y pasarlo a funciones como **std::sort** para ordenar en un criterio específico (por ejemplo, orden inverso).

18. **¿Cuál es el papel de los templates en la implementación de funciones de ordenamiento?**
    a. Los **templates** permiten que las funciones de ordenamiento sean genéricas y puedan trabajar con cualquier tipo de dato, ya sea enteros, flotantes, estructuras, etc.

19. **Explique cómo se implementan Templates con múltiples parámetros en C++.**
    Los templates con múltiples parámetros se implementan separando los parámetros con comas:

    ```cpp
    template<typename T, typename U>
    void funcion(T a, U b) { /* código */ }
    ```

20. **¿Qué son las excepciones en C++ y cómo se pueden usar para manejar errores durante las operaciones de ordenamiento?**
    Las excepciones permiten capturar y manejar errores inesperados durante la ejecución. Puedes usarlas para capturar errores como el desbordamiento de memoria.
    a. Ejemplo:

    ```cpp
    try {
        // Código que puede lanzar una excepción
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    ```

21. **Describa los bloques try, catch y throw y cómo se utilizan para el manejo de excepciones en C++.**

    - **try**: Define el bloque de código donde puede ocurrir una excepción.
    - **throw**: Lanza una excepción cuando ocurre un error.
    - **catch**: Captura la excepción lanzada y ejecuta el código de manejo de errores.

22. **Nombre al menos tres excepciones estándar proporcionadas por C++ y proporciona ejemplos de situaciones en las que podrían ser útiles.**

    - **std::bad_alloc**: Se lanza cuando no se puede asignar memoria dinámica.
    - **std::out_of_range**: Se lanza cuando se accede a un índice fuera de los límites de un contenedor.
    - **std::invalid_argument**: Se lanza cuando se proporciona un argumento inválido a una función.

23. **¿Cuál es la forma de manejar errores inesperados o no considerados durante la elaboración del código?**
    Los errores inesperados pueden manejarse utilizando bloques `catch` genéricos:

    ```cpp
    catch(...) {
        std::cerr << "Error inesperado" << std::endl;
    }
    ```

24. **Describa cómo las expresiones regulares se pueden usar para validar o filtrar datos antes del ordenamiento.**
    Las expresiones regulares permiten verificar si los datos cumplen ciertos patrones antes de procesarlos.
    a. Ejemplo: Para validar que un string contiene solo dígitos:

    ```cpp
    std::regex regex("\\d+");
    if (std::regex_match(input, regex)) {
        // Ordenar los datos
    }
    ```

25. **Enumere al menos tres caracteres especiales comúnmente utilizados en expresiones regulares y describa sus funciones.**

    - **^**: Marca el inicio de una línea.
    - **$**: Marca el final de una línea.
    - **\\d**: Representa cualquier dígito.

26. **¿Cuál es la diferencia entre std::regex_match y std::regex_search en C++?**

    - **std::regex_match**: Verifica si una cadena completa coincide con una expresión regular.
    - **std::regex_search**: Busca coincidencias dentro de una cadena, sin requerir que toda la cadena coincida.

27. **¿Cómo se puede utilizar std::regex_replace en C++ para modificar cadenas de texto?**
    Permite reemplazar partes de una cadena que coinciden con una expresión regular.

    ```cpp
    std::string result = std::regex_replace(input, std::regex("\\d"), "X");
    ```

28. **¿Qué es un Makefile y cómo se puede usar para automatizar la compilación de un programa en C++ con múltiples algoritmos de ordenamiento?**
    Un **Makefile** define reglas para compilar y enlazar un programa. Automatiza el proceso de compilación especificando cómo construir ejecutables de múltiples fuentes.
    a. Ejemplo del **Makefile** para el gestor de proyectos:

```makefile
# Carpeta donde se guardarán los archivos objeto
BUILD_DIR = build

# Compilador C++
CXX = g++

# Opciones de compilación:
# -Wall para mostrar todas las advertencias,
# -std=c++11 para usar el estándar C++11
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SRCS = src/BaseTarea.cpp src/Proyecto.cpp src/NotFoundException.cpp src/GestorDeProyectos.cpp main.cpp

# Lista de archivos objeto, se reemplaza 'src/%.cpp' por 'build/%.o'
OBJS = $(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

# Regla principal (compilar el ejecutable)
# El objetivo por defecto es generar el ejecutable usando los objetos
# Ejecutables
ifeq ($(OS),Windows_NT)
   TARGET = main_gestor.exe
   RM = del /Q /F
else
   TARGET = main_gestor
   RM = rm -rf
endif

all: $(TARGET)

# Regla para compilar cada archivo .cpp en su correspondiente .o
# El patrón '$(BUILD_DIR)/%.o' indica que se compila un .cpp en build/
$(BUILD_DIR)/%.o: src/%.cpp
ifeq ($(OS),Windows_NT) # Si el sistema operativo es Windows
   @if not exist $(BUILD_DIR) MD $(BUILD_DIR)
else	# Si el sistema operativo es Linux
   @mkdir -p $(BUILD_DIR)
endif
   $(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para generar el ejecutable
# Se usa la lista de archivos objeto (OBJS) para enlazarlos en el ejecutable
$(TARGET): $(OBJS)
   $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
   $(RM) $(BUILD_DIR) main_gestor main_gestor.exe
```

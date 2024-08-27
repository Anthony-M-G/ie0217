# Tarea 01 del curso Estructuras Abstractas de datos y Algoritmos para ingeniería IE0217

Descripción del Proyecto
Este proyecto contiene dos programas principales desarrollados en C++ como parte de la asignatura IE0217. El primer programa se centra en la conversión de unidades, mientras que el segundo realiza cálculos estadísticos y búsqueda en un arreglo de números enteros.

## Requisitos Previos

- Compilador C++: Es necesario tener un compilador compatible con C++11 o superior (por ejemplo, g++).
- Sistema Operativo: Windows o Linux.

## Compilación y Ejecución

### Compilación

Para compilar ambos programas, simplemente utiliza el comando:

#### Linux

```bash
make
```

#### Windows

En dado caso que estés usando mingw

```bash
mingw32-make
```

Este comando compilará ambos programas y generará los ejecutables programa_uno, programa_dos para Linux o programa_uno.exe, programa_dos.exe para Windows

### 1. Conversión de Unidades

Este programa permite convertir entre diferentes unidades de longitud, peso y temperatura.

#### Ejecución

#### Linux

```bash
./programa_uno
```

#### Windows

```cmd
./programa_uno.exe
```

Al ejecutar este comando, se iniciará el programa de conversión de unidades, donde podrás seleccionar la unidad de origen, la unidad de destino y el valor a convertir.

### 2. Calculadora de Estadísticas y Búsqueda en un Arreglo

Este programa permite calcular estadísticas como suma, promedio, valor máximo y mínimo, además de realizar una búsqueda en un arreglo de números enteros.

#### Ejecución

#### Linux

```bash
./programa_dos [numeros]
```

Donde [números] es una lista de números enteros que debes pasar como argumentos en la línea de comandos. Por ejemplo:

```bash
./programa_dos 10 34 56 78 21
```

#### Windows

```bash
./programa_dos.exe [numeros]
```

```bash
./programa_dos.exe 10 34 56 78 21
```

### Uso del Makefile

El Makefile está configurado para compilar ambos programas con el comando make. Si solo deseas compilar un programa específico, puedes utilizar:

- make programa_uno: Compila solo el programa de conversión de unidades.
- make programa_dos: Compila solo el programa de cálculos estadísticos y búsqueda.
  Para limpiar los archivos generados por la compilación (ejecutables), puedes usar:

#### Linux

```bash
make clean
```

#### Windows

```bash
mingw32-make clean
```

Esto eliminará los ejecutables generados por los programas.

## Sección de respuestas

| Pregunta                                                                                             | Respuesta                                                                                                                                                                                                                                                                                                                     |
| ---------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **1. Diferencias entre lenguajes compilados e interpretados**                                        | **Lenguajes compilados**: Se traducen a código máquina antes de ejecutarse. Ejemplos: C, C++. **Lenguajes interpretados**: Se ejecutan línea por línea por un intérprete. Ejemplos: Python, JavaScript.                                                                                                                       |
| **2. ¿Qué tipos de datos existen en C++? Clasifícalos y proporciona ejemplos.**                      | **Tipos de datos en C++**: **Primitivos** (int, char, float), **Derivados** (arrays, punteros), **User-defined** (struct, class, enum). Ejemplos: `int`, `char`, `int[]`, `struct Persona`.                                                                                                                                   |
| **3. ¿Qué es el linker en un lenguaje de programación compilado?**                                   | El linker combina varios módulos de código objeto en un ejecutable, resolviendo las referencias entre ellos.                                                                                                                                                                                                                  |
| **4. ¿Cuál es la diferencia entre ‘=’ y ‘==’ en C++?**                                               | **‘=’**: Asigna el valor de la derecha a la variable de la izquierda. **‘==’**: Compara si dos valores son iguales.                                                                                                                                                                                                           |
| **5. Salida en la iteración 7 y 9 de un ciclo**                                                      | El código en la iteración 7 devuelve result = 0, ya que 7 % 3 !=0, por lo que la condición del operador ternario (i % 3 == 0) ? sum : 0 es falsa, por lo cual retorna 0, por otra parte en la iteración 9 el condicional del operador ternario si es verdadero, por lo cual result = sum, que en esa iteración es igual a 45. |
| **6. ¿Cómo se pasan los argumentos a la función principal? ¿Qué es `argv[0]`?**                      | Los argumentos se pasan como un array de cadenas (`argv`). `argv[0]` contiene el nombre del programa ejecutado.                                                                                                                                                                                                               |
| **7. Diferencia entre declarar e inicializar una variable**                                          | **Declarar**: Definir una variable sin asignarle un valor inicial. **Inicializar**: Asignar un valor a la variable al momento de su declaración.                                                                                                                                                                              |
| **8. ¿Para qué sirven los modificadores en C++?**                                                    | Modificadores cambian el comportamiento o tamaño de los tipos de datos. Ejemplos: `signed`, `unsigned`, `const`.                                                                                                                                                                                                              |
| **9. ¿Qué es la sobrecarga de funciones en C++?**                                                    | Es la capacidad de definir múltiples funciones con el mismo nombre pero diferentes parámetros (diferentes firmas).                                                                                                                                                                                                            |
| **10. Diferencia entre una variable local y una local estática**                                     | **Local**: Se destruye cuando la función termina. **Estática local**: Conserva su valor entre llamadas a la función.                                                                                                                                                                                                          |
| **11. ¿Qué es type casting en C++? ¿Cuáles existen? Proporcione ejemplos.**                          | Es la conversión de un tipo de dato a otro. Ejemplos: `static_cast<int>(3.14)`, `reinterpret_cast<int*>(ptr)`.                                                                                                                                                                                                                |
| **12. ¿Cuál es la diferencia entre un bucle ‘do-while’ y ‘while’?**                                  | **‘do-while’**: Ejecuta el bloque de código al menos una vez, independientemente de la condición. **‘while’**: Puede no ejecutarse si la condición es falsa desde el principio.                                                                                                                                               |
| **13. ¿Cómo se puede dividir el código de un programa en los archivos `.hpp`, `.cpp` y `main.cpp`?** | **.hpp**: Declaraciones de funciones y clases. **.cpp**: Implementación de funciones. **main.cpp**: Contiene la función principal (`main`) y la lógica del programa.                                                                                                                                                          |
| **14. ¿Qué es la sentencia ‘goto’? ¿Cuáles son las alternativas?**                                   | **goto**: Permite saltar a una etiqueta específica en el código. **Alternativas**: Usar estructuras de control como `for`, `while`, `if-else`.                                                                                                                                                                                |
| **15. ¿Qué es la directiva ‘#ifndef’ en C++?**                                                       | Evita la inclusión múltiple de un archivo de encabezado. Si no está definido, el código dentro del bloque se ejecuta.                                                                                                                                                                                                         |
| **16. ¿Qué es un puntero en C++? ¿Cómo se declara e inicializa?**                                    | Un puntero almacena la dirección de memoria de una variable. Ejemplo: `int *ptr = &var;`.                                                                                                                                                                                                                                     |
| **17. ¿Cómo se pasan los parámetros a una función en C++? Por valor, por referencia y por puntero**  | **Por valor**: Se copia el valor del argumento. **Por referencia**: Se pasa la dirección de la variable. **Por puntero**: Se pasa un puntero que apunta a la dirección.                                                                                                                                                       |
| **18. ¿Cómo se utilizan los punteros para apuntar a un arreglo en C++?**                             | Se apunta al primer elemento del arreglo y se accede a los demás elementos mediante aritmética de punteros.                                                                                                                                                                                                                   |
| **19. ¿Qué es el operador ‘->’ en punteros?**                                                        | Se utiliza para acceder a los miembros de un objeto al que apunta un puntero a una estructura o clase.                                                                                                                                                                                                                        |
| **20. ¿Cómo se implementan punteros dobles, triples, etc., en C++?**                                 | Un puntero doble es un puntero que apunta a otro puntero, y se usa comúnmente en matrices dinámicas. Un puntero triple apunta a un puntero doble, y así sucesivamente.                                                                                                                                                        |
| **21. ¿Qué es el puntero `this` en C++?**                                                            | Es un puntero implícito que apunta al objeto actual dentro de un método de clase.                                                                                                                                                                                                                                             |
| **22. ¿Qué es el puntero `nullptr` en C++?**                                                         | Representa un puntero que no apunta a ninguna dirección de memoria válida. Es el valor por defecto para punteros no inicializados.                                                                                                                                                                                            |
| **23. ¿Qué es un prototipo de función en C++?**                                                      | Es una declaración de una función antes de su definición real, que informa al compilador sobre su existencia.                                                                                                                                                                                                                 |
| **24. ¿Cómo se almacenan las variables en memoria en C++?**                                          | **Locales**: Se almacenan en la pila. **Globales**: Se almacenan en el segmento de datos. **Estáticas**: Se almacenan en el segmento de datos y persisten entre llamadas.                                                                                                                                                     |
| **25. ¿Qué es un memory leak?**                                                                      | Es una fuga de memoria que ocurre cuando la memoria asignada dinámicamente no se libera, lo que puede agotar los recursos de memoria.                                                                                                                                                                                         |
| **26. ¿Qué es la memoria dinámica en C++?**                                                          | Es la memoria que se asigna en tiempo de ejecución usando `new` y debe ser liberada manualmente usando `delete`.                                                                                                                                                                                                              |
| **27. ¿Qué es la memoria estática en C++?**                                                          | Es la memoria que se asigna en tiempo de compilación y se libera automáticamente al final del programa.                                                                                                                                                                                                                       |

## Documentación oficial en:

[Click aquí](https://ie0217-gvdrnnm12-anthonys-projects-fc83cd10.vercel.app/index.html)

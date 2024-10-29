# Sesión 15: Depuración

## Descripción

La depuración es el proceso de identificar y corregir errores en el código, tanto en su ejecución como en su lógica, para asegurar que el programa funcione correctamente. Esta sesión cubre técnicas, herramientas y buenas prácticas esenciales para depurar eficazmente en entornos de desarrollo.

## Contenidos

### 1. Tipos de Errores

- **Errores de Sintaxis**: Ocurren cuando el código no sigue las reglas del lenguaje (ej., falta de `;` en C++).
- **Errores de Ejecución**: Se producen al intentar ejecutar el código, como dividir entre cero o accesos fuera de los límites de un array.
- **Errores Lógicos**: Cuando el código compila y se ejecuta sin errores, pero produce resultados incorrectos debido a fallos en la lógica.

### 2. Herramientas de Depuración

1. **Debuggers**:

   - **Descripción**: Los depuradores permiten pausar y controlar la ejecución del programa para observar su estado interno. Herramientas como `gdb` en C++ son populares y efectivas para depuración en línea de comandos.
   - **Uso común**:
     - Colocar puntos de interrupción (breakpoints) en el código para detener la ejecución en lugares específicos.
     - Inspeccionar el valor de variables en tiempo de ejecución.
     - Avanzar línea a línea para identificar el flujo y detectar errores.

2. **Sanitizers** (AddressSanitizer, ThreadSanitizer y UndefinedBehaviorSanitizer):

   - **Descripción**: Los sanitizers son herramientas integradas en compiladores como GCC y Clang que ayudan a detectar errores de memoria y comportamiento indefinido.
     - **AddressSanitizer (ASan)**: Detecta problemas de memoria como desbordamientos de búfer y uso de memoria después de liberarla.
     - **ThreadSanitizer (TSan)**: Detecta condiciones de carrera en aplicaciones multihilo.
     - **UndefinedBehaviorSanitizer (UBSan)**: Ayuda a identificar comportamientos indefinidos en el código.
   - **Ejemplo de uso**:

     ```bash
     # Compilar con AddressSanitizer
     g++ -fsanitize=address -g mi_programa.cpp -o mi_programa

     # Compilar con ThreadSanitizer
     g++ -fsanitize=thread -g mi_programa.cpp -o mi_programa

     # Compilar con UndefinedBehaviorSanitizer
     g++ -fsanitize=undefined -g mi_programa.cpp -o mi_programa
     ```

   - **Ventajas**: Estos sanitizers ofrecen un análisis profundo y detallado que ayuda a identificar errores difíciles de encontrar en tiempo de ejecución.

3. **Valgrind**:

   - **Descripción**: Valgrind es una herramienta para detectar fugas de memoria y errores de uso de memoria. Es ideal para encontrar problemas como acceso a memoria no inicializada y fugas de memoria.
   - **Ejemplo de uso**:
     ```bash
     valgrind --leak-check=full ./mi_programa
     ```
   - **Ventajas**: Proporciona información detallada sobre el uso de la memoria y ayuda a depurar problemas de asignación y liberación.

4. **Helgrind**:

   - **Descripción**: Helgrind es una herramienta de Valgrind diseñada para detectar condiciones de carrera en aplicaciones multihilo.
   - **Ejemplo de uso**:
     ```bash
     valgrind --tool=helgrind ./mi_programa
     ```
   - **Ventajas**: Facilita la identificación de problemas de concurrencia, como condiciones de carrera, que pueden ser difíciles de detectar y reproducir.

5. **Print Statements**:
   - **Descripción**: Una técnica básica de depuración que consiste en insertar declaraciones de impresión (`std::cout` en C++, `console.log` en JavaScript, etc.) en puntos clave del código.
   - **Uso común**:
     - Imprimir el valor de variables para ver cómo cambian en el flujo del programa.
     - Ayuda a seguir el flujo de ejecución y verificar que se están ejecutando las partes esperadas del código.

### 3. Técnicas de Depuración

- **Breakpoints (Puntos de Interrupción)**: Marcas en el código donde la ejecución se detiene para examinar el estado del programa.
- **Step Over, Step Into y Step Out**: Herramientas de ejecución en los depuradores para avanzar en el código.
- **Inspección de Variables**: Revisar el valor de las variables en tiempo de ejecución para verificar que contengan datos esperados.

### 4. Estrategias de Depuración

- **Aislamiento de Código**: Enfocarse en secciones específicas del código para identificar en qué punto ocurre el error.
- **Pruebas Unitarias**: Crear pruebas automáticas que ayuden a detectar errores de lógica y facilitar la depuración de funciones aisladas.
- **Seguimiento del Flujo de Datos**: Analizar cómo se pasa y transforma la información entre funciones o métodos para encontrar discrepancias.

### 5. Buenas Prácticas para Depurar

- **Leer Mensajes de Error**: Los mensajes de error suelen dar pistas valiosas sobre el origen del problema.
- **Revisar los Casos de Esquina**: Probar el código con valores inusuales o límites para descubrir errores en casos específicos.
- **Usar Versionado de Código**: Herramientas como Git permiten regresar a versiones previas del código cuando surgen errores después de cambios recientes.

### 6. Ejemplo de Depuración en `gdb`

```bash
# Compilar el programa con la bandera -g para generar información de depuración
g++ -g mi_programa.cpp -o mi_programa

# Iniciar gdb con el ejecutable
gdb ./mi_programa

# Dentro de gdb, colocar un breakpoint
(gdb) break main

# Ejecutar el programa dentro de gdb
(gdb) run

# Visualizar el valor de una variable
(gdb) print nombre_variable

# Continuar con el siguiente paso
(gdb) next
```

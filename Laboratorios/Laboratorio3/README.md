# Laboratorio 03 IE0247

## En este laborario se puso en práctica el uso de clases, objetos, herencia, métodos virtuales y funciones amigas

### Herencia

En C++, la herencia es un mecanismo que permite crear una nueva clase (clase derivada) basada en una clase existente (clase base). En tu código:

- `EmpleadoMedioTiempo` y `EmpleadoTiempoCompleto` son clases derivadas de la clase base `Empleado`. Esto significa que ambas heredan atributos como `id`, `nombre`, y `salario`, así como métodos de la clase `Empleado`.

### Polimorfismo

El polimorfismo permite que una función o un método adopte diferentes comportamientos según el objeto que lo esté utilizando. En tu código:

- El método `getSalario` es declarado como `virtual` en la clase `Empleado`, lo que permite que las clases derivadas como `EmpleadoMedioTiempo` y `EmpleadoTiempoCompleto` puedan implementar su propia versión de `getSalario`. Esto es un ejemplo de polimorfismo en C++, ya que el método que se ejecutará dependerá del tipo de objeto al que se esté refiriendo, incluso si se accede a través de un puntero o referencia de la clase base.

### Métodos

Los métodos son funciones que pertenecen a una clase. Pueden manipular y acceder a los datos de los objetos de esa clase. Algunos aspectos importantes:

- `Empleado` tiene métodos como `setNombre`, `getNombre`, `setId`, y `getId`, que permiten manipular y acceder a los atributos `nombre` e `id`.
- `EmpleadoMedioTiempo` y `EmpleadoTiempoCompleto` tienen métodos adicionales como `setHorasTrabajadas`, `setTarifaPorHora`, `setBonificacion`, y `setDeduccion`, que permiten ajustar atributos específicos de cada tipo de empleado.

### Clases Abstractas

Una clase abstracta es una clase que no puede ser instanciada directamente y está destinada a ser una base para otras clases. Tiene al menos un método virtual puro (un método que se iguala a `0`).

- `Empleado` es una clase abstracta porque tiene un método virtual puro `mostrarInformacion`, lo que obliga a cualquier clase derivada a implementar este método. Esto asegura que cualquier clase que herede de `Empleado` debe proporcionar su propia implementación del método `mostrarInformacion`.

### Métodos Virtuales

Un método virtual es una función que se puede sobrescribir en una clase derivada. Si una clase base define un método como `virtual`, se asegura que la versión del método que se ejecuta será la de la clase derivada, no la de la clase base.

- `getSalario` y `mostrarInformacion` son métodos virtuales en `Empleado`. Esto permite que `EmpleadoMedioTiempo` y `EmpleadoTiempoCompleto` proporcionen sus propias implementaciones específicas de estos métodos.

### Funciones Amigas

Las funciones amigas son funciones que no forman parte de una clase, pero tienen acceso a sus datos privados y protegidos. Son útiles para operaciones que requieren acceso a la implementación interna de una clase.

- La función `compararSalario` es una función amiga de `Empleado`, lo que significa que puede acceder a los atributos privados y protegidos de los objetos `Empleado` para comparar sus salarios.
- También, el operador `<<` es sobrecargado como una función amiga, permitiendo que se pueda utilizar `cout` para imprimir la información de un `Empleado`.

## Instrucciones de Compilación y Ejecución

## Compilación y Ejecución en Linux

1. **Instala `g++`**: Asegúrate de tener `g++` instalado. Puedes instalarlo usando el siguiente comando:

   ```bash
   sudo apt-get install g++
   ```

2. **Compila el programa**: Ejecuta el siguiente comando desde el directorio raíz del proyecto:

   ```bash
   g++ -o main.o main.cpp ./src/EmpleadoTiempoCompleto.cpp ./src/EmpleadoMedioTiempo.cpp ./src/Empleado.cpp
   ```

3. **Ejecuta el programa**: Una vez compilado, puedes ejecutar el programa con:
   ```bash
   ./main.o
   ```

## Compilación y Ejecución en Windows

1. **Instala `g++`**: Asegúrate de tener `g++` instalado, por ejemplo, a través de MinGW o MSYS2. Puedes descargar e instalar MinGW desde [MinGW](http://www.mingw.org/) o MSYS2 desde [MSYS2](https://www.msys2.org/).

2. **Compila el programa**: Abre Command Prompt o PowerShell y navega al directorio raíz del proyecto. Luego, ejecuta el siguiente comando:

   ```bash
   g++ -o main.exe main.cpp ./src/EmpleadoTiempoCompleto.cpp ./src/EmpleadoMedioTiempo.cpp ./src/Empleado.cpp
   ```

3. **Ejecuta el programa**: Una vez compilado, puedes ejecutar el programa con:
   ```bash
   main.exe
   ```

## Notas

- Asegúrate de que el compilador `g++` esté en tu PATH para poder ejecutarlo desde la línea de comandos.
- Si encuentras errores durante la compilación, revisa que todos los archivos fuente estén en las rutas especificadas y que el código fuente esté libre de errores.

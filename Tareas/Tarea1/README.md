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

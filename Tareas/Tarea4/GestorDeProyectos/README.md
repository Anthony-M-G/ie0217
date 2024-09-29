# Gestor de Proyectos de Construcción

Este programa simula un gestor de proyectos de construcción que permite manejar múltiples proyectos, cada uno con sus propias tareas. El sistema permite agregar y eliminar proyectos, añadir tareas a los proyectos, ordenar las tareas según diferentes criterios, y realizar análisis sobre las tareas y proyectos.

## Requisitos

- C++11 o superior
- Make (para Linux) o MinGW con Make (para Windows)

## Compilación

### En Linux:

1. Abra una terminal en el directorio del proyecto.
2. Ejecute el siguiente comando:

```bash
make
```

Esto generará un ejecutable llamado `main_gestor`.

### En Windows:

1. Asegúrese de tener MinGW instalado y configurado en su PATH.
2. Abra una terminal (Command Prompt o PowerShell) en el directorio del proyecto.
3. Ejecute el siguiente comando:

```cmd
mingw32-make
```

Esto generará un ejecutable llamado `main_gestor.exe`.

## Ejecución

### En Linux:

Para ejecutar el programa, use el siguiente comando:

```bash
./main_gestor
```

### En Windows:

Para ejecutar el programa, use el siguiente comando:

```cmd
main_gestor.exe
```

## Limpieza

Para eliminar los archivos objeto y el ejecutable:

### En Linux:

```bash
make clean
```

### En Windows:

```cmd
mingw32-make clean
```

## Uso

Al iniciar el programa, se mostrará un menú con las siguientes opciones:

1. Agregar un nuevo proyecto.
2. Agregar una tarea a un proyecto existente.
3. Eliminar una tarea de un proyecto.
4. Ordenar tareas por costo, tiempo o prioridad.
5. Mostrar el resumen de un proyecto (número de tareas, costo total y tiempo total).
6. Eliminar un proyecto.
7. Salir del programa.

Siga las instrucciones en pantalla para interactuar con el programa.

## Estructura del Proyecto

- `src/`: Contiene los archivos fuente (.cpp) y de cabecera (.hpp)
  - `main.cpp`: Punto de entrada del programa
  - `BaseTarea.cpp` y `BaseTarea.hpp`: Definición e implementación de la clase base para tareas
  - `Proyecto.cpp` y `Proyecto.hpp`: Definición e implementación de la clase Proyecto
  - `NotFoundException.cpp` y `NotFoundException.hpp`: Definición e implementación de la excepción personalizada
  - `GestorDeProyectos.cpp` y `GestorDeProyectos.hpp`: Definición e implementación de la clase GestorDeProyectos
- `Makefile`: Archivo para compilar el proyecto
- `README.md`: Este archivo

## Características

- Uso de templates para manejar diferentes tipos de tareas
- Manejo de excepciones para datos inválidos
- Uso de la STL (Standard Template Library) para gestionar colecciones de datos
- Ordenamiento de tareas por costo, tiempo y prioridad
- Cálculo de costos y tiempos totales de proyectos

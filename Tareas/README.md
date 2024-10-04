# Tarea 4 - IE-0217

Este repositorio contiene la implementación de la Tarea 4 del curso **Estructuras Abstractas de Datos y Algoritmos para Ingeniería (IE-0217)** de la Universidad de Costa Rica.

## Respuestas parte teórica:

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

La documentación generada por Doxygen está ubicada en la carpeta `doxydoc/html`. Para visualizarla, abre el archivo `index.html` en un navegador.

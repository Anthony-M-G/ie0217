# Sesión 3

Esta sesión incluye archivos de código C++ en los que se practican temas como:

- funciones con paso de parámetros por valor, referencia y puntero, también el uso de punteros para manejo de direcciones de memoria y la derreferenciación para acceder al valor ubicado en la direccion en memoria que apunta.
- El uso de arrays y acceso a sus valores mediante punteros
- La conversión de tipo de datos
- Las structuras y como acceder a sus propiedades con el operador "." y tambien con el operador flecha "->" mediante un puntero que tenga la dirección en memoria de la estructura.
- El uso de punteros dobles para tener punteros que apunten a otro puntero.

## Requisitos

Para compilar y ejecutar los archivos C++, necesitas tener instalado:

- Un compilador de C++, como **g++** (parte de GCC en sistemas Linux/Unix o disponible en MinGW para Windows).
- Un editor de texto o IDE como Visual Studio Code, CLion, o cualquier otro de tu preferencia.

## Compilación y Ejecución

### 1. Clonar el repositorio

Si aún no has clonado este repositorio, hazlo con el siguiente comando:

```bash
git clone https://github.com/Anthony-M-G/ie0217.git
cd proyecto-cpp
```

### 2. Pasos para la compilación de un archivo

```bash
g++ -o [nombre-para-ejecutable] [nombre-archivo].cpp
```

Para ejecutarlo debes estar en la carpeta donde se creó el ejecutable:

```bash
user@user:~/ruta$ ./[nombre-del-ejecutable]
```

Para entorno Windows:

```bash
g++ -o [nombre-para-ejecutable].exe [nombre-archivo].cpp
```

Ejecución:

```bash
C:\Users\user>./[nombre-del-ejecutable].exe
```

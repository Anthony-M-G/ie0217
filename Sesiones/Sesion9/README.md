# Sesión 9: Expresiones Regulares y Makefile en C++

En esta sesión se exploran dos temas clave en el desarrollo de proyectos con C++: **Expresiones Regulares** y el uso de **Makefile** en entornos Linux. Las expresiones regulares permiten trabajar con patrones en cadenas de texto, mientras que los Makefiles facilitan la automatización de la compilación y la gestión de proyectos grandes.

## Contenidos

- **Expresiones Regulares en C++**: Cómo utilizar la librería `<regex>` para buscar y manipular cadenas de texto mediante patrones.
- **Makefile**: Cómo automatizar la compilación de proyectos en Linux usando Makefile.

## Expresiones Regulares en C++

Las **expresiones regulares** son patrones que permiten realizar búsquedas y manipulaciones en cadenas de texto. C++ proporciona la librería `<regex>`, que ofrece potentes herramientas para trabajar con estas expresiones.

### Ejemplo de uso

A continuación, un ejemplo sencillo que busca palabras que comienzan con una letra mayúscula en una cadena de texto:

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string texto = "Hola Mundo, Bienvenidos a C++!";
    std::regex patron("[A-Z][a-z]+");
    std::smatch coincidencias;

    while (std::regex_search(texto, coincidencias, patron)) {
        std::cout << "Coincidencia: " << coincidencias[0] << std::endl;
        texto = coincidencias.suffix().str();
    }

    return 0;
}
```

En este ejemplo, se busca cualquier palabra que comience con una letra mayúscula, como "Hola" y "Mundo", y se imprimen las coincidencias encontradas.

## Instrucciones de Uso del Makefile

### Módulo Biblioteca

1. Abre una terminal y navega al directorio `Biblioteca`.
2. Ejecuta el comando `make` para compilar el proyecto.
3. El ejecutable `main_biblioteca` se generará en el directorio raíz del proyecto.
4. Para limpiar los archivos generados, ejecuta `make clean`.

### Módulo Estudiantes

1. Abre una terminal y navega al directorio `Estudiantes`.
2. Ejecuta el comando `make` para compilar el proyecto.
3. El ejecutable `estudiantes` se generará en el mismo directorio.
4. Para limpiar los archivos generados, ejecuta `make clean`.

## Requisitos

- Compilador de C++ (`g++` recomendado).
- Sistema operativo Linux o cualquier entorno compatible con Make.

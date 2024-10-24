# Sistema de Red Social

Este proyecto implementa un sistema de red social utilizando C++ y MongoDB Atlas.

## Requisitos Previos

- Driver MongoDB C++ (mongocxx) versión 3.10.0 o superior
- CMake
- Cuenta en MongoDB Atlas con una base de datos creada
- String de conexión a MongoDB Atlas (se proporcionará en el código)

## Compilación del Proyecto

1. Crear y entrar al directorio de compilación:

```bash
mkdir build
cd build
```

2. Generar archivos de compilación con CMake:

```bash
cmake ..
```

3. Compilar el proyecto:

```bash
make
```

4. Ejecutar el programa:

```bash
./main
```

## Estructura del Proyecto

```
.
├── CMakeLists.txt
├── Doxyfile
├── README.md
├── includes
│   ├── controlador
│   │   └── PostsController.h
│   ├── database
│   │   └── MongodbConn.h
│   └── servicios
│       └── PostsServices.h
├── index.md
├── main.cpp
└── src
    ├── controlador
    │   └── PostsController.cpp
    ├── database
    │   └── MongodbConn.cpp
    └── servicios
        ├── PostsServices.cpp
        └── Utils.h
```

El proyecto sigue una arquitectura de tres capas:

- **Controlador**: Maneja la lógica de control y las interacciones con el usuario
- **Servicios**: Implementa la lógica de negocio de las publicaciones
- **Database**: Gestiona la conexión y operaciones con MongoDB Atlas

## Ejemplo de Ejecución

Al ejecutar el programa, se presenta un menú interactivo con las siguientes opciones:

```
Conexión a MongoDB establecida.
----- MENU RED SOCIAL -----
1. Ver todas las publicaciones
2. Insertar una nueva publicación
3. Ver publicaciones por autor
4. Ver publicaciones ordenadas por fecha
5. Agregar un comentario a una publicación
6. Actualizar el contenido de una publicación
7. Eliminar una publicación por autor y fecha
8. Marcar una publicación como destacada
9. Salir
```

Al seleccionar la opción 1 (Ver todas las publicaciones), se muestra algo como esto (Apolo y theo son mis perros jaja):

```
{
Autor: Antony
Contenido: Contenido actualizado
Fecha: 23/10/2024
Comentarios:[
{
    Usuario: Apolo
    Contenido: tqm, Antony
    Fecha: 23/10/2024
},
]}
--------------------------------
{
Autor: Theo
Contenido: Holaa, soy teooo
Fecha: 23/10/2024
Comentarios:[
{
    Usuario: Antony
    Contenido: Teo teo te amooo
    Fecha: 23/10/2024
},
{
    Usuario: Jime
    Contenido: Teooooo, mi bebeeee
    Fecha: 23/10/2024
},
]}
```

## Documentación

[aquí]()

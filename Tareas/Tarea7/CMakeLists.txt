# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Tarea7)

# Agregar los archivos fuente del proyecto
set(SOURCES src/Componente.cpp src/CalculoCircuitos.cpp)

add_library(main_lib ${SOURCES})

# Crear el ejecutable para el proyecto principal
add_executable(main ${SOURCES} main.cpp)

# Incluir GoogleTest como subdirectorio
add_subdirectory(googletest)  # Esto debería apuntar a la carpeta de GoogleTest que clonamos

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Agregar GoogleTest y configurar las pruebas
enable_testing()
add_subdirectory(tests)
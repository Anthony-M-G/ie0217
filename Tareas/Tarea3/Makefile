# Detectar el sistema operativo
OS := $(OS)

# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directorios
INCLUDE_ARBOLES = ArbolBinarioBusqueda/includes
SRC_ARBOLES = ArbolBinarioBusqueda/src
INCLUDE_LISTA = GestionListaCanciones/includes
SRC_LISTA = GestionListaCanciones/src

# Archivos fuente
ARBOLES_SOURCES = $(SRC_ARBOLES)/Arbol.cpp
LISTA_SOURCES = $(SRC_LISTA)/Cancion.cpp $(SRC_LISTA)/ListaCanciones.cpp

# Ejecutables
ifeq ($(OS),Windows_NT)
    EXEC_ARBOLES = main_arbol.exe
    EXEC_LISTA = main_lista_canciones.exe
    RM = del /Q /F
else
    EXEC_ARBOLES = main_arbol
    EXEC_LISTA = main_lista_canciones
    RM = rm -f
endif

# Reglas para compilar ambos ejecutables
all: $(EXEC_ARBOLES) $(EXEC_LISTA)

# Regla para compilar el ejecutable de main_arbol.cpp
$(EXEC_ARBOLES): main_arbol.cpp $(ARBOLES_SOURCES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_ARBOLES) main_arbol.cpp $(ARBOLES_SOURCES) -o $(EXEC_ARBOLES)

# Regla para compilar el ejecutable de main_lista_canciones.cpp
$(EXEC_LISTA): main_lista_canciones.cpp $(LISTA_SOURCES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_LISTA) main_lista_canciones.cpp $(LISTA_SOURCES) -o $(EXEC_LISTA)

# Limpiar archivos binarios
clean:
	$(RM) $(EXEC_ARBOLES) $(EXEC_LISTA)

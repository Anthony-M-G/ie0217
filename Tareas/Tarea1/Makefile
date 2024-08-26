# Makefile

# Detectar el sistema operativo
ifeq ($(OS), Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := Linux
endif

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -Iincludes -Wall -Wextra -std=c++17

# Directorios
INCLUDES_DIR = includes
SRC_DIR = src

# Archivos de origen
SRC_P1 = programa_uno.cpp $(SRC_DIR)/conversiones.cpp $(SRC_DIR)/convertidor.cpp
SRC_P2 = programa_dos.cpp $(SRC_DIR)/funciones_estadisticas.cpp $(SRC_DIR)/funcion_busqueda.cpp

# Archivos de objeto
OBJ_P1 = p1.o
OBJ_P2 = p2.o

# Ejecutables
EXE_P1 = programa_uno
EXE_P2 = programa_dos

# Definir las extensiones y comandos para cada SO
ifeq ($(DETECTED_OS), Windows)
    RM = del /F /Q
    EXE_P1 := $(EXE_P1).exe
    EXE_P2 := $(EXE_P2).exe
else
    RM = rm -f
endif

# Reglas para compilar los programas

all: $(EXE_P1) $(EXE_P2)

$(EXE_P1): $(SRC_P1)
	$(CXX) $(CXXFLAGS) -o $(EXE_P1) $(SRC_P1)

$(EXE_P2): $(SRC_P2)
	$(CXX) $(CXXFLAGS) -o $(EXE_P2) $(SRC_P2)

# Reglas para compilar los objetos

$(OBJ_P1): $(SRC_P1)
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_P1) $(SRC_P1)

$(OBJ_P2): $(SRC_P2)
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_P2) $(SRC_P2)

# Limpiar los archivos generados

clean:
	$(RM) $(OBJ_P1) $(OBJ_P2) $(EXE_P1) $(EXE_P2)

.PHONY: all clean

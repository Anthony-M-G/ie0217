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

# Ejecutables
EXE_P1 = programa_uno.o
EXE_P2 = programa_dos.o

# Definir las extensiones y comandos para cada SO
ifeq ($(DETECTED_OS), Windows)
    RM = del /F /Q
    EXE_P1 := $(EXE_P1).exe
    EXE_P2 := $(EXE_P2).exe
else
    RM = rm -f
endif

# Reglas para: compilar, ejecutar programa_uno, pedir números y ejecutar programa_dos

all: $(EXE_P1) $(EXE_P2)
	./$(EXE_P1)
	@echo "Introduce números separados por espacio:"
	@read nums; ./$(EXE_P2) $$nums

$(EXE_P1): $(SRC_P1)
	$(CXX) $(CXXFLAGS) -o $(EXE_P1) $(SRC_P1)

$(EXE_P2): $(SRC_P2)
	$(CXX) $(CXXFLAGS) -o $(EXE_P2) $(SRC_P2)

# Borrar los archivos generados

clean:
	$(RM) $(EXE_P1) $(EXE_P2)

.PHONY: all clean

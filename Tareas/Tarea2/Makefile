# Variables comunes
CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
INCLUDE_DIR = includes
OBJ_DIR = obj
TARGET = main

# Archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Detección del sistema operativo
ifeq ($(OS),Windows_NT)
    RM = del /Q
    RM_DIR = rmdir /S /Q
    MKDIR = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    EXE = .exe
else
    RM = rm -f
    RM_DIR = rm -rf
    MKDIR = mkdir -p $(OBJ_DIR)
    EXE = 
endif

# Objetivo por defecto
all: $(TARGET)$(EXE)

# Compilación del ejecutable
$(TARGET)$(EXE): $(OBJECTS) $(OBJ_DIR)/main.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(OBJ_DIR)/main.o

# Compilación de archivos de objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compilación de main.o
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c main.cpp -o $(OBJ_DIR)/main.o

# Crear directorio de objetos si no existe
$(OBJ_DIR):
	$(MKDIR)

# Limpiar los archivos generados
clean:
	$(RM) $(OBJ_DIR)/*.o
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(TARGET)$(EXE)

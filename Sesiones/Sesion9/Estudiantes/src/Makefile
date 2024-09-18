# Compilador a utilizar
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Nombre del ejecutable
TARGET = main_estudiantes

# Lista de archivos fuente
SOURCES = main.cpp Estudiante.cpp

# Archivos objeto a partir de archivos fuente
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal para compilar todo (target final)
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para compilar los archivos fuente en archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)


# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 # Reglas de compilación 
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/text_processor

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp) # Busca todos los archivos con extensión .cpp en el directorio src
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) # Convierte los archivos fuente en archivos objeto

# Reglas
all: $(TARGET) 

$(TARGET): $(OBJECTS) # Dependencias para el ejecutable final
	@mkdir -p $(BINDIR) # Crea el directorio bin si no existe
	$(CXX) $(CXXFLAGS) -o $@ $^ # Compila el ejecutable final

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp # Regla para compilar los archivos objeto
	@mkdir -p $(OBJDIR) # Crea el directorio obj si no existe
	$(CXX) $(CXXFLAGS) -c $< -o $@ # Compila los archivos objeto los simbolos $< y $@ representan las dependencias y el objetivo respectivamente

clean: # Regla para limpiar los archivos objeto y el ejecutable
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)

run: $(TARGET) # Regla para ejecutar el programa
	./$(TARGET) data/file1.txt

.PHONY: all clean run

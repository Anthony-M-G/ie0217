# Nombre del ejecutable
TARGET = main_biblioteca

# Carpeta donde se guardarán los archivos objeto
BUILD_DIR = build

# Compilador C++
CXX = g++

# Opciones de compilación: 
# -Wall para mostrar todas las advertencias, 
# -std=c++11 para usar el estándar C++11
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SRCS = src/Libro.cpp src/Biblioteca.cpp main.cpp

# Lista de archivos objeto, se reemplaza 'src/%.cpp' por 'build/%.o'
OBJS = $(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

# Regla principal (compilar el ejecutable)
# El objetivo por defecto es generar el ejecutable usando los objetos
all: $(TARGET)

# Regla para compilar cada archivo .cpp en su correspondiente .o
# El patrón '$(BUILD_DIR)/%.o' indica que se compila un .cpp en build/
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(BUILD_DIR)            # Crear el directorio build si no existe
	$(CXX) $(CXXFLAGS) -c $< -o $@    # Compilar el archivo fuente .cpp a .o

# Regla para generar el ejecutable
# Se usa la lista de archivos objeto (OBJS) para enlazarlos en el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Phony target: 'clean' no genera un archivo, solo ejecuta el comando
.PHONY: clean

# Regla para limpiar: elimina el directorio build y el ejecutable
clean:
	rm -r $(BUILD_DIR) $(TARGET)      # Eliminar los archivos generados


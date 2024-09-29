# Carpeta donde se guardarán los archivos objeto
BUILD_DIR = build

# Compilador C++
CXX = g++

# Opciones de compilación: 
# -Wall para mostrar todas las advertencias, 
# -std=c++11 para usar el estándar C++11
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SRCS = src/BaseTarea.cpp  src/Proyecto.cpp  src/NotFoundException.cpp src/GestorDeProyectos.cpp main.cpp

# Lista de archivos objeto, se reemplaza 'src/%.cpp' por 'build/%.o'
OBJS = $(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

# Regla principal (compilar el ejecutable)
# El objetivo por defecto es generar el ejecutable usando los objetos
# Ejecutables
ifeq ($(OS),Windows_NT)
    TARGET = main_gestor.exe
    RM = del /Q /F
else
    TARGET = main_gestor
    RM = rm -rf
endif

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

clean:
	$(RM) $(BUILD_DIR) main_gestor main_gestor.exe

# Carpeta donde se guardarán los archivos objeto
BUILD_DIR = build

# Compilador C++
CXX = g++

# Opciones de compilación: 
# -Wall para mostrar todas las advertencias, 
# -std=c++11 para usar el estándar C++11
CXXFLAGS = -Wall -std=c++20

# Lista de archivos fuente
SRCS = ProducerConsumer.cpp 

# Librerías a linkear
LIBS = -pthread
# Lista de archivos objeto, se reemplaza 'src/%.cpp' por 'build/%.o'
OBJS = $(SRCS:src/**/%.cpp=$(BUILD_DIR)/%.o)

# Regla principal (compilar el ejecutable)
# El objetivo por defecto es generar el ejecutable usando los objetos
# Ejecutables
ifeq ($(OS),Windows_NT)
    TARGET = main.exe
    RM = del /Q /F
else
    TARGET = main
    RM = rm -rf
endif

all: $(TARGET)

# Regla para compilar cada archivo .cpp en su correspondiente .o
# El patrón '$(BUILD_DIR)/%.o' indica que se compila un .cpp en build/
$(BUILD_DIR)/%.o: src/%.cpp
ifeq ($(OS),Windows_NT) # Si el sistema operativo es Windows
	@if not exist $(BUILD_DIR) MD $(BUILD_DIR)
else	# Si el sistema operativo es Linux
	@mkdir -p $(BUILD_DIR) 
endif
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LIBS)  

# Regla para generar el ejecutable
# Se usa la lista de archivos objeto (OBJS) para enlazarlos en el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	$(RM) $(BUILD_DIR) main main.exe metrics.txt


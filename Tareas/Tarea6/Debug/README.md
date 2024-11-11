Este archivo documenta el proceso de depuración y solución de problemas para el programa `DataProcessor.cpp`, el cual maneja datos de un array y utiliza hilos para el procesamiento concurrente.

## Descripción del Problema

El programa presentaba errores debido a un acceso incorrecto a la memoria causado por un error de rango en la función `populateData`. También se identificó la necesidad de verificar condiciones de carrera en el acceso concurrente a los datos compartidos.

## Pasos para la Solución

### 1. Compilación con la Bandera de Depuración

Primero, compilé el programa con la bandera `-g` para habilitar la información de depuración necesaria para el uso de `gdb`.

```bash
g++ -g -o DataProcessor DataProcessor.cpp
```

### 2. Depuración con `gdb`

Ejecuté `gdb` para identificar el problema inicial en la función `populateData` y revisé la inicialización de la clase `DataProcessor` en la siguiente línea:

```cpp
DataProcessor *processor = new DataProcessor(size);
```

En `gdb`, identifiqué un error de rango en `populateData` donde la condición del bucle `i <= size` provocaba un acceso fuera de los límites. Lo corregí cambiando el bucle a `i < size`:

```cpp
for (int i = 0; i < size; ++i) {
    data[i] = i * 10;
}
```

### 3. Verificación de Condiciones de Carrera con `-fsanitize=thread`

Para detectar posibles condiciones de carrera, utilicé `-fsanitize=thread` en la compilación para ejecutar el programa con el sanitizador de hilos:

```bash
g++ -g -fsanitize=thread -pthread -o data_processor DataProcessor.cpp
./data_processor
```

El sanitizador de hilos (`-fsanitize=thread`) ayudó a identificar la falta de sincronización en el acceso a `data` dentro de `processData`. Añadí un `std::mutex` y un `std::lock_guard` en `processData` para proteger el acceso concurrente:

```cpp
void processData() {
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < size; ++i) {
        data[i] *= 2;
    }
}
```

### 4. Verificación de Errores de Memoria con `valgrind`

Para verificar fugas y errores de memoria, ejecuté `valgrind`:

1. Compilé el programa sin la bandera `-fsanitize=thread`, ya que `valgrind` y `fsanitize` pueden generar conflictos:

   ```bash
   g++ -g -pthread -o data_processor DataProcessor.cpp
   ```

2. Ejecuté `valgrind` en el binario:

   ```bash
   valgrind --leak-check=full ./data_processor
   ```

`valgrind` confirmó que no había fugas de memoria significativas después de las correcciones.

### 5. Verificación de Condiciones de Carrera con `helgrind`

Por último, utilicé `helgrind`, una herramienta de `valgrind` para detectar condiciones de carrera en el código:

```bash
valgrind --tool=helgrind ./data_processor
```

`helgrind` verificó que, con el `mutex` agregado en `processData`, ya no había condiciones de carrera en el programa.

## Conclusión

Con el uso de `gdb`, `-fsanitize=thread`, `valgrind` y `helgrind`, se identificaron y solucionaron problemas de acceso a memoria y sincronización en el programa. Ahora el programa se ejecuta de manera segura y eficiente en un entorno concurrente.

## Herramientas Utilizadas

- **gdb**: Para analizar y corregir el error de rango en `populateData`.
- **Sanitizer (`-fsanitize=thread`)**: Para detectar condiciones de carrera.
- **valgrind**: Para verificar fugas de memoria.
- **helgrind**: Para confirmar la ausencia de condiciones de carrera.

## Compilación y Ejecución Final

Para compilar y ejecutar el programa corregido:

```bash
g++ -g -pthread -o data_processor DataProcessor.cpp
./data_processor
```

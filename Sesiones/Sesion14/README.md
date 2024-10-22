# Sesión 14 ie0247 Programación paralela y concurrente.

En esta sesión se vio la **programación paralela y concurrente** en C++ y cómo manejar procesos e hilos para optimizar el rendimiento de aplicaciones. La correcta gestión de recursos en sistemas multinúcleo y la sincronización entre hilos son fundamentales para evitar problemas comunes como las condiciones de carrera y los bloqueos.

### Contenidos

1. **Introducción a Procesos y Hilos**

   - **Procesos**: Son instancias independientes de un programa en ejecución. Cada proceso tiene su propio espacio de memoria, lo que garantiza aislamiento, pero hace más costosa la comunicación.
   - **Hilos**: Son unidades de ejecución dentro de un proceso que comparten el mismo espacio de memoria. Son más eficientes en cuanto a la gestión de recursos, pero requieren mecanismos de sincronización cuando acceden a datos compartidos.

2. **Concurrencia vs Paralelismo**

   - **Concurrencia**: Se refiere a la capacidad de gestionar múltiples tareas en progreso al mismo tiempo, pero no necesariamente ejecutándolas simultáneamente. Es útil en sistemas de un solo núcleo donde las tareas progresan en intervalos de tiempo superpuestos.
   - **Paralelismo**: Implica la ejecución simultánea de múltiples tareas en procesadores multinúcleo, donde cada tarea se asigna a un núcleo o hilo de hardware diferente, logrando una verdadera ejecución en paralelo.

3. **Manejo de Hilos en C++**

   - Uso de `std::thread` para crear hilos concurrentes en C++.
   - Implementación de mecanismos de sincronización como `std::mutex`, `std::lock_guard`, y `std::condition_variable` para evitar problemas de acceso concurrente.

4. **Sincronización de Hilos**

   - Para evitar condiciones de carrera, los hilos deben sincronizarse correctamente cuando acceden a recursos compartidos.
   - Los principales mecanismos de sincronización son:
     - **Mutex**: Garantiza que solo un hilo acceda a una sección crítica a la vez.
     - **Semáforos**: Controlan cuántos hilos pueden acceder a un recurso.
     - **Variables de Condición**: Permiten la coordinación entre hilos en función de ciertos eventos.

5. **Ejemplo de Productor-Consumidor**
   - Se incluye un ejemplo clásico de productor-consumidor donde varios productores generan tareas que son consumidas por otros hilos, utilizando un buffer compartido.

### Ejecución del Proyecto

Para compilar y ejecutar el ejemplo de sincronización de hilos, sigue estos pasos:

1. **Compilación**:
   Usa un compilador compatible con C++11 o superior (como `g++` o `clang++`):

   ```bash
   g++ -std=c++11 -pthread threads.cpp -o threads
   ```

2. **Ejecución**:
   Ejecuta el binario generado:
   ```bash
   ./threads
   ```

### Consideraciones Finales

- **Número de Hilos**: El rendimiento óptimo se alcanza ajustando el número de hilos al número de núcleos de la CPU y la naturaleza de las tareas.
- **Sincronización**: Es crucial utilizar mecanismos de sincronización adecuados para evitar condiciones de carrera y garantizar la coherencia de los datos en programas multihilo.

### Requisitos del Sistema

- Compilador con soporte para C++11 o superior.
- Sistema operativo que soporte programación multihilo (Linux, Windows, macOS).

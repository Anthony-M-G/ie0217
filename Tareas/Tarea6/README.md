# Tarea 06 ie0217

1. **Diferencias entre proceso e hilo en programación:**

   - **a. Diferencias en uso de memoria:** Un proceso tiene su propio espacio de memoria independiente, mientras que los hilos comparten el mismo espacio de memoria del proceso que los contiene.
   - **b. Tres características de los procesos:** (1) Independencia en el espacio de memoria, (2) aislamiento de fallos, (3) comunicación inter-procesos necesaria para compartir datos.
   - **c. Tres características de los hilos:** (1) Compartición de memoria, (2) creación y finalización rápidas, (3) comunicación interna sin necesidad de mecanismos externos.

2. **Multitarea y su funcionamiento:**

   - **a. Ejemplo:** La ejecución de un reproductor de música mientras se navega en la web.
   - **b. Mecanismos de comunicación:** Comunicación entre procesos (IPC), semáforos, colas de mensajes.

3. **Generación de un proceso paralelo:**

   - **a. División de tareas:** Las tareas se dividen en sub-tareas independientes que pueden ejecutarse simultáneamente en diferentes núcleos.
   - **b. Factores de eficiencia:** Carga del sistema, sincronización entre tareas, recursos disponibles.

4. **Funcionamiento de las tareas concurrentes:**

   - **a. Mecanismos de sincronización:** Mutex, semáforos, variables de condición.
   - **b. Desafíos comunes:** Condiciones de carrera, deadlocks, coherencia de datos.

5. **Diferencias entre multinúcleo y multiprocesador:** Un sistema multinúcleo tiene múltiples núcleos en un mismo chip, mientras que un sistema multiprocesador tiene múltiples chips de CPU.

6. **Diferencias entre memoria compartida y distribuida:** En la memoria compartida, todos los procesos acceden al mismo espacio de memoria, mientras que en la distribuida cada nodo tiene su propia memoria.

7. **Condición de carrera y problemas:** Ocurre cuando múltiples hilos acceden a datos compartidos simultáneamente sin control adecuado, causando resultados inconsistentes.

8. **Mecanismos para evitar condiciones de carrera:**

   - Ejemplos: Mutex, semáforos, monitores.
   - **Ejemplo en C++ usando Mutex:**
     ```cpp
     std::mutex mtx;
     mtx.lock();
     // Sección crítica
     mtx.unlock();
     ```

9. **Diferencias entre modelos de memoria compartida y paso de mensajes:** En memoria compartida, los hilos comparten el mismo espacio, mientras que en paso de mensajes, los datos se transfieren explícitamente entre procesos.

10. **Mecanismos de sincronización en C++:** Ejemplos incluyen `std::mutex`, `std::condition_variable`, `std::lock_guard`, y semáforos. Implementar con `std::mutex` para proteger secciones críticas.

11. **Costos de administración y creación de hilos:**

- **a. Recursos involucrados:** Tiempo de CPU, memoria, administración de pila.
- **b. Estrategias de optimización:** Pool de hilos, control de prioridad, reducir hilos innecesarios.

12. **Ventajas de herramientas de depuración:** Facilitan identificar y corregir errores rápidamente y analizar el flujo de ejecución.

13. **Definición y uso de breakpoint:** Es un punto de interrupción en el código que permite al programador analizar el estado del programa en un punto específico.

14. **Stepping en depuración y sus tipos:**

- **Step Over:** Ejecuta la siguiente línea sin entrar en funciones.
- **Step Into:** Entra en cualquier función llamada en la línea.
- **Step Out:** Sale de la función actual.

15. **Cinco comandos comunes de GDB:** `break`, `run`, `next`, `step`, `print`.

16. **Uso de Valgrind y Memcheck:** Valgrind es útil para detectar fugas de memoria; Memcheck detecta accesos indebidos a memoria.

17. **AddressSanitizer y ThreadSanitizer:**

- **a. AddressSanitizer:** Detecta desbordamiento de buffer, acceso a memoria no inicializada.
- **b. ThreadSanitizer:** Detecta condiciones de carrera y errores de sincronización.

18. **Paralelismo a nivel de datos vs. tareas:**

- Ejemplo de datos: Procesamiento de una matriz en paralelo.
- Ejemplo de tareas: Ejecución simultánea de diferentes algoritmos.

19. **Balanceo de carga en sistemas paralelos:**

- **a. Estrategias:** Distribución estática, dinámica, robín redondo.
- **b. Efecto de mal balanceo:** Causaría cuellos de botella y baja eficiencia.

20. **Importancia del orden de ejecución de hilos:**

- **a. Errores posibles:** Deadlocks, condiciones de carrera.
- **b. Ejemplo de error:** Dos hilos esperando liberación de recursos en orden inverso.

21. **Barreras en programación paralela:**

- **a. Ejemplo:** Sincronización de hilos antes de una etapa.
- **b. Beneficios y desafíos:** Sincronización, pero puede causar ineficiencia si algunos hilos son más lentos.

22. **Identificación de fugas de memoria en programas paralelos:**

- **a. Herramientas:** Valgrind, AddressSanitizer.
- **b. Uso de Valgrind:**
  ```bash
  valgrind --leak-check=full ./programa
  ```

23. **Impacto de semáforos en rendimiento:**

- **a. Diferencias:** Semáforo binario permite acceso único, semáforo contado permite múltiples accesos.

24. **Herramienta para detectar accesos indebidos:** Valgrind con Memcheck para detectar estos errores.

25. **Herramienta para 'use-after-free':** AddressSanitizer también ayuda a detectar estos errores.

26. **Herramienta para depurar multihilo con bloqueos:** ThreadSanitizer para analizar deadlocks y condiciones de carrera.

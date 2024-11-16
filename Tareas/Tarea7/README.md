# Tarea 7 - Estructuras Abstractas de Datos y Algoritmos para Ingeniería

## IE-0217

### Universidad de Costa Rica

## Parte Teórica

### 1. Objetivos principales del software testing

a) **Verificación y validación en software testing:**

- La verificación asegura que el software cumple con los requisitos especificados. Se enfoca en revisar si estamos construyendo el producto correctamente.
- La validación confirma que el software cumple con las necesidades del usuario. Se centra en verificar si estamos construyendo el producto correcto.

b) **Relación con la mejora de la calidad del software:**

- Ayuda a identificar y corregir defectos tempranamente
- Asegura que el código cumple con los estándares de calidad
- Mejora la mantenibilidad y confiabilidad del software
- Reduce la deuda técnica

c) **Contribución a la experiencia del usuario y reducción de costos:**

- Mejora la confiabilidad y estabilidad del software
- Reduce el tiempo de inactividad y problemas en producción
- Disminuye los costos de mantenimiento y soporte
- Aumenta la satisfacción del usuario al prevenir errores
- Los problemas se detectan y corrigen antes de llegar al usuario final

### 2. Concepto de "semilla" en software testing

a) **Aplicaciones y ejemplos específicos:**

1. Generación de datos de prueba aleatorios pero reproducibles
2. Pruebas de funciones que dependen de números aleatorios
3. Simulación de escenarios específicos para pruebas de stress

b) **Efectos en reproducibilidad y beneficios:**

- Permite reproducir exactamente las mismas condiciones de prueba
- Facilita la depuración al poder recrear escenarios específicos
- Ayuda en la documentación de casos de prueba
- Mejora la comunicación entre equipos al poder compartir semillas específicas

### 3. Etapas genéricas del software testing

a) **Las ocho etapas genéricas:**

1. Planificación de pruebas
2. Análisis de requisitos
3. Diseño de pruebas
4. Implementación de pruebas
5. Ejecución de pruebas
6. Evaluación de resultados
7. Reporte de defectos
8. Cierre del ciclo de pruebas

b) **Propósito de cada etapa:**

- Planificación: Define alcance, objetivos y recursos
- Análisis: Identifica qué debe probarse
- Diseño: Crea casos de prueba
- Implementación: Prepara el ambiente y datos
- Ejecución: Realiza las pruebas
- Evaluación: Analiza resultados
- Reporte: Documenta defectos
- Cierre: Verifica completitud y documenta lecciones aprendidas

c) **Etapas adicionales sugeridas:**

- Retroalimentación continua
- Automatización de pruebas
- Monitoreo post-implementación
- Análisis de métricas de calidad

### 4. Tipos de pruebas de software

a) **Cinco tipos principales:**

1. **Unit Testing:**

   - Objetivo: Probar componentes individuales
   - Aplicación: Durante el desarrollo
   - Escenarios: Desarrollo de nuevas funcionalidades

2. **Integration Testing:**

   - Objetivo: Probar interacción entre componentes
   - Aplicación: Después del unit testing
   - Escenarios: Sistemas modulares

3. **System Testing:**

   - Objetivo: Probar el sistema completo
   - Aplicación: Antes del release
   - Escenarios: Validación end-to-end

4. **Performance Testing:**

   - Objetivo: Evaluar rendimiento y escalabilidad
   - Aplicación: Sistemas en producción
   - Escenarios: Aplicaciones de alto tráfico

5. **Acceptance Testing:**
   - Objetivo: Validar requisitos del usuario
   - Aplicación: Antes del deployment
   - Escenarios: Entrega al cliente

### 5. Características y ventajas del unit testing

a) **Contribución al desarrollo ágil y TDD:**

- Facilita el desarrollo iterativo
- Permite refactorización segura
- Ayuda a mantener un diseño limpio y modular
- Documenta el comportamiento esperado del código
- Promueve el diseño orientado a pruebas

b) **Beneficios clave:**

1. **Para desarrolladores:**
   - Detección temprana de errores
   - Mayor confianza al realizar cambios
   - Documentación viva del código
2. **Para la calidad del software:**
   - Reducción de bugs en producción
   - Mejor diseño de código
   - Facilita la mantenibilidad

c) **Desafíos comunes y mitigación:**

- **Desafío**: Tiempo inicial de desarrollo
  _Mitigación_: Enfocarse en código crítico primero
- **Desafío**: Curva de aprendizaje
  _Mitigación_: Capacitación y mentorías
- **Desafío**: Mantenimiento de pruebas
  _Mitigación_: Buenas prácticas de diseño de pruebas

### 6. GoogleTest en unit testing

a) **Enfoques de revisión en pruebas unitarias:**

- ASSERT\_\* : Fallos fatales que detienen la ejecución
- EXPECT\_\* : Fallos no fatales que continúan la ejecución
- Test Fixtures: Para pruebas que comparten configuración
- Test Suites: Agrupación lógica de pruebas relacionadas

b) **Diferencias en efectividad y aplicación:**

- ASSERT es mejor para precondiciones críticas
- EXPECT es mejor para validaciones múltiples
- Fixtures mejoran la reusabilidad del código de prueba
- Suites organizan mejor las pruebas por funcionalidad

c) **Tipos de revisión según caso:**

- **Cálculos numéricos**: EXPECT_NEAR o EXPECT_DOUBLE_EQ
- **Cadenas de texto**: EXPECT_STREQ o EXPECT_STRCASEEQ

### 7. Functional Testing

a) **Definición y características principales:**

1. Valida el comportamiento funcional del software
2. Se enfoca en requisitos de negocio
3. Prueba el sistema desde la perspectiva del usuario

b) **Errores específicos identificables:**

- Flujos de trabajo incorrectos
- Problemas de integración
- Errores en la lógica de negocio
- Problemas de interfaz de usuario

c) **Diferencias con otras pruebas:**

- Unit Testing: Prueba componentes aislados
- System Testing: Prueba el sistema completo
- Functional Testing: Prueba funcionalidades específicas

### 8. Comandos en unit testing

a) **Binary Comparison:**

- `EXPECT_EQ(expected, actual)`: Comparación de igualdad
- `ASSERT_NE(val1, val2)`: Comparación de desigualdad
  _Uso_: Para comparaciones exactas de valores

b) **String Comparison:**

- `EXPECT_STREQ(str1, str2)`: Comparación exacta
- `EXPECT_STRCASEEQ(str1, str2)`: Comparación ignorando mayúsculas
  _Validaciones_: Contenido, longitud, formato

c) **Exception Assertions:**

- `EXPECT_THROW(statement, exception_type)`
- `ASSERT_ANY_THROW(statement)`
  _Uso_: Validar manejo de excepciones

d) **Predicate Assertions:**

- `EXPECT_PRED1(pred, val1)`
- `ASSERT_PRED2(pred, val1, val2)`
  _Beneficio_: Mensajes de error más descriptivos

e) **Floating-Point Comparison:**

- `EXPECT_NEAR(val1, val2, abs_error)`
- `EXPECT_DOUBLE_EQ(val1, val2)`
  _Uso_: Manejo de errores de redondeo

### 9. Coverage o Cobertura de código

a) **Definición:**
La cobertura de código mide qué parte del código fuente se ejecuta durante las pruebas.

b) **Tipos de cobertura:**

1. **Line Coverage**: Porcentaje de líneas ejecutadas
2. **Branch Coverage**: Porcentaje de ramas de decisión
3. **Function Coverage**: Porcentaje de funciones llamadas
4. **Condition Coverage**: Evaluación de condiciones booleanas

c) **Ejemplo de identificación de áreas no probadas:**

```cpp
int dividir(int a, int b) {
    if (b == 0) {        // Rama 1
        return -1;       // Línea posiblemente no probada
    }
    return a / b;        // Rama 2
}
```

### 10. Herramienta de Coverity y análisis estático de código

a) **Propósito de Coverity:**
El análisis estático de código con Coverity es una metodología sofisticada que examina el código fuente sin ejecutarlo, buscando potenciales defectos y vulnerabilidades. Coverity opera mediante el análisis semántico profundo del código, construyendo un modelo matemático del comportamiento del programa. Este modelo permite identificar:

- Defectos de seguridad (buffer overflows, SQL injection, etc.)
- Problemas de rendimiento
- Violaciones de mejores prácticas de programación
- Fugas de memoria y recursos
- Código muerto o inalcanzable
- Problemas de concurrencia

b) **Ventajas del análisis estático:**

1. **Detección temprana:**

   - Encuentra errores antes de la ejecución
   - Reduce costos de corrección
   - Mejora la calidad desde el inicio del desarrollo

2. **Escalabilidad:**

   - Analiza grandes bases de código eficientemente
   - Puede ejecutarse automáticamente en CI/CD
   - No requiere casos de prueba específicos

3. **Cobertura completa:**

   - Analiza todas las rutas de código posibles
   - Identifica casos extremos difíciles de probar
   - Examina código raramente ejecutado

4. **Eficiencia en recursos:**
   - No requiere tiempo de ejecución
   - Puede ejecutarse en código incompleto
   - Integración con IDEs para feedback inmediato

c) **Flujo de trabajo en Coverity:**

1. **Fase de escaneo:**

   - Compilación del código fuente
   - Análisis sintáctico y semántico
   - Construcción del modelo de comportamiento
   - Identificación de patrones problemáticos

2. **Fase de análisis:**

   - Clasificación de defectos por severidad
   - Análisis de rutas de ejecución
   - Verificación de falsos positivos
   - Generación de reportes detallados

3. **Fase de reporte:**

   - Documentación de hallazgos
   - Sugerencias de corrección
   - Priorización de issues
   - Seguimiento de métricas

4. **Fase de remediación:**
   - Asignación de defectos
   - Verificación de correcciones
   - Validación de cambios
   - Actualización de políticas de código

### 11. Continuous Integration (CI) y Continuous Delivery (CD)

a) **Conceptos detallados:**

**Continuous Integration (CI):**

- Práctica de desarrollo que requiere que los desarrolladores integren código en un repositorio compartido varias veces al día
- Cada integración se verifica mediante una construcción automatizada
- Incluye pruebas automatizadas para detectar problemas de integración rápidamente
- Fomenta la comunicación y colaboración entre equipo
- Reduce el tiempo de detección y corrección de errores
- Mejora la calidad del código mediante validaciones constantes

**Continuous Delivery (CD):**

- Extensión natural de CI que automatiza el proceso de entrega de software
- Asegura que el código puede ser desplegado de manera confiable en cualquier momento
- Incluye automatización de pruebas, configuración y despliegue
- Reduce el riesgo en los despliegues mediante procesos repetibles
- Permite entregas más frecuentes y confiables
- Mejora la satisfacción del cliente mediante actualizaciones continuas

b) **Diferencias fundamentales:**

1. **Alcance:**

   - CI se centra en la integración y pruebas automáticas
   - CD abarca todo el proceso hasta el despliegue

2. **Objetivos:**

   - CI busca detectar problemas de integración temprano
   - CD busca mantener el software siempre listo para producción

3. **Automatización:**

   - CI automatiza construcción y pruebas
   - CD automatiza además el despliegue y la configuración

4. **Frecuencia:**

   - CI ocurre varias veces al día
   - CD puede ocurrir diaria o semanalmente según necesidades

5. **Infraestructura:**
   - CI requiere servidor de integración
   - CD necesita además infraestructura de despliegue automatizado

c) **Características y beneficios:**

**Continuous Integration:**

1. **Detección temprana de errores:**

   - Reduce el tiempo de depuración
   - Minimiza conflictos de integración
   - Mejora la calidad del código

2. **Feedback rápido:**

   - Los desarrolladores conocen el impacto de sus cambios
   - Facilita la corrección inmediata
   - Mejora la comunicación del equipo

3. **Automatización de pruebas:**
   - Garantiza consistencia en las pruebas
   - Reduce errores humanos
   - Aumenta la cobertura de pruebas

**Continuous Delivery:**

1. **Despliegues confiables:**

   - Procesos repetibles y automatizados
   - Reduce errores de despliegue
   - Facilita rollbacks si es necesario

2. **Entregas más rápidas:**

   - Reduce tiempo al mercado
   - Facilita la experimentación
   - Mejora la competitividad

3. **Mejor calidad:**
   - Validación continua del producto
   - Detección temprana de problemas de producción
   - Mayor confianza en los releases

d) **Flujo de implementación CI/CD:**

1. **Fase de desarrollo:**

   - Desarrollo local
   - Control de versiones
   - Code review
   - Merge requests

2. **Fase de CI:**

   - Build automatizado
   - Ejecución de pruebas unitarias
   - Análisis de código estático
   - Generación de reportes

3. **Fase de pruebas:**

   - Pruebas de integración
   - Pruebas de sistema
   - Pruebas de aceptación
   - Validación de calidad

4. **Fase de preparación:**

   - Configuración de ambiente
   - Gestión de dependencias
   - Validación de seguridad
   - Preparación de despliegue

5. **Fase de despliegue:**
   - Despliegue automatizado
   - Validación post-despliegue
   - Monitoreo
   - Feedback y métricas
     ¡Claro! Aquí tienes respuestas más detalladas y explicadas para las preguntas teóricas a partir de la 12. Estas respuestas están diseñadas para ser claras, completas y útiles para el contexto académico.

### **12. Uso de GitHub en CI/CD**

**a. ¿Cómo facilita GitHub la integración continua y la entrega continua en el desarrollo de software?**

GitHub simplifica la implementación de CI/CD a través de su herramienta **GitHub Actions**, que permite a los desarrolladores automatizar flujos de trabajo relacionados con la compilación, pruebas y despliegue de software. Las principales maneras en las que GitHub facilita CI/CD son:

1. **Integración nativa con repositorios**:
   GitHub Actions está completamente integrado con el ecosistema de GitHub. Esto significa que cualquier evento, como `push`, `pull request`, o creación de etiquetas, puede activar workflows personalizados.

2. **Automatización de procesos repetitivos**:
   Mediante scripts definidos en YAML, se pueden configurar pipelines automatizados para compilar el código, ejecutar pruebas unitarias y realizar despliegues. Esto reduce el trabajo manual y mejora la eficiencia.

3. **Control de calidad continuo**:
   Los workflows de CI/CD permiten detectar errores en el código a medida que se hacen cambios, reduciendo problemas en producción.

4. **Compatibilidad multiplataforma**:
   GitHub Actions ofrece entornos virtuales preconfigurados para Linux, macOS y Windows, lo que facilita la ejecución de pipelines en diferentes plataformas.

5. **Colaboración y visibilidad**:
   Todos los miembros del equipo pueden ver el estado de los pipelines directamente en GitHub, facilitando la colaboración y el seguimiento de errores.

---

**b. Principales características de GitHub Actions en el contexto de CI/CD**

1. **Workflows automatizados**:
   Los workflows son procesos definidos en archivos YAML que se ejecutan en respuesta a eventos específicos (como `push` o `pull_request`). Estos workflows permiten automatizar tareas como pruebas y despliegues.

2. **Entornos virtuales**:
   GitHub Actions proporciona entornos preconfigurados con herramientas como CMake, Node.js, Python, Docker, etc., eliminando la necesidad de configuraciones manuales.

3. **Marketplace de acciones**:
   Una biblioteca de acciones predefinidas creadas por la comunidad permite reutilizar soluciones para tareas comunes (como subir artefactos, ejecutar linters o interactuar con plataformas externas).

4. **Integración con GitHub**:
   Ofrece acceso directo a información del repositorio, como cambios recientes, ramas y etiquetas, lo que facilita la automatización basada en eventos.

---

**c. Ventajas de GitHub Actions sobre otras herramientas de CI/CD**

1. **Integración sin problemas**:
   Al ser una herramienta nativa de GitHub, no requiere configuraciones adicionales para conectarse al repositorio. Todo está listo para usarse desde el principio.

2. **Costo y accesibilidad**:

   - Ofrece minutos gratuitos para repositorios públicos.
   - Es ideal para proyectos pequeños y medianos, eliminando la necesidad de herramientas externas como Jenkins o CircleCI.

3. **Flexibilidad**:

   - Permite personalizar completamente los workflows.
   - Soporta múltiples lenguajes de programación y plataformas.

4. **Marketplace integrado**:
   Proporciona acceso a miles de acciones listas para usar, reduciendo el tiempo necesario para configurar pipelines.

---

### **13. GitHub Actions: Pasos para configurar y utilizar**

**a. Componentes principales de un archivo de configuración de GitHub Actions**

Un archivo de configuración de GitHub Actions tiene tres componentes principales:

1. **Workflow**:

   - Es el nivel más alto y define todo el proceso automatizado.
   - Cada workflow está asociado a un archivo YAML.
   - Ejemplo: Ejecutar pruebas automáticamente en cada `push`.

2. **Jobs**:

   - Son conjuntos de pasos ejecutados en paralelo o secuencialmente en un entorno independiente.
   - Ejemplo: Un job puede compilar el código, y otro puede ejecutar pruebas.

3. **Steps**:
   - Son las acciones individuales dentro de un job.
   - Ejemplo: Un step puede instalar dependencias o ejecutar comandos específicos como `make`.

---

**b. Definición de Workflow, Job y Step**

- **Workflow**:
  Un flujo completo de tareas automatizadas, que puede incluir compilación, pruebas y despliegue.

  - Ejemplo:
    ```yaml
    name: CI Workflow
    on: push
    jobs:
      build-and-test:
        steps:
          - run: make
    ```

- **Job**:
  Conjunto de pasos que se ejecutan en un entorno virtual.
  - Ejemplo: Compilar código en Ubuntu.
- **Step**:
  Acciones específicas dentro de un job.
  - Ejemplo: Ejecutar `npm install`.

---

**c. Mejores prácticas para configurar GitHub Actions en proyectos colaborativos**

1. **Separar workflows por propósito**:

   - Ejemplo: Tener un workflow para pruebas y otro para despliegues.

2. **Reutilizar código**:

   - Usa plantillas o acciones comunes del Marketplace para evitar redundancia.

3. **Usar secretos**:

   - Almacena datos sensibles (como tokens de despliegue) en **Settings → Secrets**.

4. **Configurar notificaciones**:
   - Activa notificaciones para mantener a todo el equipo informado del estado de los pipelines.

---

### **14. Mocking y Stubbing en Unit Testing**

**Mocking y Stubbing** son técnicas utilizadas en pruebas unitarias para simular dependencias externas y aislar el código bajo prueba.

- **Mocking**:

  - Simula comportamientos de dependencias externas.
  - Permite verificar cómo el código interactúa con APIs, bases de datos, etc.
  - Ejemplo:
    ```cpp
    MockDatabase db;
    EXPECT_CALL(db, saveRecord).Times(1);
    ```
  - Útil para asegurarse de que una función llama correctamente a otra.

- **Stubbing**:
  - Proporciona respuestas predefinidas en lugar de ejecutar la lógica real.
  - Ejemplo: Devolver un objeto fijo en lugar de realizar una consulta SQL real.

Ambas técnicas son esenciales para:

1. Asegurar que el código sea probado en aislamiento.
2. Simular errores en dependencias externas para evaluar la resiliencia del sistema.

---

### **15. Diferencias entre Testing Manual y Testing Automatizado**

- **Testing Manual**:

  - Realizado por humanos, ideal para pruebas exploratorias y de experiencia de usuario (UX).
  - Desventajas: Propenso a errores humanos, más lento.

- **Testing Automatizado**:
  - Ejecutado por scripts o herramientas.
  - Ideal para pruebas repetitivas (unitarias, de regresión).
  - Ventajas: Más rápido, reduce errores, repetible.

---

### **16. Herramientas de Testing Automatizado**

1. **Selenium**:

   - Pruebas en navegadores.
   - Útil para aplicaciones web.

2. **GoogleTest**:

   - Excelente para C++.
   - Muy usado en sistemas embebidos.

3. **Postman**:

   - Pruebas de API.
   - Intuitivo y fácil de usar.

4. **Jest**:

   - Ideal para JavaScript y TypeScript.
   - Compatible con React y Node.js.

5. **JUnit**:
   - Pruebas en Java.
   - Soporte extendido para frameworks como Spring Boot.

## Proceso TDD: Capacitancia Equivalente Serie-Paralelo

### Descripción

Se implementó la función `capacitanciaEquivalenteSerieParalelo` para calcular la capacitancia combinada en serie y paralelo. El desarrollo siguió el enfoque de **Test-Driven Development (TDD)**.

### Pasos

1. **Diseño de pruebas**:

   - Casos considerados:
     - Capacitancias positivas (serie y paralelo).
     - Listas vacías.
     - Valores negativos (debe lanzar excepción).

2. **Ejecución inicial**:

   - Se ejecutaron las pruebas antes de implementar la función, confirmando fallos.

3. **Implementación**:

   - La función se implementó para satisfacer las pruebas definidas.

4. **Ejecución final**:
   - Todas las pruebas se ejecutaron exitosamente.

### Resultados

Las pruebas aseguran que la función:

- Calcula correctamente capacitancias combinadas.
- Maneja entradas inválidas mediante excepciones.
- Funciona adecuadamente con entradas vacías.

### Ejecución de pruebas

1. Generar el ejecutable de pruebas:
   ```bash
   cd build
    cmake ..
    make
    cd tests/
    ./run_tests
   ```

#### **Workflow de GitHub Actions**

1. **Activación del Workflow**:
   ```yaml
   on:
     push:
       branches:
         - main
     pull_request:
       branches:
         - main
   ```
   - **Evento `push`**: El workflow se ejecuta automáticamente cada vez que se realiza un `push` a la rama `main`.
   - **Evento `pull_request`**: También se ejecuta cuando se crea o actualiza un `pull request` hacia la rama `main`.

---

2. **Entorno del Job**:
   ```yaml
   jobs:
     build-and-test:
       runs-on: ubuntu-latest
   ```
   - **`runs-on`**: Especifica que el workflow se ejecutará en un entorno Ubuntu virtual, ideal para la compilación de proyectos en C++.

---

3. **Steps del Workflow**:
   Cada paso dentro del job `build-and-test` realiza una tarea específica:

---

#### **Steps definidos en el archivo**

1. **Clonar el repositorio**:
   ```yaml
   - name: Checkout code
     uses: actions/checkout@v2
   ```
   - Utiliza la acción de GitHub `actions/checkout` para clonar el código del repositorio. Esto asegura que los archivos del repositorio estén disponibles para los pasos siguientes.

---

2. **Instalar dependencias**:
   ```yaml
   - name: Install dependencies
     run: |
       sudo apt-get update
       sudo apt-get install -y build-essential cmake
   ```
   - **`sudo apt-get update`**: Actualiza la lista de paquetes disponibles.
   - **`sudo apt-get install`**: Instala herramientas necesarias:
     - `build-essential`: Conjunto de herramientas de compilación para C++.
     - `cmake`: Herramienta de configuración y construcción.

---

3. **Clonar GoogleTest**:
   ```yaml
   - name: Clone GoogleTest
     run: |
       git clone https://github.com/google/googletest.git Tareas/Tarea7/googletest
   ```
   - Clona la biblioteca GoogleTest dentro de la estructura del proyecto para ser utilizada en las pruebas unitarias.

---

4. **Compilar el proyecto**:
   ```yaml
   - name: Build project
     run: |
       cd ./Tareas/Tarea7
       mkdir -p build
       cd build
       cmake ..
       make
   ```
   - **`mkdir -p build`**: Crea el directorio de compilación.
   - **`cmake ..`**: Configura el proyecto con las definiciones de CMake en el directorio raíz.
   - **`make`**: Compila el proyecto.

---

5. **Ejecutar las pruebas unitarias**:
   ```yaml
   - name: Run tests
     run: |
       cd ./Tareas/Tarea7/build
       ctest --output-on-failure
   ```
   - **`ctest`**: Ejecuta las pruebas definidas en el proyecto y muestra los detalles de las pruebas fallidas en caso de errores.

---

### **Pasos resumidos del Workflow**

1. **Instalar dependencias**:

   - Herramientas de compilación (`build-essential`, `cmake`).

2. **Clonar GoogleTest**:

   - Incluir GoogleTest como biblioteca para pruebas.

3. **Compilar el proyecto**:

   - Crear un directorio de compilación, configurar con CMake y compilar con `make`.

4. **Ejecutar pruebas**:
   - Ejecutar las pruebas unitarias definidas en el proyecto con `ctest`.

---

### **Ejemplo de Ejecución**

1. **Subir cambios al repositorio**:
   - Haz un `push` o crea un `pull request` con tus actualizaciones.
2. **Ver el estado del Workflow**:
   - Ve a la pestaña **Actions** en GitHub y selecciona el pipeline correspondiente.
3. **Revisar resultados**:
   - Asegúrate de que todos los pasos se completen correctamente.

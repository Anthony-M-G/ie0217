# Sesión 8: Templates y Excepciones en C++

En esta sesión se exploran dos conceptos fundamentales en C++: **Templates** y **Excepciones**. Los templates permiten la programación genérica, mientras que las excepciones ofrecen una forma de manejar errores en tiempo de ejecución de manera estructurada.

## Contenidos

- **Templates**: Permiten crear clases y funciones genéricas que funcionan con diferentes tipos de datos.
- **Excepciones**: Mecanismo para manejar errores y situaciones excepcionales durante la ejecución del programa.

## Templates

Los **templates** en C++ son una característica que permite escribir código que puede trabajar con cualquier tipo de datos. Existen dos tipos principales: templates de funciones y templates de clases.

### Templates de Funciones

Un **template de función** permite definir una función genérica que puede operar con diferentes tipos de datos. Aquí hay un ejemplo simple:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

En este ejemplo, `max` es una función template que devuelve el valor máximo de dos argumentos, sin importar su tipo.

### Templates de Clases

Un **template de clase** permite definir una clase genérica. Por ejemplo:

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& element) {
        elements.push_back(element);
    }
    
    T pop() {
        if (elements.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
        T elem = elements.back();
        elements.pop_back();
        return elem;
    }
};
```

En este ejemplo, `Stack` es una clase template que funciona con cualquier tipo de dato.

## Excepciones

Las **excepciones** en C++ proporcionan una forma de manejar errores de manera estructurada mediante bloques `try`, `catch`, y `throw`. Esto permite que el flujo del programa se interrumpa cuando ocurre un error, y que se ejecute un código especial para manejar dicho error.

### Manejo Básico de Excepciones

Un bloque `try` se utiliza para encerrar el código que podría lanzar una excepción. Si ocurre una excepción, el flujo del programa se transfiere al bloque `catch` correspondiente.

```cpp
try {
    // Código que podría lanzar una excepción
    throw std::runtime_error("Error ocurrido");
} catch (const std::runtime_error& e) {
    // Código para manejar la excepción
    std::cerr << "Excepción: " << e.what() << '\n';
}
```

En este ejemplo, si se lanza una excepción de tipo `std::runtime_error`, el mensaje de error se captura y se muestra en la salida de error estándar.

### Creación de Excepciones Personalizadas

Puedes definir tus propias excepciones derivando de `std::exception`:

```cpp
class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Mi excepción personalizada";
    }
};
```

En este caso, `MyException` es una excepción personalizada que puedes lanzar y manejar de manera específica.

## Requisitos

- Compilador de C++ (como `g++` en Linux o `g++` en MinGW para Windows).
- Conocimientos básicos de C++ y de la terminal (Linux) o el símbolo del sistema (Windows).

## Instrucciones de Compilación

### En Linux

1. Abre una terminal.
2. Navega al directorio donde se encuentran los archivos `.cpp` del proyecto.
3. Compila el código usando `g++`:

   ```bash
   g++ -o nombre_ejecutable archivo.cpp
   ```

4. Ejecuta el programa:

   ```bash
   ./nombre_ejecutable
   ```

### En Windows

1. Abre una terminal.
2. Navega al directorio donde se encuentran los archivos `.cpp` del proyecto.
3. Compila el código usando `g++`:

   ```bash
   g++ -o programa.exe archivo.cpp
   ```

4. Ejecuta el programa:

   ```bash
   .\programa.exe
   ```

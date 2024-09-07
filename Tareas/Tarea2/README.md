# Sistema de Gestión de Tienda en Línea

Este programa simula un sistema de gestión para una tienda en línea, permitiendo manejar diferentes tipos de productos, clientes, y procesar compras.

## Requisitos

- C++ 11 o superior
- Make
- Mingw si el sistema operativo es Windows

## Compilación

Para compilar el programa, siga estos pasos:

1. Abra una terminal en el directorio del proyecto.
2. Ejecute el siguiente comando:

```
make
```

Esto compilará el programa y generará un ejecutable llamado `main`.

## Ejecución

Para ejecutar el programa, use el siguiente comando en la terminal:

```
./main
```

## Funcionalidades

El programa ofrece las siguientes opciones a través de un menú interactivo:

1. Agregar producto
   - Producto Digital
   - Producto Físico
2. Registrar cliente
   - Cliente Regular
   - Cliente Premium
3. Agregar producto al carrito
4. Procesar compra
5. Salir

## Estructura del Proyecto

- `src/`: Contiene todos los archivos fuente (.cpp)
- `includes/`: Contiene todos los archivos cabecera (.cpp)
- `Makefile`: Archivo para compilar el proyecto
- `README.md`: Este archivo

## Notas Adicionales

- Los clientes premium tienen un descuento especial que se aplica en el momento de procesar la compra.
- Los productos digitales tienen un ID único, mientras que los productos físicos tienen un peso asociado.
- El programa continuará ejecutándose hasta que se seleccione la opción de salir.

## Documentación

La documentación detallada del código, generada con Doxygen, está disponible en [enlace a la documentación en Netlify].

## Respuestas a las Preguntas Teóricas

1. ¿Qué es la programación orientada a objetos y cuáles son sus principios fundamentales?

La Programación Orientada a Objetos (POO) es un paradigma de programación que organiza el diseño de software en torno a datos u objetos, en lugar de funciones y lógica. Sus principios fundamentales son:

- Encapsulamiento: Ocultar los detalles internos de un objeto y exponer solo lo necesario.
- Abstracción: Simplificar sistemas complejos ocultando detalles innecesarios.
- Herencia: Permite que las clases hereden propiedades y métodos de otras clases.
- Polimorfismo: Permite que objetos de diferentes clases se traten como objetos de una clase base común.

2. Mencione y explique al menos tres problemas clásicos de programación que POO es capaz de resolver.

- Reutilización de código: La herencia permite reutilizar código de clases existentes.
- Mantenibilidad: El encapsulamiento facilita la modificación de partes del código sin afectar otras.
- Modelado del mundo real: La POO permite representar entidades del mundo real de manera intuitiva.

3. Describa el concepto de polimorfismo y brinde un ejemplo de su implementación en POO.

El polimorfismo permite que objetos de diferentes clases se traten como objetos de una clase base común. Por ejemplo:

```cpp
class Animal {
public:
    virtual void hacerSonido() = 0;
};

class Perro : public Animal {
public:
    void hacerSonido() override { cout << "Guau"; }
};

class Gato : public Animal {
public:
    void hacerSonido() override { cout << "Miau"; }
};

// Uso
Animal* animal1 = new Perro();
Animal* animal2 = new Gato();
animal1->hacerSonido(); // Imprime "Guau"
animal2->hacerSonido(); // Imprime "Miau"
```

4. Describa el concepto de abstracción y brinde un ejemplo de su implementación en POO.

La abstracción implica ocultar los detalles complejos y mostrar solo lo esencial. Por ejemplo:

```cpp
class Motor {
private:
    // Detalles complejos ocultos
    void inyectarCombustible() { /* ... */ }
    void comprimirMezcla() { /* ... */ }
    void generarChispa() { /* ... */ }

public:
    // Interfaz simple
    void arrancar() {
        inyectarCombustible();
        comprimirMezcla();
        generarChispa();
    }
};
```

5. Describa el concepto de encapsulamiento y brinde un ejemplo de su implementación en POO.

El encapsulamiento es el ocultamiento de los datos internos de un objeto, accesibles solo a través de métodos. Por ejemplo:

```cpp
class CuentaBancaria {
private:
    double saldo;

public:
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
        }
    }

    double obtenerSaldo() const {
        return saldo;
    }
};
```

6. Defina los conceptos de clase, objeto, método y atributo de la programación orientada a objetos y brinde un ejemplo de la vida real (No de programación) que los describa intuitivamente.

Usando un automóvil como ejemplo:

- Clase: Es como el plano o diseño del automóvil (por ejemplo, Toyota Corolla 2023).
- Objeto: Es un automóvil específico basado en ese diseño (por ejemplo, el Toyota Corolla de Juan).
- Atributos: Son las características del automóvil (color, número de puertas, velocidad actual).
- Métodos: Son las acciones que el automóvil puede realizar (acelerar, frenar, girar).

7. Mencione qué elementos tiene el "boilerplate" de una clase y explique cada uno.

El boilerplate de una clase típicamente incluye:

- Declaración de la clase: `class NombreClase { };`
- Especificadores de acceso: `public:`, `private:`, `protected:`
- Constructor(es): Para inicializar objetos de la clase
- Destructor: Para limpiar recursos cuando el objeto se destruye
- Métodos: Funciones miembro que definen el comportamiento de la clase
- Atributos: Variables miembro que almacenan el estado de la clase

8. ¿Qué es el constructor de una clase? ¿Para qué sirve?

El constructor es un método especial que se llama automáticamente cuando se crea un objeto de la clase. Sirve para inicializar los atributos del objeto y realizar cualquier configuración necesaria.

9. ¿Qué es instanciar un objeto en el contexto de POO? ¿Para qué sirve?

Instanciar un objeto es crear una ocurrencia específica de una clase. Sirve para utilizar la funcionalidad definida en la clase en un contexto específico, con sus propios datos y estado.

10. ¿Cuáles son las diferencias entre los especificadores de acceso públicos, privados y protegidos?

- Público: Accesible desde cualquier parte del programa.
- Privado: Accesible solo dentro de la misma clase.
- Protegido: Accesible dentro de la clase y sus clases derivadas.

11. ¿Qué es el destructor de una clase y para qué aplicaciones es conveniente usarlo?

El destructor es un método especial que se llama automáticamente cuando un objeto se destruye. Es conveniente usarlo para liberar recursos (memoria dinámica, archivos abiertos, conexiones de red) que el objeto haya adquirido durante su vida.

12. Explique qué es la sobrecarga de operadores y proporcione un ejemplo de cómo se implementa en C++.

La sobrecarga de operadores permite definir cómo se comportan los operadores con objetos de una clase. Ejemplo:

```cpp
class Complejo {
    double real, imag;
public:
    Complejo operator+(const Complejo& otro) {
        return Complejo(real + otro.real, imag + otro.imag);
    }
};
```

13. ¿Qué es la herencia en POO?

La herencia es un mecanismo que permite que una clase (derivada) herede atributos y métodos de otra clase (base), permitiendo la reutilización de código y la creación de jerarquías de clases.

14. Mencione las diferencias entre la herencia pública, privada o protegida de una clase, qué sucede al heredar cada tipo.

- Herencia pública: Los miembros públicos y protegidos de la clase base se mantienen públicos y protegidos en la clase derivada.
- Herencia protegida: Los miembros públicos y protegidos de la clase base se vuelven protegidos en la clase derivada.
- Herencia privada: Los miembros públicos y protegidos de la clase base se vuelven privados en la clase derivada.

15.

Para objetos de la clase Base:

Accesibles:

tercera (public)
segunda (protected)

No accesibles:

primera (private)
Variables de Derived (no pertenecen a esta clase)

Para objetos de la clase Derived:

Accesibles:

tercera, segunda (heredadas de Base)
sexta (public propia)
quinta (protected propia)

No accesibles:

primera (private de Base)
cuarta (private propia)

Razones:

Miembros public: accesibles desde cualquier parte.
Miembros protected: accesibles en la misma clase y sus derivadas.
Miembros private: accesibles solo dentro de la propia clase.
La herencia permite acceso a miembros public y protected de la clase base.

16. ¿Qué es una clase amiga y para qué se usa? ¿Cuál es la manera de definirla?

Una clase amiga es una clase que tiene acceso a los miembros privados y protegidos de otra clase. Se usa para permitir un acceso controlado a los detalles internos de una clase. Se define usando la palabra clave `friend` dentro de la clase que otorga el acceso.

17. ¿Qué es una función amiga y para qué se usa? ¿Cuál es la manera de definirla?

Una función amiga es una función que no es miembro de una clase pero tiene acceso a sus miembros privados y protegidos. Se usa para operaciones que necesitan acceso interno a múltiples clases. Se define usando la palabra clave `friend` seguida de la declaración de la función dentro de la clase.

18. Explique la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.

Los métodos virtuales son fundamentales para implementar el polimorfismo en C++. Permiten que una clase base defina un método que puede ser sobrescrito por las clases derivadas. Cuando se llama a un método virtual a través de un puntero o referencia a la clase base, se ejecuta la versión del método correspondiente al tipo real del objeto, no al tipo del puntero o referencia. Esto permite tratar objetos de diferentes clases derivadas de manera uniforme a través de una interfaz común.

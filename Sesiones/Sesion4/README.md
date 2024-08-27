# Sesión 4: Clases y Objetos en C++

**Clases**: Una clase es como un molde o plantilla que define las características y comportamientos comunes de un grupo de objetos. Por ejemplo, puedes tener una clase llamada **Animal** que describe las características que todos los animales comparten, como el número de patas o el tipo de comida que consumen.

**Objetos**: Un objeto es una instancia concreta de una clase. Si la clase **Animal** es la plantilla, un objeto sería un animal específico, como un **Perro**. Cada perro es un objeto que tiene características específicas basadas en la clase **Animal**.

**Atributos**: Los atributos son las propiedades o características de una clase. En la clase **Animal**, los atributos podrían ser el número de patas o el tipo de comida que come. Cada objeto de tipo **Animal** tendrá sus propios valores para estos atributos.

**Modificadores de Acceso**: Los modificadores de acceso controlan quién puede ver y modificar los atributos y métodos de una clase. Hay tres tipos principales:

- **public**: Cualquiera puede acceder.
- **private**: Solo la propia clase puede acceder.
- **protected**: Accesible por la clase y las clases derivadas.

**Métodos**: Los métodos son las acciones o comportamientos que un objeto puede realizar. Por ejemplo, un método en la clase **Animal** podría ser `hacerSonido()`, que define cómo un animal hace ruido.

**Métodos Virtuales**: Un método virtual permite que una clase derivada (como **Perro**) sobrescriba un método de la clase base (como **Animal**). Esto es útil cuando quieres que el método `hacerSonido()` tenga un comportamiento diferente según el tipo de animal.

**Polimorfismo**: El polimorfismo es la capacidad de un método de comportarse de diferentes maneras según el objeto que lo esté utilizando. Gracias a los métodos virtuales, un mismo método puede producir diferentes resultados dependiendo del objeto en el que se llame.

**Funciones y Clases Amigas**: Las funciones y clases amigas son aquellas que tienen acceso especial a los miembros privados de una clase. Si una clase necesita acceder a detalles internos de otra clase, puede ser declarada como amiga.

## Instrucciones de Compilación

### En Linux

1. Guarda tu código en un archivo con la extensión `.cpp`, por ejemplo, `main.cpp`.
2. Abre una terminal y navega hasta la carpeta donde guardaste el archivo.
3. Compila el código usando el comando:
   ```bash
   g++ -o programa main.cpp
   ```
4. Para ejecutarlo:

```bash
  ./programa
```

### En Windows

1. Guarda tu código en un archivo con la extensión `.cpp`, por ejemplo, `main.cpp`.
2. Abre una terminal y navega hasta la carpeta donde guardaste el archivo.
3. Compila el código usando el comando:
   ```bash
   g++ -o programa.exe main.cpp
   ```
4. Para ejecutarlo:

   ```bash
   .\programa.exe
   ```

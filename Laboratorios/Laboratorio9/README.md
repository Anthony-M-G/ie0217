# Laboratorio 09, ie0217

## Depuración gdb, valgrind y sanitizers

### Ejercicio 1

Para este ejercicio se utilizó el siguiente código:

```c
#include <iostream>
#include <vector>
#include <algorithm>

double calcularMedia(const std::vector<int>& numeros) {
    int suma = 0;
    for (int i = 0; i <= numeros.size(); i++) {
        suma += numeros[i];
    }
    return suma / numeros.size();
}

double calcularMediana(std::vector<int> numeros) {
    std::sort(numeros.begin(), numeros.end());

    int tam = numeros.size();
    if (tam % 2 == 0) {
        return (numeros[tam/2 - 1] + numeros[tam/2]) / 2;
    } else {
        return numeros[tam/2];
    }
}

int main() {
    std::vector<int> numeros = {1, 4, 8, 110, 33, 49};

    double media = calcularMedia(numeros);
    double mediana = calcularMediana(numeros);

    std::cout << "Media: " << media << std::endl;
    std::cout << "Mediana: " << mediana << std::endl;

    return 0;
}
```

El cual tenía un error en la función `calcularMedia` en el ciclo `for`, ya que el límite del ciclo era incorrecto. Para corregirlo, se cambió el operador `<=` por `<` en la línea 7 y se casteo el retorno de la función a `double` en la línea 11.

En la función `calcularMediana` se casteó el retorno de la función a `double` en la línea 27 y se encerró en paréntesis la suma de los elementos en la línea 23.

### Ejercicio 2

Para este ejercicio se utilizó el siguiente código:

```c
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[10];  // Asignación dinámica de memoria para un arreglo de 10 enteros

    // Inicialización del arreglo
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Mostrar los valores del arreglo
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



```

En este se usó valgrind para detectar errores de memoria, arrojando problemas de memoria no liberada. Para corregirlo, se liberó la memoria asignada al arreglo en la línea 5.

### Ejercicio 3

Para este ejercicio se utilizó el siguiente código:

```c
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // Asigna un arreglo de 5 enteros

    // Inicializa el arreglo
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    cout << "Valor fuera de límites: " << arr[10] << endl;

    delete[] arr;  // Libera la memoria asignada
    return 0;
}




```

El cual primero se compiló con el flag `-fsanitize=address` y luego se ejecutó. Se obtuvo un error de acceso a memoria no asignada. Para corregirlo, se cambió el índice del arreglo en la línea 10 por un índice válido.

### Ejercicio 4

Para este ejercicio se utilizó el siguiente código:

```c
#include <iostream>
#include <thread>

int contador = 0;

void incrementar() {
    for (int i = 0; i < 10000; i++) {
       contador++;
    }
}

int main() {
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout << "Valor final del contador: " << contador << std::endl;
    return 0;
}


```

El cual se compiló con el flag `-pthread` y se usó valgrind --tool=helgrind para detectar errores de concurrencia. Se obtuvo un error de concurrencia en la variable `contador`. Para corregirlo, se utilizó un mutex para proteger la variable `contador` y que no se acceda a ella de manera concurrente.

### Ejercicio 5

En este ejercicio se utilizó el mismo código anterior pero se compiló con el flag `-fsanitize=thread` y se ejecutó. Se obtuvo un error de concurrencia en la variable `contador`. Para corregirlo, se utilizó un mutex para proteger la variable `contador` y que no se acceda a ella de manera concurrente.

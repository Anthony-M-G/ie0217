#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP

#include <functional>

template <typename Container, typename Func> // Plantilla de función que recibe
                                             // un contenedor y una función de
                                             // procesamiento
void processText(Container &container,
                 Func processFunc) { // Función que recibe un contenedor y una
                                     // función de procesamiento como argumentos
  for (auto &element : container) {
    processFunc(element);
  }
}

#endif // TEXTPROCESSOR_HPP

#include <iostream>
#include <regex>     

int main() {
    // Definimos una expresión regular que busca la palabra "my" o "your" seguida de " regex"
    auto const regex = std::regex("(my|your) regex");

    // Comprobamos si la cadena 'myText' contiene la expresión regular
    auto const myText = std::string("A piece of text that contains my regex.");
    bool myTextContainsRegex = std::regex_search(myText, regex);  // Busca la coincidencia en 'myText'

    // Comprobamos si la cadena 'yourText' contiene la expresión regular
    auto const yourText = std::string("A piece of text that contains your regex.");
    bool yourTextContainsRegex = std::regex_search(yourText, regex);  // Busca la coincidencia en 'yourText'

    // Comprobamos si la cadena 'theirText' contiene la expresión regular
    auto const theirText = std::string("A piece of text that contains their regex.");
    bool theirTextContainsRegex = std::regex_search(theirText, regex);  // Busca la coincidencia en 'theirText'

    // Configuramos std::cout para que imprima booleanos como 'true' o 'false' en lugar de 1 o 0
    std::cout << std::boolalpha
              // Imprimimos si cada texto contiene la expresión regular
              << myTextContainsRegex << '\n'
              << yourTextContainsRegex << '\n'
              << theirTextContainsRegex << '\n';

    return 0;
}


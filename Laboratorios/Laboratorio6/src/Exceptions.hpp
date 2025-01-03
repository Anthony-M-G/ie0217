#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class FileNotFoundException
    : public std::runtime_error { // clase que hereda de runtime_error para
                                  // manejar excepciones relacionadas con
                                  // archivos no encontrados
public:
  explicit FileNotFoundException(const std::string &message)
      : std::runtime_error(message) {}
};

class ReadException
    : public std::runtime_error { // clase que hereda de runtime_error para
                                  // manejar excepciones relacionadas con la
                                  // lectura de archivos
public:
  explicit ReadException(const std::string &message)
      : std::runtime_error(message) {}
};

class RegexException
    : public std::runtime_error { // clase que hereda de runtime_error para
                                  // manejar excepciones relacionadas con
                                  // expresiones regulares
public:
  explicit RegexException(const std::string &message)
      : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_HPP

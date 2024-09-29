#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H
#include <exception>
#include <string>

/**
 * @class NotFoundException
 * @brief Clase de excepción para manejar casos donde un recurso no se
 * encuentra.
 *
 * Esta clase hereda de std::exception y se utiliza para señalar que un
 * recurso solicitado no pudo ser encontrado. Proporciona un mensaje de error
 * personalizado que se puede recuperar utilizando el método what().
 *
 * @note Esta excepción debe lanzarse cuando una búsqueda de recursos falla.
 *
 * @autor Antony
 * @fecha 2023
 */

class NotFoundException
    : public std::exception { // Clase para recursos no encontrados
public:
  NotFoundException(const std::string &message);

  virtual const char *what() const throw();

  ~NotFoundException() throw();

private:
  std::string message;
};
#endif // NOT_FOUND_EXCEPTION_H
#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H
#include <exception>
#include <string>

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
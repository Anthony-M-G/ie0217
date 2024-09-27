#include "../includes/NotFoundException.hpp"

// Implementación de la clase NotFoundException
NotFoundException::NotFoundException(const std::string &message)
    : message(message) {}

const char *NotFoundException::what() const throw() { return message.c_str(); }

NotFoundException::~NotFoundException() throw() {}

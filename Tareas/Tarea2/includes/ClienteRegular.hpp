#ifndef CLIENTE_REGULAR_HPP
#define CLIENTE_REGULAR_HPP
#include "Cliente.hpp"
class ClienteRegular : public Cliente
{
public:
  ClienteRegular(const string &t_nombre);

  double aplicarDescuento() const override;
};

#endif
#ifndef CLIENTE_PREMIUM_HPP
#define CLIENTE_PREMIUM_HPP
#include "Cliente.hpp"
class ClientePremium : public Cliente
{
private:
  double descuento;

public:
  ClientePremium(const string &t_nombre, double descuento);

  double aplicarDescuento() const override;

  void calcularTotal() const;
};

#endif
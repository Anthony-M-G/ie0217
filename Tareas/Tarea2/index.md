# Sistema de Gestión de Tienda en Línea

## Introducción

El **Sistema de Gestión de Tienda en Línea** es una aplicación desarrollada en C++ que simula la gestión de un carrito de compras en una tienda en línea. El sistema permite agregar productos al carrito de compras y procesar la compra, calculando el total a pagar considerando descuentos especiales para clientes premium.

## Objetivo

El objetivo principal del sistema es permitir a los usuarios:

- **Añadir Productos al Carrito**: Los clientes pueden seleccionar productos y agregarlos a su carrito de compras.
- **Procesar la Compra**: Calcula el total a pagar al finalizar la compra, aplicando descuentos para clientes premium si corresponde.

## Funcionalidades

El sistema incluye las siguientes funcionalidades:

- **Gestión de Productos**:

  - Permite agregar productos al carrito de compras.
  - Actualiza el stock de los productos según la cantidad añadida al carrito.

- **Carrito de Compras**:

  - Permite añadir y eliminar productos del carrito.
  - Calcula el total de la compra, aplicando descuentos para clientes premium.

- **Procesamiento de Compras**:
  - Calcula el total final a pagar después de aplicar los descuentos.
  - Muestra el resumen de la compra, incluyendo el total a pagar.

## Estructura del Código

El código está organizado en las siguientes clases principales:

- **Producto**:

  - Representa un producto con atributos como identificador, nombre, precio y stock.
  - Métodos para gestionar el stock y mostrar detalles.

- **Cliente**:

  - Representa a los clientes de la tienda, diferenciando entre regulares y premium.
  - Métodos para gestionar el tipo de cliente y aplicar descuentos.

- **CarroCompra**:
  - Administra los productos en el carrito y su cantidad.
  - Métodos para agregar y eliminar productos del carrito, y calcular el total a pagar.

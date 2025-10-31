/**
 * @file Producto.cpp
 * @brief Implementación de los métodos de la clase Producto
 */

#include "Producto.h"
#include <iostream>

// Constructor por defecto
Producto::Producto() : nombre(""), precio(0.0), cantidad(0) {}

// Constructor con parámetros
Producto::Producto(const std::string& nombre, double precio, int cantidad) 
    : nombre(nombre), precio(precio), cantidad(cantidad) {}

// Getters
std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

// Setters
void Producto::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}

void Producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

// Calcula el valor total del inventario
double Producto::getValorInventario() const {
    return precio * cantidad;
}

// Vende una cantidad específica
bool Producto::vender(int cantidadVendida) {
    if (cantidadVendida <= cantidad) {
        cantidad -= cantidadVendida;
        return true;
    }
    return false;
}

// Reabastece el producto
void Producto::reabastecer(int cantidadReabastecida) {
    cantidad += cantidadReabastecida;
}

// Actualiza el precio
void Producto::actualizarPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
}

// Muestra la información del producto
void Producto::mostrarInfo() const {
    std::cout << "Producto: " << nombre 
              << " | Precio: $" << precio 
              << " | Cantidad: " << cantidad 
              << " | Valor Inventario: $" << getValorInventario() << std::endl;
}

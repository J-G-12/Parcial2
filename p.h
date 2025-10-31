/**
 * @file Producto.h
 * @brief Definición de la clase Producto para gestionar productos de una tienda en línea
 * @author [Tu Nombre]
 * @date 2024
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Clase que representa un producto en una tienda en línea
 */
class Producto {
private:
    std::string nombre;    ///< Nombre del producto
    double precio;         ///< Precio unitario del producto
    int cantidad;          ///< Cantidad en inventario

public:
    /**
     * @brief Constructor por defecto
     */
    Producto();

    /**
     * @brief Constructor con parámetros
     * @param nombre Nombre del producto
     * @param precio Precio unitario
     * @param cantidad Cantidad en inventario
     */
    Producto(const std::string& nombre, double precio, int cantidad);

    // Getters
    std::string getNombre() const;
    double getPrecio() const;
    int getCantidad() const;

    // Setters
    void setNombre(const std::string& nombre);
    void setPrecio(double precio);
    void setCantidad(int cantidad);

    /**
     * @brief Calcula el valor total del inventario para este producto
     * @return Valor total (precio * cantidad)
     */
    double getValorInventario() const;

    /**
     * @brief Vende una cantidad específica del producto
     * @param cantidadVendida Cantidad a vender
     * @return true si la venta fue exitosa, false si no hay suficiente stock
     */
    bool vender(int cantidadVendida);

    /**
     * @brief Reabastece el producto con una cantidad específica
     * @param cantidadReabastecida Cantidad a agregar al inventario
     */
    void reabastecer(int cantidadReabastecida);

    /**
     * @brief Actualiza el precio del producto
     * @param nuevoPrecio Nuevo precio del producto
     */
    void actualizarPrecio(double nuevoPrecio);

    /**
     * @brief Muestra la información del producto
     */
    void mostrarInfo() const;
};

#endif // PRODUCTO_H

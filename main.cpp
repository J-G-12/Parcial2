/**
 * @file main.cpp
 * @brief Aplicación principal que simula el flujo de productos en una tienda en línea
 */

#include "Producto.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

/**
 * @brief Calcula el valor total del inventario
 * @param productos Vector de productos
 * @return Valor total del inventario
 */
double calcularValorTotalInventario(const std::vector<Producto>& productos) {
    double total = 0.0;
    for (const auto& producto : productos) {
        total += producto.getValorInventario();
    }
    return total;
}

/**
 * @brief Genera un reporte en formato TXT
 * @param productos Vector de productos
 * @param nombreArchivo Nombre del archivo de reporte
 */
void generarReporte(const std::vector<Producto>& productos, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        std::cerr << "Error al crear el archivo de reporte." << std::endl;
        return;
    }

    // Encabezado del reporte
    archivo << "REPORTE DE INVENTARIO - TIENDA EN LÍNEA\n";
    archivo << "========================================\n\n";
    archivo << std::left << std::setw(20) << "PRODUCTO" 
            << std::setw(15) << "PRECIO" 
            << std::setw(10) << "CANTIDAD" 
            << std::setw(20) << "VALOR INVENTARIO" << "\n";
    archivo << std::string(65, '-') << "\n";

    double valorTotal = 0.0;

    // Datos de cada producto
    for (const auto& producto : productos) {
        archivo << std::left << std::setw(20) << producto.getNombre()
                << std::setw(15) << std::fixed << std::setprecision(2) << producto.getPrecio()
                << std::setw(10) << producto.getCantidad()
                << std::setw(20) << std::fixed << std::setprecision(2) << producto.getValorInventario() << "\n";
        valorTotal += producto.getValorInventario();
    }

    // Total
    archivo << std::string(65, '=') << "\n";
    archivo << std::left << std::setw(45) << "VALOR TOTAL DEL INVENTARIO:" 
            << "$" << std::fixed << std::setprecision(2) << valorTotal << "\n";

    archivo.close();
    std::cout << "Reporte generado exitosamente: " << nombreArchivo << std::endl;
}

int main() {
    std::cout << "=== SISTEMA DE GESTIÓN DE TIENDA EN LÍNEA ===\n\n";

    // 1. Usar contenedores STL para almacenar productos
    std::vector<Producto> inventario;

    // Agregar productos iniciales al inventario
    inventario.push_back(Producto("Laptop Gamer", 1200.00, 10));
    inventario.push_back(Producto("Smartphone", 800.00, 25));
    inventario.push_back(Producto("Tablet", 300.00, 15));
    inventario.push_back(Producto("Auriculares", 150.00, 30));
    inventario.push_back(Producto("Teclado Mecánico", 120.00, 20));

    std::cout << "Inventario inicial:\n";
    for (const auto& producto : inventario) {
        producto.mostrarInfo();
    }

    std::cout << "\n--- SIMULACIÓN DE OPERACIONES ---\n";

    // 2. Simular operaciones de venta
    std::cout << "\nOPERACIONES DE VENTA:\n";
    if (inventario[0].vender(3)) {
        std::cout << "Venta exitosa: 3 Laptops Gamer vendidas.\n";
    } else {
        std::cout << "Error: Stock insuficiente para vender Laptops.\n";
    }

    if (inventario[1].vender(5)) {
        std::cout << "Venta exitosa: 5 Smartphones vendidos.\n";
    } else {
        std::cout << "Error: Stock insuficiente para vender Smartphones.\n";
    }

    // 3. Simular operaciones de reabastecimiento
    std::cout << "\nOPERACIONES DE REABASTECIMIENTO:\n";
    inventario[2].reabastecer(10);
    std::cout << "Reabastecidas 10 Tablets.\n";

    inventario[3].reabastecer(15);
    std::cout << "Reabastecidos 15 Auriculares.\n";

    // 4. Simular actualización de precios
    std::cout << "\nACTUALIZACIÓN DE PRECIOS:\n";
    inventario[0].actualizarPrecio(1150.00);
    std::cout << "Precio de Laptop Gamer actualizado a $1150.00\n";

    inventario[4].actualizarPrecio(110.00);
    std::cout << "Precio de Teclado Mecánico actualizado a $110.00\n";

    // Mostrar inventario actualizado
    std::cout << "\nInventario actualizado:\n";
    for (const auto& producto : inventario) {
        producto.mostrarInfo();
    }

    // 5. Mostrar valor total del inventario
    double valorTotal = calcularValorTotalInventario(inventario);
    std::cout << "\n========================================\n";
    std::cout << "VALOR TOTAL DEL INVENTARIO: $" << std::fixed << std::setprecision(2) << valorTotal << std::endl;
    std::cout << "========================================\n";

    // 6. BONO: Generar reporte en formato TXT
    generarReporte(inventario, "reporte_inventario.txt");

    // Operaciones adicionales para demostrar funcionalidad
    std::cout << "\n--- OPERACIONES ADICIONALES ---\n";
    
    // Intentar vender más de lo disponible
    if (!inventario[0].vender(20)) {
        std::cout << "Venta fallida: No hay suficientes Laptops Gamer en stock.\n";
    }

    // Reabastecer y mostrar estado final
    inventario[0].reabastecer(5);
    std::cout << "Reabastecidas 5 Laptops Gamer.\n";

    std::cout << "\nEstado final del inventario:\n";
    for (const auto& producto : inventario) {
        producto.mostrarInfo();
    }

    valorTotal = calcularValorTotalInventario(inventario);
    std::cout << "\nVALOR TOTAL FINAL DEL INVENTARIO: $" << std::fixed << std::setprecision(2) << valorTotal << std::endl;

    return 0;
}

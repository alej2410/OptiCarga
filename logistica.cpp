#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include "logistica.h" // Importas tu propio contrato

using namespace std;

// --- 1. CONSTRUCTOR DE LA CLASE ---
// Así le enseñamos al programa cómo "fabricar" un camión cuando le pasamos los datos
Camion::Camion(string tipoCamion, float capacidad) {
    tipo = tipoCamion;
    capacidadMaxima = capacidad;
}

// --- 2. TU BASE DE DATOS DE VEHÍCULOS ---
// El famoso arreglo con los 4 niveles de transporte logístico.
Camion flota[4] = {
    Camion("Camion 350 (C2 Ligero)", 3500.0),
    Camion("Camion 1721 (C2 Pesado)", 9000.0),
    Camion("Toronto (C3)", 18000.0),
    Camion("Gandola Articulada", 30000.0)
};

// --- 3. LÓGICA DE LAS FUNCIONES ---

// Esta función ya está lista. Cuando Leonel pida ver el catálogo, se imprimirá esto:
void mostrarCatalogoCamiones() {
    cout << "\n--- Catalogo Oficial de Vehiculos OptiCarga ---\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << flota[i].tipo 
             << " | Capacidad: " << flota[i].capacidadMaxima << " kg\n";
    }
    cout << "-----------------------------------------------\n";
}

// Esta función agarra los datos que Leonel capturó y los mete en la memoria dinámica
void registrarPaquete(vector<Paquete>& listaPaquetes, string id, float peso) {
    Paquete nuevo;
    nuevo.idRastreo = id;
    nuevo.peso = peso;
    listaPaquetes.push_back(nuevo); // push_back añade el elemento al final del vector
}

// TU OBRA MAESTRA (En construcción)
void optimizarCarga(float pesoTotal) {
    cout << "\n[Motor Logistico] Calculando optimizacion para " << pesoTotal << " kg...\n";

    if (pesoTotal <= 0.0f) {
        cout << "Error: El peso total debe ser mayor a 0 kg.\n";
        return;
    }

    const double peso = static_cast<double>(pesoTotal);
    const double capMinima = 3500.0; 
    
    // Constante de penalizacion exponencial (300 * 10^2 = 30000 kg = 1 Gandola)
    const double CONSTANTE_PENALIZACION = 300.0;

    // Cotas maximas de iteracion por vehiculo
    const int maxG = static_cast<int>(ceil(peso / 30000.0));
    const int maxT = static_cast<int>(ceil(peso / 18000.0));
    const int max1721 = static_cast<int>(ceil(peso / 9000.0));

    double mejorCosto = numeric_limits<double>::max();
    double mejorVacio = 0.0;   
    double mejorTotal = 0.0;
    int mejorVehiculos = 0;
    
    int mejorG = 0, mejorT = 0, mejorC = 0, mejorP = 0;

    // Busqueda exhaustiva acotada a 3 dimensiones
    for (int g = 0; g <= maxG; ++g) {
        double capG = g * 30000.0;

        for (int t = 0; t <= maxT; ++t) {
            double capGT = capG + t * 18000.0;

            for (int m = 0; m <= max1721; ++m) {
                double subtotal = capGT + m * 9000.0;
                double remanente = peso - subtotal;

                int p = 0;
                if (remanente > 0.0) {
                    // Calculo directo con mitigador de error de punto flotante
                    p = static_cast<int>(ceil(remanente / capMinima - 1e-9));
                }

                double total = subtotal + p * capMinima;
                double vacio = total - peso;
                int totalVehiculos = g + t + m + p;

                // Fusion de objetivos: Espacio vacio + Penalizacion Exponencial
                double costo = vacio + (static_cast<double>(totalVehiculos) * totalVehiculos * CONSTANTE_PENALIZACION);

                if (costo < mejorCosto - 1e-9) {
                    mejorCosto = costo;
                    mejorVacio = vacio;   
                    mejorTotal = total;
                    mejorVehiculos = totalVehiculos;
                    mejorG = g;
                    mejorT = t;
                    mejorC = m;
                    mejorP = p;
                }
            }
        }
    }

    // Reporte por consola
    cout << fixed << setprecision(2);
    cout << "\n--- ASIGNACION OPTIMA DE FLOTA ---\n";
    if (mejorG > 0) cout << "-> Gandolas (30T): " << mejorG << "\n";
    if (mejorT > 0) cout << "-> Camiones Toronto (18T): " << mejorT << "\n";
    if (mejorC > 0) cout << "-> Camiones 1721 (9T): " << mejorC << "\n";
    if (mejorP > 0) cout << "-> Camiones 350 (3.5T): " << mejorP << "\n";
    
    cout << "----------------------------------\n";
    cout << "Vehiculos totales despachados: " << mejorVehiculos << "\n";
    cout << "Capacidad Total Asignada: " << mejorTotal << " kg\n";
    cout << "Espacio Vacio (Desperdicio REAL): " << mejorVacio << " kg\n";
}
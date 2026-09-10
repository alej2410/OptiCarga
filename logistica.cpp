#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include "logistica.h"

using namespace std;

// --- 1. CONSTRUCTOR DE LA CLASE ---
// El constructor de la clase Camion inicializa los atributos tipo y capacidadMaxima con los valores proporcionados al crear un objeto de la clase.
Camion::Camion(string tipoCamion, float capacidad) {
    tipo = tipoCamion;
    capacidadMaxima = capacidad;
}

// --- 2. BASE DE DATOS DE VEHÍCULOS ---
const Camion flota[4] = {
    Camion("Camion 350 (C2 Ligero)", 3500.0),
    Camion("Camion 1721 (C2 Pesado)", 9000.0),
    Camion("Toronto (C3)", 18000.0),
    Camion("Gandola Articulada", 30000.0)
};

// --- 3. LÓGICA DE LAS FUNCIONES ---

void mostrarCatalogoCamiones() {
    cout << "\n--- Catalogo Oficial de Vehiculos OptiCarga ---\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << flota[i].tipo 
             << " | Capacidad: " << flota[i].capacidadMaxima << " kg\n";
    }
    cout << "-----------------------------------------------\n";
}

// Esta función agarra los datos que main capturó y los mete en la memoria dinámica
void registrarCarga(vector<Carga>& listaCargas, string id, float peso) {
    Carga nueva;
    nueva.idRastreo = id;
    nueva.peso = peso;
    listaCargas.push_back(nueva); // push_back añade el elemento al final del vector
}

// Algoritmo que optimiza la asignación de vehículos según el peso total de las cargas registradas.
void optimizarFlota(float pesoTotal) {
    cout << "\n[Motor Logistico] Calculando optimizacion para " << pesoTotal << " kg...\n";

    if (pesoTotal <= 0.0f) {
        cout << "Error: No hay cargas registradas. El peso total debe ser mayor a 0 kg.\n";
        return;
    }

    const double peso = static_cast<double>(pesoTotal);
    const double capMinima = 3500.0; 
    
    // Constante de penalizacion cuadratica (300 * 10^2 = 30000 kg = 1 Gandola)
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

    // Iteracion de todas las combinaciones posibles de vehiculos
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

                // Funcion de costo: Espacio vacio + Penalizacion Cuadratica por cantidad de vehiculos
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
    cout << "Capacidad de carga no utilizada: " << mejorVacio << " kg\n";
}
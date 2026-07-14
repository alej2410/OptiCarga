#include <iostream>
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

    float mejorDesperdicio = 9999999.0; // Empezamos con un desperdicio altísimo
    int mejorTotalVehiculos = 999999; // Agregamos esta variable
    int mejorG = 0, mejorT = 0, mejor1721 = 0, mejor350 = 0;

    // Calculamos el límite máximo de veces que podríamos necesitar cada camión
    // El +1 asegura que siempre tengamos margen para pasarnos un poquito y evaluar el sobrante
    int limG = (pesoTotal / 30000) + 1;
    int limT = (pesoTotal / 18000) + 1;
    int lim1721 = (pesoTotal / 9000) + 1;
    int lim350 = (pesoTotal / 3500) + 1;

    // FASE ÚNICA: Evaluación exhaustiva pura (La computadora hace todo el trabajo)
    for (int g = 0; g <= limG; g++) {
        for (int t = 0; t <= limT; t++) {
            for (int c = 0; c <= lim1721; c++) {
                for (int p = 0; p <= lim350; p++) {
                    
                    float capActual = (g * 30000.0) + (t * 18000.0) + (c * 9000.0) + (p * 3500.0);
                    
                    // Solo nos interesan combinaciones que logren llevar la carga
                    if (capActual >= pesoTotal) {
                        float desperdicio = capActual - pesoTotal;
                        int totalVehiculos = g + t + c + p; // Sumamos cuántos camiones se usarían
                        
                        // Criterio 1: Si hay menos espacio vacío, es el nuevo ganador.
                        // Criterio 2 (Desempate): Si el espacio vacío es igual, gana el de menos camiones.
                        if (desperdicio < mejorDesperdicio || (desperdicio == mejorDesperdicio && totalVehiculos < mejorTotalVehiculos)) {
                            mejorDesperdicio = desperdicio;
                            mejorTotalVehiculos = totalVehiculos; // Guardamos el récord de menos camiones
                            mejorG = g;
                            mejorT = t;
                            mejor1721 = c;
                            mejor350 = p;
                        }
                    }
                }
            }
        }
    }

    // IMPRESIÓN DE RESULTADOS
    float capacidadAsignada = (mejorG * 30000.0) + (mejorT * 18000.0) + (mejor1721 * 9000.0) + (mejor350 * 3500.0);

    cout << "\n--- ASIGNACION OPTIMA DE FLOTA ---\n";
    if (mejorG > 0) cout << "-> Gandolas (30T): " << mejorG << "\n";
    if (mejorT > 0) cout << "-> Camiones Toronto (18T): " << mejorT << "\n";
    if (mejor1721 > 0) cout << "-> Camiones 1721 (9T): " << mejor1721 << "\n";
    if (mejor350 > 0) cout << "-> Camiones 350 (3.5T): " << mejor350 << "\n";
    
    cout << "----------------------------------\n";
    cout << "Capacidad Total Asignada: " << capacidadAsignada << " kg\n";
    cout << "Espacio Vacio (Desperdicio): " << mejorDesperdicio << " kg\n";
}
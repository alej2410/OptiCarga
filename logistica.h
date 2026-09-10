#ifndef LOGISTICA_H
#define LOGISTICA_H

#include <string>
#include <vector>

using namespace std;

// --- 1. ESTRUCTURA DE DATOS ---

// Estructura que representa una carga con un ID único y su peso en kilogramos
struct Carga {
    string idCarga;
    float peso;
};

// Clase que representa un camión con un tipo y una capacidad máxima de carga
class Camion {
public:
    string tipo;
    float capacidadMaxima;

    // Constructor de la clase Camion
    Camion(string tipoCamion, float capacidad);
};

// --- 2. PROTOTIPOS DE FUNCIONES ---
//
// Función que muestra el catálogo de camiones disponibles
void mostrarCatalogoCamiones();

// Función que tomará los datos de la carga y los guardará en memoria dinámica
void registrarCarga(vector<Carga>& listaCargas, string id, float peso);

// Función que optimizará la asignación de vehículos según el peso total de las cargas
void optimizarFlota(float pesoTotal);

#endif
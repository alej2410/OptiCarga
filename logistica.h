#ifndef LOGISTICA_H
#define LOGISTICA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 1. ESTRUCTURA DE DATOS ---

// El molde para guardar la informacion de cada carga
struct Carga {
    string idRastreo;
    float peso;
};

// El molde de la flota
class Camion {
public:
    string tipo;
    float capacidadMaxima;

    // Constructor de la clase Camion
    Camion(string tipoCamion, float capacidad);
};

// --- 2. PROTOTIPOS DE FUNCIONES (Tus Herramientas) ---
// Aquí solo le decimos al sistema que estas funciones van a existir.

// Función que muestra el catálogo de camiones disponibles
void mostrarCatalogoCamiones();

// Función que tomará los datos de la carga y los guardará en memoria dinámica
void registrarCarga(vector<Carga>& listaCargas, string id, float peso);

// Función que optimizará la asignación de vehículos según el peso total de las cargas
void optimizarFlota(float pesoTotal);

#endif
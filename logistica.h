#ifndef LOGISTICA_H
#define LOGISTICA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 1. ESTRUCTURA DE DATOS ---

// El molde para los paquetes
struct Paquete {
    string idRastreo;
    float peso;
};

// El molde de la flota
class Camion {
public:
    string tipo;
    float capacidadMaxima;

    // Constructor (La fábrica del camión)
    Camion(string tipoCamion, float capacidad);
};

// --- 2. PROTOTIPOS DE FUNCIONES (Tus Herramientas) ---
// Aquí solo le decimos al sistema que estas funciones van a existir.
// La logica real la programarás tú en logistica.cpp

// Función para que Leonel imprima la lista de los 4 vehículos
void mostrarCatalogoCamiones();

// Función que tomará los datos que pida Leonel y los meterá en el vector
void registrarPaquete(vector<Paquete>& listaPaquetes, string id, float peso);

// Tu función estrella: el algoritmo para evaluar el espacio vacío
void optimizarCarga(float pesoTotal);

#endif
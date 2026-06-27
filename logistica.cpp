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
    
    // (Daniel: Aquí programaremos el algoritmo para evitar el espacio vacío)
    
    cout << "(Algoritmo matemático en construcción)\n";
}
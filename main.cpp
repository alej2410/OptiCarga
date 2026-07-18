#include <iostream>
#include <string>
#include <vector>
#include "logistica.h"

using namespace std;

int main() {
    // Variables principales del sistema OptiCarga
    vector<Paquete> listaPaquetes;
    float pesoTotal = 0.0;
    int opcion = 0;

    cout << "=== Bienvenido a OptiCarga ===" << endl;
    cout << "Cargando motor logistico..." << endl;
    cout << "\n";

    // --- LEONEL: Aqui empieza tu trabajo ---
    // Instrucciones: Crea un ciclo do-while que muestre el menu principal.
    // Usa la variable 'opcion' para un switch y llama a las funciones de logistica.h
    
    // Ejemplo de la estructura que debes armar:
    // do {
    //     cout << "1. Ver catalogo de vehiculos\n";       // Llama a mostrarCatalogoCamiones()
    //     cout << "2. Registrar nuevo paquete\n";         // Pide ID y peso, llama a registrarPaquete() y suma al pesoTotal
    //     cout << "3. Optimizar asignacion de flota\n";   // Llama a optimizarCarga(pesoTotal)
    //     cout << "4. Salir\n";
    //     cin >> opcion;
    //
    //     switch(opcion) { ... }
    // } while(opcion != 4);
    
    // --- Fin del area de Leonel ---

    return 0;
}
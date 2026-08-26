#include <iostream>
#include <string>
#include <vector>
#include "logistica.h"

using namespace std;

int main() {
    int opcion{0}; 
    float pesoTotal{0.0f};  
    string idPaquete;       
    float pesoPaquete{0.0f};
    
    vector<Paquete> listaPaquetes; 
    
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ver catalogo de vehiculos\n";
        cout << "2. Registrar nuevo paquete\n";
        cout << "3. Optimizar asignacion de flota\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                mostrarCatalogoCamiones();
                break;
                
            case 2:
                cout << "Ingrese el ID del paquete (ej. P001): ";
                cin >> idPaquete;
                cout << "Ingrese el peso del paquete (kg): ";
                cin >> pesoPaquete;
                
                registrarPaquete(listaPaquetes, idPaquete, pesoPaquete);
                pesoTotal += pesoPaquete;
                cout << "Paquete registrado exitosamente. (Peso acumulado: " << pesoTotal << " kg)\n";
                break;
                
            case 3:
                cout << "Optimizando asignacion de flota...\n";
                optimizarCarga(pesoTotal);
                break;
                
            case 4:
                cout << "Saliendo del sistema...\n";
                break;
                
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
        
    } while(opcion != 4);
    
    return 0;
}
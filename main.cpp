#include <iostream>
#include <string>
#include <vector>
#include <limits>  
#include "logistica.h"

using namespace std;

int main() {
    int opcion{0}; 
    float pesoTotal{0.0f};   
    string idPaquete;        
    float pesoPaquete{0.0f};
    bool idDuplicado; 
    
    vector<Paquete> listaPaquetes; 
    
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ver catalogo de vehiculos\n";
        cout << "2. Registrar nuevo paquete\n";
        cout << "3. Ver lista de paquetes registrados\n"; 
        cout << "4. Optimizar asignacion de flota\n";   
        cout << "5. Salir\n";                          
        cout << "Seleccione una opcion: ";
        
        // --- ESCUDO PROTECTOR 1: Validar el menu ---
        if (!(cin >> opcion)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: Letra detectada. Por favor ingrese un numero valido.\n";
            continue; 
        }
        
        switch(opcion) {
            case 1:
                mostrarCatalogoCamiones();
                break;
                
            case 2:
                // --- ESCUDO PROTECTOR 3: Validar ID unico ---
                do {
                    idDuplicado = false; 
                    cout << "Ingrese el ID del paquete (ej. P001): ";
                    cin >> idPaquete;
                    
                    for (size_t i = 0; i < listaPaquetes.size(); i++) {
                        if (listaPaquetes[i].idRastreo == idPaquete) {
                            cout << "Error: El ID '" << idPaquete << "' ya se encuentra registrado. Use uno diferente.\n";
                            idDuplicado = true;
                            break; 
                        }
                    }
                } while (idDuplicado);
                
                // --- ESCUDO PROTECTOR 2: Validar el peso ---
                cout << "Ingrese el peso del paquete (kg): ";
                while (!(cin >> pesoPaquete) || pesoPaquete <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: Peso invalido. Ingrese un numero mayor a 0: ";
                }
                
                registrarPaquete(listaPaquetes, idPaquete, pesoPaquete);
                pesoTotal += pesoPaquete;
                cout << "Paquete registrado exitosamente. (Peso acumulado: " << pesoTotal << " kg)\n";
                break;
                
            case 3:

                if (listaPaquetes.empty()) {
                    cout << "\nNo hay paquetes registrados en el sistema actualmente.\n";
                } else {
                    cout << "\n--- LISTA DE PAQUETES REGISTRADOS ---\n";
                    for (size_t i = 0; i < listaPaquetes.size(); i++) {
                        cout << "ID: " << listaPaquetes[i].idRastreo << " \t| Peso: " << listaPaquetes[i].peso << " kg\n";
                    }
                    cout << "-------------------------------------\n";
                    cout << "Total de paquetes: " << listaPaquetes.size() << "\n";
                    cout << "Peso Total Acumulado: " << pesoTotal << " kg\n";
                }
                break;

            case 4:
                cout << "Optimizando asignacion de flota...\n";
                if (listaPaquetes.empty()) {
                    cout << "Error: No hay paquetes registrados. No se puede optimizar la carga.\n";
                } else {
                    optimizarCarga(pesoTotal);
                }
                break;
                
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
                
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
        
    } while(opcion != 5);
    
    return 0;
}
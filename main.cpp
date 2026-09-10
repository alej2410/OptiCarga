#include <iostream>
#include <string>
#include <vector>
#include <limits>  
#include "logistica.h"

using namespace std;

int main() {
    int opcion{0}; 
    float pesoTotal{0.0f};   
    string idCarga;        
    float pesoCarga{0.0f};
    bool idDuplicado; 
    
    vector<Carga> listaCargas; 
        
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ver catalogo de vehiculos\n";
        cout << "2. Registrar nueva carga\n";
        cout << "3. Ver lista de cargas registradas\n"; 
        cout << "4. Optimizar asignacion de flota\n";   
        cout << "5. Salir\n";                          
        cout << "Seleccione una opcion: ";
        
        // --- Validar entrada del usuario ---
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
                // --- Validar ID único ---
                do {
                    idDuplicado = false; 
                    cout << "Ingrese el ID de la carga (ej. C001): ";
                    cin >> idCarga;
                    
                    for (size_t i = 0; i < listaCargas.size(); i++) {
                        if (listaCargas[i].idCarga == idCarga) {
                            cout << "Error: El ID '" << idCarga << "' ya se encuentra registrado. Use uno diferente.\n";
                            idDuplicado = true;
                            break; 
                        }
                    }
                } while (idDuplicado);
                
                // --- Validar peso de la carga ---
                cout << "Ingrese el peso de la carga (kg): ";
                while (!(cin >> pesoCarga) || pesoCarga <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: Peso invalido. Ingrese un numero mayor a 0: ";
                }
                
                registrarCarga(listaCargas, idCarga, pesoCarga);
                pesoTotal += pesoCarga;
                cout << "Carga registrada exitosamente. (Peso acumulado: " << pesoTotal << " kg)\n";
                break;
                
            case 3:

                if (listaCargas.empty()) {
                    cout << "\nNo hay cargas registradas en el sistema actualmente.\n";
                } else {
                    cout << "\n--- LISTA DE CARGAS REGISTRADAS ---\n";
                    for (size_t i = 0; i < listaCargas.size(); i++) {
                        cout << "ID: " << listaCargas[i].idCarga << " \t| Peso: " << listaCargas[i].peso << " kg\n";
                    }
                    cout << "-------------------------------------\n";
                    cout << "Total de cargas: " << listaCargas.size() << "\n";
                    cout << "Peso Total Acumulado: " << pesoTotal << " kg\n";
                }
                break;

            case 4:
                cout << "Optimizando asignacion de flota...\n";
                if (listaCargas.empty()) {
                    cout << "Error: No hay cargas registradas. No se puede optimizar la carga.\n";
                } else {
                    optimizarFlota(pesoTotal);
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
# OptiCarga 🚚

Sistema de gestión logística y estructuración de datos desarrollado en C++ para calcular la asignación óptima de carga en una flota de vehículos pesados y ligeros.

## 📌 Características Principales
* **Motor de Optimización:** Algoritmo de escalarización que evalúa múltiples combinaciones de vehículos para encontrar el punto de equilibrio entre menor espacio vacío y menor cantidad de unidades despachadas.
* **Flota Dinámica:** Soporte para Gandolas (30T), Torontos (18T), Camiones 1721 (9T) y Camiones 350 (3.5T).
* **Gestión de Inventario:** Registro de paquetes y acumulación de peso total a despachar.

## 🛠️ Tecnologías
* Lenguaje: C++
* Compilador recomendado: GCC / MSYS2 (MinGW)
* Entorno: Visual Studio Code / Replit

## 🚀 Cómo compilar y ejecutar
Para ensamblar el proyecto a través de la terminal, utiliza el siguiente comando:
```bash
g++ main.cpp logistica.cpp -o opticarga.exe

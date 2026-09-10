# OptiCarga

OptiCarga es un programa desarrollado en C++ para registrar cargas y determinar una combinación adecuada de vehículos capaz de transportar su peso total.

El sistema busca equilibrar dos objetivos: reducir la capacidad de carga que queda sin utilizar y evitar el uso innecesario de vehículos.

## Objetivo

Simular un sistema básico de apoyo logístico en el que se registran distintas cargas y, a partir de su peso total, se determina una combinación optimizada de vehículos para realizar el transporte.

El programa trabaja únicamente con el peso de las cargas. No realiza una distribución física de cada carga dentro de los vehículos ni considera dimensiones, volumen, rutas o costos reales de transporte.

## Características principales

* **Registro de cargas:** permite ingresar cargas mediante un identificador único y su peso en kilogramos.
* **Validación de datos:** evita identificadores duplicados, pesos inválidos y entradas incorrectas en el menú.
* **Catálogo de vehículos:** utiliza cuatro tipos de vehículos con diferentes capacidades máximas de carga.
* **Optimización de flota:** evalúa diferentes combinaciones de vehículos y selecciona la que obtiene el menor valor en la función de costo.
* **Reporte de resultados:** muestra los vehículos seleccionados, la capacidad total asignada y la capacidad de carga no utilizada.

## Vehículos disponibles

| Vehículo                | Capacidad máxima |
| ----------------------- | ---------------: |
| Camión 350 (C2 Ligero)  |         3.500 kg |
| Camión 1721 (C2 Pesado) |         9.000 kg |
| Toronto (C3)            |        18.000 kg |
| Gandola Articulada      |        30.000 kg |

## Funcionamiento

1. El usuario registra una o varias cargas indicando su identificador y peso.
2. El sistema almacena las cargas y acumula el peso total que debe transportarse.
3. Al solicitar la optimización, el programa evalúa diferentes combinaciones de los vehículos disponibles.
4. Para cada combinación calcula la capacidad de carga no utilizada y la cantidad total de vehículos.
5. Finalmente, selecciona la combinación que obtiene el menor puntaje según la función de costo definida.

## Criterio de optimización

OptiCarga utiliza una función de costo que combina dos factores:

```text
costo = capacidad_no_utilizada + (cantidad_de_vehiculos² × 300)
```

La capacidad no utilizada corresponde a la diferencia entre la capacidad total de los vehículos seleccionados y el peso total de las cargas.

El segundo término aplica una penalización cuadrática al número de vehículos utilizados. De esta manera, el programa no busca únicamente llenar los vehículos al máximo, sino también evitar el uso de una cantidad excesiva de unidades.

El valor `300` funciona como un factor de ponderación dentro del modelo y permite establecer la importancia relativa de reducir la cantidad de vehículos frente a reducir la capacidad desaprovechada.

## Estructura del proyecto

```text
OptiCarga/
├── main.cpp
├── logistica.cpp
├── logistica.h
├── README.md
└── .gitignore
```

* `main.cpp`: contiene el menú principal, la entrada de datos y las validaciones realizadas durante la ejecución.
* `logistica.h`: define las estructuras de datos y los prototipos de las funciones.
* `logistica.cpp`: contiene la flota de vehículos y la lógica utilizada para registrar cargas y optimizar la combinación de vehículos.

## Tecnologías

* Lenguaje: C++
* Biblioteca estándar de C++
* Compilador recomendado: GCC / MinGW
* Entorno utilizado: Visual Studio Code

## Compilación y ejecución

Para compilar el proyecto mediante GCC:

```bash
g++ main.cpp logistica.cpp -o opticarga.exe
```

En Windows:

```bash
./opticarga.exe
```

En Linux o macOS puede compilarse como:

```bash
g++ main.cpp logistica.cpp -o opticarga
./opticarga
```

## Alcance del proyecto

OptiCarga fue desarrollado como un proyecto académico introductorio de programación. Su propósito es aplicar conceptos fundamentales de C++ como estructuras de datos, clases, vectores, funciones, ciclos, condicionales, validación de entradas y búsqueda de soluciones mediante un algoritmo de optimización.

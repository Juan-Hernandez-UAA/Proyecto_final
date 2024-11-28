/*
+---------------------------------------------------------+
| Metadata                                                |
+--------------------+------------------------------------+
| Practice name      | lorem                              |
| Suggested filename | main.cpp                           |
| Filename           | main.cpp                           |
| Team members       | Juan Pablo Hernandez Ramirez       |
|                    | Contreras Palacios Fernando Andres |
|                    | Jorge Alberto montes cruz          |
|                    | Venegas Cons Aida Montserrat       |
| Date               | 2024-10-31                         |
| Version            | 1.0.0                              |
| Description        | lorem                              |
+--------------------+------------------------------------+
*/

#include <stdio.h>
#include <cstdlib>
#include <cmath> /*No lo quiten putos, este es para el de la pelotita*/
#include <map>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

// Definicion de colores para consola
#define RESET "\033[0m"
#define BOLD "\033[1m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define CYAN "\033[36m"

// Prototipos de funciones
void tablaDepreciacion();
void pelotaLanzada();
void escaleraEdificio();
void pelotaGolf();
void cuadrante();
void ecuacion();
void trianguloLetras();
void salir();

void menu();
void encabezado();

int main() {
    encabezado();
    menu();
}

void encabezado() {
    system("CLS"); // limpiar consola
    cout << GREEN << BOLD << "Programa No. 1" << RESET << endl;
    cout << GREEN <<"\nEquipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Jorge Alberto montes cruz" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n\n";
}

void menu() {
    // Mapa de opciones con texto y funciones
    map<int, pair<string, function<void()>>> opciones = {
        {1, {"Tabla de depreciacion", tablaDepreciacion}},
        {2, {"Pelota lanzada", pelotaLanzada}},
        {3, {"Escalera en un edificio", escaleraEdificio}},
        {4, {"Pelota de golf", pelotaGolf}},
        {5, {"Cuadrante", cuadrante}},
        {6, {"Ecuacion", ecuacion}},
        {7, {"Triangulo con letras", trianguloLetras}},
        {8, {"Salir", salir}}
    };

    // Mostrar menú dinámicamente
    cout << "Menu:\n";
    for (const auto& opcion : opciones) {
        cout << opcion.first << ". " << opcion.second.first << endl;
    }

    cout << "Elija una opcion: ";
    int opcion;
    cin >> opcion;

    // Validar y ejecutar la opción seleccionada
    if (opciones.count(opcion)) {
        opciones[opcion].second(); // Ejecuta la función asociada
    } else {
        cout << "Opcion no valida\n";
    }
}

void tablaDepreciacion() {
    cout << "Ejecutando: Tabla de Depreciacion\n";
}

void pelotaLanzada() {
    cout << "Ejecutando: Pelota Lanzada\n";
    const int CONVERSION=1609, GRAVEDAD=9.81;
    float metros, altura, millas, angulo;
    printf("\nDame la velocidad en millas/hora: ");
    scanf("%f", &millas);
    printf("\nDame el angulo: ");
    scanf("%f", &angulo);
    metros= millas*CONVERSION;
    altura=(0.5* pow(metros,2)* pow(sin(angulo),2))/GRAVEDAD;
    printf("\nLa altura maxima alcanzada es: %.2f metros/hora", altura);
}

void escaleraEdificio() {
    cout << "Ejecutando: Escalera en un Edificio\n";
}

void pelotaGolf() {
    cout << "Ejecutando: Pelota de Golf\n";
}

void cuadrante() {
    cout << "Ejecutando: Cuadrante\n";
}

void ecuacion() {
    cout << "Ejecutando: Ecuacion\n";
}

void trianguloLetras() {
    cout << "Ejecutando: Triangulo con Letras\n";
}

void salir() {
    cout << "Saliendo del programa...\n";
}
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
#include <cmath>
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

void areaFigura();
void distanciaPuntos();
void cantidadMayor();
void langostaAhumada();
void companiaTelefonica();
void companiaViajes();
void naufragoSatisfecho();
void companiaPaqueteria();
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
    map<int, pair<string, function<void()>>> opciones = {
        {1, {"Area de la figura", areaFigura}},
        {2, {"Distancia entre dos puntos", distanciaPuntos}},
        {3, {"Cantidad mayor", cantidadMayor}},
        {4, {"La langosta ahumada", langostaAhumada}},
        {5, {"Compania telefonica", companiaTelefonica}},
        {6, {"Compania de viajes", companiaViajes}},
        {7, {"Naufrago satisfecho", naufragoSatisfecho}},
        {8, {"Compania de paqueteria", companiaPaqueteria}},
        {9, {"Salir", salir}}
    };

    cout << "Menu:\n";
    for (const auto& opcion : opciones) {
        cout << opcion.first << ". " << opcion.second.first << endl;
    }

    cout << "Elija una opcion: ";
    int opcion;
    cin >> opcion;

    if (opciones.count(opcion)) {
        opciones[opcion].second();
    } else {
        cout << "Opcion no valida\n";
    }
}

// Prototipos adicionales para funciones del conjunto 3
void areaFigura() {
    cout << "Ejecutando: Area de la figura\n";
}

void distanciaPuntos() {
    cout << "Ejecutando: Distancia entre dos puntos\n";
}

void cantidadMayor() {
    cout << "Ejecutando: Cantidad mayor\n";
    
}

void langostaAhumada() {
    cout << "Ejecutando: La langosta ahumada\n";
}

void companiaTelefonica() {
    cout << "Ejecutando: Compania telefonica\n";
}

void companiaViajes() {
    cout << "Ejecutando: Compania de viajes\n";
}

void naufragoSatisfecho() {
    cout << "Ejecutando: Naufrago satisfecho\n";
}

void companiaPaqueteria() {
    cout << "Ejecutando: Compania de paqueteria\n";
}

void salir() {
    cout << "Saliendo del programa...\n";
}
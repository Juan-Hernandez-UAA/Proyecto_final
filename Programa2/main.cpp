/*
+---------------------------------------------------------+
| Metadata                                                |
+--------------------+------------------------------------+
| Practice name      | Numero mayor                      |
| Suggested filename | main.cpp                           |
| Filename           | main.cpp                           |
| Team members       | Juan Pablo Hernandez Ramirez       |
|                    | Contreras Palacios Fernando Andres |
|                    | Jorge Alberto montes cruz          |
|                    | Venegas Cons Aida Montserrat       |
| Date               | 2024-10-31                         |
| Version            | 1.0.0                              |
| Description        | Programa con opciones del conjunto 2 |
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

#define RESET "\033[0m"
#define BOLD "\033[1m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define CYAN "\033[36m"

// Prototipos de funciones
void numeroMayor();
void oficinaAgua();
void oficinaEjercito();
void numeroBase10();
void mcdMcm();
void encuestaMoviles();
void numeroTexto();
void salir();

void menu();
void encabezado();

int main() {
    encabezado();
    menu();
}

void encabezado() {
    system("CLS");
    cout << GREEN << BOLD << "Programa Conjunto 2" << RESET << endl;
    cout << GREEN <<"\nEquipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Jorge Alberto montes cruz" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n\n";
}

void menu() {
    map<int, pair<string, function<void()>>> opciones = {
        {1, {"Numero mayor", numeroMayor}},
        {2, {"Oficina de agua", oficinaAgua}},
        {3, {"Oficina del ejercito", oficinaEjercito}},
        {4, {"Numero base 10", numeroBase10}},
        {5, {"MCD y MCM", mcdMcm}},
        {6, {"Encuesta moviles", encuestaMoviles}},
        {7, {"De numero a texto", numeroTexto}},
        {8, {"Salir", salir}}
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

void numeroMayor() {
    cout << "Ejecutando: Numero mayor\n";
}

void oficinaAgua() {
    cout << "Ejecutando: Oficina de agua\n";
}

void oficinaEjercito() {
    cout << "Ejecutando: Oficina del ejercito\n";
}

void numeroBase10() {
    cout << "Ejecutando: Numero base 10\n";
}

void mcdMcm() {
    cout << "Ejecutando: MCD y MCM\n";
}

void encuestaMoviles() {
    cout << "Ejecutando: Encuesta moviles\n";
}

void numeroTexto() {
    cout << "Ejecutando: De numero a texto\n";
}

void salir() {
    cout << "Saliendo del programa...\n";
}

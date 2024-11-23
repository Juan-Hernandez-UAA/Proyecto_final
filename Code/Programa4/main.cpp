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

void elCometa();
void sueldoEmpleados();
void elMandilon();
void sumaVectores();
void tercerVector();
void tiendaTikiTaka();
void empresaBigOld();
void sumaMatrices();
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
        {1, {"El cometa", elCometa}},
        {2, {"Sueldo empleados", sueldoEmpleados}},
        {3, {"El mandilon", elMandilon}},
        {4, {"Suma vectores", sumaVectores}},
        {5, {"Generando tercer vector", tercerVector}},
        {6, {"Tienda tiki taka", tiendaTikiTaka}},
        {7, {"Empresa big old", empresaBigOld}},
        {8, {"Suma matrices", sumaMatrices}},
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

void elCometa() {
    cout << "Ejecutando: El cometa\n";
}

void sueldoEmpleados() {
    cout << "Ejecutando: Sueldo empleados\n";
}

void elMandilon() {
    cout << "Ejecutando: El mandilon\n";
}

void sumaVectores() {
    cout << "Ejecutando: Suma vectores\n";
}

void tercerVector() {
    cout << "Ejecutando: Generando tercer vector\n";
}

void tiendaTikiTaka() {
    cout << "Ejecutando: Tienda tiki taka\n";
}

void empresaBigOld() {
    cout << "Ejecutando: Empresa big old\n";
}

void sumaMatrices() {
    cout << "Ejecutando: Suma matrices\n";
}

void salir() {
    cout << "Saliendo del programa...\n";
}
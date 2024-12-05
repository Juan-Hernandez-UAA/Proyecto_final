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

void displayMenu(const map<int, pair<string, function<void()>>> &opciones);
void handleOption(int opcion, const map<int, pair<string, function<void()>>> &opciones);
void printInfo(const string &message);
void printError(const string &message);
void menu();
void header();

int main() {
    header();
    menu();
}

void header() {
    system("CLS"); // limpiar consola
    cout << GREEN << BOLD << "Programa No. 3" << RESET << endl;
    cout << GREEN <<"\nEquipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Jorge Alberto montes cruz" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n";
}

void displayMenu(const map<int, pair<string, function<void()>>> &opciones) {
    cout << YELLOW << "\nMenu:\n" << RESET;
    for (const auto &opcion : opciones) {
        cout << opcion.first << ". " << opcion.second.first << endl;
    }
    cout << "Elija una opcion: ";
}

void handleOption(int opcion, const map<int, pair<string, function<void()>>> &opciones) {
    if (!opciones.count(opcion)) {
        printError("Opcion no valida, intente de nuevo");
        return;
    }

    if (opcion == 8) {
        printInfo("Saliendo del programa...");
    } else {
        printInfo("Ejecutando: " + opciones.at(opcion).first + "...");
        opciones.at(opcion).second(); // Ejecuta la función asociada
    }
}

void printInfo(const string &message) {
    cout << CYAN << message << "\n" << RESET;
}

void printError(const string &message) {
    cout << RED << "[ERROR]: " << message << "\n" << RESET;
}

void menu() {
    // Mapa de opciones con texto y funciones
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

    int opcion = -1;

    do {
        displayMenu(opciones); // Mostrar el menú

        cin >> opcion;

        system("CLS"); // Limpiar la pantalla después de la selección
        header();      // Mostrar header personalizado
        cout << "\n";

        handleOption(opcion, opciones); // Manejar la opción seleccionada
    } while (opcion != 9); // Repetir el menú hasta que el usuario elija salir
}

// Prototipos adicionales para funciones del conjunto 3
void areaFigura() {}

void distanciaPuntos() {
    int x1, y1, x2, y2;

    cout << "Ingresa la coordenada X del primer punto (" << RED << "X1" << RESET << ", Y1)(X2, Y2): ";
    cin >> x1;
    cout << "\033[1A\033[K";
    cout << "Ingresa la coordenada Y del primer punto (X1, " << RED << "Y1" << RESET << ")(X2, Y2): ";
    cin >> y1;
    cout << "\033[1A\033[K";
    cout << "Ingresa la coordenada Y del primer punto (X1, Y1)(" << RED << "X2" << RESET << ", Y2): ";
    cin >> x2;
    cout << "\033[1A\033[K";
    cout << "Ingresa la coordenada Y del primer punto (X1, Y1)(X2, " << RED << "Y2" << RESET << "): ";
    cin >> y2;
    cout << "\033[1A\033[K";

    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "La distancia entre los puntos (" << x1 << ", " << y1 << ") y (" << x2 << ", " << y2 << ") es: " << distancia << endl;
}

void cantidadMayor() {
}

void langostaAhumada() {
}

void companiaTelefonica() {
}

void companiaViajes() {
}

void naufragoSatisfecho() {
}

void companiaPaqueteria() {
}

void salir() {}
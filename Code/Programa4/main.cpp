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
#include <iomanip>
#include <functional>
#include <ctime>

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
    cout << GREEN << BOLD << "Programa No. 4" << RESET << endl;
    cout << GREEN <<"\nEquipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Jorge Alberto montes cruz" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n\n";
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
    int opcion = -1;

    // Mapa de opciones con texto y funciones
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

    do {
        displayMenu(opciones);

        cin >> opcion;

        system("CLS");   // Limpiar pantalla nuevamente
        header();    // Reimprimir header
        cout << "\n";

        handleOption(opcion, opciones);
    } while (opcion != 8);
}


void elCometa() {
}

void sueldoEmpleados() {
}

void elMandilon() {
}

void sumaVectores() {
}

void tercerVector() {
}

void tiendaTikiTaka() {
}

void empresaBigOld() {
}

void llenarMatrizAleatoria(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 10;  // Valores aleatorios entre 0 y 9
        }
    }
}

void llenarMatrizManual(int** matriz, string alias, int filas, int columnas) {
    cout << "Introduce los valores para la matriz " << alias << ":" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento en [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatriz(int** matriz, int filas, int columnas) {
    // Calcular el ancho necesario para los delimitadores
    int width = 2;  // El ancho de cada celda (puedes ajustarlo si deseas más espacio)

    // Delimitador superior
    cout << "+";
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j <= width; j++) {
            cout << "-"; // Genera el guion para llenar el ancho completo
        }
        cout << "+";
    }
    cout << endl;

    // Mostrar las filas de la matriz
    for (int i = 0; i < filas; i++) {
        cout << "|";
        for (int j = 0; j < columnas; j++) {
            cout << setw(width) << setfill(' ') << matriz[i][j] << " |"; // Ajuste con espaciado
        }
        cout << endl;

        cout << "+";
        for (int j = 0; j < columnas; j++) {
            for (int k = 0; k <= width; k++) {
                cout << "-"; // Genera el guion para llenar el ancho completo
            }
            cout << "+";
        }
        cout << endl;
    }
}


void sumarMatrices(int** matrizA, int** matrizB, int** resultado, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void sumaMatrices() {
    srand(time(0)); // Semilla para la generación de números aleatorios

    int filas, columnas;
    cout << "Introduce el numero de filas: ";
    cin >> filas;
    cout << "Introduce el numero de columnas: ";
    cin >> columnas;

    // Crear las matrices
    int** matrizA = new int*[filas];
    int** matrizB = new int*[filas];
    int** resultado = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matrizA[i] = new int[columnas];
        matrizB[i] = new int[columnas];
        resultado[i] = new int[columnas];
    }

    int opcion;
    do {
        cout << "Como quieres llenar las matrices? Aleatorio (1) o Manual (2): ";
        cin >> opcion;
    } while (opcion != 1 && opcion != 2);

    if (opcion == 1 ) {
        llenarMatrizAleatoria(matrizA, filas, columnas);
        llenarMatrizAleatoria(matrizB, filas, columnas);
    } else {
        string alias1 = "A";
        string alias2 = "B";
        llenarMatrizManual(matrizA, alias1, filas, columnas);
        llenarMatrizManual(matrizB, alias2, filas, columnas);
    }

    cout << "\nMatriz A:" << endl;
    mostrarMatriz(matrizA, filas, columnas);
    cout << "\nMatriz B:" << endl;
    mostrarMatriz(matrizB, filas, columnas);

    sumarMatrices(matrizA, matrizB, resultado, filas, columnas);

    cout << "\nMatriz Resultado (A + B):" << endl;
    mostrarMatriz(resultado, filas, columnas);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matrizA[i];
        delete[] matrizB[i];
        delete[] resultado[i];
    }
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
}

void salir() {
    cout << "Saliendo del programa...\n";
}
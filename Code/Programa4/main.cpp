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
#include <vector>
#include <numeric>
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
void handleOption(int opcion, const map<int, pair<string, function<void()>>> &opciones, int opcion_salir);
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
    cout << GREEN <<"Equipo Umizoomi, lista de integrantes:" << RESET << endl;
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

void handleOption(int opcion, const map<int, pair<string, function<void()>>> &opciones, int opcion_salir) {
    if (!opciones.count(opcion)) {
        printError("Opcion no valida, intente de nuevo");
        return;
    }

    if (opcion == opcion_salir) {
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

        handleOption(opcion, opciones, 9);
    } while (opcion != 9);
}

// ----- Funciones principales
void elCometa() {
}

void sueldoEmpleados() {
}

void elMandilon() {
    // Definimos los structs dentro de la función elMandilon
    struct Empleado {
        string nombre;
        float ventas;
    };

    struct Tienda {
        string nombre;
        vector<Empleado> empleados;

        // Calcular las ventas totales de la tienda
        float calcularVentasTotales() const {
            return accumulate(empleados.begin(), empleados.end(), 0.0f, [](float total, const Empleado& emp) { return total + emp.ventas; });
        }
    };

    struct Ciudad {
        string nombre;
        vector<Tienda> tiendas;

        // Calcular las ventas totales de la ciudad
        float calcularVentasTotales() const {
            return accumulate(tiendas.begin(), tiendas.end(), 0.0f, [](float total, const Tienda& tienda) { return total + tienda.calcularVentasTotales(); });
        }
    };

    // Función para registrar empleados
    auto registrarEmpleado = [](vector<Empleado>& empleados) {
        int numEmpleados;
        cout << "  Cuantos empleados tiene esta tienda?: ";
        cin >> numEmpleados;
        empleados.resize(numEmpleados);

        int contador_empleados = 1;

        for (Empleado& emp : empleados) {
            cout << "  Nombre del empleado No. " << contador_empleados << ": ";
            cin >> emp.nombre;
            cout << "  Ventas de " << emp.nombre << ": $";
            cin >> emp.ventas;

            contador_empleados ++;
        }
    };

    // Función para registrar tiendas
    auto registrarTienda = [&registrarEmpleado](vector<Tienda>& tiendas) {  // Capturamos registrarEmpleado
        int numTiendas;
        cout << "\nCuantas tiendas tiene esta ciudad?: ";
        cin >> numTiendas;
        tiendas.resize(numTiendas);

        int contador_tiendas = 1;

        for (Tienda& tienda : tiendas) {
            cout << BOLD << "\nNombre de la tienda No. " << contador_tiendas << ": ";
            cin >> tienda.nombre;
            cout << RESET;
            registrarEmpleado(tienda.empleados);  // Llamamos a registrarEmpleado

            contador_tiendas ++;
        }
    };

    // Función principal de elMandilon
    int numCiudades;
    cout << "\nEn cuantas ciudades " YELLOW << "el mandilon" << RESET << " tiene prescencia?: ";
    cin >> numCiudades;

    vector<Ciudad> ciudades(numCiudades);

    int contador_ciudades = 1;

    for (Ciudad& ciudad : ciudades) {
        string strCiudad = "\nNombre de la ciudad No. " + to_string(contador_ciudades) + ": ";
        cout << YELLOW << BOLD << strCiudad;
        cin >> ciudad.nombre;

        // generar separador dinamico
        int longitud = strCiudad.length() + ciudad.nombre.length() + 3;
        cout << setw(longitud) << setfill('=') << RESET << endl;

        registrarTienda(ciudad.tiendas);

        contador_ciudades ++;
    }

    // Resumen de ventas
    cout << YELLOW << BOLD << "\n\nResumen de ventas" << RESET << endl;
    float ventasTotalesCadena = 0;
    for (const Ciudad& ciudad : ciudades) {
        float ventasCiudad = ciudad.calcularVentasTotales();
        ventasTotalesCadena += ventasCiudad;

        cout << left << setfill(' '); // resetear el formato
        cout << BOLD << "\nResumen de ganancias en " << ciudad.nombre << RESET << endl;
        cout << setw(30) << "Ventas en la ciudad" << "$" << ventasCiudad << endl;

        for (const Tienda& tienda : ciudad.tiendas) {
            float ventasTienda = tienda.calcularVentasTotales();
            string strTienda = "Tienda \"" + tienda.nombre + "\"";
            cout << setw(30) << strTienda << "$" << ventasTienda << endl;

            for (const Empleado& emp : tienda.empleados) {
                string strEmpleado = "Empleado " + emp.nombre;
                cout << setw(30) << strEmpleado << "$" << emp.ventas << endl;
            }
        }
    }
    cout << GREEN << setw(31) << "\nVentas totales de la cadena" << "$" << ventasTotalesCadena << RESET << endl;
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
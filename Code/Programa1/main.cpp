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
#include <vector>
#include <stdexcept>

using namespace std;

#define PI 3.14159265358979323846

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
int cuadrante();
void tablaDepreciacion();
void pelotaLanzada();
void escaleraEdificio();
void pelotaGolf();
void ecuacion();
void trianguloLetras();
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
    cout << GREEN << BOLD << "Programa No. 1" << RESET << endl;
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
        {1, {"Tabla de depreciacion", tablaDepreciacion}},
        {2, {"Pelota lanzada", pelotaLanzada}},
        {3, {"Escalera en un edificio", escaleraEdificio}},
        {4, {"Pelota de golf", pelotaGolf}},
        {5, {"Cuadrante", cuadrante}},
        {6, {"Ecuacion", ecuacion}},
        {7, {"Triangulo con letras", trianguloLetras}},
        {8, {"Salir", salir}}
    };

    do {
        displayMenu(opciones);

        cin >> opcion;

        system("CLS");   // Limpiar pantalla nuevamente
        header();    // Reimprimir header
        cout << "\n";

        handleOption(opcion, opciones, 8);
    } while (opcion != 8);
}

void tablaDepreciacion() {
    const int costo_incial = 28000;
    const int depreciacion_anual = 4000;
    const int num_anio = 7;
    int costo_final = costo_incial;
    int depreciacion_acum = 0;

    cout << left;
    cout << setw(6) << "Anio"
              << setw(15) << "Depreciacion"
              << setw(25) << "Valor al final del anio"
              << "Depreciacion acumulada\n";
    cout << "---------------------------------------------------------------\n";


    for (int anio = 1; anio <= num_anio; ++anio) {
        depreciacion_acum += depreciacion_anual;
        costo_final = costo_incial - depreciacion_acum;


        cout << setw(6) << anio                          // Columna Año
                  << setw(15) << depreciacion_anual           // Columna Depreciación
                  << setw(25) << costo_final                  // Columna Valor al final del año
                  << depreciacion_acum << "\n";                   // Columna Depreciación acumulada
    }
}

void pelotaLanzada() {
    const float CONVERSION=0.44704, GRAVEDAD=9.81; //medida de conversion de millas/h a mts/s y valor de la gravedad
    float metros, altura, millas, angulo;
    printf("\nDame la velocidad en millas/hora: ");
    scanf("%f", &millas);
    printf("\nDame el angulo: ");
    scanf("%f", &angulo);
    metros= millas*CONVERSION;//se convierte la medida de millas a mts para hacer el calculo
    angulo = angulo * M_PI / 180; //Conversión de grados a radianes
    altura = pow(metros * sin(angulo), 2) / (2 * GRAVEDAD);//formula para calcular alt maxima
    printf("\nLa altura maxima alcanzada es: %.2f metros", altura);
}

void escaleraEdificio() {
    const double longitud_escalera_1 = 20;
    const double angulo_1 = 85;
    const double longitud_escalera_2 = 25;
    const double angulo_2 = 85;

    double angulo_1_radianes = angulo_1 * PI/ 180.0;
    double angulo_2_radianes = angulo_2 * PI/ 180.0;

    double altura_1 = longitud_escalera_1 * sin(angulo_1_radianes);
    double altura_2 = longitud_escalera_2 * sin(angulo_2_radianes);

    cout << "Altura alcanzada por la escalera de " << longitud_escalera_1
    <<" Pies colocada en una angulo de " <<angulo_1 << "grados: "
    << altura_1 << " pies " << endl;

        cout << "Altura alcanzada por la escalera de " << longitud_escalera_2
    <<" Pies colocada en una angulo de " <<angulo_2 << "grados: "
    << altura_2 << " pies " << endl;
}

void pelotaGolf() {
    const float g = 32.0; // gravedad en pies/s^2
    const int tiempo_total = 10;
    float dist_ant, dist_total, dist_inter;
    // header de la tabla
    cout << "\n==========================================================================" << endl;
    cout << setw(8) << "Tiempo"
              << setw(33) << "Distancia en el intervalo"
              << setw(28) << "Distancia total (pies)" << endl;
    cout << "==========================================================================" << endl;
    dist_ant = 0.0;

    // for para repetir por cada segundo
    for (int t = 0; t <= tiempo_total; ++t) {
        // Formula dist
        dist_total = 0.5 * g * t * t;

        // Calcular la distancia recorrida del inter actual
        dist_inter = dist_total - dist_ant;

        // Mostrar resultados en la tabla
        cout << setw(6) << t
                  << setw(22) << dist_inter
                  << setw(28) << dist_total << endl;

        // Se actualiza la dist para el nuevo intervalo (se van sumando)
        dist_ant = dist_total;
    }
}

// Funcion perteneciente a cuadrante
float obtenerAngulo() {
    float angulo;
    cout << "Dame el angulo de la linea: ";
    cin >> angulo;

    if (cin.fail()) {
        throw invalid_argument("Entrada no valida. Por favor ingresa un numero.");
    }
    if (angulo < 0 || angulo > 360) {
        throw out_of_range("El angulo debe estar entre 0 y 360 grados.");
    }
    return angulo;
}

// Funcion perteneciente a cuadrante
string determinarCuadrante(float angulo) {
    if (angulo > 0 && angulo < 90) {
        return "en el cuadrante I";
    }
    if (angulo > 90 && angulo < 180) {
        return "en el cuadrante II";
    }
    if (angulo > 180 && angulo < 270) {
        return "en el cuadrante III";
    }
    if (angulo > 270 && angulo < 360) {
        return "en el cuadrante IV";
    }
    return "en un eje";
}

// Funcion principal: cuadrante
int cuadrante() {
    try {
        float angulo = obtenerAngulo();
        string resultado = determinarCuadrante(angulo);
        cout << "El punto con angulo " << angulo << " se encuentra "
             << YELLOW << resultado << RESET << "." << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1; // Indicar fallo en la ejecucion
    }

    return 0; // Ejecucion exitosa
}

void ecuacion() {
    float x, y;

    // Solicitar el valor de x
    cout << "Dame el valor de x: ";
    cin >> x;

    // Calcular el valor de y con la fórmula
    y = (pow(x, 2) - 4) / 2 + (3 * x - 7 * pow(x, 4)) / (-5 * pow(x, 3)) + 4 * x - 2;

    // Mostrar el resultado desde el inicio
    cout << "El resultado de la ecuacion con x = " << x << " es: " << y << endl;

    // Mostrar la fórmula visualmente
    cout << "\n" << left;
    cout << setw(4) << "    " << setw(9) << " x^2 - 4 " << setw(3) << "" << setw(11) << " 3x - 7x^4 " << endl;
    cout << setw(4) << "y = " << setw(9) << "---------" <<  " + "  << "" << setw(11) << "-----------" << endl;
    cout << setw(4) << "    " << setw(9) << "    2    " << setw(3) << "" << setw(11) << "   -5x^3   " << endl;
    cout << "\n";

    cout << "Ahora, desglosaremos el proceso paso a paso...\n" << endl;

    // Paso 1: Calcular la primera fracción
    float parte1 = (pow(x, 2) - 4) / 2;
    cout << BOLD "Paso 1: Calcular la primera fraccion:" << RESET << endl;
    cout << "( x^2 - 4 ) / 2 = ( " << x << "^2 - 4 ) / 2" << endl;
    cout << "( " << pow(x, 2) << " - 4 ) / 2 = " << parte1 << endl;
    cout << endl;

    // Paso 2: Calcular la segunda fracción
    float parte2 = (3 * x - 7 * pow(x, 4)) / (-5 * pow(x, 3));
    cout << BOLD "Paso 2: Calcular la segunda fraccion:" << RESET << endl;
    cout << "( 3x - 7x^4 ) / ( -5x^3 ) = ( 3 * " << x << " - 7 * " << x << "^4 ) / ( -5 * " << x << "^3 )" << endl;
    cout << "( " << 3 * x << " - " << 7 * pow(x, 4) << " ) / ( " << -5 * pow(x, 3) << " ) = " << parte2 << endl;
    cout << endl;

    // Paso 3: Calcular el término restante
    float parte3 = 4 * x - 2;
    cout << BOLD "Paso 3: Calcular el termino restante:" << RESET << endl;
    cout << "4x - 2 = 4 * " << x << " - 2" << endl;
    cout << "4 * " << x << " - 2 = " << parte3 << endl;
    cout << endl;

    // Paso 4: Sumar todas las partes
    y = parte1 + parte2 + parte3;
    cout << BOLD "Paso 4: Sumar todas las partes:" << RESET << endl;
    cout << "y = " << parte1 << " + " << parte2 << " + " << parte3 << endl;
    cout << "El resultado de y es: " << y << endl;
}

void trianguloLetras() {
    // Vector to store letters A-Z
    vector<char> vec = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size() - i; j++) {
            cout << vec[j] << " ";
        }
        cout << endl;
    }
}

void salir() {}
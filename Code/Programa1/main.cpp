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
#include <iomanip>

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
#define Pi 3.1416

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
    
    const int costo_inicial = 28000;
    const int depreciacion_anual = 4000;
    const int num_anio = 7;
    int Costo_final;
    Costo_final = costo_inicial;
    int depreciacion_acum;
    depreciacion_acum = 0;
    int anio = 0;
    cout << left << setw(10) << "Año"
        << setw (15) <<"Depreciación"
        << setw (20) <<"Valor al final del año"
        << setw (20) <<"Depreciación acumulada" << endl ;
    for (int i = 0; i < 65; i++ )
        {    
            cout << "-";
        }
    cout << endl;
    for ( anio = 1; anio<= num_anio; anio ++)
    {
        depreciacion_acum += depreciacion_anual;
        Costo_final -= costo_inicial;

        cout << left << setw (10) << anio
        << setw (15) <<depreciacion_anual
        << setw (20) <<Costo_final
        << setw (20) <<depreciacion_acum <<endl;
    }
    }

void pelotaLanzada() {
    cout << "Ejecutando: Pelota Lanzada\n";
}

void escaleraEdificio() {
    cout << "Ejecutando: Escalera en un Edificio\n";
    const double longitud_escalera_1 = 20;
    const double angulo_1 = 85; 
    const double longitud_escalera_2 = 25;
    const double angulo_2 = 85;
    
    double angulo_1_radianes = angulo_1 * Pi/ 180.0;
    double angulo_2_radianes = angulo_2 * Pi/ 180.0;

    double altura_1 = longitud_escalera_1 * sin(angulo_1_radianes);
    double altura_2 = longitud_escalera_2 * sin(angulo_2_radianes);

    cout << "Altura alcanzada por la escalera de" << longitud_escalera_1
    <<" Pies colocada en una angulo de " <<angulo_1 << "grados: "
    << altura_1 << "pies" << endl;

        cout << "Altura alcanzada por la escalera de" << longitud_escalera_2
    <<" Pies colocada en una angulo de " <<angulo_2 << "grados: "
    << altura_2 << "pies" << endl;
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
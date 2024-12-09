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
    } while (opcion != 8);
}


void elCometa() {
}

void sueldoEmpleados() 
{
    cout << "Ejecutando: Sueldo empleados\n";
    int n, sh, dt, i, d;
    float ht, ph, ss, tp = 0;

    printf("Equipo Umizumi");

    printf("\nIngresa la cantidad de trabajadores que hay en la empresa: ");
    scanf("%d", &n);
    printf("Ingrese el pago por hora: ");
    scanf("%f", &ph);

    for (i = 1; i <= n; i++) 
    {
        printf("\nTrabajador #%d\n", i);
        printf("\nIngrese la cantidad de dias que se trabajaron: ");
        scanf("%d", &dt);

        sh = 0; 

        for (d = 1; d <= dt; d++) 
        {
            printf("\nGuardar las horas que se registraron en el trabajo durante el dia %d: ", d);
            scanf("%f", &ht);
            sh += ht; 
        }
        ss = sh * ph;
        printf("\nEl sueldo semanal del trabajador #%d es este: %.2f\n", i, ss);

        tp += ss;
    }
    printf("\nEl pago total de la empresa por %d trabajadores es: %.2f\n", n, tp);
}


void elMandilon() {
}

void sumaVectores() {
}

void tercerVector() 
{
    cout << "Ejecutando: Generando tercer vector\n";

    int A[10], B[10], C[10];

    printf("Equipo Umizumi");

    printf("\nIngresa el valor del primer vector (10 productos):\n");

    for (int i = 0; i < 10; i++) 
    {
        printf("Producto %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\nAhora ingresa el valor del segundo vector (10 productos):\n");

    for (int i = 0; i < 10; i++) 
    {
        printf("Producto %d: ", i + 1);
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < 10; i++) 
    {
        if (B[i] == A[i]) 
        {

            C[i] = B[i];
        } else if (B[i] > A[i]) 
        {
            C[i] = 2 * (B[i] - A[i]);
        } else 
        {
            C[i] = B[i];
        }
    }

    printf("\nLos valores del vector C son: ");
    for (int i = 0; i < 15; i++) 
    {
        printf("Producto %d: %d\n", i + 1, C[i]);
    }
}

void tiendaTikiTaka() 
{
    cout << "Ejecutando: Tienda tiki taka\n";
   float n, v, T1 = 0, T2 = 0, T3 = 0, TT = 0;
    int cn = 0, A = 0, B = 0, C = 0;

    printf("Equipo Umizumi");

    printf("\nIngrese el numero total de ventas realizadas: ");
    scanf("%f", &n);

    while (cn < n) 
    {
        printf("\nIngrese el monto de la venta #%d: ", cn + 1);
        scanf("%f", &v);

        TT = v + 1; 

        if (v > 1000) 
        {
            A = A + 1;
            T1 = v + 1; 
        } 
        else if (v > 500 && v <= 1000) 
        {
            B = B + 1;
            T2 = v + 1; 
        } 
        else 
        {
            C = C + 1;
            T3 = v + 1; 
        }
        cn = cn + 1;
    }
    printf("\nResultados del dia:\n");
    printf("\nVentas totales de Ventas 1: %d, la venta en total vendria siendo: %.2f", A, T1);
    printf("\nVentas totales de Ventas 2: %d, la venta en total vendria siendo: %.2f", B, T2);
    printf("\nVentas totales de Ventas 3: %d, la venta en total vendria siendo: %.2f", C, T3);
    printf("\nTotal de ventas: %.2f\n", TT);
}

void empresaBigOld() 
{
    cout << "Ejecutando: Empresa big old\n";
    int n, i, j, k[100][6], TK[100] = {0};
    char nc[100][50];

    printf("Equipo Umizumi");

    printf("\nIngresa el numero de choferes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nIngrese el nombre del chofer #%d: ", i + 1);
        scanf("%[^\n]", nc[i]);

        printf("\nIngrese los km que se han recorrido por dia para %s: \n", nc[i]);
        for ( j = 0; j < 6; j++)
        {
            printf("Dia %d: ", j+1);
            scanf("%d", &k[i][j]);
            TK[i] = TK[i] + k[i][j];
        }
    }
    printf("\nREPORTE DE KILOMETROS QUE SE HAN RECORRIDO\n");
    printf("=================================\n");
    for ( i = 0; i < n; i++)
    {
        printf("Chofer: %s\n", nc[i]);
        printf("Kilometros por dia: ");
        for ( j = 0; j < 6; j++)
        {
            printf("%d ", k[i][j]);
        }
        printf("\nTotal de kilometros: %d\n", TK[i]);
        printf("---------------------------------\n");
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
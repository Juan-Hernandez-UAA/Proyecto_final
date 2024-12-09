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
    int clave;
    float costoMateriaPrima, costoManoObra, gastosFabricacion, costoProduccion, precioVenta;
    char repetir;

    do {
        // Registro o entrada de clave para que inicie el código
        do {
            printf("Ingrese la clave del articulo (1-6): ");
            scanf("%d", &clave);
            if (clave < 1 || clave > 6) {
                printf("Clave invalida. Por favor, ingrese una clave entre 1 y 6.\n");
            }
        } while (clave < 1 || clave > 6);  // Función para repetir hasta que la opción sea válida

        // Entrada del costo de la materia prima
        printf("Ingrese el costo de la materia prima: ");
        scanf("%f", &costoMateriaPrima);

        // Calcular el costo de la mano de obra
        if (clave == 3 || clave == 4) {
            costoManoObra = costoMateriaPrima * 0.75;
        } else if (clave == 1 || clave == 5) {
            costoManoObra = costoMateriaPrima * 0.80;
        } else if (clave == 2 || clave == 6) {
            costoManoObra = costoMateriaPrima * 0.85;
        }

        // Calcular los gastos de fabricación
        if (clave == 2 || clave == 5) {
            gastosFabricacion = costoMateriaPrima * 0.30;
        } else if (clave == 3 || clave == 6) {
            gastosFabricacion = costoMateriaPrima * 0.35;
        } else if (clave == 1 || clave == 4) {
            gastosFabricacion = costoMateriaPrima * 0.28;
        }

        // Calcular el costo de producción y el precio de venta
        costoProduccion = costoMateriaPrima + costoManoObra + gastosFabricacion;
        precioVenta = costoProduccion * 1.45;

        // Datos que se imprimirán para el usuario
        printf("Costo de mano de obra: %.2f\n", costoManoObra);
        printf("Gastos de fabricacion: %.2f\n", gastosFabricacion);
        printf("Costo de produccion: %.2f\n", costoProduccion);
        printf("Precio de venta: %.2f\n", precioVenta);

        // Opción por si el usuario requiere repetir el proceso
        printf("Desea realizar otra operación? (S/N): ");
        scanf(" %c", &repetir);

    } while (repetir == 'S' || repetir == 's');
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
    int N, i;
    char repetir;

    do {
        // Captura de datos en N
        printf("Ingrese el numero de elementos en los vectores: ");
        scanf("%d", &N);

        // El numero de datos en el vector se declaran por N
        float A[N], B[N], C[N];

        // Asignación de datos a la variable A
        printf("Ingrese los elementos del vector A:\n");
        for (i = 0; i < N; i++) {
            printf("A[%d]: ", i);
            scanf("%f", &A[i]);
        }

        // Asignación de datos a la variable B
        printf("Ingrese los elementos del vector B:\n");
        for (i = 0; i < N; i++) {
            printf("B[%d]: ", i);
            scanf("%f", &B[i]);
        }

        // Sumar los vectores A y B, almacenando el resultado en C
        for (i = 0; i < N; i++) {
            C[i] = A[i] + B[i];
        }

        // Imprimir el resultado de La variable C
        printf("El vector resultante C es:\n");
        for (i = 0; i < N; i++) {
            printf("C[%d]: %.2f\n", i, C[i]);
        }

        // Preguntar si desea repetir
        printf("Desea realizar otra operacion? (S/N): ");
        scanf(" %c", &repetir);

    } while (repetir == 'S' || repetir == 's');
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
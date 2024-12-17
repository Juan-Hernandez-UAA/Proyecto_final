/*
+---------------------------------------------------------+
| Metadata                                                |
+--------------------+------------------------------------+
| Practice name      | lorem                              |
| Suggested filename | main.cpp                           |
| Filename           | main.cpp                           |
| Team members       | Juan Pablo Hernandez Ramirez       |
|                    | Contreras Palacios Fernando Andres |
|                    | Roberto Ruvalcaba Ventura          |
|                    | Venegas Cons Aida Montserrat       |
| Date               | 2024-10-31                         |
| Version            | 1.0.0                              |
| Description        | lorem                              |
+--------------------+------------------------------------+
*/

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

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

// Prototipos de funciones no moduladas
void elCometa();
void sueldoEmpleados();
void elMandilon();
void sumaVectores();
void tercerVector();
void tiendaTikiTaka();
void empresaBigOld();
void sumaMatrices();
void salir();

// Prototipos de funciones para la suma de matrices
void sumaMatrices();
void llenarMatrizAleatoria(int **matriz, int filas, int columnas);
void llenarMatrizManual(int **matriz, string alias, int filas, int columnas);
void mostrarMatriz(int **matriz, int filas, int columnas);
void sumarMatrices(int **matrizA, int **matrizB, int **resultado, int filas, int columnas);

// Prototipos de funciones para el menu
void header();
void menu();
void displayMenu(const map<int, pair<string, function<void()>>> &opciones);
void handleOption(int opcion, const map<int, pair<string, function<void()>>> &opciones, int opcion_salir);
void printInfo(const string &message);
void printError(const string &message);

int main() {
    header();
    menu();
}

void header() {
    system("CLS"); // limpiar consola
    cout << GREEN << BOLD << "Programa No. 4" << RESET << endl;
    cout << GREEN << "Equipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Roberto Ruvalcaba Ventura" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n";
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

        system("CLS"); // Limpiar pantalla nuevamente
        header();      // Reimprimir header
        cout << "\n";

        handleOption(opcion, opciones, 9);
    } while (opcion != 9);
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
        opciones.at(opcion).second(); // Ejecuta la funcion asociada
    }
}

void printInfo(const string &message) {
    cout << CYAN << message << "\n" << RESET;
}

void printError(const string &message) {
    cout << RED << "[ERROR]: " << message << "\n" << RESET;
}

void elCometa() {
    int clave;
    float costoMateriaPrima, costoManoObra, gastosFabricacion, costoProduccion, precioVenta;
    char repetir;

    do {
        // Registro o entrada de clave para que inicie el codigo
        do {
            printf("Ingrese la clave del articulo (1-6): ");
            scanf("%d", &clave);
            if (clave < 1 || clave > 6) {
                printf("Clave invalida. Por favor, ingrese una clave entre 1 y 6.\n");
            }
        } while (clave < 1 || clave > 6); // Funcion para repetir hasta que la opcion sea valida

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

        // Calcular los gastos de fabricacion
        if (clave == 2 || clave == 5) {
            gastosFabricacion = costoMateriaPrima * 0.30;
        } else if (clave == 3 || clave == 6) {
            gastosFabricacion = costoMateriaPrima * 0.35;
        } else if (clave == 1 || clave == 4) {
            gastosFabricacion = costoMateriaPrima * 0.28;
        }

        // Calcular el costo de produccion y el precio de venta
        costoProduccion = costoMateriaPrima + costoManoObra + gastosFabricacion;
        precioVenta = costoProduccion * 1.45;

        // Datos que se imprimiran para el usuario
        printf("%sCosto de mano de obra: %.2f\n", YELLOW, costoManoObra);
        printf("Gastos de fabricacion: %.2f\n", gastosFabricacion);
        printf("Costo de produccion: %.2f\n", costoProduccion);
        printf("Precio de venta: %.2f%s\n", precioVenta, RESET);

        // Opcion por si el usuario requiere repetir el proceso
        printf("\nDesea realizar otra operacion? (s/n): ");
        scanf(" %c", &repetir);
        cout << "\n";

    } while (repetir == 'S' || repetir == 's');
}

void sueldoEmpleados() {
    int numTrabajadores, horasTrabajadas, diasTrabajados, i, dia;
    float horasDia, pagoPorHora, sueldoSemanal, totalPago = 0;

    printf("\nIngresa la cantidad de trabajadores que hay en la empresa: ");
    scanf("%d", &numTrabajadores);
    printf("Ingrese el pago por hora: $");
    scanf("%f", &pagoPorHora);

    for (i = 1; i <= numTrabajadores; i++) {
        printf("%s\nTrabajador #%d%s\n", YELLOW, i, RESET);
        printf("Ingrese la cantidad de dias que se trabajaron: ");
        scanf("%d", &diasTrabajados);

        horasTrabajadas = 0;
        dia = 1;

        while (dia <= diasTrabajados) {
            printf("Horas laboradas el dia %d: ", dia);
            scanf("%f", &horasDia);

            if (horasDia > 0 && horasDia < 24) {
                horasTrabajadas += horasDia;
                dia++;
            } else {
                printError("Las horas ingresadas no son validas");
            }
        }

        sueldoSemanal = horasTrabajadas * pagoPorHora;
        printf("El sueldo semanal del trabajador #%d es de: %.2f\n", i, sueldoSemanal);

        totalPago += sueldoSemanal;
    }

    cout << YELLOW << "\nLa empresa pagara $" << totalPago << " por " << numTrabajadores
         << (numTrabajadores > 1 ? " trabajadores" : " trabajador") << RESET << endl;
}

void elMandilon() {
    // Definimos los structs dentro de la funcion elMandilon
    struct Empleado {
        string nombre;
        float ventas;
    };

    struct Tienda {
        string nombre;
        vector<Empleado> empleados;

        // Calcular las ventas totales de la tienda
        float calcularVentasTotales() const {
            return accumulate(empleados.begin(), empleados.end(), 0.0f, [](float total, const Empleado &emp) { return total + emp.ventas; });
        }
    };

    struct Ciudad {
        string nombre;
        vector<Tienda> tiendas;

        // Calcular las ventas totales de la ciudad
        float calcularVentasTotales() const {
            return accumulate(tiendas.begin(), tiendas.end(), 0.0f, [](float total, const Tienda &tienda) { return total + tienda.calcularVentasTotales(); });
        }
    };

    // Funcion para registrar empleados
    auto registrarEmpleado = [](vector<Empleado> &empleados) {
        int numEmpleados;
        cout << "  Cuantos empleados tiene esta tienda?: ";
        cin >> numEmpleados;
        empleados.resize(numEmpleados);

        int contador_empleados = 1;

        for (Empleado &emp : empleados) {
            cout << "  Nombre del empleado No. " << contador_empleados << ": ";
            cin >> emp.nombre;
            cout << "  Ventas de " << emp.nombre << ": $";
            cin >> emp.ventas;

            contador_empleados++;
        }
    };

    // Funcion para registrar tiendas
    auto registrarTienda = [&registrarEmpleado](vector<Tienda> &tiendas) { // Capturamos registrarEmpleado
        int numTiendas;
        cout << "\nCuantas tiendas tiene esta ciudad?: ";
        cin >> numTiendas;
        tiendas.resize(numTiendas);

        int contador_tiendas = 1;

        for (Tienda &tienda : tiendas) {
            cout << BOLD << "\nNombre de la tienda No. " << contador_tiendas << ": ";
            cin >> tienda.nombre;
            cout << RESET;
            registrarEmpleado(tienda.empleados); // Llamamos a registrarEmpleado

            contador_tiendas++;
        }
    };

    // Funcion principal de elMandilon
    int numCiudades;
    cout << "\nEn cuantas ciudades " YELLOW << "el mandilon" << RESET << " tiene prescencia?: ";
    cin >> numCiudades;

    vector<Ciudad> ciudades(numCiudades);

    int contador_ciudades = 1;

    for (Ciudad &ciudad : ciudades) {
        string strCiudad = "\nNombre de la ciudad No. " + to_string(contador_ciudades) + ": ";
        cout << YELLOW << BOLD << strCiudad;
        cin >> ciudad.nombre;

        // generar separador dinamico
        int longitud = strCiudad.length() + ciudad.nombre.length() + 3;
        cout << setw(longitud) << setfill('=') << RESET << endl;

        registrarTienda(ciudad.tiendas);

        contador_ciudades++;
    }

    // Resumen de ventas
    cout << YELLOW << BOLD << "\n\nResumen de ventas" << RESET << endl;
    float ventasTotalesCadena = 0;
    for (const Ciudad &ciudad : ciudades) {
        float ventasCiudad = ciudad.calcularVentasTotales();
        ventasTotalesCadena += ventasCiudad;

        cout << left << setfill(' '); // resetear el formato
        cout << BOLD << "\nResumen de ganancias en " << ciudad.nombre << RESET << endl;
        cout << setw(30) << "Ventas en la ciudad" << "$" << ventasCiudad << endl;

        for (const Tienda &tienda : ciudad.tiendas) {
            float ventasTienda = tienda.calcularVentasTotales();
            string strTienda = "Tienda \"" + tienda.nombre + "\"";
            cout << setw(30) << strTienda << "$" << ventasTienda << endl;

            for (const Empleado &emp : tienda.empleados) {
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

        // Asignacion de datos a la variable A
        printf("Ingrese los elementos del vector A:\n");
        for (i = 0; i < N; i++) {
            printf("A[%d]: ", i);
            scanf("%f", &A[i]);
        }

        // Asignacion de datos a la variable B
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
        printf("\n%sEl vector resultante C es: [", YELLOW);
        for (i = 0; i < N; i++) {
            cout << C[i] << (i < N - 1 ? ", " : "]\n");
        }
        cout << RESET;

        // Preguntar si desea repetir
        printf("\nDesea realizar otra operacion? (s/n): ");
        scanf(" %c", &repetir);
        cout << "\n";

    } while (repetir == 'S' || repetir == 's');
}

void tercerVector() {
    int A[10], B[10], C[10];

    // Encabezado con instrucciones claras
    printf("Sistema de Inventario de Productos\n");

    // Ingreso de datos para el primer vector A (stock de productos)
    printf("\nIngrese los valores del primer vector (Inventario de productos):\n");
    for (int i = 0; i < 10; i++) {
        printf("Producto %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Ingreso de datos para el segundo vector B (pedidos de clientes)
    printf("\nIngrese los valores del segundo vector (Pedidos de clientes):\n");
    for (int i = 0; i < 10; i++) {
        printf("Producto %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    // Generacion del tercer vector C (productos a comprar para mantener el inventario)
    for (int i = 0; i < 10; i++) {
        if (B[i] == A[i]) {
            C[i] = B[i];  // Si los valores son iguales, no hay necesidad de comprar mas
        } else if (B[i] > A[i]) {
            C[i] = 2 * (B[i] - A[i]);  // Si el pedido es mayor, comprar el doble de la diferencia
        } else {
            C[i] = B[i];  // Si el inventario es mayor, solo comprar lo necesario segun el pedido
        }
    }

    // Presentacion de resultados de manera mas clara
    printf("%s\nResultados del Inventario:\n\n%s", YELLOW, RESET);
    printf("=============================================================\n");
    printf("%-10s %-16s %-12s %-15s\n", "Producto", "Inventario (A)", "Pedido (B)", "Compra Necesaria (C)");
    printf("=============================================================\n");

    // Mostrar los resultados en una tabla
    for (int i = 0; i < 10; i++) {
        printf("%-10d %-16d %-12d %-15d\n", i + 1, A[i], B[i], C[i]);
    }

    printf("=============================================================\n");
}

void tiendaTikiTaka() {
    int totalVentas, ventasProcesadas = 0, ventasMayor1000 = 0, ventas500a1000 = 0, ventasMenor500 = 0;
    float montoVenta, totalMayor1000 = 0, total500a1000 = 0, totalMenor500 = 0, totalGlobal = 0;

    printf("Ingrese el numero total de ventas realizadas: ");
    scanf("%d", &totalVentas);

    while (ventasProcesadas < totalVentas) {
        printf("Ingrese el monto de la venta #%d: $", ventasProcesadas + 1);
        scanf("%f", &montoVenta);

        totalGlobal += montoVenta;

        if (montoVenta > 1000) {
            ventasMayor1000++;
            totalMayor1000 += montoVenta;
        } else if (montoVenta > 500 && montoVenta <= 1000) {
            ventas500a1000++;
            total500a1000 += montoVenta;
        } else {
            ventasMenor500++;
            totalMenor500 += montoVenta;
        }

        ventasProcesadas++;
    }

    cout << YELLOW << "\nResultados del Dia\n\n" << RESET;

    cout << "Categoria                  Ventas   Monto Total" << "\n\n";

    cout << "Mayores a $1000            " << left << setw(9) << ventasMayor1000 << "$" << fixed << setprecision(2) << setw(11) << totalMayor1000 << endl;
    cout << "Entre $501 y $1000         " << left << setw(9) << ventas500a1000  << "$" << fixed << setprecision(2) << setw(11) << total500a1000  << endl;
    cout << "Menores o iguales a $500   " << left << setw(9) << ventasMenor500  << "$" << fixed << setprecision(2) << setw(11) << totalMenor500  << "\n\n";

    cout << GREEN << "Total en ventas del dia:   " << left << setw(9) << ' ' << "$" << fixed << setprecision(2) << setw(10) << totalGlobal  << RESET << endl;
}

void empresaBigOld() {
    int numChoferes, i, j, kilometrosPorDia[100][6], totalKilometrosPorChofer[100] = {0};
    char nombreChofer[100][50];

    printf("\nIngresa el numero de choferes: ");
    scanf("%d", &numChoferes);

    // Consumir el salto de linea residual en el buffer
    getchar();

    for (i = 0; i < numChoferes; i++) {
        printf("Ingrese el nombre del chofer #%d: ", i + 1);
        // Lectura del nombre completo del chofer
        fgets(nombreChofer[i], sizeof(nombreChofer[i]), stdin);
        // Eliminar el salto de linea que fgets puede dejar en el nombre
        nombreChofer[i][strcspn(nombreChofer[i], "\n")] = 0;

        printf("\nIngrese los kilometros que %s ha recorrido: \n", nombreChofer[i]);
        for (j = 0; j < 6; j++) {
            printf("Dia %d: ", j + 1);
            scanf("%d", &kilometrosPorDia[i][j]);
        }

        // Consumir el salto de linea residual en el buffer antes de volver al bucle
        getchar();

        // Sumar los kilometros recorridos durante la semana
        for (j = 0; j < 6; j++) {
            totalKilometrosPorChofer[i] += kilometrosPorDia[i][j];
        }
    }

    // Imprimir el reporte de manera estructurada
    printf("\n%sREPORTE DE KILOMETROS QUE SE HAN RECORRIDO%s\n", "\033[1m", "\033[0m");

    // Encabezados de la tabla
    printf("%-15s%-8s%-8s%-8s%-8s%-8s%-8s%s%-8s%s\n", "Chofer", "Dia 1", "Dia 2", "Dia 3", "Dia 4", "Dia 5", "Dia 6", GREEN, "Total", RESET);

    for (i = 0; i < numChoferes; i++) {
        printf("%-15s", nombreChofer[i]);
        // Imprimir kilometros recorridos cada dia
        for (j = 0; j < 6; j++) {
            printf("%-8d", kilometrosPorDia[i][j]);
        }
        // Imprimir el total de kilometros del chofer
        printf("%s%-8d%s\n", GREEN, totalKilometrosPorChofer[i], RESET);
    }
}

void sumaMatrices() {
    srand(time(0)); // Semilla para la generacion de numeros aleatorios

    int filas, columnas;
    cout << "Introduce el numero de filas: ";
    cin >> filas;
    cout << "Introduce el numero de columnas: ";
    cin >> columnas;

    // Crear las matrices
    int **matrizA = new int *[filas];
    int **matrizB = new int *[filas];
    int **resultado = new int *[filas];
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

    if (opcion == 1) {
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

void llenarMatrizAleatoria(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 10; // Valores aleatorios entre 0 y 9
        }
    }
}

void llenarMatrizManual(int **matriz, string alias, int filas, int columnas) {
    cout << "Introduce los valores para la matriz " << alias << ":" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento en [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatriz(int **matriz, int filas, int columnas) {
    // Calcular el ancho necesario para los delimitadores
    int width = 2;
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

void sumarMatrices(int **matrizA, int **matrizB, int **resultado, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void salir() {}
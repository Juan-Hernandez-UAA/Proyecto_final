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
#include <functional>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

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
    cout << GREEN << BOLD << "Programa No. 3" << RESET << endl;
    cout << GREEN << "Equipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Roberto Ruvalcaba Ventura" << endl;
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

        handleOption(opcion, opciones, 9); // Manejar la opción seleccionada
    } while (opcion != 9); // Repetir el menú hasta que el usuario elija salir
}

// Prototipos adicionales para funciones del conjunto 3
void areaFigura() {
    printf("\nINICIANDO CALCULADOR DEL AREA....\n");

    const float PI = 3.1416;
    float hipo, radio, cateto, areatri, areacir, areatotal;

    printf("Dame el valor del radio: ");
    scanf("%f", &radio);

    printf("Dame el valor de la hipotenusa: ");
    scanf("%f", &hipo);

    // Verificación de que la hipotenusa sea mayor que el radio
    if (hipo < radio) {
        printError("la hipotenusa debe ser mayor que el radio");
        return;
    }

    // Cálculo del cateto usando el teorema de Pitágoras
    cateto = sqrt(pow(hipo, 2) - pow(radio, 2));
    // Cálculo del área triangular
    areatri = (radio * cateto) / 2;
    // Cálculo del área del semicirculo
    areacir = (PI * radio * radio) / 2;
    // Área total
    areatotal = areatri + areacir;

    printf("\n%sEl area total de la figura es: %.2f%s\n", YELLOW, areatotal, RESET);
}

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
    float numero1, numero2, numero3, mayor;
    char repetir;

    do {
        // Entrada de los tres números
        printf("Ingrese el primer valor (A): ");
        scanf("%f", &numero1);
        printf("Ingrese el segundo valor (B): ");
        scanf("%f", &numero2);
        printf("Ingrese el tercer valor (C): ");
        scanf("%f", &numero3);

        // Determinar el mayor
        if (numero1 >= numero2 && numero1 >= numero3) {
            mayor = numero1;
        } else if (numero2 >= numero1 && numero2 >= numero3) {
            mayor = numero2;
        } else {
            mayor = numero3;
        }

        // Mostrar el resultado
        printf("%sLa cantidad mayor es: %.2f%s\n", YELLOW, mayor, RESET);

        // Preguntar al usuario si desea realizar otra operación
        printf("\nDesea realizar otra operacion? (s/n): ");
        scanf(" %c", &repetir);
        cout << "\n";

    } while (repetir == 'S' || repetir == 's'); // Repetir si el usuario ingresa 'S' o 's'
}

void langostaAhumada() {
    int personas, ctotal, pplat;
    char resp;
    printf("\nBIENVENIDO A LA LANGOSTA AHUMADA");
    do {
        printf("\nIniciando calculador de presupuestos...");
        printf("\nIngrese la cantidad de personas en el banquete: ");
        scanf("%d", &personas);
        if (personas > 200 && personas <= 300) {
            pplat = 85;
        } else if (personas > 300) {
            pplat = 75;
        } else {
            pplat = 95;
        }
        ctotal = personas * pplat;
        printf("%sEl precio para cada platillo es de: $%d%s", YELLOW, pplat, RESET);
        printf("\n%sEl costo total del banquete es de: $%d%s", YELLOW, ctotal, RESET);
        printf("\n\nDesea realizar otro presupuesto? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');
}

void companiaTelefonica() {
    float tiempo, costo, impuesto, total;
    char dia, resp, turno;
    // PEDIDO DE VARIABLES PRINCIPALES
    printf("\nCOMPANIA TELEFONICA CHIMEFON");
    printf("\nIniciando calculador de tarifa....\n");
    do {
        printf("\nIngrese los minutos de su llamada: ");
        scanf("%f", &tiempo);
        printf("Ingrese el dia de realizacion de la llamada Dia habil(H) Domingo(D) :");
        scanf(" %c", &dia);
        // VALIDACIONES DE DATO DIA
        if (!(dia == 'h' || dia == 'H' || dia == 'd' || dia == 'D')) {
            printf("\nERROR EN EL DIA INGRESADO");
        } else {
            // VALIDACION DE DATO TURNO
            printf("Ingrese el turno de realizacion de la llamada Matutino(M) Vespertino(V) :");
            scanf(" %c", &turno);
            if (!(turno == 'm' || turno == 'M' || turno == 'v' || turno == 'V')) {
                printf("\nERROR EN EL TURNO INGRESADO");
            } else {
                if (tiempo <= 5) {
                    costo = tiempo * 1;
                } else if (tiempo <= 8) {
                    costo = (tiempo - 5) * 0.8 + 5;
                } else if (tiempo <= 10) {
                    costo = (tiempo - 8) * 0.7 + 7.4;
                } else {
                    costo = (tiempo - 10) * 0.5 + 8.8;
                }

                if (dia == 'd' || dia == 'D') {
                    impuesto = costo * 0.5;
                } else if (turno == 'm' || turno == 'M') {
                    impuesto = costo * 0.15;
                } else {
                    impuesto = costo * 0.10;
                }
                total = costo + impuesto;
                printf("%sEl total a pagar es de: $%.2f%s\n", YELLOW, total, RESET);
            }
        }
        printf("\nDesea calcular otra llamada? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');
}

void companiaViajes() {
    char tipo_autobus;
    float distancia, costo_total = 0.0, costo_por_persona = 0.0;
    int personas;

    // Ingreso de datos
    printf("Ingrese el tipo de autobus (A, B, C): ");
    scanf(" %c", &tipo_autobus); // El espacio antes de %c es para consumir cualquier caracter previo en el buffer
    printf("Ingrese la distancia en kilometros: ");
    scanf("%f", &distancia);
    printf("Ingrese el numero de personas: ");
    scanf("%d", &personas);

    // Ajustar el número de personas si es menor a 20
    if (personas < 20) {
        personas = 20;
    }

    // Asignar el precio del boleto dependiendo el tipo de autobus
    switch (tipo_autobus) {
    case 'A':
    case 'a':
        costo_por_persona = 2.0;
        break;
    case 'B':
    case 'b':
        costo_por_persona = 2.5;
        break;
    case 'C':
    case 'c':
        costo_por_persona = 3.0;
        break;
    default:
        printf("Tipo de autobus invalido.\n");
        return; // Salir de la función si el tipo de autobús no es válido
    }

    // Cálculo del costo total
    costo_total = distancia * personas * costo_por_persona;

    // Mostrar los resultados
    printf("%sCosto total del viaje: $%.2f%s\n", YELLOW, costo_total, RESET);
    printf("%sCosto por persona: $%.2f%s\n", YELLOW, costo_total / personas, RESET);
}

void naufragoSatisfecho() {
    const int HAMBURGUESA_SENCILLA = 20, HAMBURGUESA_DOBLE = 25, HAMBURGUESA_TRIPLE = 28;
    int precioHamburguesa, cantidadHamburguesas, tipoHamburguesa, costoTotal;
    char continuarPedido, pagoTarjeta;

    printf("\nBIENVENIDO AL NAUFRAGO SATISFECHO\n");

    do {
        printf("\nMenu:");
        printf("\n(1) Hamburguesa Sencilla");
        printf("\n(2) Hamburguesa Doble");
        printf("\n(3) Hamburguesa Triple");
        printf("\n\nINICIANDO PEDIDO...\n");

        printf("Ingrese el tipo de hamburguesa: ");
        scanf("%d", &tipoHamburguesa);

        if (tipoHamburguesa == 1) {
            precioHamburguesa = HAMBURGUESA_SENCILLA;
        } else if (tipoHamburguesa == 2) {
            precioHamburguesa = HAMBURGUESA_DOBLE;
        } else if (tipoHamburguesa == 3) {
            precioHamburguesa = HAMBURGUESA_TRIPLE;
        } else {
            printf("Opción inválida. Por favor, elige un número entre 1 y 3.\n");
            continue; // Si la opción es inválida, reinicia el ciclo
        }

        printf("Ingresa la cantidad de hamburguesas: ");
        scanf("%d", &cantidadHamburguesas);

        costoTotal = precioHamburguesa * cantidadHamburguesas;

        // Preguntar si desea pagar con tarjeta de crédito
        printf("Desea pagar con tarjeta de credito? (s/n): ");
        scanf(" %c", &pagoTarjeta);

        if (pagoTarjeta == 's' || pagoTarjeta == 'S') {
            costoTotal = costoTotal + (costoTotal * 0.05); // Añadir el 5% por pago con tarjeta
        }

        printf("%sEl costo total del pedido es de: $%.2f%s\n", YELLOW, (float) costoTotal, RESET);
        printf("\nDesea realizar otro pedido? (s/n): ");
        scanf(" %c", &continuarPedido);

    } while (continuarPedido == 's' || continuarPedido == 'S');
}

void companiaPaqueteria() {
    const int COSTO_AMERICA_NORTE = 11, COSTO_AMERICA_CENTRAL = 10, COSTO_AMERICA_SUR = 12, COSTO_EUROPA = 24, COSTO_ASIA = 27;
    int destino;
    float pesoPaquete, costoEnvio;
    char respuesta;

    printf("\nBIENVENIDO AL SERVICIO DE PAQUETERIA\n");

    do {
        printf("\nLos destinos disponibles son:");
        printf("\n(1) America del Norte");
        printf("\n(2) America Central");
        printf("\n(3) America del Sur");
        printf("\n(4) Europa");
        printf("\n(5) Asia");

        printf("\n\nIngresa el destino del paquete a enviar: ");
        scanf("%d", &destino);

        if (!(destino == 1 || destino == 2 || destino == 3 || destino == 4 || destino == 5)) {
            printError("El destino ingresado no es valido");
        } else {
            printf("Ingresa el peso del paquete en kg: ");
            scanf("%f", &pesoPaquete);

            if (pesoPaquete <= 5) {
                // Cálculo del costo según el destino
                switch (destino) {
                case 1:
                    costoEnvio = pesoPaquete * COSTO_AMERICA_NORTE;
                    break;
                case 2:
                    costoEnvio = pesoPaquete * COSTO_AMERICA_CENTRAL;
                    break;
                case 3:
                    costoEnvio = pesoPaquete * COSTO_AMERICA_SUR;
                    break;
                case 4:
                    costoEnvio = pesoPaquete * COSTO_EUROPA;
                    break;
                case 5:
                    costoEnvio = pesoPaquete * COSTO_ASIA;
                    break;
                default:
                    break;
                }
                printf("\n%sEl costo de enviar el paquete es de: $%.2f%s\n", YELLOW, costoEnvio, RESET);
            } else {
                printf("\n%sLo siento, el peso del paquete excede el limite permitido (maximo 5kg)%s\n", YELLOW, RESET);
            }
        }

        printf("\nDesea cotizar otro paquete? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');
}

void salir() {}
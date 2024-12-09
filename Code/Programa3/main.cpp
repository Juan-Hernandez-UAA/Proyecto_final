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
    const float PI=3.1416;
    float hipo, radio, cateto, areatri, areacir, areatotal;
    printf("\nINICIANDO CALCULADOR DEL AREA....\n");
    printf("\nDame el valor de R: ");
    scanf("%f", &radio);
    printf("\nDame el valor de H: ");
    scanf("%f", &hipo);
    // Cálculo del cateto faltante
    cateto= sqrt(pow(hipo, 2) - pow(radio, 2));
    // Cálculo del área triangular
    areatri= 2*(radio*cateto)/2;
    // Cálculo del área del semicírculo
    areacir= (PI*radio*radio)/2;
    // Área total
    areatotal= areatri+areacir;
    printf("\nEl area total de la figura es: %.2f", areatotal);
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
        printf("El mayor valor es: %.2f\n", mayor);

        // Preguntar al usuario si desea realizar otra operación
        printf("¿Desea realizar otra operación? (S/N): ");
        scanf(" %c", &repetir);

    } while (repetir == 'S' || repetir == 's');  // Repetir si el usuario ingresa 'S' o 's'
}

void langostaAhumada() {
    int personas,ctotal, pplat;
    char resp;
    printf("\nBIENVENIDO A LA LANGOSTA AHUMADA");
    do{
        printf("\nIniciando calculador de presupuestos...");
        printf("\nIngrese la cantidad de personas en el banquete: ");
        scanf("%d", &personas);
        if (personas>200&&personas<=300)
        {
            pplat=85;
        }
        else if (personas>300)
        {
            pplat=75;
        }
        else
        {
            pplat=95;
        }
        ctotal=personas*pplat;
        printf("\nEl precio para cada platillo es de: $%d", pplat);
        printf("\nEl costo total del banquete es de: $%d", ctotal);
        printf("\nDesea realizar otro presupuesto? s/n: ");
        scanf(" %c", &resp);
    } while(resp=='s'||resp=='S');
}

void companiaTelefonica() {
    float tiempo,costo, impuesto, total;
    char dia, resp, turno;
    //PEDIDO DE VARIABLES PRINCIPALES
    printf("\nCOMPANIA TELEFONICA CHIMEFON");
    printf("\nIniciando calculador de tarifa....");
    do{
        printf("\nIngrese los minutos de su llamada: ");
        scanf("%f", &tiempo);
        printf("\nIngrese el dia de realizacion de la llamada (H)Dia habil (D)Domingo :");
        scanf(" %c", &dia);
        //VALIDACIONES DE DATO DIA
        if (!(dia=='h'||dia=='H'||dia=='d'||dia=='D'))
        {
            printf("\nERROR EN EL DIA INGRESADO");
        }
        else
        {
            //VALIDACION DE DATO TURNO
            printf("\nIngrese el turno de realizacion de la llamada (M)Matutino (V)Vespertino :");
            scanf(" %c", &turno);
            if (!(turno=='m'||turno=='M'||turno=='v'||turno=='V'))
            {
                printf("\nERROR EN EL TURNO INGRESADO");
            }
            else
            {
                if (tiempo<=5)
                {
                    costo=tiempo*1;
                }
                else if (tiempo<=8)
                {
                    costo=(tiempo-5)*0.8+5;
                }
                else if (tiempo<=10)
                {
                    costo=(tiempo-8)*0.7+7.4;
                }
                else
                {
                    costo=(tiempo-10)*0.5+8.8;
                }
                if (dia=='d'||dia=='D')
                {
                    impuesto=costo*0.5;
                }
                else if (turno=='m'||turno=='M')
                {
                    impuesto=costo*0.15;
                }
                else
                {
                    impuesto=costo*0.10;
                }
                total=costo+impuesto;
                printf("\nEl total a pagar es de: $%.2f", total);
            }
        }
        printf("\nDesea calcular otra llamada? s/n: ");
        scanf(" %c", &resp);
    }while (resp=='s'||resp=='S');
}

void companiaViajes() {
    char tipo_autobus;
    float distancia, costo_total, costo_por_persona;
    int personas;

    // Ingreso de datos
    printf("Ingrese el tipo de autobus (A, B, C): ");
    scanf(" %c", &tipo_autobus);  // El espacio antes de %c es para consumir cualquier caracter previo en el buffer
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
    }

    // Formula para el costo total
    costo_total = distancia * personas * costo_por_persona;

    // Formula para el costo por persona
    costo_por_persona = costo_total / personas;

    // Datos a imprimir
    printf("Costo total del viaje: $%.2f\n", costo_total);
    printf("Costo por persona: $%.2f\n", costo_por_persona);

}

void naufragoSatisfecho() {
    const int HSENC=20, HDOBL=25, HTRIP=28;
    int phamb, nham, tipoham, total;
    char resp;
    printf("\nBIENVENIDO AL NAUFRAGO SATISFECHO");
    do
    {
        printf("\nEl menu es:");
        printf("\n(1) Hamburguesa Sencilla");
        printf("\n(2) Hamburguesa Doble");
        printf("\n(3) Hamburguesa Triple");
        printf("\nINICIANDO PEDIDO...\n");
        printf("\nIngrese el tipo de hamburguesas: ");
        scanf("%d", &tipoham);
        printf("\nIngresa la cantidad de hamburguesas: ");
        scanf("%d", &nham);
        switch (tipoham)
        {
        case (1):
            phamb=HSENC;
           break;
        case (2):
            phamb=HDOBL;
            break;
        case (3):
            phamb=HTRIP;
            break;
        default:
            break;
        }
        total= phamb*nham;
        printf("\nEl costo total del pedido es de: $%d", total);
        printf("\nSe desea realizar otro pedido? s/n: ");
        scanf(" %c", &resp);
    } while (resp=='s'||resp=='S');
}

void companiaPaqueteria() {
    const int AMENORT=11, AMECEN=10, AMESUR=12, EURO=24, ASIA=27;
    int destino;
    float peso, costo;
    char resp;
    printf("\nBIENVENIDO AL SERVICIO DE PAQUETERIA");
    do{
        printf("\nLos destinos disponibles son:");
        printf("\n(1) America del Norte");
        printf("\n(2)America Central");
        printf("\n(3)America del Sur");
        printf("\n(4)Europa");
        printf("\n(5)Asia");
        printf("\nIngresa el destino del paquete a enviar: ");
        scanf("%d", &destino);
        if (!(destino==1||destino==2||destino==3||destino==4||destino==5))
        {
            printf("\nError en el destino ingresado");
        }
        else
        {
            printf("\nIngresa el peso del paquete en kg: ");
            scanf("%f", &peso);
            if (peso<=5)
            {
                switch (destino)
                {
                case (1):
                    costo=peso*AMENORT;
                    break;
                case (2):
                    costo=peso*AMECEN;
                    break;
                case (3):
                    costo=peso*AMESUR;
                    break;
                case (4):
                    costo=peso*EURO;
                    break;
                case (5):
                    costo=peso*ASIA;
                    break;
                default:
                    break;
                }
                printf("\nEl costo de enviar el paquete es de: $%.2f", costo);

            }
            else
            {
            printf("\nLo siento, el peso del paquete excede el limite permitido (maximo 5kg)\n");
            }
        }
            printf("\nDesea cotizar otro paquete? s/n:");
            scanf(" %c", &resp);
    }while (resp=='s'||resp=='S');
}

void salir() {}
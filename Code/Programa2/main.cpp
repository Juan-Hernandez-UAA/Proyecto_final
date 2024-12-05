/*
+---------------------------------------------------------+
| Metadata                                                |
+--------------------+------------------------------------+
| Practice name      | Numero mayor                      |
| Suggested filename | main.cpp                           |
| Filename           | main.cpp                           |
| Team members       | Juan Pablo Hernandez Ramirez       |
|                    | Contreras Palacios Fernando Andres |
|                    | Jorge Alberto montes cruz          |
|                    | Venegas Cons Aida Montserrat       |
| Date               | 2024-10-31                         |
| Version            | 1.0.0                              |
| Description        | Programa con opciones del conjunto 2 |
+--------------------+------------------------------------+
*/

#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <string.h>//Ejercito

using namespace std;

#define RESET "\033[0m"
#define BOLD "\033[1m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define CYAN "\033[36m"

// Prototipos de funciones
void numeroMayor();
void oficinaAgua();
void oficinaEjercito();
void numeroBase10();
void mcdMcm();
void encuestaMoviles();
void numeroTexto();
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
    system("CLS");
    cout << GREEN << BOLD << "Programa No. 2" << RESET << endl;
    cout << GREEN << "\nEquipo Umizoomi, lista de integrantes:" << RESET << endl;
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

    map<int, pair<string, function<void()>>> opciones = {
        {1, {"Numero mayor", numeroMayor}},
        {2, {"Oficina de agua", oficinaAgua}},
        {3, {"Oficina del ejercito", oficinaEjercito}},
        {4, {"Numero base 10", numeroBase10}},
        {5, {"MCD y MCM", mcdMcm}},
        {6, {"Encuesta moviles", encuestaMoviles}},
        {7, {"De numero a texto", numeroTexto}},
        {8, {"Salir", salir}}
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

void numeroMayor() {
    cout << "Ejecutando: Numero mayor\n";
    int num1, num2, num3, num4, mayor;

    printf("Equipo Umizumi\n");
    printf(" Ingrese el numero 1: ");
    scanf("%d", &num1);
    printf("Ingrese el numero 2: ");
    scanf("%d", &num2);
    printf("Ingrese el numero 3: ");
    scanf("%d", &num3);
    printf("Ingrese el numero 4: ");
    scanf("%d", &num4);

    vector<int> numeros = {num1, num2, num3, num4};

    mayor = numeros [0];

    for (int numero : numeros)
    {
        if (numero > mayor)
        {
            mayor = numero;
        }
    }

    printf("EL numero mayor es: %d\n", mayor);
}

void oficinaAgua() {
    cout << "Ejecutando: Oficina de agua\n";
}

void oficinaEjercito() {
    cout << "Ejecutando: Oficina del ejercito\n";
    char sexo, estado, resp, apto[60];
    int edad;
    float estatura;

    do{
        printf("\nSISTEMA DE VALIDACION PARA ASPIRANTES AL EJERCITO");
        printf("\nIngrese el genero:");
        printf("\nHombre(H) Mujer(M): ");
        scanf("%s", &sexo);
        printf("\nIngrese el estado civil:");
        printf("\nSoltero(S) Casado(C) Viudo(V) Divorciado(D): ");
        scanf(" %c", &estado);
        if (not (estado=='s' or estado=='S'))//se valida si no es soltero para mandar directamente a NO aceptado y no seguir con los demás datos
        {
            strcpy(apto,"El aspirante NO es apto para el ejercito");//se va a usar la variable de cadena para ir cambiando el mensaje dependiendo si es apto o no
        }
        else
        {
            printf("\nIngrese la estatura en mts: ");
            scanf("%f", &estatura);
            printf("\nIngrese la edad: ");
            scanf("%d", &edad);
            switch (sexo)
            {
            case 'M':
            case 'm':
                if (estatura>1.6 && (edad>=20 && edad<=25)){//criterios para mujeres
                    strcpy(apto,"El aspirante SI es apto para el ejercito");
                }
                else{
                    strcpy(apto,"El aspirante NO es apto para el ejercito");
                }
            break;

            case 'H':
            case 'h':
                if (estatura>1.65 && (edad>=18 && edad<=24)){//criterios para hombres
                    strcpy(apto,"El aspirante SI es apto para el ejercito");
                }
                else{
                    strcpy(apto,"El aspirante NO es apto para el ejercito");
                }
            break;

            default:
                break;
            }
        }
        printf("\nEl resultado es: %s", apto);
        printf("\nDesea ingresar otro aspirante?: s/n ");//ciclo por si hay más aspirantes
        scanf(" %c", &resp);
    } while (resp=='s' or resp=='S');
}

void numeroBase10() {
    cout << "Ejecutando: Numero base 10\n";

    int numero, suma = 0, cifras = 0;

    printf("Equipo Umizumi\n");

    printf("Ingrese un numero en sistema decimal: ");
    scanf("%d", &numero);

    if (numero > 0) {
        int temp = numero;
        while (temp > 0) {
            suma += temp % 10;
            temp /= 10;
            cifras++;
        }
        printf("El numero tiene %d cifras\n", cifras);
        printf("La suma total entre esos numeros es: %d\n", suma);
    } else
    {
        printf("El numero no es positivo.\n");
    }
}

void mcdMcm() {
    cout << "Ejecutando: MCD y MCM\n";
    int calcularMCD(int a, int b);
    int calcularMCM(int a, int b, int mcd);
    int num1, num2, mcd, mcm;
    char continuar;

    printf("Equipo Umizumi");

    do
    {
        printf(" Ingrese el numero 1 positivo: ");
        scanf("%d", &num1);
        printf(" Ingrese el numero 2 positivo: ");
        scanf("%d", &num2);
        if (num1 > 0 && num2 > 0)
        {
            // Calcular el MCD
            mcd = calcularMCD(num1, num2);
            // Calcular el MCM usando el MCD
            mcm = calcularMCM(num1, num2, mcd);
            // Mostrar los resultados
            printf("El MCD de %d y %d es: %d\n", num1, num2, mcd);
            printf("El MCM de %d y %d es: %d\n", num1, num2, mcm);
        }
        else
        {
            printf("\nAmbos son positivos\n");
        }
        // Preguntar si desea continuar
        printf("Desea realizar otro clculo (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
    printf("Gracias por usar el programa, adios.\n");
}

// Función para calcular el MCD usando el Algoritmo de Euclides
int calcularMCD(int a, int b)
{
    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int calcularMCM(int a, int b, int mcd)
{
    return (a * b) / mcd;
}

void encuestaMoviles() {
    cout << "Ejecutando: Encuesta moviles\n";
}

void numeroTexto() {
    cout << "Ejecutando: De numero a texto\n";
    void numeroEnPalabras(int numero);
    int numero;
    printf("Equipo Umizumi");

    printf(" Ingresa cualquier numero entre el 0 y 99: ");
    scanf("%d", &numero);
    if (numero < 0 || numero > 99)
    {
        printf("El numero que usted ingreso, no está en el rango permitido (0-99).\n");
    }
    else
    {
        printf("El numero en palabras es: ");
        numeroEnPalabras(numero);
    }
}
void numeroEnPalabras(int numero)
{
    const char *unidades[] = {"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
    const char *especiales[] = {"Diez", "Once", "Doce", "Trece", "Catorce", "Quince", "Dieciseis", "Diecisiete", "Dieciocho", "Diecinueve"};
    const char *decenas[] = {"", "", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa"};

    if (numero < 10)
    {
        printf("%s\n", unidades[numero]);
    }
    else if (numero < 20)
    {
        printf("%s\n", especiales[numero - 10]);
    }
    else if (numero % 10 == 0)
    {
        printf("%s\n", decenas[numero / 10]);
    }
    else
    {
        printf("%s y %s\n", decenas[numero / 10], unidades[numero % 10]);
    }
}

void salir() {
    cout << "Saliendo del programa...\n";
}

/*
+-----------------------------------------------------------+
| Metadata                                                  |
+--------------------+--------------------------------------+
| Practice name      | Numero mayor                         |
| Suggested filename | main.cpp                             |
| Filename           | main.cpp                             |
| Team members       | Juan Pablo Hernandez Ramirez         |
|                    | Contreras Palacios Fernando Andres   |
|                    | Roberto Ruvalcaba Ventura            |
|                    | Venegas Cons Aida Montserrat         |
| Date               | 2024-10-31                           |
| Version            | 1.0.0                                |
| Description        | Programa con opciones del conjunto 2 |
+--------------------+--------------------------------------+
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
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
void numeroMayor();
void oficinaAgua();
void numeroBase10();
void encuestaMoviles();
void numeroTexto();
void salir();

// Prototipos de funciones para la oficina del ejercito
void oficinaEjercito();
int validarSujeto(char estadoCivilValido, float estaturaMinima, int edadMinima, int edadMaxima);

// Prototipos de funciones para calcular el MCD y MCM
void mcdMcm();
int calcularMCD(int a, int b);
int calcularMCM(int a, int b, int mcd);

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
    system("CLS");
    cout << GREEN << BOLD << "Programa No. 2" << RESET << endl;
    cout << GREEN << "Equipo Umizoomi, lista de integrantes:" << RESET << endl;
    cout << "-" << YELLOW << " (PM) " << RESET << "Hernandez Ramirez Juan Pablo " << endl;
    cout << "- Contreras Palacios Fernando Andres" << endl;
    cout << "- Roberto Ruvalcaba Ventura" << endl;
    cout << "- Venegas Cons Aida Montserrat" << "\n";
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

        system("CLS"); // Limpiar pantalla nuevamente
        header();      // Reimprimir header
        cout << "\n";

        handleOption(opcion, opciones, 8);
    } while (opcion != 8);
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

// Funcion para valiar caracteres
template <typename T>
bool validarCaracter(const string &input, T &caracterValido, const string &mensajeError, const string &caracteresValidos) {
    if (input.length() != 1) {
        printError(mensajeError);
        return false;
    }
    char caracter = toupper(input[0]);
    if (caracteresValidos.find(caracter) == string::npos) {
        printError(mensajeError);
        return false;
    }
    caracterValido = caracter;
    return true;
}

void numeroMayor() {
    vector<int> numeros(4);

    // Entrada de números con un bucle para evitar repetición
    for (int i = 0; i < 4; ++i) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Encontrar el mayor utilizando std::max_element
    int mayor = *max_element(numeros.begin(), numeros.end());

    // Imprimir el resultado con estilo
    cout << YELLOW << "El numero mayor es: " << mayor << RESET << endl;
}

void oficinaAgua() {
    const int cargo_fijo[6] = {2500, 2800, 3000, 3300, 3700, 4400};
    const int costo_metro[6] = {2200, 2350, 2600, 3400, 3900, 4800};
    const int basura_alcantarillado[6] = {5500, 6200, 7400, 8600, 9700, 11000};

    int estrato, metros_consumidos;
    int total_factura = 0;

    // Solicitud de datos para el cálculo de agua
    cout << "Ingrese el estrato socioeconomico (1-6): ";
    cin >> estrato;

    // Validación del estrato
    if (estrato < 1 || estrato > 6) {
        cout << "Error, el estrato ingresado es incorrecto, ingrese uno entre 1 y 6" << endl;
    } else {
        cout << "Ingrese la cantidad de metros cubicos consumidos: ";
        cin >> metros_consumidos;

        // Cálculo de factura
        int indice = estrato - 1; // Ajuste del indice al rango del arreglo
        total_factura += cargo_fijo[indice];
        total_factura += costo_metro[indice] * metros_consumidos;
        total_factura += basura_alcantarillado[indice];

        // Despliegue del resultado
        cout << YELLOW << "El total a pagar es: $" << total_factura << RESET << endl;
    }
}

void oficinaEjercito() {
    bool esGeneroValido = true;
    char sexo, continuar;
    string input;

    do {
        do {
            cout << "Ingrese el sexo: Femenino(F) Masculino(M): ";
            cin >> input;
            if (!validarCaracter(input, sexo, "Debe ingresar solo un caracter (F o M)", "FM")) {
                esGeneroValido = false;
                continue;
            }
            esGeneroValido = true;
        } while (!esGeneroValido);

        // Definir parámetros de validación para cada género
        if (sexo == 'F') {
            validarSujeto('S', 1.60, 20, 25);
        } else {
            validarSujeto('S', 1.65, 18, 24);
        }

        cout << "Desea realizar otra validacion? (s/n): ";
        cin >> input;
        if (!validarCaracter(input, continuar, "Debe ingresar solo un caracter (S o N)", "SN")) {
            continuar = 'N'; // Salir si la entrada es inválida
        }

        cout << "\n";

    } while (continuar == 'S');
}

int validarSujeto(char estadoCivilValido, float estaturaMinima, int edadMinima, int edadMaxima) {
    int edad;
    float estatura;
    string input;
    char estadoCivil;

    // Validación del estado civil
    do {
        cout << "Ingrese el estado civil: Soltero(S), Viudo(V), Casado(C), Divorciado(D): ";
        cin >> input;
        if (!validarCaracter(input, estadoCivil, "Debe ingresar solo un caracter (S, V, C o D)", "SVCD")) {
            continue;
        }
        if (estadoCivil != estadoCivilValido) {
            cout << YELLOW << "El aspirante no es apto, debe estar soltero (S)" << RESET << endl;
            return 1;
        }
        break;
    } while (true);

    // Validación de la edad
    cout << "Ingrese la edad: ";
    cin >> edad;
    if (edad < edadMinima || edad > edadMaxima) {
        cout << YELLOW << "El aspirante no es apto, debe tener entre " << edadMinima << " y " << edadMaxima << " anios" << RESET << endl;
        return 1;
    }

    // Validación de la estatura
    cout << "Ingrese la estatura en metros: ";
    cin >> estatura;
    if (estatura <= estaturaMinima) {
        cout << YELLOW << "El aspirante no es apto. La estatura minima es: " << estaturaMinima + 0.01 << " metros" << RESET << endl;
        return 1;
    }

    // Si todo es válido
    cout << GREEN << "\nSujeto apto para el ejercito." << RESET << endl;
    return 0;
}

void numeroBase10() {

    int numero, suma = 0, cifras = 0;

    printf("Ingrese un numero en sistema decimal: ");
    scanf("%d", &numero);

    if (numero > 0) {
        int temp = numero;
        while (temp > 0) {
            suma += temp % 10;
            temp /= 10;
            cifras++;
        }
        printf("%sEl numero tiene %d cifras%s\n", YELLOW, cifras, RESET);
        printf("%sLa suma total entre esos numeros es: %d%s\n", YELLOW, suma, RESET);
    } else {
        printf("El numero no es positivo.\n");
    }
}

void mcdMcm() {
    int num1, num2, mcd, mcm;
    char continuar;

    do {
        // Validación de número 1 positivo
        do {
            printf("Ingrese el numero 1 positivo: ");
            scanf("%d", &num1);

            if (num1 <= 0) {
                cout << YELLOW << "El primer numero debe ser positivo. Intente nuevamente." << RESET << endl;
            }
        } while (num1 <= 0); // Repetir hasta que el número 1 sea positivo

        // Validación de número 2 positivo
        do {
            printf("Ingrese el numero 2 positivo: ");
            scanf("%d", &num2);

            if (num2 <= 0) {
                cout << YELLOW << "El segundo numero debe ser positivo. Intente nuevamente." << RESET << endl;
            }
        } while (num2 <= 0); // Repetir hasta que el número 2 sea positivo

        // Calcular el MCD
        mcd = calcularMCD(num1, num2);
        // Calcular el MCM usando el MCD
        mcm = calcularMCM(num1, num2, mcd);
        // Mostrar los resultados
        printf("El MCD de %d y %d es: %d\n", num1, num2, mcd);
        printf("El MCM de %d y %d es: %d\n", num1, num2, mcm);

        // Preguntar si desea realizar otro cálculo
        printf("Desea realizar otro calculo (s/n): ");
        scanf(" %c", &continuar); // Espacio antes de %c para leer correctamente el carácter

    } while (continuar == 's' || continuar == 'S');
}

int calcularMCD(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int calcularMCM(int a, int b, int mcd) {
    return (a * b) / mcd;
}

void encuestaMoviles() {
    int contador = 0;
    int votosAndroid = 0, votosIos = 0;
    int alumnos;
    char opcion;
    string input;

    do {
        cout << "Alumnos a responder la encuesta: ";
        cin >> alumnos;

        if (alumnos <= 0) {
            cout << "El numero de alumnos debe ser mayor a 0" << endl;
        }

    } while (alumnos <= 0);

    while (contador < alumnos) {
        cout << "Alumno " << contador + 1 << ", por favor vota por una opcion: Android(A) o iOS(I): ";
        cin >> input;

        if (!validarCaracter(input, opcion, "Debe ingresar solo un caracter (A o I)", "AI")) {
            continue;
        }

        if (opcion == 'A') {
            votosAndroid++;
        } else if (opcion == 'I') {
            votosIos++;
        }
        contador++;
    }

    // Mostrar resultados y manejar empate
    cout << "Resultados de la encuesta:" << endl;
    cout << "Votos Android: " << votosAndroid << endl;
    cout << "Votos iOS: " << votosIos << endl;

    if (votosAndroid == votosIos) {
        cout << "La encuesta terminó en empate. Por favor, vuelva a realizarla." << endl;
    } else if (votosAndroid > votosIos) {
        cout << "Android es el sistema preferido." << endl;
    } else {
        cout << "iOS es el sistema preferido." << endl;
    }
}

void numeroTexto() {
    void numeroEnPalabras(int numero);
    int numero;
    printf("Ingresa cualquier numero entre el 0 y 99: ");
    scanf("%d", &numero);
    if (numero < 0 || numero > 99) {
        printf("El numero que usted ingreso, no está en el rango permitido (0-99).\n");
    } else {
        printf("%sEl numero en palabras es: ", YELLOW);
        numeroEnPalabras(numero);
    }
}

void numeroEnPalabras(int numero) {
    const char *unidades[] = {"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
    const char *especiales[] = {"Diez", "Once", "Doce", "Trece", "Catorce", "Quince", "Dieciseis", "Diecisiete", "Dieciocho", "Diecinueve"};
    const char *decenas[] = {"", "", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa"};

    if (numero < 10) {
        printf("%s\n%s", unidades[numero], RESET);
    } else if (numero < 20) {
        printf("%s\n%s", especiales[numero - 10], RESET);
    } else if (numero % 10 == 0) {
        printf("%s\n%s", decenas[numero / 10], RESET);
    } else {
        printf("%s y %s\n%s", decenas[numero / 10], unidades[numero % 10], RESET);
    }
}

void salir() {}
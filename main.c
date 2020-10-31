// Polo, Salinas, Juan
#include <stdio.h>
// Resto de include necesarios

void ejercicio1() {
    // TO-DO
}

void ejercicio2() {
    // TO-DO
}

void ejercicio3() {
    // TO-DO
}

int main() {

    int resultado = 0;

    printf("1.- Ejercicio 1\n2.- Ejercicio 2\n3.- Ejercicio 3\n4.- Salir\n\nIntroduzca una opcion(1-4) ");

    scanf("%d", &resultado);

    printf(resultado);

    if (resultado > 4 || resultado < 1) {
        printf("ERROR: Opcion introducida no valida");
    }

    ejercicio1(); // Salta al codigo de ejercicio 1 y cuando termina vuelve a este punto
    ejercicio2(); // Salta al codigo de ejercicio 1 y cuando termina vuelve a este punto
    ejercicio3(); // Salta al codigo de ejercicio 1 y cuando termina vuelve a este punto

}
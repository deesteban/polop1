// Polo, Salinas, Juan
#include <stdio.h>
#include <math.h>
#include "stdlib.h"
// Resto de include necesarios

void ejercicio1() {

    for (int i = 20; i > 0; i--) {
        for (int j = 0; j < 20; j++) {
            if (pow((j - 10), 2.0) + pow((i - 10), 2.0) == 100) {
                printf("* ");
            } else {
                printf(" ");
            }

            printf("\n");
        }
    }


}

void ejercicio2() {
    printf("Ej2");

}

void ejercicio3() {
    printf("Ej3");

}

int main() {

    int resultado = 0;

    do {

        printf("1.- Ejercicio 1\n2.- Ejercicio 2\n3.- Ejercicio 3\n4.- Salir\n\nIntroduzca una opcion(1-4) ");

        //se lee el numero por teclado
        scanf("%d", &resultado);

        //se controlan los numeros fuera del rango
        if (resultado > 4 || resultado < 1) {
            printf("ERROR: Opcion introducida no valida\n\n");
        }

        //se selecciona el ejercicio correcto
        if (resultado == 1) ejercicio1();
        if (resultado == 2) ejercicio2();
        if (resultado == 3) ejercicio3();
        if (resultado == 4) {
            //se finaliza el programa
        }

    } while (resultado != 4);

}
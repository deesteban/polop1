// Polo, Salinas, Juan
#include <stdio.h>
#include <math.h>
#include "stdlib.h"
// Resto de include necesarios

void ejercicio1() {

    double radio = 10.0;
    int porcentaje = 10;
    printf("\n");


    for (int i = 2 * radio; i >= 0; i--) {
        for (int j = 0; j <= 1.5 * radio; j++) {

            double res = pow((j - radio), 2.0) + pow((i - radio), 2.0);
            if (res > (pow(radio, 2.0) - porcentaje) && res < (pow(radio, 2.0) + porcentaje)) {
                printf("* ");
            } else {
                printf(" ");
            }

            double res2 = pow((j - 2.0 * radio), 2.0) + pow((i - radio), 2.0);
            if (res2 > (pow(radio, 2.0) - porcentaje) && res2 < (pow(radio, 2.0) + porcentaje)) {
                printf("* ");
            } else {
                printf(" ");
            }


        }
        printf("\n");
    }


}

void ejercicio2() {

    int numerosTopper = 0;
    int numerosHarriet = 0;
    int numerosSpewart = 0;
    int numerosRango = 0;
    int longitud = 0, primerNumero = 0;
    //poner print de topper, intruce...

    scanf("%d", &numerosTopper);
    //para saber longitud de un numero int
    longitud = floor(1 + log10(abs(numerosTopper)));
    primerNumero = numerosTopper / 1000;

    //solo se entra si los numeros de topper son correctos
    if (longitud == 4 && primerNumero != 0) {

        //comprobamos numeros de harriet
        //print de numeros harriet
        scanf("%d", &numerosHarriet);
        longitud = floor(1 + log10(abs(numerosHarriet)));
        primerNumero = numerosHarriet / 1000;

        if (longitud == 4 && primerNumero != 0) {

            //comprobamos numeros de spewart
            //print de numeros spewart
            scanf("%d", &numerosSpewart);
            longitud = floor(1 + log10(abs(numerosSpewart)));
            primerNumero = numerosSpewart / 10000;

            if (longitud == 5 && primerNumero != 0) {

                //comprobamos numeros de rango
                //print de numeros rango
                scanf("%d", &numerosRango);
                longitud = floor(1 + log10(abs(numerosRango)));
                primerNumero = numerosRango / 10000;

                if (longitud == 5 && primerNumero != 0) {

                    //Solo entramos si todos los numeros estan ok
                    int resultadoTotal = 0;

                    for (int i = 5, itr = 1; i >= 2; i--, itr = itr * 10) {
                        int digito = (numerosTopper / itr) % 10;
                        int factor = pow(2, i);
                        factor = factor % 11;
                        int resultado = digito * factor;
                        resultadoTotal = resultadoTotal + resultado;
                    }

                    for (int i = 9, itr = 1; i >= 6; i--, itr = itr * 10) {
                        int digito = (numerosHarriet / itr) % 10;
                        int factor = pow(2, i);
                        factor = factor % 11;
                        int resultado = digito * factor;
                        resultadoTotal = resultadoTotal + resultado;
                    }

                    resultadoTotal = resultadoTotal % 11;

                    resultadoTotal = 11 - resultadoTotal;

                    if (resultadoTotal < 10) {
                        printf("Primer digito: %d\n", resultadoTotal);
                    } else if (resultadoTotal == 10) {
                        printf("Primer digito: 1\n");
                    } else {
                        printf("Primer digito: 0\n");
                    }

                    //segundo digito


                    //Solo entramos si todos los numeros estan ok
                    resultadoTotal = 0;

                    for (int i = 4, itr = 1; i >= 0; i--, itr = itr * 10) {
                        int digito = (numerosSpewart / itr) % 10;
                        int factor = pow(2, i);
                        factor = factor % 11;
                        int resultado = digito * factor;
                        resultadoTotal = resultadoTotal + resultado;
                    }

                    for (int i = 9, itr = 1; i >= 5; i--, itr = itr * 10) {
                        int digito = (numerosRango / itr) % 10;
                        int factor = pow(2, i);
                        factor = factor % 11;
                        int resultado = digito * factor;
                        resultadoTotal = resultadoTotal + resultado;
                    }

                    resultadoTotal = resultadoTotal % 11;

                    resultadoTotal = 11 - resultadoTotal;

                    if (resultadoTotal < 10) {
                        printf("Segundo digito: %d\n", resultadoTotal);
                    } else if (resultadoTotal == 10) {
                        printf("Segundo digito: 1\n");
                    } else {
                        printf("Segudno digito: 0\n");
                    }

                }


            } else {
                printf("Codigo No valido");
            }


        } else {
            printf("Codigo No valido");
        }


    } else {
        printf("Codigo No valido");
    }

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
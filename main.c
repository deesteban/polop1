// Polo, Salinas, Juan
#include <stdio.h>
#include <math.h>
#include "stdlib.h"
// Resto de include necesarios

void ejercicio1() {

    int radio = 10;
    float porcentaje = 10;
    float res;
    float res2;

    for (int i = 2 * radio; i >= 0; i--) {
        for (int j = 0; j <= 1.5 * radio; j++) {

            res = pow((j - radio), 2.0) + pow((i - radio), 2.0);
            if (res > (pow(radio, 2.0) - porcentaje) && res < (pow(radio, 2.0) + porcentaje)) {
                printf("* ");
            } else {
                printf(" ");
            }

            res2 = pow((j - 2.0 * radio), 2.0) + pow((i - radio), 2.0);
            if (res2 > (pow(radio, 2.0) - porcentaje) && res2 < (pow(radio, 2.0) + porcentaje)) {
                printf("* ");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }

    printf("\n");

}

void ejercicio2() {

    int numerosTopper = 0;
    int numerosHarriet = 0;
    int numerosSpewart = 0;
    int numerosRango = 0;
    int longitud = 0;
    int primerNumero = 0;
    int factor;
    int resultado;
    int digito;
    int resultadoTotal;
    int itr;

    printf("Topper, introduce el codigo de activación (4 digitos)?\n");
    scanf("%d", &numerosTopper);
    //utilizo esta formula para que me diga el numero de digitos que tiene el numero intoducido
    longitud = floor(1 + log10(abs(numerosTopper)));
    primerNumero = numerosTopper / 1000;

    if (longitud == 4 && primerNumero != 0) {
    //solo se entra si los numeros de topper son correctos

        //comprobamos numeros de harriet
        printf("Harriet, introduce el codigo de activación (4 digitos)?\n");
        scanf("%d", &numerosHarriet);
        longitud = floor(1 + log10(abs(numerosHarriet)));
        primerNumero = numerosHarriet / 1000;

        if (longitud == 4 && primerNumero != 0) {
            //solo se entra si los numeros de harriet son correctos

            //comprobamos numeros de spewart
            printf("Spewart, introduce el codigo de activación (5 digitos)?\n");
            scanf("%d", &numerosSpewart);
            longitud = floor(1 + log10(abs(numerosSpewart)));
            primerNumero = numerosSpewart / 10000;

            if (longitud == 5 && primerNumero != 0) {
                //solo se entra si los numeros de spewart son correctos

                //comprobamos numeros de rango
                printf("Rango, introduce el codigo de activación (5 digitos)?\n");
                scanf("%d", &numerosRango);
                longitud = floor(1 + log10(abs(numerosRango)));
                primerNumero = numerosRango / 10000;

                if (longitud == 5 && primerNumero != 0) {
                    //Solo entramos si todos los numeros estan correctos

                    resultadoTotal = 0;
                    itr=1;

                    for (int i = 9; i>= 2; i--){
                        if (i>=5) {
                            digito = (numerosHarriet / itr) % 10;
                            // el modulo 10 me da la cifra decimal del digito
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        } else(i<5);{
                            itr=1;
                            digito = (numerosTopper / itr) % 10;
                            // el modulo 10 me da el la cifra decimal del digito
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        }
                        itr=itr*10;
                    }

                    resultadoTotal = resultadoTotal % 11;

                    resultadoTotal = 11 - resultadoTotal;
                    // obtenemos el resultado final

                    printf("\n");

                    // miramos el resultado final y dependiendo de él, el primer digito es un numero u otro
                    if (resultadoTotal < 10) {
                        printf("Primer digito: %d\n", resultadoTotal);
                    } else if (resultadoTotal == 10) {
                        printf("Primer digito: 1\n");
                    } else {
                        printf("Primer digito: 0\n");
                    }

                    //segundo digito

                    resultadoTotal = 0;
                    itr=1;

                    // hacemos lo mismo que hemos hecho arriba, cambiando la posicion de los numeros
                    for (int i = 9; i >= 0; i--) {
                        if (i<5) {
                            digito = (numerosSpewart / itr) % 10;
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        } else(i>=5);{
                            itr=1;
                            digito = (numerosRango / itr) % 10;
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        }
                        itr=itr*10;
                    }

                    resultadoTotal = resultadoTotal % 11;

                    resultadoTotal = 11 - resultadoTotal;
                    //obtenemos el resultado final

                    // miramos el resultado final y dependiendo de él, el primer digito es un numero o otro
                    if (resultadoTotal < 10) {
                        printf("Segundo digito: %d\n", resultadoTotal);
                    } else if (resultadoTotal == 10) {
                        printf("Segundo digito: 1\n");
                    } else {
                        printf("Segundo digito: 0\n");
                    }

                    printf("\n");
                }// obtenemos el codigo de desactivacion de la bomba


            } else {
                printf("Codigo No valido\n");
            }


        } else {
            printf("Codigo No valido\n");
        }


    } else {
        printf("Codigo No valido\n");
    }

    printf("\n");
}

void ejercicio3() {



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
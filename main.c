// Polo, Salinas, Juan
#include <stdio.h>
#include <math.h>
#include "stdlib.h"
// Resto de include necesarios

void ejercicio1() {

    int radio = 10;
    float porcentaje = 10.0f;
    float res = 0.0f;
    float res2 = 0.0f;

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
    int factor = 0;
    int resultado = 0;
    int digito = 0;
    int resultadoTotal = 0;
    int itr = 0;

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
                    itr = 1;

                    for (int i = 9; i >= 2; i--) {
                        if (i >= 6) {
                            digito = (numerosHarriet / itr) % 10;
                            // el modulo 10 me da la cifra decimal del digito
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        } else if (i <= 5) {
                            if (i == 5) itr = 1;
                            digito = (numerosTopper / itr) % 10;
                            // el modulo 10 me da el la cifra decimal del digito
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        }
                        itr = itr * 10;
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
                    itr = 1;

                    // hacemos lo mismo que hemos hecho arriba, cambiando la posicion de los numeros
                    for (int i = 9; i >= 0; i--) {
                        if (i >= 5) {
                            digito = (numerosRango / itr) % 10;
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        } else if (i <= 4) {
                            if (i == 4) itr = 1;
                            digito = (numerosSpewart / itr) % 10;
                            factor = pow(2, i);
                            factor = factor % 11;
                            resultado = digito * factor;
                            resultadoTotal = resultadoTotal + resultado;
                        }
                        itr = itr * 10;
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

    int pasillos = 0, filas = 0, huecos = 0, opcion = 0, pasilloDestino = 0, filaDestino = 0, huecoDestino = 0;
    int robot[] = {0, 0, 0};
    int todoOk = 0;
    do {
        printf("Numero de pasillos? ");
        scanf("%d", &pasillos);
        if (pasillos > 0) {
            printf("\nFilas de cada pasillo? ");
            scanf("%d", &filas);
            if (filas > 0) {
                printf("\nNumero de huecos de cada fila? ");
                scanf("%d", &huecos);
                if (huecos > 0) todoOk = 1;
                else printf("El numero de pasillos debe de ser un numero positivo mayor que 0");
            } else printf("El numero de pasillos debe de ser un numero positivo mayor que 0");
        } else printf("El numero de pasillos debe de ser un numero positivo mayor que 0");

    } while (todoOk != 1);

    int contenedor[pasillos + 2][filas][huecos];

    do {

        printf("Operacion a realizar\n[1] Recoger\n[2] Almacenar\n[3] Salir\nOpcion? ");

        scanf("%d", &opcion);

        if (opcion == 2) {

            todoOk = 0;

            printf("\nDonde almacenar?");

            do {
                printf("Pasillo? ");
                scanf("%d", &pasilloDestino);
                if (pasilloDestino > 0 && pasilloDestino <= pasillos) {
                    printf("\nFila?");
                    scanf("%d", &filaDestino);
                    filaDestino -= 1;
                    if (filaDestino > 0 && filaDestino <= filas) {
                        printf("\nHueco?");
                        scanf("%d", &huecoDestino);
                        huecoDestino -= 1;
                        if (huecoDestino > 0 && huecoDestino <= huecos) todoOk = 1;
                        else printf("Hueco no valido");
                    } else printf("Fila no valida");
                } else printf("Pasillo no valido");

            } while (todoOk != 1);


            if (contenedor[pasilloDestino][filaDestino][huecoDestino] != 1) {

                printf("\nPosicion Robot - pasillo: %d, fila: %d, hueco: %d\n", robot[0], robot[1] + 1, robot[2] + 1);
                printf("mov\t pasillo\t\t\tfila\t\t\thueco\n===============================================\n");
                printf("-\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                if (robot[2] != 0) {
                    for (int i = robot[2]; i > 0; i--) {
                        robot[2]--;
                        printf("L\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                    }
                }

                if (robot[1] != 0) {
                    for (int i = robot[1]; i > 0; i--) {
                        robot[1]--;
                        printf("D\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                    }
                }

                // 7 0 0

                // 4 0 1

                //

                if (robot[0] != 0) {
                    for (int i = robot[0]; i > 0; i--) {
                        robot[0]--;
                        printf("B\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                    }
                }

                printf("Recogida de material\n");

                if (robot[0] != pasilloDestino) {
                    int maxIteraciones = abs(robot[0] - pasilloDestino);
                    for (int i = 0; i < maxIteraciones; i++) {
                        if (robot[0] >= pasilloDestino) {
                            robot[0]--;
                            printf("B\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                        } else {
                            robot[0]++;
                            printf("F\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                        }
                    }
                }

                if (robot[1] != filaDestino) {
                    for (int i = 0; i < filaDestino; i++) {
                        robot[1]++;
                        printf("U\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                    }
                }

                if (robot[2] != huecoDestino) {
                    for (int i = 0; i < huecoDestino; i++) {
                        robot[2]++;
                        printf("R\t\t%d\t\t\t\t%d\t\t\t\t%d\t\n", robot[0], robot[1] + 1, robot[2] + 1);
                    }
                }

                printf("Almacenado de material\n");
                contenedor[pasilloDestino][filaDestino][huecoDestino] = 1;

            } else {
                printf("Posicion no valida, ya existe mercancia almacenada en la posicion indicada.\n");
            }

        }

    } while (opcion != 3);


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
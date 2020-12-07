// Galiñanes Martinez, Pablo (hace entrega de la practica en Canvas)
// Polo Salinas, Juan
#include <stdio.h>
#include <ctype.h>

#define MAX_CAD 100
#define CAPACIDAD_ARMARIO 50
// Si se hace uso de constantes deben definirse aqui

struct disfraz {
    char nombre[MAX_CAD];
    short traje;
    short gorra;
    float precio;
};

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[]);

void mostrarDisfraces(struct disfraz armario[], int capacidadMaxima);

struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]);

int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]);

int main() {
    int menu = 0, returnval = 0;
    char nombreCRUD[MAX_CAD] = "?";
    char *tipo = "gorra";
    float precioCRUD = 0.0f;
    short trajeCRUD = 0, gorraCRUD = 0;
    struct disfraz disfrazNulo = (struct disfraz) {.nombre="?", .precio=0, .traje=0, .gorra=0};
    struct disfraz armario[CAPACIDAD_ARMARIO];
    for (int i = 0; i < sizeof(armario) / sizeof(armario[0]); ++i) armario[i] = disfrazNulo;
    do //menu que se ejecuta en bucle salvo que el usuario introduza un 5
    {
        printf("\n\n1.- Insertar parte\n2.- Buscar disfraz\n3.- Mostrar disfraces\n4.- Borrar disfraz\n5.- Salir\n\nIntroduzca una opción(1-5)");
        scanf("%d", &menu);
        if (menu <= 0 || menu > 5) {
            printf("ERROR: Opcion introducida no valida\n");
        }

        if (menu == 1) {
            //Hacer ej 1;
            printf("Insertar Parte\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD);
            printf("Introduzca si es traje: ");
            scanf("%hu", &trajeCRUD);
            if (trajeCRUD >= 0 && trajeCRUD <= 1) {
                printf("Introduzca si es gorra: ");
                scanf("%hu", &gorraCRUD);
                if (gorraCRUD >= 0 && gorraCRUD <= 1) {
                    printf("Introduzca el precio: ");
                    scanf("%f", &precioCRUD);
                    if (precioCRUD >= 0.0f) {
                        if (gorraCRUD == 1) tipo = "gorra";
                        else if (trajeCRUD == 1) tipo = "traje";
                        returnval = insertarParte(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD, precioCRUD,
                                                  tipo);
                        if (returnval == 1) {
                            printf("Parte insertada con exito\n");
                        } else if (returnval == 0) {
                            printf("Error, la parte no es valida o la agenda esta llena\n");
                        } else {
                            printf("La parte ya estaba insertada");
                        }

                    }


                }
            }
        }


        if (menu == 2) {
            //Hacer ej 2;
        }

        if (menu == 3) {
            //Hacer ej 3;
        }

        if (menu == 4) {
            //Hacer ej 4;
        }

    } while (menu != 5);
}

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[]) {
    int encontrado = 0;
    short traje = 0, gorra = 0;

    if (tipo == "gorra" || tipo == "traje") {
        if (armario[49].nombre[0] == "?"[0]) {

            for (int i = 0; i < capacidadMaxima; ++i) {

                if (tipo == "traje") traje = 1;
                if (tipo == "gorra") gorra = 1;

                if (armario[i].nombre[0] == "?"[0]) {
                    armario[i] = (struct disfraz) {.nombre = nombreDisfraz, .precio = precioParte, .traje= traje, .gorra=gorra};
                    return 1;
                }

                if (armario[i].nombre[0] > nombreDisfraz[0]) {
                    for (int j = capacidadMaxima - 1; j > i; --j) {
                        armario[j + 1] = armario[j];
                    }
                    armario[i] = (struct disfraz) {.nombre = nombreDisfraz, .precio = precioParte, .traje= traje, .gorra=gorra};
                    return 1;
                }

            }

        } else {
            return -1;
        }
    } else {
        return 0;
    }
}

void mostrarDisfraces(struct disfraz armario[], int capacidadMaxima) {
    // TO-DO
    printf("Parte no realizada\n");
}

struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {
    // TO-DO
    struct disfraz nulo = {"?", 0, 0, 0.0};
    return nulo;
}

int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {
    // TO-DO
    return -1;
}
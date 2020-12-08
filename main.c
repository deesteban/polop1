// Galiñanes Martinez, Pablo (hace entrega de la practica en Canvas)
// Polo Salinas, Juan
#include <stdio.h>
#include <string.h>

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
    char tipoCRUD[MAX_CAD] = "";
    float precioCRUD = 0.0f;
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
            printf("Es traje o gorra?");
            scanf("%s", &tipoCRUD);
            if (strcmp(tipoCRUD, "gorra") == 0 || strcmp(tipoCRUD, "traje") == 0) {
                printf("Introduzca el precio: ");
                scanf("%f", &precioCRUD);
                if (precioCRUD >= 0.0f) {
                    returnval = insertarParte(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD, precioCRUD,
                                              tipoCRUD);
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


        if (menu == 2) {
            printf("Buscar Disfraz\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD);
            struct disfraz disfrazEncontrado = buscarDisfraz(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD);
            if (disfrazEncontrado.nombre[0] != '?') {
                printf("%s\t%.2f\t", disfrazEncontrado.nombre, disfrazEncontrado.precio);
                if (disfrazEncontrado.traje == 1) printf("Traje: [Si]\t");
                else printf("Traje: [No]\t");
                if (disfrazEncontrado.gorra == 1) printf("Gorra: [Si]\n");
                else printf("Gorra: [No]\n");
            } else {
                printf("El disfraz no existe.");
            }
        }

        if (menu == 3) {
            mostrarDisfraces(armario, sizeof(armario) / sizeof(armario[0]));
        }

        if (menu == 4) {
            printf("Borrar Disfraz\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD);
            int contactosBorrados = borrarDisfraz(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD);
            if (contactosBorrados > 0) printf("%d disfraz(ces) borrados con exito.", contactosBorrados);
            else printf("Error, no existen disfraces con ese nombre");
        }

    } while (menu != 5);
}

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[]) {
    struct disfraz busquedaPre = buscarDisfraz(armario, capacidadMaxima, nombreDisfraz);
    if ((busquedaPre.gorra != 1 && strcmp(tipo, "gorra") == 0) ||
        (busquedaPre.traje != 1 && strcmp(tipo, "traje") == 0)) {
        if (armario[49].nombre[0] == "?"[0] || strcmp(tipo, "gorra") == 0 || strcmp(tipo, "traje") == 0) {

            if (busquedaPre.nombre[0] != '?') {
                for (int i = 0; i < capacidadMaxima; ++i) {
                    if (strcmp(armario[i].nombre, nombreDisfraz) == 0) {
                        armario[i].precio += precioParte;
                        if (strcmp(tipo, "traje") == 0) armario[i].traje = 1;
                        if (strcmp(tipo, "gorra") == 0) armario[i].gorra = 1;
                        return 1;
                    }
                }

            } else {

                for (int i = 0; i < capacidadMaxima; ++i) {

                    if (armario[i].nombre[0] == '?') {
                        strcpy(armario[i].nombre, nombreDisfraz);
                        armario[i].precio = precioParte;
                        if (strcmp(tipo, "traje") == 0) armario[i].traje = 1;
                        if (strcmp(tipo, "gorra") == 0) armario[i].gorra = 1;
                        return 1;
                    }

                    if (armario[i].nombre[0] > nombreDisfraz[0]) {
                        for (int j = capacidadMaxima - 1; j >= i; --j) {
                            armario[j + 1] = armario[j];
                        }
                        strcpy(armario[i].nombre, nombreDisfraz);
                        armario[i].precio = precioParte;
                        if (strcmp(tipo, "traje") == 0) armario[i].traje = 1;
                        if (strcmp(tipo, "gorra") == 0) armario[i].gorra = 1;
                        return 1;
                    }

                }
            }

        } else {
            return 0;
        }
    } else {
        return -1;
    }
    return -1;
}


void mostrarDisfraces(struct disfraz armario[], int capacidadMaxima) {
    if (armario[0].nombre[0] != '?') {
        for (int i = 0; i < capacidadMaxima; ++i) {
            if (armario[i].nombre[0] != '?') {
                printf("%d\t%s\t%.2f\t", i + 1, armario[i].nombre, armario[i].precio);
                if (armario[i].traje == 1) printf("Traje: [Si]\t");
                else printf("Traje: [No]\t");
                if (armario[i].gorra == 1) printf("Gorra: [Si]\n");
                else printf("Gorra: [No]\n");
            }
        }
    } else {
        printf("Armario Vacio.");
    }
}

struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {

    struct disfraz disfrazEncontrado = (struct disfraz) {.nombre="?", .precio=0, .traje=0, .gorra=0};

    for (int i = 0; i < capacidadMaxima; ++i) {
        if (strcmp(armario[i].nombre, nombre) == 0) {
            disfrazEncontrado = armario[i];
        }
    }

    return disfrazEncontrado;
}

int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {
    int contactosBorrados = 0;
    for (int i = 0; i < capacidadMaxima; ++i) {
        if (strcmp(armario[i].nombre, nombre) == 0) {
            for (int j = i; j < capacidadMaxima - 1; ++j) {
                armario[j] = armario[j + 1];
            }
            contactosBorrados++;
        }
    }
    return contactosBorrados;
}

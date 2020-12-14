// Galiñanes Martinez, Pablo (hace entrega de la practica en Canvas)
// Polo Salinas, Juan
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//usamos math.h para la insercion ordenada y solo para calcular el minimo entre dos numeros (fmin)
#include <math.h>


#define MAX_CAD 100
#define CAPACIDAD_ARMARIO 3


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
    int menu = 0, returnval = 0, len = 0, len1 = 0, len2 = 0;
    char nombreCRUD[MAX_CAD] = "?";
    char tipoCRUD[MAX_CAD] = "";
    float precioCRUD = 0.0f;
    struct disfraz disfrazNulo = (struct disfraz) {.nombre="?", .precio=0, .traje=0, .gorra=0};
    struct disfraz armario[CAPACIDAD_ARMARIO];
    for (int i = 0; i < sizeof(armario) / sizeof(armario[0]); ++i) armario[i] = disfrazNulo;
    do {
        printf("\n1.- Insertar parte\n2.- Buscar disfraz\n3.- Mostrar disfraces\n4.- Borrar disfraz\n5.- Salir\n\nIntroduzca una opcion(1-5)\n");
        scanf("%d", &menu);
        if (menu <= 0 || menu > 5) {
            printf("\nERROR: Opcion introducida no valida\n"); //menu que se ejecuta en bucle salvo que el usuario introduza un 5
        }

        if (menu == 1) {
            printf("Insertar Parte\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD); //Solicitamos el nombre del disfraz
            len = strlen(nombreCRUD);
            for (int i = 0; i <= len; i++) {
                nombreCRUD[i] = tolower(nombreCRUD[i]); // convertimos el nombre del disfraz a minusculas
            }
            printf("Es traje o gorra?");
            scanf("%s", &tipoCRUD); // solicitamos el tipo de disfraz
            len1 = strlen(tipoCRUD);
            for (int i = 0; i <= len1; i++) {
                tipoCRUD[i] = tolower(tipoCRUD[i]); // convertimos la palabra gorra/traje a minusculas
            }

            if (strcmp(tipoCRUD, "gorra") == 0 || strcmp(tipoCRUD, "traje") ==
                                                  0) { //si la palabra es traje o gorra seguimos con el proceso preguntando por el precio
                printf("Introduzca el precio: ");
                scanf("%f", &precioCRUD); //solicitamos el precio
                if (precioCRUD >= 0.0f) {
                    returnval = insertarParte(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD, precioCRUD,
                                              tipoCRUD);
                    if (returnval == 1) { //si el precio es positivo la parte se inserta con exito
                        printf("\nParte insertada con exito\n");
                    } else if (returnval == 0) { // si el armario esta lleno o no es válida devuelve un error
                        printf("\nError, la parte no es valida o el armario esta lleno\n");
                    } else {
                        printf("\nLa parte ya estaba insertada"); //si no devuelve nada el if es porque la parte ya estaba insertada
                    }

                }


            } else {
                printf("\nERROR: No es un traje o una gorra");
            } //si la palabra no es traje o gorra indica un error
        }


        if (menu == 2) {
            printf("Buscar Disfraz\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD);
            len = strlen(nombreCRUD);
            for (int i = 0; i <= len; i++) {
                nombreCRUD[i] = tolower(
                        nombreCRUD[i]); // convertimos el nombre que se solicita al usuario en minusculas
            }
            struct disfraz disfrazEncontrado = buscarDisfraz(armario, sizeof(armario) / sizeof(armario[0]),
                                                             nombreCRUD); //creamos una estructura para el disfraz encontrado
            if (disfrazEncontrado.nombre[0] !=
                '?') { //si el nombre es distinto de ?, es decir, si no esta vacío el hueco, imprime en pantalla el nombre, el precio y si es traje o gorra
                printf("%s\t%.2f\t", disfrazEncontrado.nombre, disfrazEncontrado.precio);
                if (disfrazEncontrado.traje == 1) printf("Traje: [Si]\t");
                else printf("Traje: [No]\t");
                if (disfrazEncontrado.gorra == 1) printf("Gorra: [Si]\n");
                else printf("Gorra: [No]\n");
            } else {
                printf("\nEl disfraz no existe."); // si el nombre no coincide se muestra que el disfraz no existe
            }
        }

        if (menu == 3) {
            mostrarDisfraces(armario, sizeof(armario) /
                                      sizeof(armario[0])); //muestra la estructura mostrar disfraces en pantalla
        }

        if (menu == 4) {
            printf("Borrar Disfraz\n---------\nPor favor introduzca el nombre del disfraz: ");
            scanf("%s", &nombreCRUD);
            len2 = strlen(nombreCRUD);
            for (int i = 0; i <= len2; i++) {
                nombreCRUD[i] = tolower(nombreCRUD[i]); //convertimos el nombre introducido a minusculas
            }
            int disfracesBorrados = borrarDisfraz(armario, sizeof(armario) / sizeof(armario[0]), nombreCRUD);
            if (disfracesBorrados > 0)
                printf("%d disfraz(ces) borrados con exito.",
                       disfracesBorrados); //si el disfraz se encuentra en el armario se elimina y se devuelve un numero positivo que muestra el numero de disfraces eliminados
            else printf("Error, no existen disfraces con ese nombre");
        }

    } while (menu != 5);
}

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[]) {
    struct disfraz busquedaPre = buscarDisfraz(armario, capacidadMaxima,
                                               nombreDisfraz); //creamos esta estructura para hacer una prebusqueda por si el disfraz introducido estuviera ya en el armario
    if ((busquedaPre.gorra != 1 && strcmp(tipo, "gorra") == 0) ||
        //si no hay gorra o traje del nombre introducido sigue el ejercicio
        (busquedaPre.traje != 1 && strcmp(tipo, "traje") == 0)) {
        if (armario[capacidadMaxima - 1].nombre[0] == "?"[0] && (strcmp(tipo, "gorra") == 0 || strcmp(tipo, "traje")) ==
                                                                0) { //si hay un hueco vacio sigue el ejercicio y ademas el nombre introducido es gorra/disfraz

            if (busquedaPre.nombre[0] != '?') {
                for (int i = 0; i < capacidadMaxima; ++i) {
                    if (strcmp(armario[i].nombre, nombreDisfraz) ==
                        0) { //recorre el armario comparando el nombre introducido con los huecos distintos de '?'
                        armario[i].precio += precioParte; //se suma el precio al elemento si se añade un la otra parte del disfraz si existe
                        if (strcmp(tipo, "traje") == 0)
                            armario[i].traje = 1; //convierte el valor de 0 a 1 si se actualizase
                        if (strcmp(tipo, "gorra") == 0) armario[i].gorra = 1;
                        return 1;
                    }
                }

            } else {

                for (int i = 0; i <
                                capacidadMaxima; ++i) { //recorre el armario comparando el nombre introducido con los huecos vacios

                    //si el hueco es vacio insertamos
                    if (armario[i].nombre[0] == '?') {
                        strcpy(armario[i].nombre, nombreDisfraz);
                        armario[i].precio = precioParte;
                        if (strcmp(tipo, "traje") == 0)
                            armario[i].traje = 1; //convierte el valor de 0 a 1 si se actualizase
                        if (strcmp(tipo, "gorra") == 0) armario[i].gorra = 1;
                        return 1;
                    }

                    //si el hueco tiene un item con nombre menor seguimos, si es mayor quiere decir que se tiene que desplazar (insercion ordenada)
                    int minLets = fmin(strlen(armario[i].nombre),
                                      strlen(nombreDisfraz)), digitsToCompareA = 0, digitsToCompareB = 0;
                    //hacemos la suma individual del valor ASCII de cada digito de los nombres hasta el final de uno de los nombres.
                    for (int j = 0; j < minLets; ++j) {
                        digitsToCompareA += armario[i].nombre[j];
                        digitsToCompareB += nombreDisfraz[j];
                    }
                    //comparamos para ver si es menor o no.
                    if (digitsToCompareA > digitsToCompareB) {
                        //en caso de que si, desplazamos to-do el armario hasta el final teniendo en cuenta que pueda haber un overflow.
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
                printf("%d\t%s\t%.2f\t", i + 1, armario[i].nombre,
                       armario[i].precio); //imprime en pantalla desde la posicion cero a la capacidad maxima del armario, solo si el nombre del disfraz es distinto de '?'
                if (armario[i].traje == 1)
                    printf("Traje: [Si]\t"); //si el valor traje es 1 muestra que hay traje, igual con la gorra
                else printf("Traje: [No]\t");
                if (armario[i].gorra == 1) printf("Gorra: [Si]\n");
                else printf("Gorra: [No]\n");
            }
        }
    } else {
        printf("\nArmario Vacio."); // si el armario esta lleno de '?', muestra armario vacio
    }
}

struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {

    struct disfraz disfrazEncontrado = (struct disfraz) {.nombre="?", .precio=0, .traje=0, .gorra=0}; //creamos la estructura disfraz encontrado

    for (int i = 0; i < capacidadMaxima; ++i) {
        if (strcmp(armario[i].nombre, nombre) ==
            0) { // recorre la matriz y si el nombre introducido por el usuario coincide lo muestra junto a todos sus datos(precio y tipo)
            disfrazEncontrado = armario[i];
        }
    }

    return disfrazEncontrado; //devuelve el struct disfraz encontrado
}

int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]) {
    int disfracesBorrados = 0;
    for (int i = 0; i < capacidadMaxima; ++i) {
        if (strcmp(armario[i].nombre, nombre) ==
            0) { //compara si el nombre recibido se encuentra en algun punto del armario y si es asi, el contador de disfraces aumenta y indica el numero de elementos borrados
            for (int j = i; j < capacidadMaxima - 1; ++j) {
                armario[j] = armario[j + 1];
            }
            disfracesBorrados++;
        }
    }
    return disfracesBorrados;
}
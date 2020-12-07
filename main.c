// Galiñanes Martinez, Pablo (hace entrega de la practica en Canvas)
// Polo Salinas, Juan
#include <stdio.h>
#include <ctype.h>

#define MAX_CAD 100
// Si se hace uso de constantes deben definirse aqui

struct disfraz
{
    char nombre[MAX_CAD];
    short traje;
    short gorra;
    float precio;
};

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[]);
void mostrarDisfraces(struct disfraz armario[], int capacidadMaxima);
struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]);
int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[]);

int main()
{
    int menu;


    do //menu que se ejecuta en bucle salvo que el usuario introduza un 5
    {
        printf("\n\n1.- Insertar parte\n2.- Buscar disfraz\n3.- Mostrar disfraces\n4.- Borrar disfraz\n5.- Salir\n\nIntroduzca una opción(1-5)");
        scanf("%d", &menu);
        if(menu<=0 || menu>5)
        {
            printf("ERROR: Opcion introducida no valida\n");
        }

        if (menu==1)
        {
            //Hacer ej 1;
        }

        if (menu==2)
        {
            //Hacer ej 2;
        }

        if (menu==3)
        {
            //Hacer ej 3;
        }

        if (menu==4)
        {
            //Hacer ej 4;
        }

    }
    while(menu!=5);

    // El contenido que hay a continuación es solo un ejemplo de suo de las funciones
    struct disfraz armario[50];
    struct disfraz buscado;
    int resultadoInsercion, numeroElementosBorrados;
    // debe inicializarse el armario a vacio. todos los elementos nulos despues importar desde un txt si hubiera disfraces con la estructura por ejemplo boda;1;1;3300.000
    resultadoInsercion = insertarParte(armario, 50, "disfraz1", 100, "traje");
    mostrarDisfraces(armario, 50);
    buscado = buscarDisfraz(armario, 50, "disfraz1");
    // se puede imprimir el disfraz
    numeroElementosBorrados= borrarDisfraz(armario, 50, "disfraz1");
    return 0;
}

int insertarParte(struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[])
{
    // TO-DO
    return -1;
}

void mostrarDisfraces(struct disfraz armario[], int capacidadMaxima)
{
    // TO-DO
    printf("Parte no realizada\n");
}

struct disfraz buscarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[])
{
    // TO-DO
    struct disfraz nulo = {"?", 0, 0, 0.0};
    return nulo;
}

int borrarDisfraz(struct disfraz armario[], int capacidadMaxima, char nombre[])
{
    // TO-DO
    return -1;
}
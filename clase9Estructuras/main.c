#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_PERSONAS 3


// TYPEDEF = esta palabra reservada te permite definir tipos nuevos. usar palabras a
// como de tipo. para no tener que escribir muchas veces toda la estructura de
// tipos que son mas complejos que un int o un float como es el caso de estas estructuras.


typedef struct
    {
        float dni;
        char nombre[30];
        char apellido[30];
        int estaVacio;
    }ePersona;

void pedirDatos (ePersona[], int);
void mostrar (ePersona[], int);
void inicializarPersonas (ePersona[], int);

int main()
{
    ePersona persona[CANT_PERSONAS];
    inicializarPersonas (persona,CANT_PERSONAS);
    pedirDatos (persona,CANT_PERSONAS);
    mostrar (persona, CANT_PERSONAS);
}

void inicializarPersonas (ePersona tabla[], int cantidad)
{
    int i;
    for (i=0; i<cantidad; i++)
    {
        tabla[i].estaVacio = 1;
    }
}


void mostrar (ePersona tabla[], int cantidad)
{
    int i;
    for (i=0; i<cantidad; i++)
    {
        if (tabla[i].estaVacio == 0)
        {
            printf (" El nombre y apellido son %s %s y su dni es %f ", tabla[i].nombre, tabla[i].apellido, tabla[i].dni );
        }
        else
        {
            printf ("un vacio");
        }
    }

}

void pedirDatos (ePersona tabla[], int cantidad)
{
    int i;
    for (i=0; i<cantidad; i++)
    {
        printf ("nombre:");
        fflush(stdin);
        gets (tabla[i].nombre);

        printf ("apellido:");
        fflush(stdin);
        gets (tabla[i].apellido);

        printf ("dni:");
        scanf ("%f", &tabla[i].dni);

        tabla[i].estaVacio = 0;
    }
}


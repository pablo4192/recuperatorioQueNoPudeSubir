#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"



int listarAlquileres(eAlquileres alquileres[], int tamA)
{
    int todoOk=0;
    int flagNoSeMostro=1;

    printf("      *** Listado de Alquileres ***  \n\n");
    printf("Codigo     CodigoJuego  CodigoCliente Fecha  \n");

    if(alquileres!=NULL && tamA>=0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(!alquileres[i].isEmpty)
            {
                mostrarAlquiler(alquileres[i]);
                flagNoSeMostro=0;
                todoOk=1;


            }
        }


        if(flagNoSeMostro)
        {
            printf("No hay Alquileres que mostrar");

        }
    }
    printf("\n\n");
    return todoOk;
}

void mostrarAlquiler(eAlquileres unAlquiler)
{
   printf("%d       %d       %d          %d/%d/%d   \n", unAlquiler.codigoAlquiler,
                                             unAlquiler.codigoJuego,
                                             unAlquiler.codigoCliente,
                                             unAlquiler.fecha.dia,
                                             unAlquiler.fecha.mes,
                                             unAlquiler.fecha.anio);

}

int altaAlquiler(eAlquileres alquiler[], int tamA, int* pId, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    int indice;
    eAlquileres nuevoAlquiler;

    if(alquiler!=NULL && tamA>0 && pId!=NULL)
    {
        system("cls");
        printf("Alta de Alquileres\n\n");


        indice=buscarAlquilerLibre(alquiler, tamA);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            listarJuegos(juegos, tamJ, categorias, tamC);

            printf("Se le asigno el idAlquiler: %d\n", *pId);
            nuevoAlquiler.codigoAlquiler=*pId;

            printf("Ingrese Codigo de juego: ");
            scanf("%d", &nuevoAlquiler.codigoJuego);

            printf("Ingrese CodigoCliente: ");
            scanf("%d", &nuevoAlquiler.codigoCliente);

            printf("Ingrese Fecha: ");
            scanf("%d/%d/%d", &nuevoAlquiler.fecha.dia,
                              &nuevoAlquiler.fecha.mes,
                              &nuevoAlquiler.fecha.anio);

            nuevoAlquiler.isEmpty=0;
            alquiler[indice]=nuevoAlquiler;

            (*pId)++;
            todoOk=1;
        }
    }

    return todoOk;
}

int buscarAlquilerLibre(eAlquileres alquiler[], int tamA)
{
    int indice =-1;

    if(alquiler!=NULL && tamA>0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(alquiler[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;  //retorno el indice libre
}

int inicializarAlquileres(eAlquileres alquileres[], int tamA)   //recorre en la estructura los arrays de empleados y inicializa el valor del flag isEmpty en 1 (este lugar esta vacio, disponible para un nuevo empleado)
{
     int todoOk=0;

    if(alquileres!=NULL && tamA>0)
    {
        for(int i=0; i<tamA; i++)
        {
            alquileres[i].isEmpty=1;
        }
        todoOk=1;
    }


    return todoOk;
}

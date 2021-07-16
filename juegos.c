#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"
#include "utn.h"
#include "informes.h"



int listarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;

    printf("      *** Listado de Juegos Disponibles ***  \n\n");
    printf("Codigo   Descripcion  Importe    Categoria  \n");

    if(juegos!=NULL && tamJ>=0 && categorias!=NULL && tamC>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            mostrarJuego(juegos[i], categorias, tamC);
            todoOk=1;
        }
    }
    printf("\n\n");
    return todoOk;
}

void mostrarJuego(eJuego unjuego, eCategoria categorias[], int tamC)  //recibe solo un empleado a la vez y lo printea
{
    char descripcion[20];
    cargarDescripcionCategoria(unjuego.idCategoria, categorias, tamC, descripcion);

    printf("  %d    %10s   %.2f   %10s   \n", unjuego.codigo,
                                             unjuego.descripcion,
                                             unjuego.importe,
                                             descripcion);
}

int buscarJuego(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, int id)
{
    int indice=-1;


    if(juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].codigo==id)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;


}

int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamC, char descripcion[])
{
    int todoOk=0;

    if(idCategoria>=1 && idCategoria<=5 && categorias!=NULL && tamC>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamC; i++)
        {
            if(categorias[i].id==idCategoria)  //si el id (sector) que me paso mostrarEmpleado es == al id en el campo de la estructura esector
            {
                strcpy(descripcion, categorias[i].descripcion);   //copio descripcion que se encuentra en la estructura esector a la variable descripcion (que la tengo por referencia) de mostrarEmpleado
                todoOk=1;
                break;
            }
        }

    }

    return todoOk;

}

int cargarDescripcionJuego(int idJuego, eCliente clientes[], int tam, eJuego juegos[], int tamJ, char descripcionJuego[])
{
    int todoOk=0;

    if(juegos!=NULL && tamJ>0 && descripcionJuego!=NULL && clientes!=NULL && tam>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].codigo==idJuego)  //si el id (sector) que me paso mostrarEmpleado es == al id en el campo de la estructura esector
            {
                strcpy(descripcionJuego, juegos[i].descripcion);   //copio descripcion que se encuentra en la estructura esector a la variable descripcion (que la tengo por referencia) de mostrarEmpleado
                todoOk=1;
                break;
            }
        }

    }

    return todoOk;

}




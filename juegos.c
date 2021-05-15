#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"




int listarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;



    printf("      *** Listado de Clientes ***  \n\n");
    printf("Codigo     Descripcion  Importe  IdCategoria  \n");

    if(juegos!=NULL && tamJ>=0)
    {
        for(int i=0; i<tamJ; i++)
        {
                mostrarJuego(juegos[i]);

                todoOk=1;
        }
    }
    printf("\n\n");
    return todoOk;
}

void mostrarJuego(eJuego unjuego)  //recibe solo un empleado a la vez y lo printea
{
   printf("%d        %10s    %.2f  %d   \n", unjuego.codigo,
                                             unjuego.descripcion,
                                             unjuego.importe,
                                             unjuego.idCategoria);
}


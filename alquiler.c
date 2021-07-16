#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"
#include "utn.h"
#include "informes.h"



int listarAlquileres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    int flagNoSeMostro=1;

    printf("      *** Listado de Alquileres ***  \n\n");
    printf("CodAlquiler  CodJuego  Descripcion      Nombre   Apellido      Localidad     CodCliente   Fecha Alquiler  \n");

    if(alquileres!=NULL && tamA>=0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(!alquileres[i].isEmpty)
            {
                mostrarAlquiler(alquileres[i], clientes, tam, juegos, tamJ, categorias, tamC);
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

void mostrarAlquiler(eAlquileres unAlquiler, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    char nombreCliente[51];
    char apellido[51];
    char descripcionJuego[20];
    char descripcionLocalidad[20];

    cargarApellidoCliente(unAlquiler.codigoCliente, clientes, tam, nombreCliente, apellido);
    cargarDescripcionJuego(unAlquiler.codigoJuego,clientes, tam, juegos, tamJ, descripcionJuego);
    cargarLocalidadCliente(unAlquiler.codigoCliente, clientes, tam, descripcionLocalidad);


    printf("   %d           %d   %10s  %10s %10s     %10s           %d        %d/%d/%d   \n", unAlquiler.codigoAlquiler,
           unAlquiler.codigoJuego,
           descripcionJuego,
           nombreCliente,
           apellido,
           descripcionLocalidad,
           unAlquiler.codigoCliente,
           unAlquiler.fecha.dia,
           unAlquiler.fecha.mes,
           unAlquiler.fecha.anio);

}

int altaAlquiler(eAlquileres alquiler[], int tamA, int* pId, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eCliente clientes[], int tam)
{
    int todoOk=0;
    int indiceAlquiler;
    int indiceJuego;
    int idCliente;
    int idJuego;
    eAlquileres nuevoAlquiler;

    if(alquiler!=NULL && tamA>0 && pId!=NULL && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0 && clientes!=NULL && tam>0)
    {
        system("cls");
        printf("Alta de Alquileres\n\n");


        indiceAlquiler=buscarAlquilerLibre(alquiler, tamA);

        if(indiceAlquiler==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            listarJuegos(juegos, tamJ, categorias, tamC);

            printf("Se le asigno el idAlquiler: %d\n", *pId);
            nuevoAlquiler.codigoAlquiler=*pId;
//juego
            if(!utn_getNumero(&idJuego, "Ingrese codigo de juego que desea alquilar: \n", "Error, el codigo ingresado no existe..\n", 1000, 1014, 3))
            {
                printf("Hubo un problema al guardar el codigo de juego\n");
            }
            else
            {
                indiceJuego=buscarJuego(juegos, tamJ, categorias, tamC, idJuego);
                if(indiceJuego==-1)
                {
                    printf("El juego no esta disponible en este momento\n");
                }
                else
                {
                    nuevoAlquiler.codigoJuego=idJuego;
                    system("cls");
                    printf("Juego a alquilar:\n");
                    printf("Codigo   Descripcion  Importe  IdCategoria  \n");
                    mostrarJuego(juegos[indiceJuego], categorias, tamC);
                    printf("\n");
                    listarClientes(clientes, tam);
//cliente
                    printf("Ingrese CodigoCliente: ");
                    scanf("%d", &idCliente);

                    if(buscarCliente(clientes, tam, idCliente)==-1)
                    {
                        printf("No hay un cliente con el id ingresado\n");
                    }
                    else
                    {
                        nuevoAlquiler.codigoCliente=idCliente;
                        printf("Ingrese Fecha: ");
                        scanf("%d/%d/%d", &nuevoAlquiler.fecha.dia,
                                          &nuevoAlquiler.fecha.mes,
                                          &nuevoAlquiler.fecha.anio);


                        nuevoAlquiler.isEmpty=0;
                        alquiler[indiceAlquiler]=nuevoAlquiler;

                        (*pId)++;
                        todoOk=1;
                    }
                }
            }

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






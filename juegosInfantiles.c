#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"




int menu()
{
    int opcion; //variable donde guardo la opcion elegida

    system("cls"); //para limpiar cada vez que aparece el menu
    printf("*** Menu Gestion de Juegos Infantiles ***\n");
    printf("1) Alta Clientes\n");
    printf("2) Modificar Clientes\n");
    printf("3) Baja Clientes\n");
    printf("4) Listar Clientes\n");
    printf("5) Alta Alquiler\n");
    printf("6) Listar Alquileres\n");
    printf("7) Salir\n");

    printf("Escoja una opcion: ");
    scanf("%d", &opcion);   //guardo la opcion

    return opcion;  //retorno la opcion al main
}

int altaCliente(eCliente lista[], int tam, int* pId)
{
    int todoOk=0;
    int indice;
    eCliente nuevoCliente;

    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("Alta de Clientes\n\n");


        indice=buscarLibre(lista, tam);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Se le asigno el id: %d\n", *pId);
            nuevoCliente.codigo=*pId;

            printf("Ingrese Nombre: ");
            fflush(stdin);
            scanf("%s", nuevoCliente.nombre);

            printf("Ingrese Apellido: ");
            fflush(stdin);
            scanf("%s", nuevoCliente.apellido);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);

            printf("Ingrese Telefono: ");
            scanf("%d", &nuevoCliente.telefono);

            nuevoCliente.isEmpty=0;
            lista[indice]=nuevoCliente;

            (*pId)++;
            todoOk=1;
        }
    }

    return todoOk;
}

int inicializarClientes(eCliente lista[], int tam)   //recorre en la estructura los arrays de empleados y inicializa el valor del flag isEmpty en 1 (este lugar esta vacio, disponible para un nuevo empleado)
{
    int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }


    return todoOk;
}

int buscarLibre(eCliente lista[], int tam)
{
    int indice =-1; //variable donde voy a guardar el indice libre, la precargo con -1, si se se encuentra lugar se cambia el valor por el indice

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)    //==1 quiere decir que el indice esta libre
            {
                indice=i;   //copio el indice que itero en la variable a retornar
                break;  //corto una vez que encontro un indice vacio
            }
        }
    }
    return indice;  //retorno el indice libre
}

int modificarCliente(eCliente lista[], int tam)
{
    int todoOk=0;
    int id;
    int indice;
    int opcion;
    char confirma;

    system("cls");
    printf("Modificar Cliente:\n");

    if(listarClientes(lista, tam))
    {

        printf("Ingrese id cliente a Modificar: ");
        scanf("%d", &id);

        indice=buscarCliente(lista, tam, id);

        if(indice==-1)
        {
            printf("No existe un cliente con el numero de id: %d\n", id);
        }
        else
        {

            listarClientes(lista, tam);

            printf("\n\n");
            printf("Informacion del Cliente:\n");
            printf("1) Nombre\n");
            printf("2) Apellido\n");
            printf("3) Sexo\n");
            printf("4) Telefono\n");


            printf("Que dato desea Modificar?: ");
            scanf("%d", &opcion);

            printf("Confirma opcion?: \n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {
                switch(opcion)
                {
                case 1:
                    printf("Modificar nombre: ");
                    scanf("%s", lista[indice].nombre);
                    break;
                case 2:
                    printf("Modificar Apellido: ");
                    scanf("%s", lista[indice].apellido);
                    break;
                case 3:
                    printf("Modificar Telefono: ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].telefono);
                    break;

                }
                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada!\n");
            }

        }
    }
    return todoOk;
}

int listarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    int flagNoSeMostro=1;

    printf("      *** Listado de Clientes ***  \n\n");
    printf("Codigo     Nombre  Apellido  Sexo     Telefono  \n");

    if(lista!=NULL && tam>=0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarCliente(lista[i]);
                flagNoSeMostro=0;
                todoOk=1;


            }
        }


        if(flagNoSeMostro)
        {
            printf("No hay Clientes que mostrar");

        }
    }
    printf("\n\n");
    return todoOk;
}

void mostrarCliente(eCliente unCliente)  //recibe solo un empleado a la vez y lo printea
{
   printf("%d  %10s    %10s   %c   %d   \n", unCliente.codigo,
                                             unCliente.nombre,
                                             unCliente.apellido,
                                             unCliente.sexo,
                                             unCliente.telefono);

}

int buscarCliente(eCliente lista[], int tam, int id)    //busco el legajo pasado por parametro en el arreay de empleados
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && id==lista[i].codigo)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;

}

int ordenarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    eCliente auxiliar;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].apellido, lista[j].apellido) >0)
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int bajaCliente(eCliente lista[], int tam)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("Baja Cliente:\n");

    if(listarClientes(lista, tam))
    {
        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);

        indice=buscarCliente(lista, tam, id);

        if(indice==-1)
        {
            printf("No existe un Cliente con el numero de id: %d\n", id);
        }
        else
        {
            printf("Codigo     Nombre  Apellido  Sexo     Telefono  \n");
            mostrarCliente(lista[indice]);
            printf("\nConfirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {
                lista[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("\nBaja cancelada\n");
            }
        }
    }

    return todoOk;
}









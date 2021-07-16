#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "utn.h"
#include "informes.h"





int menu()
{
    int opcion;

    system("cls");
    printf("*** Menu Gestion de Juegos Infantiles ***\n");
    printf("1) Alta Clientes\n");
    printf("2) Modificar Clientes\n");
    printf("3) Baja Clientes\n");
    printf("4) Listar Clientes\n");
    printf("5) Alta Alquiler\n");
    printf("6) Listar Alquileres\n");
    printf("7) Informes\n");
    printf("8) Salir\n");

    utn_getNumero(&opcion, "Escoja una opcion: \n", "Error ingrese una opcion valida: \n", 1, 8, 3);

    return opcion;
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

            if(!utn_getStringChar(nuevoCliente.nombre, "Ingrese Nombre: \n", "Error Ingrese nombre (Solo letras, Respete min y max caracteres): \n", 2, 51, 2))
            {
                printf("Hubo un problema al guardar el Nombre\n");
            }

            if(!utn_getStringChar(nuevoCliente.apellido, "Ingrese Apellido: \n", "Error Ingrese Apellido (Solo letras, Respete min y max caracteres): \n", 2, 51, 2))
            {
                printf("Hubo un problema al guardar el Apellido\n");
            }

            if(!utn_getSexo(&nuevoCliente.sexo, "Ingrese sexo (f (femenino), m (masculino), o (otro)): \n", "Error.. \n", 2))
            {
                 printf("Hubo un problema al guardar el Sexo\n");
            }

            if(!utn_getNumero(&nuevoCliente.localidad.id, "Ingrese idLocalidad (cod.post): \n", "Error ingrese un id valido (cod.post): \n", 1000, 1999, 3))
            {
                printf("Hubo un problema al guardar id localidad\n");
            }

            if(!utn_getStringChar(nuevoCliente.localidad.descripcion, "Ingrese nombre localidad: \n", "Error ingrese nombre localidad valida: \n", 2, 20, 3))
            {
                printf("Hubo un problema al guardar la localidad\n");
            }

            if(!utn_getTelefono(nuevoCliente.telefono, "Ingrese telefono: \n", "Error, respete maximo caracteres..\n", 21, 3))
            {
                printf("Hubo un problema al guardar el telefono\n");
            }


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

            mostrarCliente(lista[indice]);

            printf("\n\n");
            printf("Informacion del Cliente:\n");
            printf("1) Nombre\n");
            printf("2) Apellido\n");
            printf("3) Telefono\n");

            if(utn_getNumero(&opcion, "Escoja una opcion: \n", "Error ingrese una opcion valida: \n", 1, 3, 2))
            {
                printf("Confirma opcion?: \n");
                fflush(stdin);
                scanf("%c", &confirma);
            }



            if(confirma=='s')
            {
                switch(opcion)
                {
                case 1:
                    if(!utn_getStringChar(lista[indice].nombre, "Ingrese Nombre: \n", "Error Ingrese nombre (Solo letras, Respete min y max caracteres): \n", 2, 51, 2))
                    {
                        printf("Hubo un problema al guardar el Nombre\n");
                    }
                    break;
                case 2:
                    if(!utn_getStringChar(lista[indice].apellido, "Ingrese Apellido: \n", "Error Ingrese Apellido (Solo letras, Respete min y max caracteres): \n", 2, 51, 2))
                    {
                        printf("Hubo un problema al guardar el Apellido\n");
                    }
                    break;
                case 3:
                    if(!utn_getTelefono(lista[indice].telefono, "Ingrese telefono: \n", "Error, respete maximo caracteres..\n", 21, 2))
                    {
                        printf("Hubo un problema al guardar el telefono\n");
                    }
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
    printf("Codigo    Nombre      Apellido  Sexo    idLoc   DescripcionLoc     Telefono  \n");

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
   printf(" %d  %10s    %10s     %c     %d       %10s   %s   \n", unCliente.codigo,
                                                    unCliente.nombre,
                                                    unCliente.apellido,
                                                    unCliente.sexo,
                                                    unCliente.localidad.id,
                                                    unCliente.localidad.descripcion,
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

int cargarApellidoCliente(int idCliente, eCliente clientes[], int tam, char nombre[], char apellido[])
{
    int todoOk=0;

    if(clientes!=NULL && tam>0 && apellido!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].codigo==idCliente && !clientes[i].isEmpty)
            {
                strcpy(nombre, clientes[i].nombre);
                strcpy(apellido, clientes[i].apellido);
                todoOk=1;
                break;
            }
        }

    }

    return todoOk;

}

int buscarLocalidad(eLocalidad localidades[], int tamL, int idLoc)
{
    int indice=-1;


    if(localidades!=NULL && tamL>0 && idLoc>0)
    {
        for(int i=0; i<tamL; i++)
        {
            if(localidades[i].id==idLoc)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;


}

int cargarLocalidadCliente(int idCliente, eCliente clientes[], int tam, char decripcionLocalidad[])
{
    int retorno=0;

    if(decripcionLocalidad!=NULL && clientes!=NULL && tam>0 && idCliente>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].codigo==idCliente)
            {
                strcpy(decripcionLocalidad, clientes[i].localidad.descripcion);
                retorno=1;
                break;
            }
        }

    }

    return retorno;

}

int listarLocalidades(eLocalidad localidades[], int tamLoc)
{
    int todoOk=0;
    int flagNoSeMostro=1;

    printf("      *** Listado de localidades ***  \n\n");
    printf("idLocalidad    Descripcion  \n");

    if(localidades!=NULL && tamLoc>0)
    {
        for(int i=0; i<tamLoc; i++)
        {
            mostrarLocalidad(localidades[i]);
            flagNoSeMostro=0;
            todoOk=1;
        }


        if(flagNoSeMostro)
        {
            printf("No hay localidades para mostrar");

        }
    }
    printf("\n\n");
    return todoOk;
}

void mostrarLocalidad(eLocalidad unaLocalidad)
{
    printf(" %d  %10s    \n", unaLocalidad.id, unaLocalidad.descripcion);

}

int buscarClienteMujer(eCliente lista[], int tam, int id)    //busco el legajo pasado por parametro en el arreay de empleados
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && id==lista[i].codigo && lista[i].sexo=='f')
            {
                indice=i;
                break;
            }
        }
    }

    return indice;

}



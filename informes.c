#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"
#include "utn.h"
#include "informes.h"
/*
RECUPERATORIO PRIMER PARCIAL
Se deberá agregar a la estructura cliente el campo localidad y refactorizar el
programa para que en los lugares donde se muestran los datos del cliente se
muestre su localidad. Incluso en aquellos lugares donde solo aparece el nombre
del cliente.
Para aprobar

Se deberán crear 5 informes de los cuales 3 deben tener que ver con la localidad
Para promocionar agregar 3 informes más.
El nivel de los informes determina la nota final.
*/


int menuInformes(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA, eLocalidad localidades[], int tamLoc)
{
    int todoOk=0;
    int opcion;

    if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC && alquileres!=NULL && tamA)
    {
        printf("***Menu de informes***\n");
        printf("1) Mostrar juegos categoria: de mesa\n"); //ok
        printf("2) Mostrar alquiler por cliente\n"); //ok
        printf("3) Mostrar total importe por cliente\n"); //ok
        printf("4) Listado de clientes sin alquileres\n"); //ok
        printf("5) Listado de juegos sin alquilar\n"); //ok
        printf("6) Listado telefonos de clientes que alquilaron juegos en determinada fecha\n"); //ok
        printf("7) Listado de juegos alquilados por mujeres\n"); //ok
        printf("8) Juego/s mas alquilados por hombres\n"); //ok
        printf("9) Listado de clientes por alquiler de juego\n"); //ok
        printf("10) Mostrar recaudacion por fecha\n"); //ok
        printf("11) Mostrar clientes por localidad\n"); //ok
        printf("12) Cantidad clientes por localidad\n"); //ok
        printf("13) Mostrar importe total por localidad\n"); //ok
        printf("14) Mostrar localidad por codigo solo mujeres\n"); //ok
        printf("15) Actualizar precio de juego\n"); //ok
        printf("16) Mostrar juego/s mas barato/s\n"); //ok
        printf("17) Mostrar apellido mas largo\n"); //ok

        utn_getNumero(&opcion, "Escoja opcion: \n", "Error escoja opcion valida: \n", 1, 18, 3);

        switch(opcion)
        {
        case 1:
            system("cls");
            mostrarJuegosMesa(categorias, tamC, juegos, tamJ);
            break;
        case 2:
            system("cls");
            MostrarAlquilerPorCliente(clientes, tam, juegos, tamJ, categorias, tamC, alquileres, tamA);
            break;
        case 3:
            system("cls");
            MostrarTotalImportePorCliente(clientes, tam, juegos, tamJ, alquileres, tamA);
            break;
        case 4:
            system("cls");
            listarClientesSinAlquileres(clientes, tam, alquileres, tamA, juegos, tamJ);
            break;
        case 5:
            system("cls");
            listarJuegosSinAlquilar(juegos, tamJ, categorias, tamC, alquileres, tamA);
            break;
        case 6:
            system("cls");
            if(!listarAlquilerPorFecha(alquileres, tamA, juegos, tamJ, clientes, tamC, categorias, tamC))
            {
                printf("La fecha ingresada no tiene alquileres\n");
            }
            break;
        case 7:
            system("cls");
            listarAlquileresPorMujeres(alquileres, tamA, clientes, tam, juegos, tamJ, categorias, tamC);
            break;
        case 8:
            system("cls");
            juegoMasAlquiladoHombres(alquileres, tamA, clientes, tam, juegos, tamJ, categorias, tamC);
            break;
        case 9:
            system("cls");
            listarClientesPorJuego(alquileres, tamA, clientes, tam, juegos, tamJ, categorias, tamC);
            break;
        case 10:
            system("cls");
            if(!mostrarRecaudacionPorFecha(alquileres, tamA, clientes, tam, juegos, tamJ, categorias, tamC))
            {
                printf("La fecha ingresada no tiene alquileres\n");
            }
            break;
        case 11:
            system("cls");
            MostrarclientesPorLocalidad(clientes, tam);
            break;
        case 12:
            system("cls");
            cantidadClientesPorLocalidad(clientes, tam);
            break;
        case 13:
            system("cls");
            mostrarImporteTotalPorLocalidad(alquileres, tamA, clientes, tam, juegos, tamJ, categorias, tamC, localidades, tamLoc);
            break;
        case 14:
            system("cls");
            mostrarLocalidadPorCodigoMujeres(clientes, tam, localidades, tamLoc);
            break;
        case 15:
            system("cls");
            actualizarPrecio(juegos, tamJ, categorias, tamC, clientes, tam);
            break;
        case 16:
            system("cls");
            juegoMasBarato(juegos, tamJ, categorias, tamC);
            break;
        case 17:
            system("cls");
            mostrarApellidoMasLargo(clientes, tam);
            break;
        }
        todoOk=1;
    }
    else
    {
        printf("Hubo un problema al cargar menu de informes!\n");
    }

    return todoOk;
}

int mostrarJuegosMesa(eCategoria categorias[], int tamC, eJuego juegos[], int tamJ)
{
    int todoOk=0;

    if(categorias!=NULL && tamC>0 && juegos!=NULL && tamJ>0)
    {
        printf("Listado juegos categoria: mesa\n");
        printf("Codigo   Descripcion  Importe    Categoria  \n");
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].idCategoria==1)
            {
                mostrarJuego(juegos[i], categorias, tamC);
            }
        }

        todoOk=1;
    }


    return todoOk;
}

int MostrarAlquilerPorCliente(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA)
{
    int todoOk=0;
    int codigo;
    int flagSeMostro=0;

    if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC && alquileres!=NULL && tamA)
    {
        printf("Mostrar alquiler por cliente\n");
        if(listarClientes(clientes, tam))
        {
            utn_getNumero(&codigo, "Ingrese codigo de cliente para ver sus alquileres: \n", "Error, Ingrese codigo de cliente para ver sus alquileres (solo numeros): \n", 0, 1000, 3);

            if(buscarCliente(clientes, tam, codigo)==-1)
            {
                printf("El codigo de cliente no pertenece a un cliente existente\n");
            }
            else
            {
                printf("      *** Listado de Alquileres del cliente %d***  \n\n", codigo);
                printf("CodAlquiler  CodJuego  Descripcion      Nombre   Apellido    CodCliente   Fecha Alquiler  \n");
                for(int i=0; i<tam; i++)
                {
                    if(codigo==clientes[i].codigo)
                    {
                        for(int j=0; j<tamA; j++)
                        {
                            if(clientes[i].codigo==alquileres[j].codigoCliente)
                            {
                                mostrarAlquiler(alquileres[j], clientes, tam, juegos, tamJ, categorias, tamC);
                                flagSeMostro=1;
                            }
                        }
                    }
                }
                todoOk=1;
            }
            if(!flagSeMostro)
            {
                printf("El cliente seleccionado no presenta alquileres\n");
            }
        }
        else
        {
            printf("No es posible realizar el informe ya que no hay clientes ingresados en el sistema\n");
        }


    }

    return todoOk;
}

int MostrarTotalImportePorCliente(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA)
{
    int todoOk=0;
    int codigo;
    float total=0;
    int indice;


    if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && alquileres!=NULL && tamA)
    {
        printf("Total importe a pagar por cliente\n");
        if(listarClientes(clientes, tam))
        {
            utn_getNumero(&codigo, "Ingrese codigo de cliente: \n", "Error, Ingrese codigo de cliente: \n", 0, 1000, 3);

            indice=buscarCliente(clientes, tam, codigo);

            if(indice==-1)
            {
                printf("El codigo de cliente no pertenece a un cliente existente\n");
            }
            else
            {
                for(int i=0; i<tam; i++)
                {
                    if(codigo==clientes[i].codigo)
                    {
                        for(int j=0; j<tamA; j++)
                        {
                            if(clientes[i].codigo==alquileres[j].codigoCliente)
                            {
                                for(int k=0; k<tamJ; k++)
                                {
                                    if(alquileres[j].codigoJuego==juegos[k].codigo)
                                    {
                                        total+=juegos[k].importe;

                                    }
                                }
                            }
                        }
                    }
                }
                printf("El importe total del cliente %s %s es: $%.2f\n", clientes[indice].nombre, clientes[indice].apellido, total);
                if(total==0)
                {
                    printf("El cliente no presenta alquileres\n");
                }
                todoOk=1;
            }
        }
        else
        {
            printf("No es posible realizar el informe ya que no hay clientes ingresados en el sistema\n");
        }


    }


    return todoOk;
}

int listarClientesSinAlquileres(eCliente clientes[], int tam, eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ)
{
    int todoOk=0;
    float total[tam];
    int flagSinAlquiler=0;

    for(int i=0; i<tam; i++)
    {
        total[i]=0;
    }



    if(clientes!=NULL && tam>0 && alquileres!=NULL && tamA>0)
    {
        printf("Listado de clientes sin alquileres\n");
        printf("Codigo    Nombre      Apellido  Sexo    idLoc   DescripcionLoc     Telefono  \n");

        if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && alquileres!=NULL && tamA)
        {
            for(int i=0; i<tam; i++)
            {
                for(int j=0; j<tamA; j++)
                {
                    if(clientes[i].codigo==alquileres[j].codigoCliente)
                    {
                        for(int k=0; k<tamJ; k++)
                        {
                            total[i]+=juegos[k].importe;
                        }
                    }

                }
                if(!total[i] && !clientes[i].isEmpty)
                {
                    mostrarCliente(clientes[i]);
                    flagSinAlquiler=1;
                }


            }
            if(!flagSinAlquiler)
            {
                printf("No hay clientes sin alquileres\n");
            }


            todoOk=1;

        }




    }


    return todoOk;
}

int listarJuegosSinAlquilar(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA)
{
    int todoOk=0;
    int flagAlquilado;

    if(juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        printf("Listado de juegos sin alquilar\n");
        printf("Codigo   Descripcion  Importe    Categoria  \n");

        for(int i=0; i<tamJ; i++)
        {
            flagAlquilado=0;
            for(int j=0; j<tamA; j++)
            {
                if(juegos[i].codigo==alquileres[j].codigoJuego)
                {
                    flagAlquilado=1;
                }

            }
            if(!flagAlquilado)
            {
                mostrarJuego(juegos[i], categorias, tamC);
            }
        }


        todoOk=1;
    }

    return todoOk;
}

int listarAlquilerPorFecha(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eCliente clientes[], int tam, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    eFecha fecha;

    if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC && alquileres!=NULL && tamA)
    {
        printf("Listado telefonos por fecha de alquiler\n");
        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        for(int i=0; i<tamA; i++)
        {
            if(fecha.dia==alquileres[i].fecha.dia && fecha.mes==alquileres[i].fecha.mes && fecha.anio==alquileres[i].fecha.anio)
            {

                for(int j=0; j<tam; j++)
                {

                    if(alquileres[i].codigoCliente==clientes[j].codigo)
                    {
                        printf("Telefono del cliente: %s\n", clientes[j].telefono);
                        todoOk=1;
                    }
                }
            }

        }




    }


    return todoOk;
}

int listarAlquileresPorMujeres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    int flagSeMostro=0;

    if(clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC && alquileres!=NULL && tamA)
    {
        printf("***Listado de juegos alquilados por mujeres***\n\n");
        printf("CodAlquiler  CodJuego  Descripcion      Nombre   Apellido    CodCliente   Fecha Alquiler  \n");

        for(int i=0; i<tam; i++)
        {
            if(clientes[i].sexo=='f' && !clientes[i].isEmpty)
            {
                for(int j=0; j<tamA; j++)
                {
                    if(clientes[i].codigo==alquileres[j].codigoCliente)
                    {
                        mostrarAlquiler(alquileres[j], clientes, tam, juegos, tamJ, categorias, tamC);
                        flagSeMostro=1;
                    }
                }
            }
        }
        if(!flagSeMostro)
        {
            printf("No hay juegos alquilados por mujeres\n\n");
        }
        todoOk=1;

    }



    return todoOk;
}

int juegoMasAlquiladoHombres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    int contador[tamJ];
    int mayor;

    if(alquileres!=NULL && tamA>0 && clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        printf("****Listado de juegos mas alquilados por hombres***\n\n");


        for(int i=0; i<tamJ; i++)
        {
            contador[i]=0;
        }

        for(int i=0; i<tamJ; i++)
        {
            for(int j=0; j<tamA; j++)
            {
                if(juegos[i].codigo==alquileres[j].codigoJuego)
                {
                    for(int k=0; k<tam; k++)
                    {
                        if(alquileres[j].codigoCliente==clientes[k].codigo && clientes[k].sexo=='m')
                        {
                            contador[i]++;

                        }

                    }
                }
            }

        }

        mayor=contador[0];
        for(int i=1; i<tamJ; i++)
        {
            if(contador[i]>mayor)
            {
                mayor=contador[i];
            }
        }
        if(mayor>0)
        {
            for(int i=0; i<tamJ; i++)
            {
                if(contador[i]==mayor)
                {
                    printf("Alquilado por %d clientes. \n", contador[i]);
                    printf("Codigo   Descripcion  Importe    Categoria  \n");
                    mostrarJuego(juegos[i], categorias, tamC);
                    printf("\n");
                    todoOk=1;
                }
            }
        }
        else
        {
            printf("No hay juegos alquilados\n");
        }
    }

    return todoOk;

}

int listarClientesPorJuego(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    int codigoJuego;
    int indice;
    int contador=0;

    if(alquileres!=NULL && tamA>0 && clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        printf("***Listado de clientes por juego alquilado***\n");

        listarJuegos(juegos, tamJ, categorias, tamC);

        utn_getNumero(&codigoJuego, "Ingrese codigo de juego: \n", "Error codigo invalido, Ingrese codigo de juego: \n", 1000, 1005, 3);

        indice=buscarJuego(juegos, tamJ, categorias, tamC, codigoJuego);

        if(indice==-1)
        {
            printf("El codigo de juego no pertenece a un juego existente\n");
        }
        else
        {
            printf("\nCodigo   Descripcion  Importe    Categoria  \n");
            mostrarJuego(juegos[indice], categorias, tamC);
            printf("\n");

            printf("Codigo    Nombre      Apellido  Sexo    idLoc   DescripcionLoc     Telefono  \n");

            for(int i=0; i<tamA; i++)
            {
                if(juegos[indice].codigo==alquileres[i].codigoJuego)
                {
                    for(int j=0; j<tam; j++)
                    {
                        if(alquileres[i].codigoCliente==clientes[j].codigo)
                        {
                            mostrarCliente(clientes[j]);
                            contador++;
                            todoOk=1;
                        }
                    }
                }
            }
            printf("\nClientes que alquilaron %s: %d\n", juegos[indice].descripcion, contador);
        }
    }

    return todoOk;
}

int mostrarRecaudacionPorFecha(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;
    eFecha fecha;
    float totalRecaudacion=0;

    if(alquileres!=NULL && tamA>0 && clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        printf("***Recaudacion por fecha***\n\n");

        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        for(int i=0; i<tamA; i++)
        {
            if(fecha.dia==alquileres[i].fecha.dia && fecha.mes==alquileres[i].fecha.mes && fecha.anio==alquileres[i].fecha.anio)
            {
                for(int j=0; j<tamJ; j++)
                {
                    if(alquileres[i].codigoJuego==juegos[j].codigo)
                    {
                        totalRecaudacion+=juegos[j].importe;
                        todoOk=1;
                    }
                }
            }
        }
        printf("La recaudacion total es: %.2f\n",totalRecaudacion);



    }

    return todoOk;
}

int MostrarclientesPorLocalidad(eCliente clientes[], int tam)  //1
{
    int retorno=0;
    int idLocalidad;
    int flagSeMostro=0;


    if(clientes!=NULL && tam>0)
    {
        printf("***Lista de clientes por localidad***\n");
        utn_getNumero(&idLocalidad, "Ingrese idlocalidad: \n", "Error, Ingrese idlocalidad: \n", 0, 10000, 2);

        printf("Codigo    Nombre      Apellido  Sexo    idLoc   DescripcionLoc     Telefono  \n");
        for(int i=0; i<tam; i++)
        {
            if(idLocalidad==clientes[i].localidad.id)
            {

                mostrarCliente(clientes[i]);
                flagSeMostro=1;
                retorno=1;
            }
        }
        if(!flagSeMostro)
        {
            printf("No hay cliente que resida en esta localidad\n");
        }
    }

    return retorno;
}

int cantidadClientesPorLocalidad(eCliente clientes[], int tam) //2
{
    int retorno=0;
    int idLocalidad;
    int contador=0;

    if(clientes!=NULL && tam>0)
    {
        printf("***Lista de clientes por localidad***\n");
        utn_getNumero(&idLocalidad, "Ingrese idlocalidad: \n", "Error, Ingrese idlocalidad: \n", 0, 10000, 2);


        for(int i=0; i<tam; i++)
        {
            if(idLocalidad==clientes[i].localidad.id)
            {
                contador++;
                retorno=1;
            }
        }
        if(!contador)
        {
            printf("No hay clientes que resida en esta localidad\n");
        }
        else
        {
            printf("Hay %d clientes residiendo en esta localidad\n", contador);
        }
    }

    return retorno;
}

int mostrarImporteTotalPorLocalidad(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eLocalidad localidades[], int tamLoc) //3
{
    int retorno=0;
    int idLocalidad;

    float importeTotal=0;

    if(alquileres!=NULL && tamA>0 && clientes!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamC>0)
    {
        printf("***Importe Total por localidad de residencia***\n\n");

        listarLocalidades(localidades, tamLoc);
        utn_getNumero(&idLocalidad, "Ingrese id localidad: \n", "Ingrese id localidad: \n", 0, 10000, 2);

        if(buscarLocalidad(localidades, tamLoc, idLocalidad)==-1)
        {
            printf("La localidad no se encuentra en la lista\n");
        }
       else
        {

            for(int i=0; i<tamLoc; i++)
            {
                if(idLocalidad==localidades[i].id)
                {
                    for(int j=0; j<tam; j++)
                    {
                        if(localidades[i].id==clientes[j].localidad.id  && !clientes[i].isEmpty)
                        {
                            for(int k=0; k<tamA; k++)
                            {
                                if(clientes[j].codigo==alquileres[k].codigoCliente)
                                {
                                    for(int l=0; l<tamJ; l++)
                                    {
                                        if(alquileres[k].codigoJuego==juegos[l].codigo)
                                        {
                                            importeTotal+=juegos[l].importe;
                                            retorno=1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("La recaudacion total es: %.2f\n",importeTotal);
        }
    }

    return retorno;
}

int mostrarLocalidadPorCodigoMujeres(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc) //4
{
    int retorno=0;
    int idCliente;

    if(clientes!=NULL && localidades!=NULL && tam>0 && tamLoc>0)
    {
        printf("***Mostrar localidades clientes solo mujeres por codigo cliente***\n");

        listarClientes(clientes, tam);

        utn_getNumero(&idCliente, "Ingrese IdCliente: \n", "Error, Ingrese IdCliente: \n", 100, 109, 2);

        if(buscarClienteMujer(clientes, tam, idCliente)==-1)
        {
            printf("El idCliente no pertenece a la lista o no es mujer\n");
        }
        else
        {

            for(int i=0; i<tam; i++)
            {
                if(idCliente==clientes[i].codigo && !clientes[i].isEmpty)
                {
                    for(int j=0; j<tamLoc; j++)
                    {
                        if(clientes[i].localidad.id==localidades[j].id)
                        {
                            printf("La clienta %10s %10s reside en idLocalidad:", clientes[i].nombre, clientes[i].apellido);
                            mostrarLocalidad(localidades[j]);
                            retorno=1;
                        }
                    }
                }
            }
        }


    }

    return retorno;
}

int actualizarPrecio(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eCliente clientes[], int tam) //5
{
    int todoOk=0;
    int idJuego;
    float porcentaje;
    char descripcion[20];

    if(juegos!=NULL && tamJ>0)
    {
        system("cls");
        printf("***Actualizar precio de juego***\n");
        listarJuegos(juegos, tamJ, categorias, tamC);
        utn_getNumero(&idJuego, "Ingrese idJuego que desea actualizar: \n","Error, Ingrese idJuego que desea actualizar: \n", 1000, 1005, 2);

        utn_getNumeroFlotante(&porcentaje, "Ingrese porcentaje que desea incrementar al precio: \n", "Error, Ingrese porcentaje que desea incrementar al precio: \n", 0, 1000, 2);
        cargarDescripcionJuego(idJuego, clientes, tam, juegos, tamJ, descripcion);

        for(int i=0; i<tamJ; i++)
        {
            if(idJuego==juegos[i].codigo)
            {
                juegos[i].importe=juegos[i].importe+juegos[i].importe*porcentaje/100;
                printf("Codigo   Descripcion  Importe    Categoria  \n");
                mostrarJuego(juegos[i],categorias, tamC);
            }
        }
        todoOk=1;
        printf("Se actualizo el precio del juego %s correctamente\n", descripcion);

    }
    return todoOk;

}

int juegoMasBarato(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC) //6
{
    int retorno=0;
    float menor;

    if(juegos!=NULL && tamJ>0)
    {
        printf("***Juego mas economico de la lista***\n");

        for(int i=0; i<tamJ; i++)
        {
            if(i==0 || juegos[i].importe<menor)
            {
                menor=juegos[i].importe;

            }
        }

        printf("Codigo   Descripcion  Importe    Categoria  \n");
        for(int i=0; i<tamJ; i++)
        {
            if(menor==juegos[i].importe)
            {
                mostrarJuego(juegos[i], categorias, tamC);
                retorno=1;
            }
        }

    }

    return retorno;
}

int mostrarApellidoMasLargo(eCliente clientes[], int tam)
{
    int retorno=0;
    int masLargo;
    int largo;

    if(clientes!=NULL && tam>0)
    {
        printf("Mostrar apellido mas largo***\n");
        for(int i=0; i<tam; i++)
        {
            largo=strlen(clientes[i].apellido);
            if(i==0 || largo>masLargo)
            {
                masLargo=largo;
                retorno=1;
            }
        }

        for(int i=0; i<tam; i++)
        {
            largo=strlen(clientes[i].apellido);
            if(masLargo==largo)
            {
                printf("El apellido mas largo es %s con %d caracteres\n", clientes[i].apellido, masLargo);
            }
        }
    }


    return retorno;
}








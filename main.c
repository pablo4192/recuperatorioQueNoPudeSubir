#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"
#include "utn.h"
#include "informes.h"
#include "dataWareHouse.h"

#define TAM 10
#define TAMCAT 5
#define TAMJUEGOS 6
#define TAMALQ 10
#define TAMLOC 10

int main()
{
    eCliente clientes[TAM];

    eLocalidad localidades[TAMLOC]={
    {1765, "Pompeya"},
    {1754, "Ramos"},
    {1785, "Burzaco"},
    {1786, "ElPato"},
    {1748, "Chascomus"},
    {1752, "Tablada"},
    {1736, "Tapiales"},
    {1791, "Liniers"},
    {1780, "Lugano"},
    {1759, "Bonzi"}
    };

    eAlquileres alquileres[TAMALQ];

    eCategoria categorias[TAMCAT]={
    {1, "Mesa"},
    {2, "Azar"},
    {3, "Estrategia"},
    {4, "Salon"},
    {5, "Magia"},
    };

    eJuego juegos[TAMJUEGOS]={
    {1000, "Damas", 400, 1},
    {1001, "Generala", 300, 2},
    {1002, "Teg", 600, 3},
    {1003, "Poker", 800,4},
    {1004, "CartasMag", 200,5},
    {1005, "Ludo", 750, 1}
    };

    int nextIdCliente=100;
    int nextIdAlquiler=500;
    char seguir='s';
    char confirma='s';

    inicializarClientes(clientes, TAM);
    inicializarAlquileres(alquileres, TAMALQ);
    hardcodearClientes(clientes, TAM, 10, &nextIdCliente);
    hardcodearAlquileres(alquileres, TAMALQ, 10, &nextIdAlquiler);

    do
    {


        switch(menu())
        {
        case 1:
            if(altaCliente(clientes, TAM, &nextIdCliente))
            {
                printf("Alta Exitosa!!\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta\n");
            }
            system("pause");
            break;
        case 2:
            if(modificarCliente(clientes, TAM))
            {
                 printf("Modificacion exitosa!!\n");
            }
            else
            {
                printf("Hubo un problema al modificar\n");
            }
            system("pause");
            break;
        case 3:
            if(bajaCliente(clientes, TAM))
            {
                printf("Baja exitosa!!\n");
            }
            else
            {
                printf("Hubo un problema al dar de baja\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            ordenarClientes(clientes, TAM);
            listarClientes(clientes, TAM);
            system("pause");
            break;
        case 5:
            system("cls");
            if(altaAlquiler(alquileres, TAMALQ, &nextIdAlquiler, juegos, TAMJUEGOS, categorias, TAMCAT, clientes, TAM))
            {
                printf("Alta alquiler exitosa!!\n");
            }
            else
            {
                printf("Hubo un problema al alquilar\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            listarAlquileres(alquileres, TAMALQ, clientes, TAM, juegos, TAMJUEGOS, categorias, TAMCAT);
            system("pause");
            break;
        case 7:
            system("cls");
            menuInformes(clientes, TAM, juegos, TAMJUEGOS, categorias, TAMCAT, alquileres, TAMALQ, localidades, TAMLOC);
            system("pause");
            break;
        case 8:
            printf("Seguro desea salir? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            else
            {
                printf("Salida cancelada\n");
            }

            break;

        }
    }while(seguir=='s');






    return 0;
}

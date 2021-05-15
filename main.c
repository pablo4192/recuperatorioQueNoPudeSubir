#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegosInfantiles.h"
#include "juegos.h"
#include "alquiler.h"

#define TAM 10
#define TAMCAT 5
#define TAMJUEGOS 5
#define TAMALQ 10

int main()
{
    eCliente clientes[TAM]={
    {100, "Pepe", "Cakero", 'm', 1550505060, 0},
    {101, "Julian", "Perez", 'm', 1560908042, 0},
    {102, "Carla", "Miller", 'f', 1550963602, 0},
    {103, "Andres", "Yuti", 'm', 1550508914, 0},
    {104, "Mica", "Randal", 'f', 1550505896, 0},
    {105, "Lorena", "Poli", 'f', 1550505458, 0},
    {106, "Jose", "Chatruc", 'm', 1550145896, 0},
    {107, "Flavio", "Mendoza", 'm', 1550986325, 0},
    {108, "Bernardo", "Gandorchi", 'm', 1550450360, 0},
    {109, "Maria", "Odonnel", 'f', 1550507896, 0},
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
    {1001, "Generala", 300,2},
    {1002, "Teg", 600, 3},
    {1003, "Poker", 800,4},
    {1004, "CartasMag", 200,5},
    };

    int nextIdCliente=100;
    int nextIdAlquiler=500;
    char seguir='s';
    char confirma='s';

    //inicializarClientes(clientes, TAM);
    inicializarAlquileres(alquileres, TAMALQ);

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
            if(altaAlquiler(alquileres, TAMALQ, &nextIdAlquiler, juegos, TAMJUEGOS, categorias, TAMCAT))
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
            listarAlquileres(alquileres, TAMALQ);
            system("pause");
            break;
        case 7:
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
            system("pause");
            break;

        }
    }while(seguir=='s');






    return 0;
}

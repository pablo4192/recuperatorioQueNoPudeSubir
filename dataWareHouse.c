#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "dataWareHouse.h"

char nombres[10][20]={
"Pepe",
"Julian",
"Carla",
"Andres",
"Mica",
"Lorena",
"Jose",
"Flavio",
"Bernardo",
"Maria",
};

char apellidos[10][20]={
"Cakero",
"Perez",
"Miller",
"Yuti",
"Randal",
"Poli",
"Chatruc",
"Mendoza",
"Gandorchi",
"Odonnel",
};

char sexos[10]={'m', 'm', 'f', 'm', 'f', 'f', 'm', 'm', 'm','f'};

int idLocalidades[10]={1765, 1754, 1785, 1786, 1748, 1752, 1736, 1791, 1785, 1754};

char descripcionLocalidades[10][20]={
"Pompeya",
"Ramos",
"Burzaco",
"El Pato",
"Chascomus",
"Tablada",
"Tapiales",
"Liniers",
"Burzaco",
"Ramos"
};

char telefonos[10][20]={
"1550505060",
"1560908042",
"1550963602",
"1550508914",
"1550505896",
"1550505458",
"1550145896",
"1550986325",
"1550450360",
"1550507896"
};

int codigosAlquileres[10]={500,501,502,503,504,505,506,507,508,509};

int codigosJuegos[10]={1000,1003,1001,1000,1004,1001,1002,1000,1001, 1001};

int codigosClientes[10]={108,102,108,101,106,103,102,107,102,104};

eFecha fechas[10]={
{15,05,2020},
{13,04,2020},
{05,01,2020},
{13,04,2020},
{10,04,2020},
{04,04,2020},
{06,12,2020},
{15,07,2020},
{25,06,2020},
{19,07,2020},
};

int hardcodearClientes(eCliente clientes[],int tam, int cant, int* pNextIdCliente)
{
    int totalClientes=0;

    if(clientes!=NULL && tam>0 && cant>=0 && cant<=tam && pNextIdCliente!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            clientes[i].codigo=*pNextIdCliente;
            (*pNextIdCliente)++;
            strcpy(clientes[i].nombre, nombres[i]);
            strcpy(clientes[i].apellido, apellidos[i]);
            clientes[i].sexo=sexos[i];
            clientes[i].localidad.id=idLocalidades[i];
            strcpy(clientes[i].localidad.descripcion, descripcionLocalidades[i]);
            strcpy(clientes[i].telefono, telefonos[i]);
            clientes[i].isEmpty=0;
            totalClientes++;
        }
}
    return totalClientes;
}

int hardcodearAlquileres(eAlquileres alquileres[],int tamAlq, int cant, int* pNextIdAlquiler)
{
    int totalAlquileres=0;

    if(alquileres!=NULL && tamAlq>0 && cant>=0 && cant<=tamAlq && pNextIdAlquiler!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            alquileres[i].codigoAlquiler=*pNextIdAlquiler;
            (*pNextIdAlquiler)++;
            alquileres[i].codigoJuego=codigosJuegos[i];
            alquileres[i].codigoCliente=codigosClientes[i];
            alquileres[i].fecha=fechas[i];
            alquileres[i].isEmpty=0;
            totalAlquileres++;
        }
    }
    return totalAlquileres;

}


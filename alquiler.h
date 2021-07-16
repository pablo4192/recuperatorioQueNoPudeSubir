#include "juegosInfantiles.h"
#include "juegos.h"

#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
int codigoAlquiler; //autoincremental
int codigoJuego; //validar
int codigoCliente; //validar
eFecha fecha;
int isEmpty;
}eAlquileres;


#endif // ALQUILER_H_INCLUDED

/** \brief Printea los encabezados de los alquileres
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamA int Tamaño del array
 * \return int 1 Exito, 0 Error
 *
 */
int listarAlquileres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);


/** \brief Muestra los datos de un alquiler
 *
 * \param unAlquiler eAlquileres Array del cliente con los datos a mostrar
 * \param clientes[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \return void
 *
 */
void mostrarAlquiler(eAlquileres unAlquiler, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);


/** \brief Hace la peticion de datos para dar de alta el alquiler
 *
 * \param alquiler[] eAlquileres Array de alquileres
 * \param tamA int Tamaño del array alquileres
 * \param pId int* Puntero a id de alquiler
 * \param juegos[] eJuego Array de juegos
 * \param tamJ int Tamaño de array de juegos
 * \param categorias[] eCategoria Array de categorias
 * \param tamC int Tamaño de array de categorias
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño de array de clientes
 * \return int 1 Exito, 0 Error
 *
 */
int altaAlquiler(eAlquileres alquiler[], int tamA, int* pId, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eCliente clientes[], int tam);

/** \brief Busca indice libre para guardar un alquiler
 *
 * \param alquiler[] eAlquileres Array de alquileres
 * \param tamA int  Tamaño del array
 * \return int 1 Exito, 0 Error
 *
 */
int buscarAlquilerLibre(eAlquileres alquiler[], int tamA);

/** \brief Inicializa campo isEmpty de estructura eAlquiler
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamA int Tamaño del array
 * \return int 1 Exito, 0 Error
 *
 */
int inicializarAlquileres(eAlquileres alquileres[], int tamA);

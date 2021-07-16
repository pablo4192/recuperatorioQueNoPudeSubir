#include "juegos.h"
#include "alquiler.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief
 *
 * \param categorias[] eCategoria
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int
 *
 */
int mostrarJuegosMesa(eCategoria categorias[], int tamC, eJuego juegos[], int tamJ);


/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int menuInformes(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA, eLocalidad localidades[], int tamLoc);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int MostrarAlquilerPorCliente(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int MostrarTotalImportePorCliente(eCliente clientes[], int tam, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param alquilere[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int listarClientesSinAlquileres(eCliente clientes[], int tam, eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ);

/** \brief
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int listarJuegosSinAlquilar(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eAlquileres alquileres[], int tamA);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param clientes[] eCliente
 * \param tam int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int listarAlquilerPorFecha(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eCliente clientes[], int tam, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int listarAlquileresPorMujeres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int juegoMasAlquiladoHombres(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int listarClientesPorJuego(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int mostrarRecaudacionPorFecha(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \return int
 *
 */
int MostrarclientesPorLocalidad(eCliente clientes[], int tam);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int cantidadClientesPorLocalidad(eCliente clientes[], int tam);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \param clientes[] eCliente
 * \param tam int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param localidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int mostrarImporteTotalPorLocalidad(eAlquileres alquileres[], int tamA, eCliente clientes[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eLocalidad localidades[], int tamLoc);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param localidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int mostrarLocalidadPorCodigoMujeres(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc);

/** \brief
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int actualizarPrecio(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, eCliente clientes[], int tam);

/** \brief
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int
 *
 */
int juegoMasBarato(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int mostrarApellidoMasLargo(eCliente clientes[], int tam);

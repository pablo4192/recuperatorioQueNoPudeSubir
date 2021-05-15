#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{
int codigoAlquiler; //autoincremental
int codigoJuego; //validar
int codigoCliente; //validar
eFecha fecha;
int isEmpty;
}eAlquileres;


#endif // ALQUILER_H_INCLUDED

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int listarAlquileres(eAlquileres alquileres[], int tamA);

/** \brief
 *
 * \param unAlquiler eAlquileres
 * \return void
 *
 */
void mostrarAlquiler(eAlquileres unAlquiler);

/** \brief
 *
 * \param alquiler[] eAlquileres
 * \param tam int
 * \param pId int*
 * \return int
 *
 */
int altaAlquiler(eAlquileres alquiler[], int tamA, int* pId, eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param alquiler[] eAlquileres
 * \param tamJ int
 * \return int
 *
 */
int buscarAlquilerLibre(eAlquileres alquiler[], int tamA);

/** \brief
 *
 * \param alquileres[] eAlquileres
 * \param tamA int
 * \return int
 *
 */
int inicializarAlquileres(eAlquileres alquileres[], int tamA);

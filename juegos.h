

#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct{
int codigo;
char descripcion[20];
float importe;
int idCategoria;
}eJuego;

typedef struct{
int id;
char descripcion[51]; //maximo 51 caracteres; hardcodeado
}eCategoria;

#endif // JUEGOS_H_INCLUDED


/** \brief Printea los encabezados de la lista de juegos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamJ int Tamaño del array juegos
 * \param categorias[] eCategoria Array de categorias
 * \param tamC int Tamaño del array categorias
 * \return int 1 Exito, 0 Error
 *
 */
int listarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);


/** \brief Muestra array de un juego con sus datos
 *
 * \param unjuego eJuego juego a mostrar
 * \param categorias[] eCategoria Array de categorias
 * \param tamC int Tamaño del array
 * \return void
 *
 */
void mostrarJuego(eJuego unjuego, eCategoria categorias[], int tamC);

/** \brief Busca juego en el array mediante id
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamJ int Tamaño del array de juegos
 * \param categorias[] eCategoria Array de categorias
 * \param tamC int Tamaño del array de categorias
 * \return int 1 Exito, 0 Error
 *
 */
int buscarJuego(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC, int id);


/** \brief Carga la descripcion de una categoria para ser mostrada
 *
 * \param idCategoria int Id categoria a mostrar
 * \param categorias[] eCategoria Array de categorias
 * \param tamC int Tamaño del array de categorias
 * \param descripcion[] char Variable para guardar los datos
 * \return int 1 Exito, 0 Error
 *
 */
int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamC, char descripcion[]);

/** \brief
 *
 * \param idJuego int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionJuego(int idJuego, eCliente clientes[], int tam, eJuego juegos[], int tamJ, char descripcionJuego[]);

/** \brief
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int
 *
 */
int inicializarJuegos(eJuego juegos[], int tamJ);







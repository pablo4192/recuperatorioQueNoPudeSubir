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


/** \brief
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int
 *
 */
int listarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief
 *
 * \param unjuego eJuego
 * \return void
 *
 */
void mostrarJuego(eJuego unjuego);

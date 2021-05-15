#ifndef JUEGOSINFANTILES_H_INCLUDED
#define JUEGOSINFANTILES_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}eFecha;



typedef struct{
int codigo; //autoincremental
char nombre[51]; //maximo 51 caracteres
char apellido[51]; //maximo 51 caracteres
char sexo; //validar
int telefono; //maximo 21 numeros cadena de caracteres
int isEmpty;
}eCliente;




#endif // JUEGOSINFANTILES_H_INCLUDED

/** \brief
 *
 * \return int
 *
 */
int menu();

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \param pId int*
 * \return int
 *
 */
int altaCliente(eCliente lista[], int tam, int* pId);

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eCliente lista[], int tam);

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int inicializarClientes(eCliente lista[], int tam);


/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int modificarCliente(eCliente lista[], int tam);


/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int listarClientes(eCliente lista[], int tam);

/** \brief
 *
 * \param unCliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente);

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarCliente(eCliente lista[], int tam, int id);

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int ordenarClientes(eCliente lista[], int tam);


/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \return int
 *
 */
int bajaCliente(eCliente lista[], int tam);










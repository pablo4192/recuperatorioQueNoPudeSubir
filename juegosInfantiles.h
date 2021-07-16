

#ifndef JUEGOSINFANTILES_H_INCLUDED
#define JUEGOSINFANTILES_H_INCLUDED

typedef struct{
int id;
char descripcion[20];
}eLocalidad;

typedef struct{
int codigo; //autoincremental
char nombre[51]; //maximo 51 caracteres
char apellido[51]; //maximo 51 caracteres
char sexo; //validar
eLocalidad localidad;
char telefono[21]; //maximo 21 numeros cadena de caracteres
int isEmpty;
}eCliente;

#endif // JUEGOSINFANTILES_H_INCLUDED

/** \brief Presenta el menu de opciones
 *
 * \return int Opcion elegida por el usuario
 *
 */
int menu();

/** \brief Hace la peticion de datos al usuario
 *
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \param pId int* Puntero a Id de cliente
 * \return int 1 Exito, o Error
 *
 */
int altaCliente(eCliente lista[], int tam, int* pId);

/** \brief Busca un indice libre en el array de clientes
 *
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \return int int 1 Exito, o Error
 *
 */
int buscarLibre(eCliente lista[], int tam);

/** \brief Inicializa el campo isEmpty de la estructura eCliente en 1
 *
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \return int  1 Exito, o Error
 *
 */
int inicializarClientes(eCliente lista[], int tam);


/** \brief Modifica datos de los clientes
 *
 * \param lista[] eCliente  Array de clientes
 * \param tam int Tamaño del array
 * \return int 1 Exito, o Error
 *
 */
int modificarCliente(eCliente lista[], int tam);


/** \brief Printea los encabezados de la lista de clientes
 *
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \return int 1 Exito, o Error
 *
 */
int listarClientes(eCliente lista[], int tam);

/** \brief Muestra datos de un cliente
 *
 * \param unCliente eCliente Array donde se encuentran los datos del cliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente);

/** \brief Busca un cliente en la estructura por su id
 *
 * \param lista[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \param id int Id a buscar
 * \return int 1 Exito, o Error
 *
 */
int buscarCliente(eCliente lista[], int tam, int id);

/** \brief Ordena la lista de clientes
 *
 * \param lista[] eCliente Tamaño del array
 * \param tam int Tamaño del array
 * \return int 1 Exito, o Error
 *
 */
int ordenarClientes(eCliente lista[], int tam);


/** \brief Da de baja un cliente por su id
 *
 * \param lista[] eCliente  Tamaño del array
 * \param tam int Tamaño del array
 * \return int 1 Exito, o Error
 *
 */
int bajaCliente(eCliente lista[], int tam);


/** \brief
 *
 * \param idCliente int Id de cliente
 * \param clientes[] eCliente Array de clientes
 * \param tam int Tamaño del array
 * \param nombre[] char Variable para cargar nombre
 * \param apellido[] char Variable para cargar apellido
 * \return int 1 Exito, o Error
 *
 */
int cargarApellidoCliente(int idCliente, eCliente clientes[], int tam, char nombre[], char apellido[]);

/** \brief
 *
 * \param localidades[] eLocalidad
 * \param tamL int
 * \param idLoc int
 * \return int
 *
 */
int buscarLocalidad(eLocalidad localidades[], int tamL, int idLoc);

/** \brief
 *
 * \param idCliente int
 * \param clientes[] eCliente
 * \param tam int
 * \param decripcionLocalidad[] char
 * \return int
 *
 */
int cargarLocalidadCliente(int idCliente, eCliente clientes[], int tam, char decripcionLocalidad[]);

/** \brief
 *
 * \param localidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int listarLocalidades(eLocalidad localidades[], int tamLoc);

/** \brief
 *
 * \param unaLocalidad eLocalidad
 * \return void
 *
 */
void mostrarLocalidad(eLocalidad unaLocalidad);

/** \brief
 *
 * \param lista[] eCliente
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarClienteMujer(eCliente lista[], int tam, int id);







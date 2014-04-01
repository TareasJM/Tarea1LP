#ifndef _LISTA_H_
#define _LISTA_H_
/******** Funcion: initLista **************
Descripcion: Funcion encargada de inicializar una lista vacia 
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void initLista(Lista *lista);


/******** Funcion: next **************
Descripcion: Funcion que avanza un nodo en la lista
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void next(Lista *lista);


/******** Funcion: prev **************
Descripcion: Funcion que retrocede un nodo en la lista
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void prev(Lista *lista);


/******** Funcion: goToStart **************
Descripcion: Funcion que apunta el nodo actual al inicio de la lista
Parametros: 
	lista: Puntero a Lista
Retorno: void
************************************************/
void goToStart(Lista *lista);


/******** Funcion: goToEnd **************
Descripcion: Funcion que apunta el nodo actual al fin de la lista
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void goToEnd(Lista *lista);


/******** Funcion: clear **************
Descripcion: Funcion en cargada de vaciar la lista y liberar punteros
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void clear(Lista *lista);


/******** Funcion: append **************
Descripcion: Funcion en cargada de agregar un nodo al fin de la lista
Parametros:
	newColor: Color
	lista: Puntero a Lista
Retorno: void
************************************************/
void append(Lista *lista, Color newColor);


/******** Funcion: remove **************
Descripcion: Funcion en cargada de borrar un nodo de la lista
Parametros:
	lista: Puntero a Lista
	colorName: string
Retorno: void
************************************************/
void remove(Lista *lista, char *colorName);


/******** Funcion: listToText **************
Descripcion: Funcion en cargada guardar los colores de la lista en el archivo "colors.txt"
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void listToText(Lista *lista);


/******** Funcion: textToList **************
Descripcion: Funcion en cargada de leer el archivo "colors.txt" e ingresa los colores en la lista
Parametros:
	lista: Puntero a Lista
Retorno: void
************************************************/
void textToList(Lista *lista);

/******** Funcion: getCurrentColor **************
Descripcion: Funcion que retorna el color en la posición actual en la lista
Parametros:
	lista: Puntero a Lista
Retorno: 
	color: Color
************************************************/
Color getCurrentColor(Lista *lista)


#endif
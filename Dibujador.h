#ifndef _DIBUJADOR_H_
#define _DIBUJADOR_H_
/******** Funcion: drawColorList **************
Descripcion: Funcion que imprime un color en la consola, con posición respecto a su número, vista lista 
Parametros:
	pos: entero (número del color en la página)
	nombre: string con nombre del color
	red: entero con valor del rojo
	green: entero con valor del verde
	blue: entero con valor del azul
Retorno: void
************************************************/
void drawColorList(int pos, char *nombre, char *red, char *green, char *blue);

/******** Funcion: drawColorGrid **************
Descripcion: Funcion que imprime un color en la consola, con posición respecto a su número, vista grilla 
Parametros:
	posx: entero posición en el eje X
	posy: entero posición en el eje Y
	nombre: string con nombre del color
	red: entero con valor del rojo
	green: entero con valor del verde
	blue: entero con valor del azul
Retorno: void
************************************************/
void drawColorGrid(int num, int posx, int posy, char *nombre, char *red, char *green, char *blue);

/******** Funcion: drawPage **************
Descripcion: Funcion que genera una página de colores en consola 
Parametros:
	tipo: entero; 1-> list, 2-> grid
Retorno: void
************************************************/
void drawPage(int tipo);


#endif
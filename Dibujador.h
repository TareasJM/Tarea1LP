#ifndef _DIBUJADOR_H_
#define _DIBUJADOR_H_
/******** Funcion: drawColorList **************
Descripcion: Funcion encargada de inicializar una lista vacia 
Parametros:
	int: pos 
	char: puntero a nombre
	char: puntero a red
	char: puntero a green
	char: puntero a blue
Retorno: void
************************************************/

void drawColorList(int num, char *nombre, char *red, char *green, char *blue);
/******** Funcion: drawColorGrid **************
Descripcion: Funcion encargada de inicializar una lista vacia 
Parametros:
	int: num (numero del color)
	int: posx (pos eje x en la terminal)
	int: poy (pos eje y en la terminal)
	char: puntero a nombre
	char: puntero a red
	char: puntero a green
	char: puntero a blu
Retorno: void
************************************************/

void drawColorGrid(int num, int posx, int posy, char *nombre, char *red, char *green, char *blue);

/******** Funcion: drawPage**************
Descripcion: Funcion encargada de inicializar una lista vacia 
Parametros:
	int: tipo ( para dibujar lista o grid)
Retorno: void
************************************************/
void drawPage(int tipo)

#endif
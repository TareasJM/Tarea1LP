#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct
{
	char* nombre;
	int red;
	int green;
	int blue;
}Color;	

/******** Funcion: newColor **************
Descripcion: Funcion que inicializa un color
Parametros:
	color: string
	red: int
	gree: int
	blue: int
Retorno: Puntero a Color
************************************************/
Color* initColor(char *colorName, int red, int green, int blue);

/******** Funcion: newColor **************
Descripcion: Funcion que crea un nuevo color y lo ingreasa a la lista
Parametros:
	color: Puntero a Color
Retorno: 0->exito, 1->error
************************************************/
int newColor(Color *color);

/******** Funcion: deleteColor **************
Descripcion: Funcion que elimina un color de la lista
Parametros:
	color: string
Retorno: 0->exito, 1->error
************************************************/
int deleteColor(char *colorName);

/******** Funcion: getColorName **************
Descripcion: Funcion que retorna el nombre de un Color
Parametros:
	color: puntero a Color
Retorno: string
************************************************/
char *getColorName(Color *color);

/******** Funcion: getColorRed **************
Descripcion: Funcion que retorna el valor rojo del Color 
Parametros:
	color: puntero a Color
Retorno: int
************************************************/
char *getColorRed(Color *color);

/******** Funcion: getColorGreen **************
Descripcion: Funcion que retorna el valor verde del Color 
Parametros:
	color: puntero a Color
Retorno: int
************************************************/
char *getColorGreen(Color *color);

/******** Funcion: getColorBlue **************
Descripcion: Funcion que retorna el valor azul del Color
Parametros:
	color: puntero a Color
Retorno: int
************************************************/
char *getColorBlue(Color *color);


#endif



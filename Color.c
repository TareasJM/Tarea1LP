#include "Color.h"
#include "Lista.h"

Color*  initColor(char *colorName, int red, int green, int blue)
{
	Color *color = (Color*)malloc(sizeof(Color));
	color->nombre = colorName;
	color->red = red;
	color->green = green;
	color->blue = blue;

	return color;
}

int newColor(Color *color)
{
	Lista lista;
	initLista(&lista);
	textToList(&lista);
	while( getPos(&lista) <= getSize(&lista))
	{
		Color *current = getCurrentColor(&lista);
		if (strcmp( current->nombre, color->nombre) == 0)
		{
			printf("Nombre de color ya ingresado\n");
			return 1;
		}  
		next(&lista);
	}
	append(&lista, color);
	listToText(&lista);
	clear(&lista);
	return 0;
}	

int deleteColor(char *colorName)
{
	Lista lista;
	initLista(&lista);
	textToList(&lista);
	if (removeNode(&lista, colorName) == 1)
	{
		printf("Nombre de color no ingresado\n");
	}
	else
	{
		listToText(&lista);
	}
	clear(&lista);
	return 0;
}	
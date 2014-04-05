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
	Lista *lista = initLista();
	textToList(lista);
	goToStart(lista);
	while( getSize(lista) > 0 ) 
	{	
		Color *current = getCurrentColor(lista);
		if (strcmp( current->nombre, color->nombre) == 0)
		{
			printf("Nombre de color ya ingresado (%s)\n", color->nombre);
			return 1;
		}  
		if (next(lista) == 1)
		{
			break;
		}
		
	}
	append(lista, color);
	listToText(lista);
	clearList(lista);
	return 0;
}	

int deleteColor(char *colorName)
{
	Lista *lista;
	lista = initLista();
	textToList(lista);
	if (removeNode(lista, colorName) == 1)
	{
		printf("Color no existe(%s)\n", colorName);
	}
	else
	{
		listToText(lista);
	}
	clearList(lista);
	return 0;
}	

char *getColorName(Color *color)
{
	return color->nombre;
}

char *getColorRed(Color *color)
{
	char *red = (char*)malloc(sizeof(char)*5);
	snprintf(red, 5, "%d", color->red);
	return red;
}

char *getColorGreen(Color *color)
{
	char *green = (char*)malloc(sizeof(char)*5);
	snprintf(green, 5, "%d", color->green);
	return green;
}

char *getColorBlue(Color *color)
{
	char *blue = (char*)malloc(sizeof(char)*5);
	snprintf(blue, 5, "%d", color->blue);
	return blue;
}
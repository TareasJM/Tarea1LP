#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.c"
#include "Lista.c"
#include "Dibujador.c"

int main(int argc, char const *argv[])
{
	if (  (argc == 6) && strcmp( argv[1], "-i" ) == 0 )
    {
    	char *colorName = (char*)malloc(strlen(argv[2])+1);
    	strcpy(colorName,argv[2]);
    	Color *color = initColor(colorName,atoi(argv[3]),atoi(argv[4]), atoi(argv[5]));
		newColor(color);
		return 0;
    }
    else if (  (argc == 2) && strcmp( argv[1], "-d" ) == 0 )
    {
    	char *colorName = (char*)malloc(strlen(argv[2])+1);
    	strcpy(colorName,argv[2]);
    	deleteColor(colorName);
    	return 0;
    }
    else if (  (argc == 2) && strcmp( argv[1], "-list" ) == 0 )
    {
    	drawPage(1);
    	return 0;
    }
    else if( (argc == 2) && strcmp( argv[1], "-grid" ) == 0 )
    {
    	drawPage(2);
        return 0;
    }
    else
    {
        printf("Opciones validas:\n");
        printf("    -i name red green blue (ingresa color name (red,green,blue))\n");
        printf("    -d name                (borra el color name)\n");
        printf("    -list                  (muestra los colores en una lista)\n");
        printf("    -grid                  (muestra los colores en una cuadricula)\n");
        return 1;
    }
}

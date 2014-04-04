#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.c"
#include "Lista.c"

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
    else if (  (argc == 3) && strcmp( argv[1], "-i" ) == 0 )
    {
    	char *colorName = (char*)malloc(strlen(argv[2])+1);
    	strcpy(colorName,argv[2]);
    	deleteColor(colorName);
    	return 0;
    }
    else	
    {
		return 1;
	}
}

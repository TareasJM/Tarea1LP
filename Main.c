// argument_definitions.cpp
// compile with: /EHsc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


int init_color(char *nombre, int num_red, int num_green, int num_blue)
{	
	FILE *archivo;
		
	archivo = fopen("colors.txt","a+");
	fprintf(archivo,"%s\n%s\n%s\n%s\n", nombre, num_red,num_green,num_blue);
	printf("Se ha ingresado %s\n %s\n %s\n %s\n", nombre, num_red,num_green,num_blue);
		
	return 10; 
}

int main( int argc, char *argv[], char *envp[] ) {
    

    if (  (argc == 6) &&strcmp( argv[1], "-i" ) == 0 )
    {
		init_color(argv[2],atoi(argv[3]),atoi(argv[4]), atoi(argv[5]));
		return 0;
    }
    else	
    {

    	
		return 1;
	}
        
}



///////////marco chupalooooooooooooooooooo


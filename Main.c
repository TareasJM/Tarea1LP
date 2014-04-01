// argument_definitions.cpp
// compile with: /EHsc
#include <stdio.h>
#include <string.h>

int init_color(char *nombre, char *num_red, char *num_green, char *num_blue)
{	
	FILE *archivo;
		
	archivo = fopen("colors.txt","a+");
	fprintf(archivo,"%s\n%s\n%s\n%s\n", nombre, num_red,num_green,num_blue);
	printf("Se ha ingresado %s\n %s\n %s\n %s\n", nombre, num_red,num_green,num_blue);
	return 10;
}

int main( int argc, char *argv[], char *envp[] ) {
    
	int opcion;
    // If /n issed to the .exe, display numbered listing
    // of environment variables.

    if (  (argc == 6) &&strcmp( argv[1], "-i" ) == 0 )
    {
		
		printf("Yupi\n");
       
       opcion = 1;
    }
    else
    {
		opcion = 0;
	}
    
    
    switch(opcion)
    
    {
		
    case 1: init_color(argv[2],argv[3],argv[4], argv[5]);
			break;
			
    default: 	printf("BUUU WENDY BUU");
	}
    return 0;
    
}


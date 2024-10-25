#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	/* int opcion = 0;

	*while(opcion != 4){
	//Código a ejecutar
	*printf("Introduce una opción: (4 para salir) \n");
	*scanf("%d", &opcion);
	}*/


	int opcion;
	
	do{
	printf("Introduce una opción: (4 para salir) \n");
        scanf("%d", &opcion);
        }
	while(opcion != 4);
return 0;
}


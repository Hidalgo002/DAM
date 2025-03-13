#include <stdio.h>
#include <stdlib.h>



int main(){
	int condicion = 1;
	
	scanf("%d", &condicion);

	if ( condicion == 0){
		printf("Condición vale 0\n");}
	else if (condicion == 1){
		printf("Condición vale 1\n");}
	else if (condicion == 2){
		printf("Condición vale 2\n");}
	
	return EXIT_SUCCESS;
}

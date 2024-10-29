#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char palabra1 [50];
	char palabra2 [50];
	
	printf("Introduce la primera palabra: ");
	scanf("%49s", palabra1);
	printf("Introduce la segunda palabra: ");
	scanf("%49s", palabra2);

	if (strlen(palabra1) >= 50 ||  strlen( palabra2) >= 50){
		printf("La palabra introducida es demasiado larga.\n");}

	else if (strlen(palabra1) == strlen( palabra2)){
		printf("Las dos palabras tienen el mismo número de letras. \n");}
	else if (strlen(palabra1) > strlen( palabra2)){
		printf("La palabra 1 es mayor que la palabra 2.\n");}
	else if (strlen(palabra1) < strlen( palabra2)){
		printf("La palabra 2 es mayor que la palabra 1.\n");}
	else{
		printf("Opción no válida \n");}


	//Bucles: Comparando caracter a caracter
	
	for(int i = 0; i<50; i++){
		printf(palabra1[i] == palabra2[i]);
/bin/bash: line 1: aa-remove-unknown::: command not found
return 0;
}

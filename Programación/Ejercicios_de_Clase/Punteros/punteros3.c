#include <stdio.h>
#include <stdlib.h>

/*	EJEMPLO DE PASO DE UN ARGUMENTO A UNA FUNCIÓN POR VALOR */

void incrementar (int n){
	printf("Valor recibido: %d\n" ,n);
	n = n +1; //Se incrementa + 1
	printf("Valor incrementado en la función: %d\n" ,n);}


int main(){
	int valor = 10;
	incrementar(valor); //Llamamos al void, sustituyendo 'n' por 'valor'
	printf("Valor: %d \n", valor);







	
	
	
	
	
	
	
	
	
	
	
	
return 0;
}


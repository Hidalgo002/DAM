#include <stdio.h>
#include <stdlib.h>

/*	EJEMPLO DE PASO DE UN ARGUMENTO A UNA FUNCIÓN POR REFERENCIA */


//Quiero que realmente incremente la variable dada como argumento.

void incrementar (int *n){//Ya no recibe un entero, recibe la dirección de memoria 
			  //donde se encuentra un número entero
	printf("Valor recibido: %d\n" , *n);
	*n = (*n) +1; //Se incrementa + 1 en contenido del puntero, pues hemos puesto '*'
	printf("Valor incrementado en la función: %d\n" , *n);}


int main(){
	int valor = 10; 
	incrementar(&valor); //Llamamos al void, sustituyendo 'n' por 'valor'
			     // Accedemos a la dirección de la memoria con un &valor
/* Lo que hace esta línea de código es pasar la dirección de memoria de valor a la función incrementar, lo que permite que la función modifique directamente el valor de valor. Como se está trabajando con la dirección de memoria, el cambio realizado dentro de la función (incrementar el valor de valor en 1) afecta de manera permanente a la variable en el main.*/

	printf("Valor: %d \n", valor);


	
	
	
	
	
	
	
	
	
	
	
	
return 0;
}


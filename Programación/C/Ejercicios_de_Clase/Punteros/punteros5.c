#include <stdio.h>
#include <stdlib.h>


int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	int *p = arr;

	printf("Elemento 1: %d\n", *p);     // Actualmente, apunta a la primera casilla del array.
					    // por lo que imprime 1.
	p++; //Se suma 1 a la posición del puntero
	printf("Elemento 2: %d\n", *p);     // Por lo que imprimer la segunda casilla, 2.

	p += 2; //Se le suman dos posiciones al puntero, por lo que nos deplazamos a
		//la cuarta posición. Resultado= 4
	printf("Elemento 4: %d\n", *p);     // Imprime 4

	printf("Elemento posición 0: %d\n",p[0]); // Cuando indicamos P[0], no hay modificaciones, no hay suma al puntero ni resta. Es decir, la posición actualizada está apuntando al 4. Por lo que es su valor primario, el 4.
	
	//Si quiero que se reinicie el array, tenemos que traer atrás al puntero al inicio del array, es decir:
	// p = arr; //Fijate que es solamente nuestra variable p, no es el puntero '*'
	

	//Ahora, si hacemos:
	printf("Elemento posición 0: %d\n",p[-2]);
	//Nos movemos dos posiciones hacia atrás, antes cuando hemos hecho p[0], solo estábamos apuntando a la posición 0, que está actializado al 4-
	printf("Elemento posición 0: %d\n",p[1]);//Sumará 1 a la posición actual de nuestro puntero que ahora está estacionado en el 4.
	

	
return 0;
}

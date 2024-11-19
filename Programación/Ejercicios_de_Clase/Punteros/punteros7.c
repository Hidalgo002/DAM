#include <stdio.h>
#include <stdlib.h>

//7. PUNTEROS VOID Y CASTING
//Punteros VOID-> Trabajar con punteros sin saber lo que hay dentro.

//*ptr será lo que hay que imprimir
//tipo indica el tipo de variable
void printValor(void *ptr, char tipo){
	switch(tipo){
		case 'i':
//NOTA: UN CASTING ES CONVERTIR UN TIPO DE VARIABLE A OTRO. TODOS MENOS LA CENVERSIÓN DE INT A CHAR Y CHAR A INT (QUE ES UN CASTING IMPLÍCITO) SON EXPLÍCITOS EN C
		printf("Valor entero: %d\n", *(int *)ptr)); //*ptr es la variable que 
		break;			      		//quiero convertir. por lo que
						      	//no podemos poner solo
						      	//'printf("Double %lf\n", *ptr);'
		case 'f':
		printf("Valor Flotante: %f\n", *((float *)ptr));
		break;

		default:
			printf("ERROR");
	}
}


int main(){
	int num = 2;
	float val = 3.14;

	printValor(dir, 'i');
        printValor(dir, 'f');




return 0;
}

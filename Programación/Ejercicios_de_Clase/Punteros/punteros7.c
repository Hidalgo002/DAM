#include <stdio.h>
#include <stdlib.h>

//7. PUNTEROS VOID Y CASTING
//Punteros VOID-> Trabajar con punteros sin saber lo que hay dentro.

//*ptr será lo que hay que imprimir
//tipo indica el tipo de variable
void printValor(void *ptr, char tipo){
	switch(tipo){
		case 'd':
//NOTA: UN CASTING ES CONVERTIR UN TIPO DE VARIABLE A OTRO. TODOS MENOS LA CENVERSIÓN DE INT A CHAR Y CHAR A INT (QUE ES UN CASTING IMPLÍCITO) SON EXPLÍCITOS EN C
		printf("Double %lf\n", *((double *)ptr)); //*ptr es la variable que 
		break;			      		//quiero convertir. por lo que
						      	//no podemos poner solo
						      	//'printf("Double %lf\n", *ptr);'
		case 'i':
		printf("Entero %d\n", *((int *)ptr));
		break;

		default:
			printf("ERROR");
	}
}


int main(){
	double num = 2.1;

	void * dir = &num;	
	printValor(dir, 'd');
        printValor(dir, 'i');




return 0;
}

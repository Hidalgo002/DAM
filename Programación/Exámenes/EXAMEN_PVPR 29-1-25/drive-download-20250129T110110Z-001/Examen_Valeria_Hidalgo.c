#include <stdio.h>
#include <stdlib.h>

void modificar_elemento (int *ARR, int valor, int n){
        ARR[n] = valor;

        printf("Nuevo valor: %d\n", ARR[n]);

}

void modificar_por_referencia(int *ARR, int *valor, int* n){
        ARR[n]* = valor;

        printf("Nuevo valor: %d\n", ARR[n]);
}

int main(){
	int valor = 10;
	int n;
	printf("Introduzca un número entero positivo: ");
	scanf("%d", &n);

	int * ARR = (int*) malloc(n*sizeof(int));
	
	printf("Ingrese los números del array:\n ");
       
       	for(int i = 0; i<n; i++){
                printf("\t Número %d:", i+1);
                scanf("%d", &ARR[i]);
      }

	modificar_elemento(int *ARR, int valor, int n);

	modificar_por_referencia (int *ARR, int *valor, int* n);
	
	return 0;
}

/**
 *Cuando se pasa un valor se modifica temporalmente, pero vuelve a su valor original una vez se haya acabado la función.

 Cuando lo pasmos por referencia, estamos pasando la localización que debe cambiar y por lo tanto, el cambio es permanente.


Para calcular el espacio que ocupa un array double, n * sizeof(double)
int ocupa 4 espacios y souble 8. por lo que 8*n.
 */


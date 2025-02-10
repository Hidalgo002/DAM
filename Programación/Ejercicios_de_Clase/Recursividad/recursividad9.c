#include <stdio.h>
#include <stdlib.h>

int numPar (int num, int n, int suma){
	for(int i = 0; i<n; i){
		if(num[i] == %2){
			suma++;
		}
	}
}

int main(){
	int n;
	printf("Introduzca el tamaño del número: ");
	scanf("%d", &n);

	int * num = (int*) malloc(n*sizeof(int));
	printf("Introduzca el número: ");
	scanf("%d", num);

	printf("La cantidad de números pares es: %d.\n");


return 0;
}
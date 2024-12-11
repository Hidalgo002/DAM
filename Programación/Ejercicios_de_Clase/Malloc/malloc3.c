#include <stdio.h>
#include <stdlib.h>

/*EJERCICIO: Crea un programa que pida por pantalla un número entero y cree un array de enteros de ese tamaño inicializando con número pares*/

int main(){
	int n;
	printf("Introduce en tamaño del array: ");
	scanf("%d", &n);

	int * arr = (int *) malloc(n*sizeof(int));

	if(arr == NULL){
		printf("ERROR: no se pudo asignar memoria.\n");
		return 1;
	}

	for(int i = 0; i<n;i++){
		arr[i]= 2*i;
		printf("%d. Arr[%d] = %d\n",i+1,n, arr[i]);
	}

free (arr);
return 0;
}	
#include <stdio.h>
#include <stdlib.h>

/*EJERCICIO: Crea un programa que pida por pantalla un número entero y cree un array de enteros de ese tamaño inicializando con número pares*/
/*6. **Ingresar datos del usuario en memoria dinámica:**
    
    Reserva memoria para un arreglo de `int` según un tamaño dado por el usuario, solicita los valores y luego imprímelos.*/

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

//EJERCICIO: MODIFICA EL PUNETO PARA QUE SEA UN ARRAY EL DOBLE DE GRANDE Y, EN LA SEGUNDA PARTE DEL ARRAY, SE GUARDAN LOS NÚMERO IMPARES
	int n2 = n*2;
	int * arr2 = (int *) realloc(arr, n2*sizeof(int));

	if(arr == NULL){
		printf("ERROR: no se pudo asignar memoria.\n");
		free(arr);
		return 1;
	}

arr = arr2;

	for(int i = 0; i<n2;i++){
		arr[i]= 2*i+1;
		printf("%d. Arr 2 [%d] = %d\n",i+1,n2, arr[i]);
	}

free(arr);
return 0;
}	
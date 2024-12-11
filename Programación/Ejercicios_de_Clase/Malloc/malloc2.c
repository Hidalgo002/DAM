#include <stdio.h>
#include <stdlib.h>

//EJERCICIO: Declara un array tamaño 3 utilizando memoria dinámica.
int main(){
	int n = 3;

	int * arr = (int *) malloc(3*sizeof(int));
	//puntero a entreo int * arr a (int*) el int es casting
	//malloc(3*sizeof(int)) -> reservamos el tamaño de 3 enteros

	if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

  //EJERCICIO: Inicializa los valores con los número 1,2 y 5

    for (int i = 0; i < 3; i++) {
    	arr[i] = 2*i + 1;
    	printf("arr[%d] = %d\n", i, arr[i]);
    }

//EJERCICIO: Ampliar el array a 5 elementos
    int * arr_Ampliado = (int *) realloc(arr, 5*sizeof(int)); //Le damos el array viejo (arr)

    if (arr_Ampliado == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        free(arr); //MOVEMOS EL FREE A ESTE LUGAR PARA QUE SE LIBERE LA MEMORIA VIEJA EN CASO DE QUE NO HAYAMOS PODIDO MOVERNOS AL ARRAY NUEVO
        return 1;
    }

    //Para evitar confiusiones entre arr_Ampliado y arr es recomendable añadir: 
    arr = arr_Ampliado;

	for (int i = 0; i < 5; i++) {
    	arr[i] = 2*i + 1;
    	printf("arr_Ampliado[%d] = %d\n", i, arr[i]);
    }

free(arr);
return 0;
}
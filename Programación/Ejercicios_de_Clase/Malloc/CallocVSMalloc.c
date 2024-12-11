#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
	int n = 5;	
    //MALLOC
    //RESERVA ESTÁTICA ->  int arr[5];
    //RESERVA DINÁMICA :
    int * arr = (int *) malloc(5*sizeof(int));


    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); //Para recorrer el array, también podemos usar: printf("arr[%d] = %d\n", i, *(arr+i)
    }

    /*LO MISMO CON CALLOC*/
    //CALLOC
    int * arr2 = (int *) calloc(5, sizeof(int)); // Reserva e inicializa a cero

    if (arr2 == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

free(arr);
free(arr2);
return 0;
}


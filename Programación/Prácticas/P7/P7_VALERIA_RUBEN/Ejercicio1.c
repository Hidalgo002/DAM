#include <stdio.h>
#include <stdlib.h>

void ordenar(int *arr, int tamaño);

int main() {

    int tamaño; //reserva de memoria para introducir los numeros

    printf("Introduzca cuántos números quieres ordenar de menor a mayor: ");
    scanf("%d", &tamaño);

    int *arr = (int *)malloc(tamaño * sizeof(int));
    if (arr == NULL) {
        printf("ERROR CATASTRÓFICO. NO SE PUDO ASIGNAR MEMORIA.\n");
        return 1;
    }

    printf("Introduzca los números: \n"); //bucle para rellenar el array
    for (int i = 0; i < tamaño; i++){
        scanf("%d", &arr[i]);
    }

    ordenar(arr, tamaño); //funcion orden

    printf("Los números ordenados de menor a mayor: \n"); //bucle para imprimir el array ordenado
    for (int i = 0; i < tamaño; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}

void ordenar(int *arr, int tamaño) {
    for (int i = 0; i < tamaño; i++){

        for (int j = 0; j < tamaño - 1 ; j++){ // tamaño -1 - i ->el -1 se utiliza para evitar desbordamientos, si nuestro 
                                               // tamaño es 5, el array seria 0,1,2,3,4 sin el -1 se saldria al 5. 
                                               
            if (arr[j] > arr[j + 1]) { //si arr[0] = 3, arr[1] = 2, se ejecuta e intercambia el 2 por el 3 en arr[j] = arr[j + 1]

                int intercambio; //guarda el valor temporalmente
                intercambio = arr[j]; //guardamos el valor de arr[j] en intercambio
                arr[j] = arr[j + 1];//movemos el valor de arr[j+1] a arr[j] si se cumple el if
                arr[j + 1] = intercambio;//asignamos el valor a arr[j+1] de itercambio
            }
        }
    }
}


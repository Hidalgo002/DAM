#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamano1, tamano2;
    int multiplo1 = 1; // Múltiplo fijo para el primer array
    int multiplo2 = 2; // Múltiplo fijo para el segundo array
    int opcion;

    // Solicitar el tamaño del primer array
    printf("Introduce el tamaño del primer array: ");
    scanf("%d", &tamano1);

    // Reservar memoria para el primer array
    int *array1 = (int *)malloc(tamano1 * sizeof(int));
    if (array1 == NULL) {
        printf("Error al reservar memoria para el primer array.\n");
        return 1;
    }

    // Llenar el primer array con múltiplos de 1
    for (int i = 0; i < tamano1; i++) {
        array1[i] = multiplo1 * (i + 1);
    }

    // Solicitar el tamaño del segundo array
    printf("Introduce el tamaño del segundo array: ");
    scanf("%d", &tamano2);

    // Reservar memoria para el segundo array
    int *array2 = (int *)malloc(tamano2 * sizeof(int));
    if (array2 == NULL) {
        printf("Error al reservar memoria para el segundo array.\n");
        free(array1); // Liberar memoria del primer array
        return 1;
    }

    // Llenar el segundo array con múltiplos de 2
    for (int i = 0; i < tamano2; i++) {
        array2[i] = multiplo2 * (i + 1);
    }

    // Preguntar al usuario si desea sumar o concatenar los arrays
    printf("¿Qué operación deseas realizar?\n");
    printf("1. Sumar coordenada a coordenada\n");
    printf("2. Concatenar los arrays\n");
    printf("Introduce tu opción (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Sumar coordenada a coordenada
        int tamano_resultado = (tamano1 < tamano2) ? tamano1 : tamano2;
        int *array_suma = (int *)malloc(tamano_resultado * sizeof(int));
        if (array_suma == NULL) {
            printf("Error al reservar memoria para el array suma.\n");
            free(array1);
            free(array2);
            return 1;
        }

        for (int i = 0; i < tamano_resultado; i++) {
            array_suma[i] = array1[i] + array2[i];
        }

        // Imprimir el resultado
        printf("Resultado de la suma coordenada a coordenada:\n");
        for (int i = 0; i < tamano_resultado; i++) {
            printf("%d ", array_suma[i]);
        }
        printf("\n");

        free(array_suma); // Liberar memoria del array suma
    } else if (opcion == 2) {
        // Concatenar los arrays
        int tamano_resultado = tamano1 + tamano2;
        int *array_concatenado = (int *)malloc(tamano_resultado * sizeof(int));
        if (array_concatenado == NULL) {
            printf("Error al reservar memoria para el array concatenado.\n");
            free(array1);
            free(array2);
            return 1;
        }

        // Copiar los elementos del primer array
        for (int i = 0; i < tamano1; i++) {
            array_concatenado[i] = array1[i];
        }

        // Copiar los elementos del segundo array
        for (int i = 0; i < tamano2; i++) {
            array_concatenado[tamano1 + i] = array2[i];
        }

        // Imprimir el resultado
        printf("Resultado de la concatenación:\n");
        for (int i = 0; i < tamano_resultado; i++) {
            printf("%d ", array_concatenado[i]);
        }
        printf("\n");

        free(array_concatenado); // Liberar memoria del array concatenado
    } else {
        printf("Opción no válida.\n");
    }

    // Liberar la memoria de los arrays originales
    free(array1);
    free(array2);

    return 0;
}


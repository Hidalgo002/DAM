#include <stdio.h>
#include <stdlib.h>

void rellenar_array(int *arr, int tamaño, int multiplo) {
    for (int i = 0; i < tamaño; i++) {
        arr[i] = (i + 1) * multiplo; // Llenamos el array con múltiplos de "multiplo"
    }
}

void imprimir_array(int *arr, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tamaño1;
    int tamaño2;
    int multiplo1 = 10;
    int multiplo2 = 2;
    char opción;

    // Paso 1: Solicitar un número entero positivo que determinará el tamaño del primer array
    printf("Introduce el tamaño del primer array: ");
    scanf("%d", &tamaño1);


    int *array1 = (int *)malloc(tamaño1 * sizeof(int));
    if (array1 == NULL) {
        printf("No se pudo reservar memoria para el primer array.\n");
        return 1;
    }
    rellenar_array(array1, tamaño1, multiplo1);
    printf("Primer array: ");
    imprimir_array(array1, tamaño1);

    // Paso 3: Solicitar el tamaño y múltiplo para el segundo array
    printf("Introduce el tamaño del segundo array: ");
    scanf("%d", &tamaño2);


    int *array2 = (int *)malloc(tamaño2 * sizeof(int));
    if (array2 == NULL) {
        printf("No se pudo reservar memoria para el segundo array.\n");
        free(array1);
        return 1;
    }
    rellenar_array(array2, tamaño2, multiplo2);
    printf("Segundo array: ");
    imprimir_array(array2, tamaño2);

    // Paso 4: Preguntar al usuario si quiere concatenar o sumar
    printf("¿Quieres concatenar (c) o sumar (s) los arrays? ");
    scanf(" %c", &opción);  // El espacio antes de %c es para ignorar cualquier espacio en blanco previo

    if (opción == 's') {
        // Caso 1: Sumar los arrays
        if (tamaño1 == tamaño2) {
            int *resultado_suma = (int *)malloc(tamaño1 * sizeof(int));
            if (resultado_suma == NULL) {
                printf("No se pudo reservar memoria para el array de la suma.\n");
                free(array1);
                free(array2);
                return 1;
            }

            for (int i = 0; i < tamaño1; i++) {
                resultado_suma[i] = array1[i] + array2[i];
            }

            printf("Resultado de la suma coordenada a coordenada: ");
            imprimir_array(resultado_suma, tamaño1);
            free(resultado_suma);
        } else {
            printf("Los arrays no tienen el mismo tamaño, no se puede realizar la suma coordenada a coordenada.\n");
        }
    } else if (opción == 'c') {
        // Caso 2: Concatenar los arrays
        int *resultado_concatenado = (int *)malloc((tamaño1 + tamaño2) * sizeof(int));
        if (resultado_concatenado == NULL) {
            printf("No se pudo reservar memoria para el array concatenado.\n");
            free(array1);
            free(array2);
            return 1;
        }

        // Copiar el primer array al array concatenado
        for (int i = 0; i < tamaño1; i++) {
            resultado_concatenado[i] = array1[i];
        }

        // Copiar el segundo array al array concatenado
        for (int i = 0; i < tamaño2; i++) {
            resultado_concatenado[tamaño1 + i] = array2[i];
        }

        printf("Resultado de la concatenación: ");
        imprimir_array(resultado_concatenado, tamaño1 + tamaño2);
        free(resultado_concatenado);
    } else {
        printf("Opción no válida. El programa terminará.\n");
    }

    // Liberar memoria
    free(array1);
    free(array2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void modificar_por_valor(int *ARR, int valor, int n) {
    // Modifica temporalmente el array, pero el cambio no persiste en main
    ARR[n] = valor;
    printf("En modificar_por_valor - Nuevo valor en ARR[%d]: %d\n", n, ARR[n]);
}

void modificar_por_referencia(int *ARR, int *valor, int *n) {
    // Modifica el array permanentemente porque se pasan punteros
    ARR[*n] = *valor;
    printf("En modificar_por_referencia - Nuevo valor en ARR[%d]: %d\n", *n, ARR[*n]);
}

int main() {
    int valor = 10;
    int n;
    
    printf("Introduzca un número entero positivo: ");
    scanf("%d", &n);

    // Validar entrada
    if (n <= 0) {
        printf("El número debe ser positivo.\n");
        return 1;
    }

    // Reservar memoria para el array
    int *ARR = (int*) malloc(n * sizeof(int));
    if (ARR == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Llenar el array
    printf("Ingrese los números del array:\n");
    for (int i = 0; i < n; i++) {
        printf("\tNúmero %d: ", i + 1);
        scanf("%d", &ARR[i]);
    }

    // Llamar a modificar_por_valor (NO cambia permanentemente)
    modificar_por_valor(ARR, valor, n - 1);
    printf("Después de modificar_por_valor - ARR[%d]: %d\n", n - 1, ARR[n - 1]);

    // Llamar a modificar_por_referencia (SÍ cambia permanentemente)
    modificar_por_referencia(ARR, &valor, &n);
    printf("Después de modificar_por_referencia - ARR[%d]: %d\n", n, ARR[n]);

    // Liberar memoria
    free(ARR);

    return 0;
}

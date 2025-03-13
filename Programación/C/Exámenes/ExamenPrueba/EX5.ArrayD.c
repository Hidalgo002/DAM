#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Solicitar al usuario un número entero positivo
    printf("Introduce un numero entero positivo: ");
    scanf("%d", &n);

    // Verificar si el número es válido
    if (n <= 0) {
        printf("El número debe ser mayor que cero.\n");
        return 1;
    }

    // Reservar memoria dinámica para el array
    double* array = (double*)malloc(n * sizeof(double));

    // Verificar si la memoria se asignó correctamente
    if (array == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Inicializar el array con la fórmula valor[i] = 1/(i+1)
    for (int i = 0; i < n; i++) {
        array[i] = 1.0 / (i + 1);
    }

    // Imprimir el contenido del array
    printf("Contenido del array:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.4f\n", i, array[i]);
    }

    // Liberar la memoria dinámica
    free(array);

    return 0;
}


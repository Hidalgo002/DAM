#include <stdio.h>
#include <stdlib.h>

// Función para intercambiar la primera y la última fila de la matriz
void intercambiar_filas(int **matriz, int n) {
    // Intercambiar la primera fila (índice 0) y la última fila (índice n-1)
    for (int j = 0; j < n; j++) {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[n-1][j];
        matriz[n-1][j] = temp;
    }
}

int main() {
    int n;
    
    // Solicitar un número entero positivo n
    printf("Introduce el tamaño de la matriz cuadrada (n): ");
    scanf("%d", &n);
    
    // Verificar si el número es válido
    if (n <= 0) {
        printf("El número debe ser mayor que cero.\n");
        return 1;
    }

    // Reservar memoria dinámica para una matriz de n × n enteros
    int **matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }

    // Rellenar la matriz con valores ingresados por el usuario
    printf("Introduce los elementos de la matriz de tamaño %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrar la matriz antes del intercambio
    printf("\nMatriz antes de intercambiar las filas:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Llamar a la función para intercambiar la primera y última fila
    intercambiar_filas(matriz, n);

    // Mostrar la matriz después del intercambio
    printf("\nMatriz después de intercambiar las filas:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria utilizada
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

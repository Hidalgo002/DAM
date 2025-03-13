#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Solicitar al usuario dos números enteros positivos
    printf("Introduce el número de filas (n): ");
    scanf("%d", &n);
    printf("Introduce el número de columnas (m): ");
    scanf("%d", &m);

    // Verificar si los números son válidos
    if (n <= 0 || m <= 0) {
        printf("Los números deben ser mayores que cero.\n");
        return 1;
    }

    // Reservar memoria dinámica para la matriz de n × m
    int** matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(m * sizeof(int));
    }

    // Reservar memoria para el array de sumas por filas
    int* sumas = (int*)malloc(n * sizeof(int));

    // Inicializar la matriz y calcular la suma de los elementos de cada fila
    for (int i = 0; i < n; i++) {
        sumas[i] = 0;  // Inicializar la suma de la fila
        for (int j = 0; j < m; j++) {
            matriz[i][j] = i + j;  // La suma de la fila y columna
            sumas[i] += matriz[i][j];  // Acumulamos la suma de la fila
        }
    }

    // Imprimir la matriz
    printf("Matriz %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimir el array con las sumas por fila
    printf("Suma de los elementos por fila:\n");
    for (int i = 0; i < n; i++) {
        printf("Suma de la fila %d: %d\n", i, sumas[i]);
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(sumas);

    return 0;
}


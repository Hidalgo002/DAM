#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Solicitar al usuario un número entero positivo
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);
    
    // Verificar que el número sea positivo
    if (n <= 0) {
        printf("El número debe ser un entero positivo.\n");
        return 1;
    }
    
    // Reservar memoria dinámicamente para el array
    double *array = (double *)malloc(n * sizeof(double));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    // Inicializar el array con la fórmula valor[i] = 1 / (i + 1)
    for (int i = 0; i < n; i++) {
        array[i] = 1.0 / (i + 1);
    }
    
    // Imprimir el contenido del array
    printf("Contenido del array:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %lf\n", i, array[i]);
    }
    
    // Liberar la memoria asignada dinámicamente
    free(array);
    
    return 0;
}
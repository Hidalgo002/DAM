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
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    // Solicitar al usuario los valores para llenar el array
    printf("Ingrese %d valores enteros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor[%d]: ", i);
        scanf("%d", &array[i]);
    }
    
    // Imprimir el contenido del array
    printf("Contenido del array:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    // Liberar la memoria asignada dinámicamente
    free(array);
    
    return 0;
}

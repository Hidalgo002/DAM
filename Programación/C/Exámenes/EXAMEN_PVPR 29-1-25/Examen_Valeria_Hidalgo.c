#include <stdio.h>
#include <stdlib.h>


void modificar_elemento(int valor, int *ARR, int n) {
    int temp = ARR[n - 1] + valor;
    printf("En modificar_elemento - Nuevo valor calculado para ARR[%d]: %d (pero no se modifica en el array)\n", n - 1, temp);
}

void modificar_elemento_por_referencia(int *valor, int *ARR, int n) {
    ARR[n - 1] += *valor;
    printf("En modificar_elemento_por_referencia - Nuevo valor en ARR[%d]: %d\n", n - 1, ARR[n - 1]);
}

int main() {
    int valor = 10;
    int n;
    
    printf("Introduzca un numero entero positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El numero debe ser positivo.\n");
        return 1;
    }

    int *ARR = (int*) malloc(n * sizeof(int));
    if (ARR == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese los numeros del array:\n");
    for (int i = 0; i < n; i++) {
        printf("\tNumero %d: ", i + 1);
        scanf("%d", &ARR[i]);
    }

    modificar_elemento(valor, ARR, n);
    printf("Despues de modificar_elemento - ARR[%d]: %d (sin cambios)\n", n - 1, ARR[n - 1]);

    modificar_elemento_por_referencia(&valor, ARR, n);
    printf("Despues de modificar_elemento_por_referencia - ARR[%d]: %d\n", n - 1, ARR[n - 1]);

    free(ARR);
    return 0;
}
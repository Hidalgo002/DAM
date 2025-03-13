#include <stdio.h>
#include <stdlib.h>

// Función para verificar si un número es primo
int es_primo(int numero) {
    if (numero < 2) {
        return 0; // Falso
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
}

int main() {
    int tamano;

    // Solicitar el tamaño del array
    printf("Introduce el tamaño del array (número entero positivo): ");
    scanf("%d", &tamano);

    if (tamano <= 0) {
        printf("El tamaño debe ser un número entero positivo.\n");
        return 1;
    }

    // Reservar memoria para el array
    int *array_primos = (int *)malloc(tamano * sizeof(int));
    if (array_primos == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Llenar el array con los primeros `n` números primos
    int numero = 2; // Primer número candidato
    int contador = 0; // Índice del array
    while (contador < tamano) {
        if (es_primo(numero)) {
            array_primos[contador] = numero;
            contador++;
        }
        numero++;
    }

    // Imprimir el array
    printf("Array de los primeros %d números primos:\n", tamano);
    for (int i = 0; i < tamano; i++) {
        printf("%d ", array_primos[i]);
    }
    printf("\n");

    // Liberar la memoria
    free(array_primos);

    return 0;
}


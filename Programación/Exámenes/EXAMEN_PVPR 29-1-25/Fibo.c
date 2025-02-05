#include <stdio.h>
#include <stdlib.h>

// Función para calcular la sucesión de Fibonacci y guardarla en un array usando punteros
void fibonacciConPunteros(int n, int *arr) {
    int a = 0;
    int b = 1;
    int temp;

    arr[0] = a; // La primera posición será 0
    arr[1] = b; // La segunda posición será 1

    for (int i = 2; i < n; i++) {
        temp = a + b; // Se suman los dos valores y se asigna a un valor tempicional
        a = b; // Actualizamos el valor de A al valor de B
        b = temp; // Actualizamos el valor de B al valor tempicional
        arr[i] = b; // Guardamos el resultado en el array a partir de la posición dos
    }
}

// Función para sumar los valores de un array de Fibonacci
int sumarFibonacci(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}

int main() {
    int n;

    printf("Introduce el número de términos de Fibonacci que deseas calcular: ");
    scanf("%d", &n);

    // Validamos que el usuario ingrese un número válido
    if (n <= 0) {
        printf("Por favor, introduce un número mayor que 0.\n");
        return 1;
    }

    int *fibonacciArray = (int *)malloc(n * sizeof(int));
    if (fibonacciArray == NULL) {
        printf("ERROR CATASTRÓFICO. NO SE PUDO ASIGNAR MEMORIA.\n");
        return 1;
    }

    fibonacciConPunteros(n, fibonacciArray);

    printf("Los primeros %d términos de Fibonacci son:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacciArray[i]);
    }
    printf("\n");

    // Llamamos a la nueva función y mostramos la suma
    int suma = sumarFibonacci(fibonacciArray, n);
    printf("La suma de los términos de Fibonacci es: %d\n", suma);

    free(fibonacciArray); // Liberamos la memoria asignada
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Función para calcular la sucesión de Fibonacci y guardarla en un array usando punteros
void fibonacciConPunteros(int n, int *arr) {
    int a = 0
    int b = 1
    int trans;

    // Guardamos los primeros dos valores, que son 0 y 1. No podemos partir sin ningún valor
    arr[0] = a;// La primera posición será 0
    arr[1] = b;// La segunda posición será 1

    // Calcular los términos de Fibonacci a partir del tercero
    for (int i = 2; i < n; i++) {
        trans = a + b;//Se suman los dos valores y se asgina a un valor transicional 
        a = b; //Actualizamnos el valor de A al valor de B
        b = trans; // Actualizamos el valor de B al valor transicional
        arr[i] = b; // Guardamos el resultado en el array a partir de la posisción dos
    }
    /*Se suma  */
}

int main() {
    int n;

    // Solicitar al usuario cuántos términos de Fibonacci desea calcular
    printf("Introduce el número de términos de Fibonacci que deseas calcular: ");
    scanf("%d", &n);

    // Usamos memoria dinámica para crear un array de n términos
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

free(fibonacciArray);// Liberamos la memoria asignada
return 0;
}

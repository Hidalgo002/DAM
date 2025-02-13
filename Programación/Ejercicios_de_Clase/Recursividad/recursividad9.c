/*1. **Contar dígitos pares en un número entero:**

Escribe una función recursiva que, dado un número entero, cuente la cantidad de dígitos que son pares (por ejemplo, en 2846 hay 3 dígitos pares: 2, 8, 4, el 6 también es par, total 4).*/

#include <stdio.h>
#include <stdlib.h>

int numPar(int num, int suma) {
    if (num <= 0) {
        return suma; // Caso base: si num es 0, devolvemos la cantidad de pares encontrados
    }

    int ultimoNum = num % 10; // Extraemos el último dígito

    if (ultimoNum % 2 == 0) { // Si es par, aumentamos suma
        suma++;
    }

    return numPar(num / 10, suma); // Llamada recursiva reduciendo el número
}

int main() {
    int num;

    printf("Introduzca el número: ");
    scanf("%d", &num);

    int resultado = numPar(num, 0); // Se inicializa suma en 0

    printf("La cantidad de números pares es: %d.\n", resultado);

    return 0;
}

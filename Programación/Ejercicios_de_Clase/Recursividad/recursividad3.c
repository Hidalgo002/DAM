#include <stdio.h>

//SUMA DE LOS N PRIMEROS NÚMEROS
// sum(n) = n + sum(n-1) con sum(0)=0
int suma(int n) {
    if (n == 0) return 0;//ESTE ES EL CASO BASE
    return n + suma(n-1);
}

int main() {
    int n;
    printf("Introduzca un número: ");
    scanf("%d", &n);
    printf("La suma de los primeros %d numeros es %d\n", n, suma(n));
    return 0;
}


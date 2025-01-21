#include <stdio.h>// Devuelve el n-ésimo número de Fibonacci.
// Caso base: fib(0)=0, fib(1)=1
// Recursivo: fib(n)=fib(n-1)+fib(n-2)
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;//ESTE ES EL CASO BASE
    
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 10;
    printf("fib(%d) = %d\n", n, fib(n));
    return 0;
}
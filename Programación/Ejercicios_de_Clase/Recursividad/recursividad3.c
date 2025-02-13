#include <stdio.h>

//SUMA DE LOS N PRIMEROS NÚMEROS
// sum(n) = n + sum(n-1) con sum(0)=0
int suma(int n) {
    if (n == 0) return 0;//ESTE ES EL CASO BASE
    return n + suma(n-1);

   /* suma(4) = 4 + suma(3)
      suma(3) = 3 + suma(2)
      suma(2) = 2 + suma(1)
      suma(1) = 1 + suma(0)
      suma(0) = 0  -> Aquí termina la recursión

    Cuando llega al caso base empieza a sumnar en orden inverso, es decir, 1+0, 1+2, 3+3, 6+4, 10+5 = 15

    Cuando una función recursiva alcanza su caso base, la ejecución comienza a resolver las llamadas en orden inverso, es decir, desde la última hasta la primera.
      */
}

int main() {
    int n;
    printf("Introduzca un número: ");
    scanf("%d", &n); //EJEMPLO: 5
    printf("La suma de los primeros %d numeros es %d\n", n, suma(n));
    return 0;
}


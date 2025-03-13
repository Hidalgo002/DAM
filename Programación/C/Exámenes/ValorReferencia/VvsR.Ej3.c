#include <stdio.h>
#include <stdlib.h>

//INTERCAMBIAR DOS VALORES DE FORMA TEMPORAL.-> por VALOR

void intercambioV(int a, int b ){
    int trans;

    trans = a;
    a = b;
    b = trans;
    printf("Los valores intercambiados son: \n"
            "\t A: %d\n"
            "\t B: %d\n", a, b);
}

int main(){
    int a;
    int b;

    printf("Introduzca dos valores: \n"
            "\t Valor A: ");
    scanf("%d", &a);
    printf("\t Valor B: ");
    scanf("%d", &b);

    intercambioV(a, b);

    printf("Los valores después de la función: \n"
            "\t A: %d\n"
            "\t B: %d\n", a, b);

return 0;
}
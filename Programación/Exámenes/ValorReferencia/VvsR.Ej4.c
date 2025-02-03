#include <stdio.h>
#include <stdlib.h>

//INTERCAMBIAR DOS VALORES DE FORMA PERMANENTE.-> por REFERENCIA

void intercambioR(int *a, int *b ){
    int trans;

    trans = *a;
    *a = *b;
    *b = trans;
    printf("Los valores intercambiados son: \n"
            "\t A: %d\n"
            "\t B: %d\n", *a, *b);
}
/*Usamos los punteros *a y *b para acceder a los valores almacenados en las 
direcciones de memoria que se pasaron. Al hacer *a = *b; estamos modificando 
el valor de la variable que a apunta (es decir, a en main()).

El valor de b también se cambia de la misma manera con *b = trans;.

Como a y b en la función apuntan a las mismas direcciones que en main(), 
los cambios son permanentes en main(). */

int main(){
    int a;
    int b;

    printf("Introduzca dos valores: \n"
            "\t Valor A: ");
    scanf("%d", &a);
    printf("\t Valor B: ");
    scanf("%d", &b);

    intercambioR(&a, &b);
    /*La función intercambioR recibe direcciones de memoria de las variables a y b de main() 
a través de los punteros *a y *b.

Es decir, no estamos pasando copias de las variables, sino que estamos pasando la dirección 
donde se encuentran esas variables. */

    printf("Los valores después de la función: \n"
            "\t A: %d\n"
            "\t B: %d\n", a, b);

return 0;
}


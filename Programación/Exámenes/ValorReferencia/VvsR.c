#include <stdio.h>
#include <stdlib.h>
//CUANDO SE LLAMA A UNA FUNCIÓN EN C. SE PUEDE PASAR EL DATO DE DOS FORMAS

/*1.VALOR:
Se envía una copia de la variable a la función.
Cualquier cambio dentro de la función NO afecta a la variable original en main().*/


void sumarUnoV(int numV) {
    numV = numV + 1;
    printf("Dentro de la función: %d\n", numV);
}


/*2.REFERENCIA:
Se envía la dirección de memoria de la variable.
Cualquier cambio en la función afecta la variable original.*/
void sumarUnoR(int *numR) {//Puntero para modificar directamente los datos
    *numR = *numR + 1;
    printf("Dentro de la función: %d\n", *numR);
}

int main() {
    //1.VALOR:
    int x = 5;
    sumarUnoV(x);
    printf("Después de la función: %d\n", x);

    //2.REFERENCIA:
    int y = 5;
    sumarUnoR(&y);
    printf("Después de la función: %d\n", y);
return 0;
}

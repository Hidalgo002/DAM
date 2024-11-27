#include <stdio.h>
int main() {
    //CASO 1:
    const int LIMITE = 100;  // Definir una constante

    printf("El valor de LIMITE es: %d\n", LIMITE);

    // LIMITE = 200;  // Esto daría un error porque LIMITE es constante. Esto valdria 
                     // para modificar un puntero, como cuando hacemos p++


    //CASO 2: //Nos cargamos el CONST con un puntero trampa. En este caso, guardamos el 
            // límite en un puntero trampa y después modificamos el valor del puntero.
            //Evidentemente, genera un warning porque estamos modificando el contenido de
            //un CONST
    int * trampa = &LIMITE;
    *trampa = 200;

    printf("El valor de LIMITE es %d \n", LIMITE);



    return 0;
}
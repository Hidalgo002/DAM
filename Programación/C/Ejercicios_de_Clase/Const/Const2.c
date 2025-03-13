#include <stdio.h>

int main() { 
    int numero = 10;
    const int *ptr = &numero;  // El valor apuntado es constante

    printf("Valor: %d\n", *ptr);

    // *ptr = 20;  // Esto daría un error porque el valor es constante
    numero = 20;   // Cambiar el valor directamente es válido
    printf("Nuevo valor: %d\n", *ptr);

    //Lo que es const es el PUNTERO, por lo que este no puede ser modificado, pero si 
    //Se puede modificar el contenido, este no es contante, solo el puntero, por lo que
    //si ponemos numero = valor_nuevo, si podemos.

    //CASO 2: SEGUNDA FORMA TRAMPA DE MODIFICAR UN CONST
    int trampa = 30;
    ptr = &trampa;
    printf("Nuevo valor trampa: %d \n", *ptr);



    /*RESUMEN: Se puede modificar en una primera estancia el valor número, al que asisgnamos 20
    Pero no se puede cambiar su dirección de memoria, aka, el puntero. 
    En el segundo caso, se hace lo mismo, pero en lugar de modificar el valor de numero,
    modificamos el valor del puntero, que ahora es quivalente a nuestra TRAMPA.*/
    

return 0;
}
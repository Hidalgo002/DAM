#include <stdio.h>

int main() {
//CASO 1:

    int numero = 10;
    int const *ptr = &numero;  // El valor apuntado es constante, *ptr

    printf("Valor: %d\n", *ptr);

    // *ptr = 20;  // Esto daría un error porque el valor es constante
    numero = 20;   // Cambiar el valor directamente es válido
    printf("Nuevo valor: %d\n", *ptr);

    //Trampa, ahora podemos modificar desde el puntero, no como en const2
    *ptr = 30;
    printf("Nuevo valor trampa: %d \n", *ptr);

//CASO 2: NO SE PUEDE MODIFICAR NI LA DIRECCIÓN NI EL VALOR DEL PUNTERO:
    int num = 50;
    const int * const ptr2 = &num;
    printf("Valor: %d\n", *ptr);

    return 0;
}
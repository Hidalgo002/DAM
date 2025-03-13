#include <stdio.h>
#include <stdlib.h>

void metodoCriba(int numero);

int main() {
    int numero;

    printf("Introduce un número m: ");
    scanf("%d", &numero);

    metodoCriba(numero);

    //como todo se hace en el void, no necesitamos meter un free, ya que no es por referencia y no existen los valores en el main

    return 0;
}

void metodoCriba(int numero) {
    int *numeroPrimo = (int *)malloc((numero + 1) * sizeof(int)); //el + 1, se utiliza por que, si introducimos un 26, necesitariamos una rreglo de 26 y sin el +1
                                                         // solo prodria acceder a los 9 primeros
    if (numeroPrimo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    for (int i = 0; i <= numero; i++) { //Bucle que reccorre todos los numeros del array 0-numero
        numeroPrimo[i] = 1; //le asignamos 1, por que segun la criba de eratostenes todos los numeros son primos
    }
    if (0 <= 1) { //como 0 y 1 no son primos, le asignamos 0
        numeroPrimo[0] = 0;
        numeroPrimo[1] = 0;
    }

    for (int i = 2; i * i <= numero; i++) {// empieza desde el 2 pq 0 y 1 no son primos, i * i <= numero raiz cuadrada para controlar hasta que numeros se ejecuta el bucle
        if (numeroPrimo[i] == 1) {//Comprueba que i sea primo
            for (int j = i * i; j <= numero; j += i) { //Recorre y marca todos los multiplos i menores que i*i ya marcados en el if,
                numeroPrimo[j] = 0;//marca un numero como no primo si al menos tien un divisor distinto a 1 y si mismo
            }
        }
    }


    //Memoria para almacenar los numeros primos
    int *almacenarPrimos = (int *)malloc(sizeof(int));  
    if (almacenarPrimos == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    int count = 0;
    for (int i = 2; i <= numero; i++) {
        if (numeroPrimo[i] == 1) {//Comprueba que sea primo
            almacenarPrimos = (int *)realloc(almacenarPrimos, (count + 1) * sizeof(int));//hace un realloc para almacenar 1 numero mas si el if es positivo + 1
            if (almacenarPrimos == NULL) {
                printf("Error al reasignar memoria.\n");
                return;
            }
            almacenarPrimos[count++] = i; //guarda el numero primo 
        }
    }


    //Imprime los primos
    printf("Los números primos hasta %d son:\n", numero);
    for (int i = 0; i < count; i++) {
        printf("%d ", almacenarPrimos[i]);
    }
    printf("\n");

    free(numeroPrimo);
    free(almacenarPrimos);
}


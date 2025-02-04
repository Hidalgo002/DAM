#include <stdio.h>
#include <stdlib.h>

// Función para verificar si un número es primo
int es_primo(int num) {
    if (num <= 1) return 0;  // 1 y números negativos no son primos
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // No es primo si es divisible por otro número
        }
    }
    return 1;  // Es primo
}

// Función para llenar el array con los primeros n números primos
void llenar_primos(int *arr, int n) {
    int num = 2;  // Comenzamos con el primer número primo
    int count = 0;

    while (count < n) {
        if (es_primo(num)) {
            arr[count] = num;
            count++;
        }
        num++;
    }
}

int main() {
    int n;

    // Paso 1: Solicitar el tamaño del array
    printf("Introduce el número de números primos que deseas: ");
    scanf("%d", &n);

    // Verificamos si el número ingresado es positivo
    if (n <= 0) {
        printf("Por favor, ingresa un número entero positivo.\n");
        return 1;
    }

    // Paso 2: Reservar memoria dinámica para el array
    int *array = (int *)malloc(n * sizeof(int));

    if (array == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    // Paso 3: Llenar el array con los primeros n números primos
    llenar_primos(array, n);

    // Paso 4: Imprimir los números primos almacenados en el array
    printf("Los primeros %d números primos son: \n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Paso 5: Liberar la memoria dinámica
    free(array);

    return 0;
}


/*Al liberar la memoria con free(), ¿los datos almacenados en el array desaparecen inmediatamente? ¿Qué ocurre si intentamos acceder a ellos después de liberar la memoria?*/

/*RESPUESTA: No completamente, el free lo que hace es dar permido al sistema para volver a asignar ese sitio como 'libre' es decir, que se puede sobreescrobir. No es seguro acceder de nuevo una vez liberada la memoria porque ya no sabemos si siguen los datos con los que hemos estado trabajando ahí o si ya a sido sobreescrita la memoria. En realidad los datos no desaparecen inmediatamente, pero son subceptibles a ser editados por cualquier otro programa. Si se vuelve a acceder, habrá un comportamiento inesperado.*/
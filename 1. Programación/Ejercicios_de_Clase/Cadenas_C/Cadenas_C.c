#include <stdio.h>
#include <stdlib.h>

int main() {
    char cara[26];
    int numero;
    char letra;

    printf("Introduzca una palabra (máx. 25 caracteres): ");
    scanf("%25s", cara);

    printf("¿Qué posición desea modificar? (0 a 24): ");
    scanf("%d", &numero);

    if (numero < 0 || numero >= 25) {
        printf("La posición tiene que ser entre 0 y 24.\n");
    } else {
        printf("¿Qué carácter desea poner? ");
        scanf(" %c", &letra);
        cara[numero] = letra;
        printf("La nueva palabra es: %s\n", cara);
    }

    return 0;
}

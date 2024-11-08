#include <stdio.h>
#include <stdlib.h>

int main() {
    char palabra[50];
    char nueva[50]; //palabra nueva

    printf("Introduzca una palabra: ");
    scanf(" %s", palabra);

    printf("Introduzca una nueva palabra: ");
    scanf(" %s", nueva);

    printf("La nueva palabra es: %s%s\n", palabra, nueva);

    return 0;
}

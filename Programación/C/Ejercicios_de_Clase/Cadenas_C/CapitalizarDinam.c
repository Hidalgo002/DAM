#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int tamano;
    char *palabra;

    // Pedir al usuario el tamaño de la palabra
    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamano);

    // Reservar dinámicamente espacio para la palabra
    palabra = (char *)malloc((tamano + 1) * sizeof(char)); // +1 para el carácter nulo
    if (palabra == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Leer la palabra desde la entrada estándar
    printf("Introduce una palabra de longitud %d: ", tamano);
    scanf("%s", palabra);

    // Capitalizar cada carácter de la palabra
    for (int i = 0; i < tamano; i++) {
        if (palabra[i] >= 'a' && palabra[i] <= 'z') {
            palabra[i] = palabra[i] - ('a' - 'A'); // Convertir a mayúscula
        }
    }

    // Imprimir la palabra capitalizada
    printf("\nLa palabra capitalizada es: %s\n", palabra);

    // Liberar la memoria reservada
    free(palabra);

    return 0;
}


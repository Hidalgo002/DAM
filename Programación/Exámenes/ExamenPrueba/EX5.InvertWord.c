#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invertir(char *palabra) {
    int len = strlen(palabra);
    char *invertida = (char *)malloc((len + 1) * sizeof(char));
    if (invertida == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        invertida[i] = palabra[len - 1 - i];
    }
    invertida[len] = '\0';
    
    printf("Palabra invertida: %s\n", invertida);
    return invertida;
}

int main() {
    int tamano;
    printf("Ingrese el tamaño de la palabra: ");
    scanf("%d", &tamano);
    getchar();
    
    char *palabra = (char *)malloc((tamano + 1) * sizeof(char));
    if (palabra == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }
    
    printf("Ingrese una palabra: ");
    fgets(palabra, tamano + 1, stdin);
    palabra[strcspn(palabra, "\n")] = 0;
    
    printf("Palabra original: %s\n", palabra);
    
    char *palabra_invertida = invertir(palabra);
    
    free(palabra);
    free(palabra_invertida);
    return 0;
}


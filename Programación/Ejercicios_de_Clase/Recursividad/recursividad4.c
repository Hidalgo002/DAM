#include <stdio.h>
#include <string.h>

// Función recursiva para invertir una cadena in-place

void invertirCadena(char *str, int inicio, int fin) {
    if (inicio >= fin) return; // Caso base: nada que intercambiar
    char trans = str[inicio];
    str[inicio] = str[fin];
    str[fin] = trans;
    invertirCadena(str, inicio+1, fin-1);
}

int main() {
    char cadena[] = "Hola mundo";
    int len = strlen(cadena);

    invertirCadena(cadena, 0, len-1);
    
    printf("Cadena invertida: %s\n", cadena);
    return 0;
}


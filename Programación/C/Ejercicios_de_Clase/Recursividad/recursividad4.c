#include <stdio.h>
#include <string.h>

// Función recursiva para invertir una cadena in-place

void invertirCadena(char *str, int inicio, int fin) {
    if (inicio >= fin) return; // Caso base: nada que intercambiar
    char temp = str[inicio];
    str[inicio] = str[fin];
    str[fin] = temp;
    invertirCadena(str, inicio+1, fin-1);
}

int main() {
    char cadena[] = "Hola mundo";
    int len = strlen(cadena);

    invertirCadena(cadena, 0, len-1);
    
    printf("Cadena invertida: %s\n", cadena);
    return 0;
}

/* unsigned int i = 0, d = (int) strlen(cad)-1;
    int palin=1;
    while ((palin == 1) && (i < ((int)strlen(cad))))
    {
        if (cad[i] != cad[d]) palin=0;
        else
        {
            i++;
            d--;
        }
    }
    return palin;
}*/
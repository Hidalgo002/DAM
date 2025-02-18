#include <stdio.h>
#include <ctype.h>

void verificarSoloNumeros(char str[]) {
    int soloNumeros = 1;    // Variable para verificar si solo hay números

    // Recorremos cada carácter de la cadena
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) { // Si encontramos un carácter que no es un número, marcamos que no es solo números
            soloNumeros = 0;
            break;
        }
    }

    if (soloNumeros) {
        printf("La cadena contiene solo números.\n");
    } else {
        printf("La cadena contiene caracteres no numéricos.\n");
    }
}

int main() {
    char str[] = "123456";  // Ejemplo de cadena que solo tiene números
    verificarSoloNumeros(str);  // Llamamos a la función con la cadena
    return 0;
}

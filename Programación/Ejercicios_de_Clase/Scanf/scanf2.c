#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Función para verificar si la cadena contiene al menos una letra y un número
int EsLetraYNum(char str[]) {
    int tieneLetra = 0;
    int tieneNumero = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { // Verifica si es una letra (A-Z, a-z)
            tieneLetra = 1;
        }
        if (isdigit(str[i])) { // Verifica si es un número (0-9)
            tieneNumero = 1;
        }
    }

    return tieneLetra && tieneNumero; // Solo es válido si tiene ambos
}

int main() {
    char str[50];

    printf("Ingrese un mensaje alfanumérico (debe contener letras y números): ");
    scanf("%49s", str);

    if (EsLetraYNum(str)) {
        printf("Mensaje válido: %s\n", str);
    } else {
        printf("Entrada inválida. Debe contener al menos una letra y un número.\n");
    }

    return 0;
}

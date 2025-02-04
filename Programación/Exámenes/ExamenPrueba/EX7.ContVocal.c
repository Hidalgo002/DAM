#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Función para contar el número de vocales en la palabra
int contar_vocales(char *palabra) {
    int count = 0;
    
    // Recorrer cada carácter de la palabra
    for (int i = 0; palabra[i] != '\0'; i++) {
        char c = tolower(palabra[i]);  // Convertir a minúscula para comparar fácilmente
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;  // Contar vocales
        }
    }
    
    return count;
}

int main() {
    int tamaño;
    
    // Solicitar un número entero positivo que representa el tamaño del array de caracteres
    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);
    
    // Verificar si el tamaño es válido
    if (tamaño <= 0) {
        printf("El tamaño debe ser un número entero positivo.\n");
        return 1;
    }
    
    // Reservar memoria dinámica para la palabra
    char *palabra = (char*)malloc((tamaño + 1) * sizeof(char));  // +1 para el terminador '\0'
    
    // Verificar si la memoria se asignó correctamente
    if (palabra == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }
    
    // Solicitar al usuario que introduzca la palabra
    printf("Introduce la palabra (maximo %d caracteres): ", tamaño);
    scanf("%s", palabra);  // Utilizamos %s para leer una palabra
    
    // Llamar a la función contar_vocales
    int num_vocales = contar_vocales(palabra);
    
    // Mostrar el número de vocales en la palabra
    printf("La palabra tiene %d vocales.\n", num_vocales);
    
    // Liberar la memoria utilizada
    free(palabra);
    
    return 0;
}


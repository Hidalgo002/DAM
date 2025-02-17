#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to extract vowels recursively and store them in a new string
void buscar_vocal(char *palabra, char *resultado) {
    // Base case: end of string
    if (*palabra == '\0') {
        *resultado = '\0';  // End the new string
        return;
    }

    // Check if the current character is a vowel
    char letra = tolower(*palabra);
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        *resultado = *palabra;  // Store the vowel in the result string
        buscar_vocal(palabra + 1, resultado + 1);  // Recursive call for the next character
    } else {
        buscar_vocal(palabra + 1, resultado);  // Skip non-vowel characters
    }
}

int main() {
    char *palabra = (char *)malloc(100 * sizeof(char));  // Memory allocation for the input
    if (palabra == NULL) {
        printf("Error de memoria\n");
        return 1;  // Exit if malloc fails
    }

    printf("Introduzca la palabra: ");
    scanf("%s", palabra);

    // Allocate memory for the result string (it could be the same size as input)
    char *vocales = (char *)malloc(100 * sizeof(char));
    if (vocales == NULL) {
        printf("Error de memoria para la cadena de vocales\n");
        free(palabra);  // Free the previously allocated memory
        return 1;  // Exit if malloc fails
    }

    // Call the function to extract vowels
    buscar_vocal(palabra, vocales);

    // Print the vowels
    printf("Vocales: %s\n", vocales);

    // Free the allocated memory
    free(palabra);
    free(vocales);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Función para capitalizar un carácter minúsculo
char capitalizar(char letra_minuscula) {
    // Convertir de minúscula a mayúscula
    letra_minuscula = letra_minuscula + 'Z' - 'z';
    return letra_minuscula;  // Devolver la letra capitalizada
}

int main(int argc, char **argv) {
    int longitud;
    char *palabra;

    // Paso 1: Pedir el tamaño de la palabra
    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &longitud);

    // Paso 2: Reservar dinámicamente espacio para la palabra
    palabra = (char *)malloc((longitud + 1) * sizeof(char));  // +1 para el carácter '\0'

    if (palabra == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    // Paso 3: Leer la palabra de esa longitud
    printf("Introduce una palabra de longitud %d: ", longitud);
    scanf("%s", palabra);

    // Paso 4: Llamar a la función capitalizar para cada uno de los caracteres
    for (int i = 0; i < longitud; i++) {
        palabra[i] = capitalizar(palabra[i]);  // Capitalizar el carácter
    }

    // Paso 5: Imprimir la palabra
    printf("Palabra capitalizada: %s\n", palabra);

    // Liberar la memoria dinámica
    free(palabra);

    return 0;
}



/*¿Los cambios que realiza la función capitalizar son persistentes al terminar la función? Es decir, ¿la palabra introducida por el usuario ha sido modificada en memoria o no? En caso de responder negativamente, modifica la función para que los cambios que realiza sean persistentes en el main. En caso de responder afirmativamente, realiza un diagrama de memoria en el que expliques cómo ocurre esa modificación.*/

/*RESPUESTA: En mi caso, si son persistentes porque paso el puntero por referencia, por lo que se modifica en contenido de mi 'char palabra'. Si, la palabra ha sido modificada en la función y en la memoria.*/

/* ¿Qué ocurre si se introduce una palabra de más longitud de la reservada? Por ejemplo, qué ocurriría si se reserva memoria para una palabra de longitud 5 y se introduce por pantalla “murciélago”. ¿Podría imprimirse la palabra? ¿Se imprimiría correctamente? ¿Por qué?*/

/*RESPUESTA: solo se modifican el número de carácteres que sea han introducido, la función solo lee hasta n caracteres, después imprimira la palabra con las letras sin cambiar.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // tolower

int comprobar_palindromo(char *arr, int principio, int final) {

    //Caso base

    if (principio >= final) { //si principio es igual o mayor a final significa que ya esta todo comparado y acabamos la funcion
        return 1;
    }
    
    if (tolower(arr[principio]) != tolower(arr[final])) { //tolower lo usamos para pasar todo el string a minisculas y evitar problemas (sugerencia profe)
                                                          //Si los caracteres no coinciden desde el principio hasta el final y viceversa, retorna 0, es decir, no es  palindromo
        return 0; 
    }
    
    return comprobar_palindromo(arr, principio + 1, final - 1);
}

int main() {

    int tamaño;
    printf("Introduce el tamaño de la palabra: ");
    scanf("%d", &tamaño);

        if (tamaño <= 0) {
            printf("El tamaño debe ser mayor o igual que 1.\n");
            return 1;
        }

    char *arr = (char*) malloc((tamaño + 1) * sizeof(char));
        if (arr == NULL) {
            printf("No se ha podido reservar memoria\n");
            return 1; 
        }

    printf("Introduce la palabra: ");
    scanf("%s", arr);

    if (comprobar_palindromo(arr, 0, strlen(arr) - 1)) { //comprobar_palindromo(arr, 0, strlen(arr) - 1) comienza en el 0 del array, y acaba en la longitud del array -1, el -1 es por el \0
        printf("La palabra %s es un palindromo.\n",arr);
    } else {
        printf("La palabra %s no es un palindromo.\n",arr);
    }

    free(arr);

    return 0;
}

/*
EJEMPLO DE COMPARACION
(tolower(arr[principio]) != tolower(arr[final]), si introduces alguna palabra en mayusculas tolower la cambia a minuscula

a  s  d  d  s  a
0  1  2  3  4  5

principio = 0, final = 5
arr[0] = a
arr[5] = a

principio = 1, final = 4
arr[1] = s
arr[4] = s

principio = 2, final = 3
arr[2] = d
arr[3] = d

principio = 3, final = 2
Como ya se han cruzado, significa que ya hemos comprobado todos los caracteres y da un return 1 para indicar que si es palindromo

el if (principio >= final) es el caso base que se encarga de que se pare de comprobar, sin el caso base seria infinito.

*/

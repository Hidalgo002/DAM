#include <stdio.h>

int main() {
    char str[20];
    printf("Introduzca la palabra: ");
    scanf("%[A-Za-z]", str);
    printf("Palabra: %s\n", str);
    

/* 
El parámetro '%[A-Za-z]' solo permite letras y por tanto solo guarda letras.

Ejemplo: hooLlllaaaa55588 --> salida --> hooLlllaaaa
*/
return 0;
}
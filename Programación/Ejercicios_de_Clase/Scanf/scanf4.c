#include <stdio.h>
#include <ctype.h>

int main() {
   char cadena[] = "555";

   int tieneLetra = 0;
   int tieneNumero = 0;

   for(int i = 0; cadena[i]; i++) {
      if (isalpha(cadena[i] )) {tieneLetra = 1;} 
      
      else if (isdigit(cadena[i])) {tieneNumero = 1;}

   }

   if (tieneLetra && tieneNumero) {
      printf("ERROR\n");  // Si hay letras y números
   } else {
      printf("BIEN\n");  // Si solo hay letras o solo números
   }

   return 0;
}




/*
En la cadena hay letras y números, cuando es una letra, Si hay numeros y letras --> MAL
*/
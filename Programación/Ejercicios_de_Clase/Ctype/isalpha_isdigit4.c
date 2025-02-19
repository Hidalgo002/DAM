#include <stdio.h>
#include <ctype.h>

int main() {
   char cadena[] = "ho5la";  // Input string
   int NoNum = 0;

   for (int i = 0; cadena[i]; i++) {
      if (!isdigit(cadena[i])) {  // Check if character is NOT a digit
         NoNum = 1;  // Set the flag if it's not a digit
         break;  // No need to check further, we already found an invalid character
      }
   }

   if (NoNum == 1) {
      printf("ERROR\n");  // If there's any non-digit character
   }

   return 0;
}





/*
En la cadena hay letras y números, cuando es una letra, Si hay numeros y letras --> MAL
*/


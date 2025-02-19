#include <ctype.h>
#include <stdio.h>

int main() {
   char c = '5';

   printf("Enter a character: ");
   c = getchar();

   if (isxdigit(c) != 0) {
      printf("%c is a hexadecimal character.", c);
   } else {
      printf("%c is not a hexadecimal character.", c);
   }

   return 0;
}

#include <ctype.h>
#include <stdio.h>

int main() {
   char c = '5';
   int result;

   // hexadecimal character is passed
   result = isxdigit(c); // result is non-zero
   printf("Result when %c is passed to isxdigit(): %d", c, isxdigit(c));

   c = 'M';

   // non-hexadecimal character is passed
   result = isxdigit(c); // result is 0

   printf("\nResult when %c is passed to isxdigit(): %d", c, isxdigit(c));

   return 0;
}
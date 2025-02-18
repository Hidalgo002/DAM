#include <stdio.h>
#include <ctype.h>
 
int main()
{
  char cadena[200];
printf("Ingrese un numero: ");
scanf("%s", cadena);
int length = strlen(cadena);
int error = 0;
for(int i=0; i<length && !error; i++)
{
    if(!isdigit(cadena[i])){
    {
        error = 1;
     }
}

if (error != 0)
{
    printf("\nIngrese un numero, no un caracter");
}else{
    printf("\nBien hecho");
}
}
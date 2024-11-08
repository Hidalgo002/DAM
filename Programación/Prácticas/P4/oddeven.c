#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int numero;
	printf("Introduzca un número entero: ");
	scanf("%d", &numero);

	if (numero % 2 == 0){
		printf("Es un número par. \n");}
	else {
		printf("Es un número impar. \n");}

return 0;
}

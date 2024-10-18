#include <stdio.h>
#include <stdlib.h>


int main(){
	char cara[25];
	int numero;
	char letra;	

	printf("Introduza una palabra: ");
	scanf("%s", cara);

	printf("¿Qué posición desea modificar? ");
	scanf("%d", &numero);

	printf("¿Qué caracter desea poner? ");
	scanf("%s", &letra);

	cara[numero]= letra;
	printf("La nueva palabra es: %s\n", cara);

return 0;
}

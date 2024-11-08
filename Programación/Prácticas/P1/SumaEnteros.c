#include <stdio.h>
#include <stdlib.h>

int main(){
	int numero1;
	printf("Introduce el primer número: ");
	scanf("%d", &numero1);
	
	int numero2;
	printf("Introduce el segundo número: ");
	scanf("%d", &numero2);

	int suma,resta,multiplicacion,division;
	suma = numero1+numero2;
	resta = numero1-numero2;
	multiplicacion= numero1*numero2;
	division = numero1/numero2;

	printf("Resultado Suma= %d\n",suma);
	printf("Resultado Resta= %d\n",resta);
	printf("Resultado Multiplicacion =%d\n",multiplicacion);
	printf("Resultado Division= %.d\n", division);

	return 0;
}

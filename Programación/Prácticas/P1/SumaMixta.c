#include <stdio.h>
#include <stdlib.h>

int main(){
	int numero1;
	printf("Introduce el primer número: ");
	scanf("%d", &numero1);
	
	int numero2;
	printf("Introduce el segundo número: ");
	scanf("%d", &numero2);

	float suma,resta,multiplicacion,division;
	suma = numero1+numero2;
	resta = numero1-numero2;
	multiplicacion= numero1*numero2;
	division = numero1/numero2;

	printf("Resultado Suma= %f\n",suma);
	printf("Resultado Resta= %f\n",resta);
	printf("Resultado Multiplicacion =%f\n",multiplicacion);
	printf("Resultado Division= %.4f\n", division);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){
	float numero1;
	printf("Introduce el primer número: ");
	scanf("%f", &numero1);
	
	float numero2;
	printf("Introduce el segundo número: ");
	scanf("%f", &numero2);

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

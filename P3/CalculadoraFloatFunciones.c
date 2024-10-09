#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int suma (float a, float b){
	float suma = 0;
	suma = a + b;
	return suma;
}

int resta (float a, float b){
	float resta = 0;
	resta = a - b;
	return resta;
}

int multiplicacion (float a, float b){
	float multiplicacion = 0;
	multiplicacion = a * b;
	return multiplicacion;
}

float division (float a, float b){
	float division = 0;
	division = a / b;
	return division;
}

int main(){
	float numero1;
		printf("Introduce el primer número: ");
		scanf("%f", &numero1);
	float numero2;
		printf("Introduce el segundo número: ");
		scanf("%f", &numero2);

	float suma2 = suma (numero1,numero2);
	float resta2 = resta (numero1,numero2);
	float multiplicacion2 = multiplicacion (numero1,numero2);
	float division2 = division (numero1,numero2);

	printf("Suma: %.2f\n", suma2);
	printf("Resta: %.2f\n", resta2);
	printf("Multiplicacion: %.2f\n", multiplicacion2);
	printf("Division: %.2f\n", division2);
	return 0;
}

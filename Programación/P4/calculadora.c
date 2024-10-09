#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Funciones:
float suma (float a, float b){
	float suma = 0;
        suma = a + b;
        return suma;
}

float resta (float a, float b){
        float resta = 0;
        resta = a - b;
        return resta;
}

float multiplicacion (float a, float b){
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
		printf("Introduzca el primer número: ");
		scanf("%f", &numero1);
	float numero2;
                printf("Introduzca el segundo número: ");
                scanf("%f", &numero2);
	char signo;
                printf("Introduce el operador: '+, -, *, o /': ");
                scanf(" %c", &signo);

//Condicionales:
		
	switch (signo) {
		case '+':
                	float suma2 = suma (numero1,numero2);
                	printf("Resultado: %.2f\n", suma2);
			break;
		case '-':
                	float resta2 = resta (numero1,numero2);
                	printf("Resultado: %.2f\n", resta2);
			break;
		case '*':
                	float multiplicacion2 = multiplicacion (numero1,numero2);
                	printf("Resultado: %.2f\n", multiplicacion2);
			break;
		case '/':
                	float division2 = division (numero1,numero2);
                	printf("Resultado: %.2f\n", division2);
        		break;
		default: 
                	printf("Operador no válido \n");
	}


return 0;
}

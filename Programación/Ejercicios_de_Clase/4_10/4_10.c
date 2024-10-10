#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//UNO. Función de VOCAL:
void es_vocal(char letra){

        if (    letra=='a'||letra=='A'||
                letra=='e'||letra=='E'||
                letra=='i'||letra=='I'||
                letra=='o'||letra=='O'||
                letra=='u'||letra=='U'){
        printf("La letra %c es una vocal. \n", letra);}

        else {printf("La letra %c no es una vocal. \n", letra);}
}
//DOS. Función de FIGURA:
void calcular_area_figura(){
	char figura;
		printf("¿Qué figura deseas calcular (círculo=1, cuadrado=2)?: ");
        	scanf(" %c", &figura); //Se pone un  espacio antes de %c porque si no, no coge el valor de figura.

	if( figura=='1'){ //CÍRCULO RADIO
		int radio;
			printf("Introduce el radio del círculo: ");
			scanf("%d", &radio);
        	float area = 3.1416 * radio * radio;
			printf("El área del círculo con radio %d es %.2f. \n", radio, area);
	}
	else if ( figura =='2'){ //CUADRADO LADO
		int lado;
                	printf("Introduce el lado del cuadrado: ");
                	scanf("%d", &lado);
                float area = lado * lado;
                	printf("El área del cuadrado con lado %d es %.2f. \n", lado, area);
	}
	else if ( figura != '1' || figura != '2'){
                printf("Error en la función calcular_area_figura \n");}
}
//TRES. Función de Promedio:
double calcular_promedio_tres_num(double num1, double num2, double num3){
	return (num1 + num2 + num3)/3;
}

double calcular_promedio_cuatro_num(double num1, double num2, double num3,double num4){
	return (num1 + num2 + num3 + num4)/4;
}
void calcular_promedio(){
	char promedio;                                        
		printf("¿De cuántos números quiere hacer el promedio? (3 o 4) ");
		scanf(" %c", &promedio);

	if ( promedio =='3' ){
	double num1, num2, num3;
		printf("Introduce en número 1: ");
		scanf("%lf", &num1);
		printf("Introduce en número 2: ");
		scanf("%lf", &num2);
		printf("Introduce en número 3: ");
		scanf("%lf", &num3);
	double promedio1 = calcular_promedio_tres_num (num1, num2, num3);
		printf("El promedio de %.2lf, %.2lf, %.2lf es %.2lf. \n", num1, num2, num3, promedio1);	
	}

	else if ( promedio =='4' ){
	double num1, num2, num3, num4;
		printf("Introduce en número 1: ");
        	scanf("%lf", &num1);
        	printf("Introduce en número 2: ");
        	scanf("%lf", &num2);
        	printf("Introduce en número 3: ");
        	scanf("%lf", &num3);
        	printf("Introduce en número 4: ");
        	scanf("%lf", &num4);
	double promedio2 = calcular_promedio_cuatro_num (num1, num2, num3, num4);
        	printf("El promedio lf, %.2lf, %.2lf, %.2lf, %.2lf es %.2lf. \n", num1, num2, num3, num4, promedio2);
	}
}
//CUATRO. Función horas:

void convertir_hora_24_a_12(){
	int hora;
	printf("Introduce la hora en formato 24 horas: ");
	scanf("%d", &hora);

	if (hora > 24 || hora < 0){
		printf("Hora no válida. \n");}
	else if (hora == 0){
		printf("La hora en formato de 12 horas es PM: 12 AM.\n");}
	else if (hora == 12){
		printf("La hora en formato de 12 horas es PM: 12 PM.\n");}
	else if (hora < 12){
		printf("La hora en formato de 12 horas es PM: %d AM.\n", hora);}
	else {
		printf("La hora en formato de 12 horas es PM: %d PM.\n", hora - 12);}
}
//CINCO. Función números primos:

void es_primo(){
	int numero;
	printf("Introduce un número menor de 10: ");
	scanf(" %d", &numero);

	if (numero > 10){
		printf("El número debe ser menor de 10.\n");}
	else if (numero == 2 ||numero == 3 ||numero == 5 ||numero == 7){
		printf("El número %d es primo.\n", numero);}
	else {printf("El número %d no es primo.\n", numero);}
	}

//SEIS. Función de comparar números:

void comparar_3_numeros(){
	float num1, num2, num3;	

        printf("Introduce el número 1: ");
        scanf(" %f", &num1);
	printf("Introduce el número 2: ");
        scanf(" %f", &num2);
	printf("Introduce el número 3: ");
        scanf(" %f", &num3);

	if(num1 == num2 && num2 == num3){
		printf("Los números son iguales.\n");
	}
	else if (num1 > num2 && num1 > num3){
		printf("El número mayor es %.2f\n", num1);
	}
	else if (num2 > num1 && num2 > num3){
                printf("El número mayor es %.2f\n", num2);
        }
	else {printf("El número mayor es %.2f\n", num3);}
	}

int main(){
	printf("1. Verificar si una letra es una vocal. \n");
	printf("2. Calcular el área de una figura (círculo o cuadrado). \n");
	printf("3. Calcular el promedio de 3 o 4 números. \n");
	printf("4. Convertir una hora en formato de 24 horas a 12 horas. \n");
	printf("5. Verificar si un número menor de 10 es primo. \n");
	printf("6. Comparar tres números. \n");
	printf("7. Salir. \n");
	
	int numero;
	printf("Opción: ");
	scanf("%d", &numero);

	switch (numero){
		case 1:
		char letra;
		printf("Introduce una letra: ");
		scanf(" %c", &letra);
		es_vocal(letra);
		break;

		case 2:	
		calcular_area_figura();
                break;

		case 3:
		calcular_promedio();
                break;

		case 4:
		convertir_hora_24_a_12();
                break;

		case 5:
		es_primo();
                break;

		case 6:
		comparar_3_numeros();
                break;

		default:
			printf("Operador no válido. \n");
		}

return EXIT_SUCCESS;
}

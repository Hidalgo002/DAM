#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiplicacion (float a, float b){
	float multiplicacion = 0;
	multiplicacion = a * b;
	return multiplicacion;
}

int main(){
	char rol;
	printf ("Para realizar un descuento en su compra, indique 'E' si es un alumno, 'P' si es un profesor o 'O' si es otro: ");
        scanf("%c", &rol);	
	
	int dinero;
        printf("Indique el monto total de su compra: ");
        scanf("%d", &dinero);

//Condicionales

	if (rol == 'E' || rol == 'e'){ 
		float a = 0.85;
		float multiplicacion2 = multiplicacion (a, dinero);
		printf("Monto total de: %.2f\n", multiplicacion2);}
	else if (rol == 'P' || rol == 'p'){
		float a1 = 0.90;
                float multiplicacion2 = multiplicacion (a1, dinero);
                printf("Monto total de: %.2f\n", multiplicacion2);}
	else if (rol == 'O' || rol == 'o'){
		printf("No hay descuento \n");}


return 0;
}

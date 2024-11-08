#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int num; //Aquí se guarda el número proporcionado por el usuario
	int factorial = 1; //Aquí se guarda el valor del factorial, partimos del 1
	int num2; //Variable adicional para cálculos
	
	//GUARDAMOS EN NUMERO
	printf("Introduce un número: ");
	scanf("%d", &num);
	
	if(num<0){
	printf("Introduce un número positivo.\n");}
	
	else {
	for (num2 = 1; num2 <= num; num2++){ /**Asignamos al num2 el valor de 1 de partida. 
					     Después indicamos que el num2 debe ser menor o igual al 
					     número proporcionado por el usuario. 
					     Finalmente, se guarda todo en num2*/
	factorial = factorial * num2;
	printf("El factorial de %d! es %d\n", num, factorial);}
	}
return 0;
}

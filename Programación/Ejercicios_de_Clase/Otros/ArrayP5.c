#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	char semana[7][10]={"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"}; //Array dedicado a los dias de la semana
	float temp[7]; //Aquí se van almacenando los valores pedidos al usuario
	float recop = 0;

	//PRIMER APARTADO
	for (int i = 0; i<7; i++){
		printf("La temperatura media del %s ha sido: ", semana[i]);
		scanf("%f", &temp[7]);
		
		recop += temp[7];
	}

	//SEGUNDO APARTADO
	float sol = recop / 7.0;
	printf("Temperatura promedio de la semana: %.2f\nºC", sol);	
	
	//TERCER APARTADO

	//1. Leer los valores almacenados en el array temp.
	//2. Comparar uno a uno cual es el mayor. Si a es mayor a b, entonces a. SIGUIENTE
	//3. Se guardan y se compara con la siguiente. Así, 7 veces.
	
	for(int max = 0; temp[0]>max; temp[0+1])
		}
	return 0;
}


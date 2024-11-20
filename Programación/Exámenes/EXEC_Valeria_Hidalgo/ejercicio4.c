#include <stdio.h>
#include <stdlib.h>

//EJERCICIO 4-> FOR.

int main(){
	int num;
	int suma = 0; //Donde se almacena la suma
	int num2 = 1;
	
	scanf("%d", &num);


	for(num2 = 1; num2<=num; num2++){
	suma += num2;
	}
	printf("La suma de los primeros %d números es %d.	
		       	\n", num, suma);



return 0;	
}

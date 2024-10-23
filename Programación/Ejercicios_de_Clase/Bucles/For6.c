#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int num; // Valor dado por el usuario
	printf("Introduce un número: ");
	scanf("%d", &num);
	
	int a = 0; //Donde se almacena la suma
	int b = 1; //Variable de  suma

	for (b=1; b<=num ; b++){
	a += b;
	}
	printf("La suma de los números desde el 1 hasta el %d es %d.\n", num, a);
	/*Llamamos a la variable número y se coloca en el enunciado el número que ha
	dado el usuario. Después, llamamo a la variable a, que es donde se almacena
	la suma*/

return 0;
}


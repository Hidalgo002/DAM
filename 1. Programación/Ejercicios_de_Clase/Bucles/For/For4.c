#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int a = 0; //Donde se almacenan los resultados de las multiplicaciones
	int b = 5; //Valor fijo en 5, porque es la tabla del 5
	int c = 0; //Donde almacenamos los números del 1 al 10

	for(c=0; c<11; c++){
	a = c * b;
	printf("%d x %d = %d\n", c, b, a);}

return 0;
}

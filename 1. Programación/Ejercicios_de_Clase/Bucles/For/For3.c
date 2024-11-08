#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int i = 1;
	int suma = 0;

	for(i=0; i<11;i++){
	
	suma += i; //Aquí se va acumulando la suma
	
	if (i == 0){
	printf("La suma de 0 y %d es %d\n", i, suma);}
	else{
	printf("La suma de %d y %d es %d\n", suma - i, i , suma);} //Llamo a la suma-1, lo que quiere decir que le resta 1 al valor que teniamos en i, 	que es 1, lo hemos declarado en la variable. Luego llamamos a la i, que es 1. Por último llamamos a la variable suma, que va acumulando igual que 1 los valores.
	}
	
return 0;

}

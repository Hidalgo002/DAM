#include <stdio.h>
#include <stdlib.h>


int numPar (int num, int suma){
	if(num == 0){
		return suma;
	}

	int ultimoNum = num % 10;//Almacenamos el último dígito

	if(ultimoNum % 2 == 0){
		suma++;
	}
	return numPar(num/10, suma+1);//En cada llamada, reducimos num en 10.

}

int main(){
	int num;

	printf("Introduzca el número: ");
	scanf("%d", &num);

	int resultado = numPar(num);
	printf("La cantidad de números pares es: %d.\n", resultado);

return 0;
}
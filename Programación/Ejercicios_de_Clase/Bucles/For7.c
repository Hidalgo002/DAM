#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int num; //Pedir por terminal el lado del cuadrado
	printf("Introduce un número para determinar el lado del cuadrado: ");
	scanf("%d", &num);
	
	for (int i = 1; i<=num; i++){//Bucle para meterle asteríscos horizontal
		for (int j = 1; j<=num; j++){
		printf("*");} //Bucle para meterle asteríscos vertical
	
	printf("\n");}

return 0;
}

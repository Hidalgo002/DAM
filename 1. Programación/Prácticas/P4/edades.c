#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int edad;
	printf("Introduzca su edad: ");
	scanf("%d", &edad);

	if (edad < 12){
		printf("Niño. \n");}
	else if (edad >= 12 && edad <= 17){
                printf("Adolescente. \n");}
	else if (edad >= 18 && edad <= 64){
                printf("Adulto. \n");}
	else if (edad >= 65){
                printf("Mayor. \n");}
	

return 0;
}

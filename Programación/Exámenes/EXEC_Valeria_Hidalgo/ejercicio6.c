#include <stdio.h>
#include <stdlib.h>

//EJERCICIO 6-> DO-WHILE.

int main(){
	int num;
	
	do{
	scanf("%d", &num);
	if(num<0 && num>10){printf("Número no válido.\n");} continue;
	}

	while(num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8 && num != 9 && num != 10);
	printf("Has ingresado el número %d \n", num);



return 0;
}

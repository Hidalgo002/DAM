#include <stdio.h>
#include <stdlib.h>

//EJERCICIO 1 -> IF. IF ELSE Y ELSE IF.

int main(){
	int num;
	scanf("%d", &num);

	if(num > 0){printf("El número %d es positivo. \n", num);}
	
	else if (num < 0){printf("El número %d es negativo. \n", num);}

	else{printf("El número ingresado es cero. \n");}

return 0;
}

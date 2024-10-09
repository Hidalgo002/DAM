#include <stdio.h>
#include <stdlib.h>

int main(){
	int numero1 = 7;
	int numero2 = 8;
	int resta,multiplicacion,division;

	resta = numero2-numero1;
	multiplicacion = numero1*numero2;
	division = numero1/numero2;

printf("Resta=%f\n",resta);
printf("Multiplicacion=%f\n",multiplicacion);
printf("Division=%f\n",division);

return EXIT_SUCCESS;
}

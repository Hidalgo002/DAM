#include <stdio.h>

int main(){
	int num1;
	int num2;
	int recopilacion  = 0; 

	printf("Introduce un número: ");
	scanf(" %d", &num1);

	while(num1>0){
	num2 = num1 % 10; //Obtención del último dígito, se guarda en num2 
	recopilacion = recopilacion * 10 + num2; //Recopilacion es 0 al principio, por lo que al multiplicarlo por 10, se queda cero, luego, se suma el num2, que almacena el último valor. luego, recopilación pasará tener el valor, p.ej, 40, y se le suma el num2
	num1 = num1 / 10; //Trabajar con el número limpio
	}

	printf("El número invertido será: %d\n", recopilacion);
return 0;
}

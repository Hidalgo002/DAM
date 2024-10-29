#include <stdio.h>

int main(){
	int num1; //Aquí se guarda el número primero del usuario
	int num2;
	int suma=0;

	printf("Introduce un número: "); //Se pide un número al usuario
	scanf("%d", &num1);
	while(num1>0){//mientrar el numero sea mayor a 0, se dividirá entre 10.
	num2 = num1 % 10; //Obtención del último dígito, será 5 y quedará 12, luego se obtendrá el 2 y quedará 1. Esto se consigue dividiendo p.ej 125 / 10 = 12.5, luego, guardamos el "resto" que no permite que sea entero el número. Luego, 12/10 = 1.2, guardamos el 2. El último será 1/10= 0.1, y se guarda el 1.
	suma = suma + num2; //Sumará los dígitos que se van guardando en num2, el 5+2+1
	num1 = num1 / 10; //Se divide el número de forma ordinaria, al ser un int, no se guardarán los números decimales, por lo que el num1 se asignan solo números enteros, por lo que cuando el bucle llegue a esta parte, ya habrá guardado en num2 los valores que tiene que sumar, en suma los suma y num1 solo proporciona un numero "limpio" con el que trabajar.
	
	//printf("Del número %d hemos obtenido el %d, por lo que se suma en: %d\n", num1, num2, suma);
	}
	
	printf("La suma de los dígitos es %d\n", suma);
return 0;
}

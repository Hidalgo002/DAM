/*
5. Profundidad máxima de paréntesis anidados:

Dada una cadena que contiene paréntesis (por ejemplo, "((()))(())", crea una función recursiva que calcule la profundidad máxima de anidamiento (en el ejemplo la profundidad es 3). [Solo puedes esperar cadenas como ((()))(()) o ((()))(((())))()(()) pero no “((()(()(())))” porque esas son para el siguiente ejercicio]
*/

#include <stdio.h>
#include <stdlib.h>

int profundidad(char * cadena, int balance){

	static int profundidad_MAX = 0;

	if(*cadena == '\0'){
		return profundidad_MAX;
	}

	if(balance > profundidad_MAX){
			profundidad_MAX = balance;
	}

	if(*cadena == '('){
		return profundidad(cadena+1, balance+1);
	}
	else if(*cadena == ')'){
		return profundidad(cadena+1, balance-1);
	}
}


int main(){

	char * cadena1 = "((()))";
	char * cadena2 = "(((())))";

	int balance = 0;

	int resultado = profundidad(cadena1, balance);
	printf("%d  \n", resultado);

	int resultado2 = profundidad(cadena2, balance);
	printf("%d  \n", resultado2);

return 0;
}
/*1. **Números triangulares**

Un número triangular se define como la suma de los primeros n números naturales:

Tn=1+2+3+...+n

Ejemplos:

- T1=1
- T2=1+2 = 3
- T3=1+2+3=6
- T4=1+2+3+4=10

Escribe una función recursiva que, dado un número nnn, retorne el número triangular correspondiente.

*Nota: se llaman triangulares porque con esa cantidad de objetos puedes formar un triángulo de n capas. Por ejemplo, con 10 objetos [T4] se puede hacer un triángulo de 4 niveles de altura*
*/
#include <stdio.h>
#include <stdlib.h>

int triangulo(int n, int suma){
	//CASO BASE
	if(n <= 0){
		return suma;
	}
	//Función. n resta 1 y va almacenando el numero en suma.
	suma += n;
	return triangulo(n-1, suma);
}


int main(){
	int n, suma = 0;
	printf("Introduce el número: ");
	scanf("%d", &n);

	printf("Número triangular: %d \n", triangulo(n, suma));


}
#include <stdio.h>

//SOLUCIONAR FIBONACCI

int fibo(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return fibo(n-1) + fibo(n-2); //Se suma fibo (n-1) que es 
}
/*Si n es mayor que 1, la función se llama a sí misma dos veces:
fibo(n-1): Calcula el término anterior en la serie.
fibo(n-2): Calcula el término dos posiciones antes.
La función sigue llamándose recursivamente hasta que alcanza los casos base 
(fibo(0) y fibo(1)).*/

int main() {

	int n;
	printf("Introduzca un número: ");
	scanf("%d", &n);

	printf("Resultado: %d\n", fibo(n));

return 0;
}
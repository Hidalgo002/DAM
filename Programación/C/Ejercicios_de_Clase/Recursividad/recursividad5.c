#include <stdio.h>


int factorial(int n){
	if (n == 1){
		return 1;
	}
	int ret = n* factorial(n-1);
	return ret;
} 

/* Si n = 1, salimos de la función, siendo este NUESTRO CASO BASE, ya que el factorial de 1 es 1. 
Si no, BAJAMOS a INT RET. En esta función se multiplica n (que es el número que se le pregunta al usuario) por (n - 1). 
Es decir, si el usuario ha puesto n = 4, entonces se comprueba si n es 1 (el caso base) y luego se hace la llamada recursiva. 
En cada llamada, n se va reduciendo, y finalmente cuando n llega a 1, la función retorna 1, y luego las multiplicaciones se van haciendo de vuelta.
Por ejemplo, 4 * (3 * (2 * (1 * 1))) = 24.*/


int main(){

	int n;
    printf("Introduzca un número: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("No se admiten número negativos.\n");
    } else {
        printf("Factorial de %d es %d\n", n, factorial(n));
    }

return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*### **Ejercicio 4:**

- Crea una función que intercambie los valores de dos variables enteras usando punteros. */

void intercambio (int *n, int *m){
	printf("Valor recibido: %d\n" , *n);
	*n = *m;
	printf("Valor intercambiado: %d\n" , *m);
}


int main(){
	int n1 = 10;
	int n2 = 5;

	intercambio(&n1);
	printf("%d", n1);
	printf("%d \n", n2);
	
return 0;
}


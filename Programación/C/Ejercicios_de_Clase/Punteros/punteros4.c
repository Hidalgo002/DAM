#include <stdio.h>
#include <stdlib.h>

/*### **Ejercicio 4:**

- Crea una función que intercambie los valores de dos variables enteras usando punteros. */

void intercambio (int *n1, int *n2){ //Indicamos puntero n1 y puntero n2
	int aux = *n1; //Declaramos 
	*n1 = *n2;
	*n2 = aux;
}


int main(){
	int n1 = 10;
	int n2 = 5;

	printf("Antes:\n");
	printf("%d\n",n1); //5
	printf("%d\n",n2); //10

	intercambio(&n1,&n2); //Llamamos a VOID

	printf("Después:\n");
	printf("%d\n",n1); //5
	printf("%d\n",n2); //10

return 0;
}


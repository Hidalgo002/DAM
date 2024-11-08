#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(){
	double radio,area;
	double resultado_raiz;
	int valor;

	//PARTE DEL CÁLCULO DE UNA RAÍZ CUADRADA
	printf("Introduzca un número para calcular su raíz\n");
	
	scanf("%d",&valor);
	resultado_raiz = sqrt(valor);
	printf("La raíz cuadrada de %d es %lf\n",valor,resultado_raiz);

 	//PARTE DEL CÁLCULO DEL ÁREA DEL CIRCULO
	printf("Introduzca el radio del círculo para calcular su área\n");
	scanf("%lf",&radio);
	area = radio * radio * M_PI; //M_PI está definido en Math.h. Además, para usar esta libreria tenemos que poner -lm cuando ejecutemos el gcc -o.
	printf("El área del círculo es %lf\n",area);

	return 0;

}

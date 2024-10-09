#include <stdio.h>
#include <stdlib.h>
#include<math.h>

///Esto es un comentario
/**
* Este es un código de priebas de programación.
*
* Autora: Valeria Hidalgo
*/



int calcularRaiz(){
	int valor;
	double raiz;

	//PARTE DEL CÁLCULO DE UNA RAÍZ CUADRADA
	printf("Introduzca un número para calcular su raíz\n");
	
	scanf("%d",&valor);
	raiz = sqrt(valor);
	printf("La raíz cuadrada de %d es %lf\n",valor,raiz);
	
	return 0; //Como todo ha ido bien, devuelvo un cero
}

void calcularArea(){
	double radio,area;

 	//PARTE DEL CÁLCULO DEL ÁREA DEL CIRCULO
	printf("Introduzca el radio del círculo para calcular su área\n");
	scanf("%lf",&radio);
	area = radio * radio * M_PI; //M_PI está definido en Math.h. Además, para usar esta libreria tenemos que poner -lm cuando ejecutemos el gcc -o.
	printf("El área del círculo es %lf\n",area);

}	
int main(){
	calcularRaiz();
 	calcularRaiz();
 	calcularRaiz();

	calcularArea();
	calcularArea();
	calcularArea();

	return 0;

}

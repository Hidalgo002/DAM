#include <stdio.h>

void contadorLlamadas(){
	static int contador = 0;
	contador ++;
	printf("Llamada número: %d\n", contador );

	if (contador < 5){
		contadorLlamadas();
	}
}

int main (){

	contadorLlamadas();
	return 0;
}
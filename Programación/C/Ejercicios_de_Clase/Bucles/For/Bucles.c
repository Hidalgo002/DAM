#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i = 0;
	for (/*Valor inicial*/ i = 0;
	     /*Condición*/ i <= 100;
	     /*Código a ejecutar entre vueltas*/ i = i + 2){
	printf("%d," ,i);}

	printf("Terminado\n");
	/**1) Inicializo i=0
	 * 2) Compruebo si i<5. Como se cumple, el bucle se ejecuta
	 * 3) hago un printf
	 * 4) Terminado el interior del bucle, ejecuto el "código entre vueltas": i=i+1
	 * 5) Vuelvo al punto 2. Compurebo si i<5. Se cumple porque i==1. Ejecuto el interior
	 * 6) otro printf
	 * 7) Terminado el interior del bucle, ejeuto i=i+1. Ahora i vale 2
	 * 8) Vuelvo a la condición: ¿i<5? Sí. Interior del bucle
	 * 9) Otro printf
	 * 10) Terminado el interior del bucle, ejecuto i=i+1. Ahora i vale 3
	 * 11) Comprobar la condición. ¿i<5? Sí. Interior del bucle de nuevo
	 * 12) 13) i vale 4 14) Condición.  ¿i<5? Sí. Interior del bucle de nuevo
	 * 15) 16) i vale 5 17) Condición.  ¿i<5? NO. Salimos del bucle */
return 0;
}

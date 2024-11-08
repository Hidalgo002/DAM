#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Cuarto caso con time

int main(){
	/* double r;

	while(1){
	r = rand() % 8; //Divide el número entero entre 8 y se queda con el resto
	printf("%lf\n", r);
	}
	*/

	/* int r;
	for(int i = 0; i<4; i++){
	r = rand() % 8; //hacer módulo 8, da números aleatorios entre 0 y 7
	printf("%d\n", r);}
	*/


	/* int r;
	srand(10); //el 10 es la 'semilla'. Marca donde empiezan a generarse los número aleatorios.
	for (int i = 0; i<4; i++){
		r = rand () % 8;
		printf("%d\n", r);}
	*/

	/* int r;
	srand(time(NULL)); //Cada segundo
	for (int i = 0; i<4; i++){
                r = rand () % 8;
                printf("%d\n", r);}
	*/

	int r;
	srand(time(NULL));
	for (int i = 0; i<4; i++){
                r = (rand () % 5)+1; //rand()5 genera aaleatorio entre 0 y 4 incluidos. Al sumar 1, consigo número aleatorios entre 1 y 5
                printf("%d\n", r);}
		
		
return 0;}

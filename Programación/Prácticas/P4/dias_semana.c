#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	 int dia;
                printf("Introduce un número entre 1 y 7: ");
                scanf("%d", &dia);

//Condicionales:
	switch (dia) {
		case 1:
		printf( "Resultado: Lunes \n");
		break;

		case 2:
                printf( "Resultado: Martes \n");
                break;

		case 3:
                printf( "Resultado: Miércoles \n");
                break;

		case 4:
                printf( "Resultado: Jueves \n");
                break;

		case 5:
                printf( "Resultado: Viernes \n");
                break;

		case 6:
                printf( "Resultado: Sábado \n");
                break;

		case 7:
                printf( "Resultado: Domingo \n");
                break;

	default:
		printf("Número inválido \n");

	}
return 0;
}

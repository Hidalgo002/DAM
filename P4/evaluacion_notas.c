#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float calificación;
	printf("Introduce la calificación: ");
	scanf("%f", &calificación);

	printf("Resultado: %s\n", 
		(calificación < 0 || calificación > 10) 
		? "Calificación no válida"
		: (calificación >= 5 
		? "Aprobado" 
		: "Suspendido"));


return 0;
}

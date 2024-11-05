#include <stdio.h>
#include <stdlib.h>


int main(){
	
#define MÍNIMO 5.0

	double notas[5];
	double suma = 0;
	for (int i = 0; i<5; i++){ //Se va aumentando en 1 y se va moviendo la posición del array, se va guardando en nota[0], luego nota[1]... hasta 4
	printf("Introduce la nota: ");//Pedimos la nota
	scanf("%lf", &notas[i]); //Mandamos las notas introducidas en el teminal al array de notas
	suma+= notas[i]; //Suma de las notas, se almacenan en suma
	}

	//PROMEDIO
	double promedio = suma / 5;
	printf("Promedio de notas: %.2lf\n", promedio);
	
	//NÚMERO DE APROBADOS Y SUSPENSOS
	int aprobado = 0;
	int suspenso = 0;

	for(int i = 0; i<5;i++){
	if(notas[i] >= MÍNIMO){
	aprobado += 1;}
	else{
	suspenso += 1;}
	}
	printf("Número de estudiantes aprobados: %d\n", aprobado);
	printf("Número de estudiantes suspensos: %d\n", suspenso);

	//NOTA MÁXIMA Y MÍNIMA:
	int max = notas[0];
	for(int i=1;i<5;i++){
	if(notas[i] > max){
	max = notas[i];}
	}
	printf("Nota máxima:%d\n", max);	
	

return 0;
}

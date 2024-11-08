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
	double promedio = suma / 5; //Para el promedio, creo una variable que se llama 'promedio' en la que almaceno la suma de todas las notas y las divido entre 5.
	printf("Promedio de notas: %.2lf\n", promedio);
	
	//NÚMERO DE APROBADOS Y SUSPENSOS
	int aprobado = 0;
	int suspenso = 0;

	for(int i = 0; i<5;i++){ //El bucle va cambiando la posición del almacenamiento del array
	if(notas[i] >= MÍNIMO){ //Si la casilla es mayor o igual que el mínimo, entonces, a la varible de aprobado, se le suma 1 para aprobado, si no, se le suma 1 a suspendido
	aprobado += 1;}
	else{
	suspenso += 1;}
	}
	printf("Número de estudiantes aprobados: %d\n", aprobado);
	printf("Número de estudiantes suspensos: %d\n", suspenso);

	//NOTA MÁXIMA Y MÍNIMA:
	float max = notas[0]; 
	int max_posicion = 0; //Igual que antes, para averiguar la posición, se crea una variable independiente para buscar el mayor y almacenarlo en max_posicion
	float min = notas[0];
	int min_posicion = 0;

	for(int i=1;i<5;i++){ //int= 1 porque empezamos a comparar el notas[0] con el notas [1]
		if(notas[i] > max){ //Si el dato del array es mayor al máximo, que inicializa con el valor de la primera casilla, es mayor, etonces, a máximo se le asigna un nuevo valor y se guarda la posicón en max_posicion
		max = notas[i];
		max_posicion = i;}

		else{min = notas[i];
		min_posicion = i;}
	}
	printf("Nota máxima: %.2lf (Estudiante en la posición %d)\n", max, max_posicion + 1);
	printf("Nota mínima: %.2lf (Estudiante en la posición %d)\n", min, min_posicion + 1);


	//NOTAS POR ENCIMA DEL PROMEDIO
	int alto_prom = 0; 
	for(int i=0;i<5;i++){ 
                if(notas[i] > promedio){
		alto_prom = i;	//SI es mayor que el promedio, se guarda el i en alto_prom
		printf("Estudiante en la posición %d: %.2lf\n", alto_prom + 1, notas[i]);
		} 
	}



return 0;
}

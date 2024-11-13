#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	float suma= 0;
	float temperatura [7];
	char dias [7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
	float maxTemp = 0;
	float minTemp = 100;
	float nuevaTemp;
	int maxDia = 0;
	int minDia = 0;

	//se repetira el bucle hasta que i sea mayor a 7. i = 0 -> lunes ... i = 6 -> domingo i = 7 -> Ultimo valor
	//valido. Cada vez que se repite el bucle te pregunta por la temperatura de cada dia, 

	for(int i = 0; i<7; i++){
		printf("%s:", dias[i]);
		scanf("%f", &temperatura[i]);	
	
	//"suma" almacena la suma acumulada de las temperaturas de cada dia es decir el scanf de el lunes+martes...
	//"+=" acualiza el valor es decir suma empieza en 0, 0 + lunes(10) = 10 
	//suma += temperatura[i] seria lo mismo que decir suma = suma + temperatura[i] 
	//suma(0) += temperatura[0](10) Lunes
	//suma(10) += temperatura[1](20) Martes
	//suma(30)... 

		suma += temperatura[i] ;
	
	//"temperatura[i]" indica la temperatura de cada dia, si la temperatura de cada dia es mayor a 0(en este
	//caso) maxTemp ira guardando los valores mas altos es decir, si el lunes la temperatura es de 25 y el
	//martes de 10 solo guardara la de el lunes hasta que haya una superior.
	//"maxDia" representa los dias de la semana es decir la [i] de temperatura
	
	//temperatura(15)[0] > maxTemp(0)
	//maxTemp(15) = temperatura[0] es decir la maxTemp corresponde al lunes (0)
	//maxDia(0) = [0] es decir el dia con la mayor temperatura corresponde al lunes (0)
	
	if(temperatura[i] > maxTemp){
	   maxTemp = temperatura[i];
	   maxDia = i;
	}
	if(temperatura[i] < minTemp){
	   minTemp = temperatura[i];
	   minDia = i;
	}
        }

	//Declaramos "resultado" para realizar el promedio de los 7 dias en este caso, recogemos el valor de todos
	//los dias en "suma" y lo dividimos entre 7 para saber el promedio.

	float resultado = suma / 7;
	printf("La temperatura promedio de la semana es: %.2f°C\n", resultado);

	//dias va con [], porque la "i" de dias toma un nuevo valor guardando el dia maximo o minimo del anterior
	//codigo, en vez de poner "dias[i]", se pone "dias[maxDia]"

	printf("La temperatura maxima de la semana es el %s a: %.2lf°C\n", dias[minDia], maxTemp);
	printf("La temperatura minima de la semana es el %s a: %.2lf°C\n", dias[maxDia], minTemp);

	//Declaramos "mayorMedia" y que empiece desde el 0 

	int mayorMedia = 0;
	
	//Declaramos una variable "int i" dentro de for para que recorra todos los dias de la semana

	for(int i = 0; i < 7; i++){

	//el if ira comparando cada dia de la semana(cada array) con el promedio de todas las semanas
	//y el "mayorMedia" ira sumado un "1" por cada temperatura mayor al resultado
	//es decir, si(temperatura(10)[0] > 6
	//mayorMedia(0) + 1
	//si la temperatura del lunes es mayor a 6, mayorMedia aumenta 1
	
	if(temperatura[i] > resultado){

	//incrementa su valor en 1

	mayorMedia++;

	}
	}
	printf("Número de días con temperaturas superiores al promedio: %d\n", mayorMedia);
	printf("Dias con temperaturas por debajo del promedio:\n");
	for(int i = 0; i<7; i++){
	if(temperatura[i] < resultado){
		printf("%s: %.2lf°C\n", dias[i], temperatura[i]);
	}
	}

	return 0;
}

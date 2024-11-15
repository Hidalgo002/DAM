#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[5] = {1,2,3,4,5};
	

	//Queremos recorrer el array y sumarlo
	//for(int *p = arr; *p <= 5;p++){
	//	printf("%d\n", *p);}
	
	//Corregimos el error de del bucle pues ahora mismo imprime despues del array. Modificamos solo la condición, donde ya no decimos que el *p puntero es menor o igual a 5. Decimos que la variable p, donde se están almacenando las posiciones del punterom tiene que ser menor o igual al valor que hay en el &arr[4], que es 5.
	//Después, con el sizeof hacemos cositas.
	int numElementos = sizeof(arr)/sizeof(int);
	//Guardamos el número cualesquiera del array entre la clase de unidad que esta guardando
	//Luego, el [] de la condición de nuestro array, pasamos a llamarlo x, vamos, que sea lo que sea es un número.
	
	for(int *p = arr; p <= &arr[numElementos - 1];p++){
		printf("%d\n", *p);}

	//Sizeof nos indica los bytes que ocupa cada cosa. Int ocupa 4 y el array al tener 5 elementos ocupa 4*5, es decir, 20
	printf("Size of arr: %ld\n", sizeof(arr));
	printf("Size of int: %ld\n", sizeof(int));

	printf("Elementos del array: %ld\n", sizeof(arr) / sizeof(int));	
	
	//Aprendemos a leer cadenas de caracteres. LO APRENDIDO: ponemos en el bucle quie la condición es que se seguirá ejecutando hasta que lea algo que sea \0, que es con lo que acaban los char
	char palabra[10]= "gratis";
	
	for(char * l = palabra; *l != '\0'; l++){
		printf("%c", *l);}
	printf("\n");



return 0;
}


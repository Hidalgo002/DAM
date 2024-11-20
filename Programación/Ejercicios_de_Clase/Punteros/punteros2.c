#include <stdio.h>
#include <stdlib.h>

int main(){
	/*Ejercicio 1:
	- Declara una variable `float` y un puntero que apunte a ella.
	- Imprime el valor de la variable, su dirección y el valor apuntado por el puntero */

	float x = 8.8;
	float *p; //LA VARIBLE DE LOS PUNTEROS DEBE SER IGUAL. Por ejemplo, mi dato de llama
		  //'int', pues solo encaja con el puntero que se llame 'int'.

	p = &x;

        printf("Valor de x: %.2f\n", x);
        printf("Dirección de x: %p\n", &x); 
        printf("Valor de p: %p\n", p);

	printf("\n\n");
	/*2. PUNTEROS Y ARRAYS. 
	 Objetivo: Relacionar punteros con arrays y entender 
	 	   cómo se accede a elementos mediante punteros.*/
	
	int arr[5] = {10, 20, 30, 40, 50}; //Es lo mismo que decir 'int *arr={...}'
	int *punt = arr;
	
	for (int i = 0; i < 5; i++) { //Mientras i sea < 5, entonces se ejecutará el bucle
		printf("Elemento %d: %d (en la dirección %p)\n", i, *(punt + i),punt+i);}
		// Elemento 'vuelta de i': '* puntero de p, (que es arr)+i' muestra
		// el contenido de p; 'p+i' muestra la dirección de memoria por el %p
	
	//El resultado que se imprime en el terminal, el último digito de la dirección de             //memoria '%p', se irá sumando de 4 en 4.
	
	printf("SOBREESCRITO EL PUNTERO QUEDA: %d\n ", *punt);
	printf("\n\n");

	//¿Qué pasa cuando uso en lugar de un int (que son 4 bytes) un long (que son 8 bytes)?
	
	long long_arr[5] = {10, 20, 30, 40, 50};
	long *long_p = long_arr;
		for (int i = 0; i < 5; i++) {
		printf("Elemento %d: %ld (en la dirección %p)\n", i, *(long_p + i),long_p+i);}
	//El resultado que se imprime en el terminal, el último digito de la dirección de 
	//memoria '%p', se irá sumando de 8 en 8.

	printf("\n\n");

	/*3. Ejercicio 3: Escribe un programa que calcule 
	 la suma de todos los elementos de un array utilizando punteros. */

	int Array_3[5] = {10, 20, 30, 40, 50};
	int *Puntero_3 = Array_3;
	int suma = 0;
		for (int i = 0; i < 5; i++){
		suma += *(Puntero_3+i);} //También se puede poner: 'suma += *(++Puntero_3)'
		printf("La suma del array es: %d\n", suma);
	
	printf("\n\n");

	/*3.2.*/
  	int array_2[5] = {10, 20, 30, 40, 50};
  	int *puntero_2 = array_2+5; //La variable puntero debe apuntar a la última dirección
				     	//de memoria de nuestro array
					//Cuando accedemos al array [5], accedemos a la 6ta 
					//posición. Accediendo a la memoria, y no queremos eso
					//porque puede explotar.
					//En cambio, array + 5, no
	int resta = 0;	
  	for (int i = 5; i >0; i--){
    	printf("Elemento %d: %d\n", i, *(puntero_2 - i));} 	
	
		
	
	
	
	
return 0;
}


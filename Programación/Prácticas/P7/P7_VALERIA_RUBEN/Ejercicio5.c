#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 100

void rellenar_matriz(int *matriz, int filas, int columnas, int multiplo);

void imprimir_matriz(int *matriz, int filas, int columnas);

int Suma_PrimeraRow(int *matriz, int filas, int columnas);

int Suma_UltimaRow(int *matriz, int filas, int columnas, int m);

int Suma_PrimeraCol(int *matriz, int filas, int columnas);

int Suma_UltimaCol(int *matriz, int filas, int columnas);

int main(){

	int n; //FILAS
	int m; //COLUMNAS

	int bandera = 0;

    printf("Introduzca el número de filas: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAXN) {
        printf("El número de filas debe estar comprendido entre 1 y 100.\n");
        bandera	= 1;
        return 1;
    }

   	if(bandera	== 0){
   	printf("Introduzca el número de columnas: ");
    scanf("%d", &m);
    if (m <= 0 || m > MAXM) {
        printf("El número de columnas debe estar comprendido entre 1 y 100.\n");
        return 1;
    }
}
    

    int * matriz = (int*) malloc (n*m*sizeof(int));
    if (matriz==NULL){
    	printf("ERROR CATASTRÓFICO. NO SE PUDO ASIGNAR MEMORIA.\n");
    	return 1;
    }
    
    int multiplo = (n*2*m);

    printf("\nMATRIZ:\n");
    rellenar_matriz(matriz, n, m, multiplo);
    imprimir_matriz(matriz, n, m);

    int suma1 = Suma_PrimeraRow(matriz, n, m);
    printf("La suma de la primera fila es: %d.\n", suma1);

    int suma2 = Suma_UltimaRow(matriz, n, m, 0);
    printf("La suma de la última fila es: %d.\n", suma2);

    int suma3 = Suma_PrimeraCol(matriz, n, m);
    printf("La suma de la primera columna es: %d.\n", suma3);

    int suma4 = Suma_UltimaCol(matriz, n, m);
    printf("La suma de la última columna es: %d.\n", suma4);

    int sumaC = suma1 + suma2 + suma3 + suma4;
	printf("La suma del contorno es: %d.\n", sumaC);    

free(matriz);
return 0;
}


//FUNCIONES:
//1. RELLENAR MATRIZ.
	void rellenar_matriz(int *matriz, int filas, int columnas, int multiplo) {
	    for (int i = 0; i < filas; i++) {
	    	 for (int j = 0; j < columnas; j++){
	        	matriz[i * columnas + j] = (i * columnas + j + 1)* multiplo;
	        }
	    }
	}

/*
- El bucle exterior (for i) recorre las filas, una por una.
- El bucle interior (for j) recorre todas las columnas de la fila i antes de pasar a la siguiente fila.

matriz[i * columnas + j]

	- [i * columnas -> mueve la posición al inicio de la fila i.
	- + j] avanza hasta la columna j dentro de esa fila.
	Por lo que vamos rellenando todas las columnas de una fila antes de pasar a la siguiente fila.

*/

//2. IMPRIMIR MATRIZ.
	void imprimir_matriz(int *matriz, int filas, int columnas) {//*matriz almacena los datos de la matriz
	    for (int i = 0; i < filas; i++) {
	        for (int j = 0; j < columnas; j++) {
	            printf("%d\t", matriz[i * columnas + j]); //El índice va imprimiendo casilla por casilla
	        }
	        printf("\n");
	    }
	}

//3. SUMA DE LA PRIMERA FILA.
	int Suma_PrimeraRow(int *matriz, int filas, int columnas){
		int suma1 = 0; //Variable acumulativa
		for (int j = 0 ; j < columnas; j++) {//Recorre las columnas de la primera fila
		        suma1 += matriz[j]; //Suma los elementos de la primera fila
		    } // 
		return suma1;//Devuelve la suma
	}

//4. SUMA DE LA ÚLTIMA FILA.
	int Suma_UltimaRow(int *matriz, int filas, int columnas, int m){
		int suma2 = 0;
		int inicio = (filas - 1) * columnas; //Índice que empieza en la última fila
		for (int j = m ; j < columnas; j++) { //Recorre desde la col m hasta la última
		        suma2 += matriz[inicio + j];
		    }
		return suma2;
	}

//5. SUMA DE LA PRIMERA COLUMNA
	int Suma_PrimeraCol(int *matriz, int filas, int columnas){
		int suma3 = 0;
		for (int i = 0; i < filas; i++) {//Recorre todas las filas
		    suma3 += matriz[i* columnas]; //Suma el elemnto de la primera fila. [i*col] calcula el índice del primer elemento de cada fila
		    }
		return suma3;
	}

//6. SUMA DE LA ÚLTIMA COLUMNA.
	int Suma_UltimaCol(int *matriz, int filas, int columnas){
		int suma4 = 0;
		for (int i = 0; i < filas; i++) {
		        suma4 += matriz[i* columnas + (columnas - 1)]; // Suma el último elemento de cada fila (índice + último elementos de la fila)
		        /*En este caso, no hay "j" porque tenemos que irnos a la última columas e ir sumando las últimas casillas de todas las filas
		    }
		return suma4;
	}

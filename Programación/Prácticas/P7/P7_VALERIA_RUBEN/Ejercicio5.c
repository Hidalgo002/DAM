#include <stdio.h>
#include <stdlib.h>

void rellenar_matriz(int *matriz, int filas, int columnas, int multiplo);

void imprimir_matriz(int *matriz, int filas, int columnas);

int Suma_PrimeraRow(int *matriz, int filas, int columnas);

int Suma_UltimaRow(int *matriz, int filas, int columnas, int m);

int Suma_PrimeraCol(int *matriz, int filas, int columnas);

int Suma_UltimaCol(int *matriz, int filas, int columnas);

int main(){

	int n; //FILAS
	int m; //COLUMNAS

    printf("Introduzca el número de filas: ");
    scanf("%d", &n);

    printf("Introduzca el número de columnas: ");
    scanf("%d", &m);

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
	void rellenar_matriz(int *arr, int filas, int columnas, int multiplo) {
	    for (int i = 0; i < filas; i++) {
	    	 for (int j = 0; j < columnas; j++){
	        	arr[i * columnas + j] = (i * columnas + j + 1)* multiplo;
	        }
	    }
	}

//2. IMPRIMIR MATRIZ.
	void imprimir_matriz(int *arr, int filas, int columnas) {
	    for (int i = 0; i < filas; i++) {
	        for (int j = 0; j < columnas; j++) {
	            printf("%d\t", arr[i * columnas + j]);
	        }
	        printf("\n");
	    }
	}

//3. SUMA DE LA PRIMERA FILA.
	int Suma_PrimeraRow(int *matriz, int filas, int columnas){
		int suma1 = 0;
		for (int j = 0 ; j < columnas; j++) {
		        suma1 += matriz[j];
		    } // 
		return suma1;
	}

//4. SUMA DE LA ÚLTIMA FILA.
	int Suma_UltimaRow(int *matriz, int filas, int columnas, int m){
		int suma2 = 0;
		int inicio = (filas - 1) * columnas; 
		for (int j = m ; j < columnas; j++) {
		        suma2 += matriz[inicio + j];
		    }
		return suma2;
	}

//5. SUMA DE LA PRIMERA COLUMNA
	int Suma_PrimeraCol(int *matriz, int filas, int columnas){
		int suma3 = 0;
		for (int i = 0; i < filas; i++) {
		    suma3 += matriz[i* columnas];
		    }
		return suma3;
	}

//6. SUMA DE LA ÚLTIMA COLUMNA.
	int Suma_UltimaCol(int *matriz, int filas, int columnas){
		int suma4 = 0;
		for (int i = 0; i < filas; i++) {
		        suma4 += matriz[i* columnas + (columnas - 1)];
		    }
		return suma4;
	}

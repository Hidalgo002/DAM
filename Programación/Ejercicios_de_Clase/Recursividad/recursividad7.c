#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int * array, int a_buscar, int start, int end){
	start = 0;
	end = 9;
	int mitad = (start + end)/2;
	if(a_buscar == array[mitad]){
		return 1;}
	
	if(a_buscar < array[mitad]){
		ret = busqueda_binaria(array, a_buscar, int mitad);
		return ret;
	}
	if(a_buscar > array[mitad]){
		ret = busqueda_binaria(array, a_buscar, int mitad);
		return ret;
	}
}


int main(){
	int array[10] = {-5, 1, 9, 10, 11, 12, 17, 120, 150, 1500};
	int a_buscar = 120;
	int encontrado = busqueda_binaria (array, 120, 0,9);

	printf("Número que coincide con %d: %d", a_buscar, encontrado);
return 0;
}
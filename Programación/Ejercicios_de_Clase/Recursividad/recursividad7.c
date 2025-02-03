#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int * array, int a_buscar, int start, int end){

	int mitad = (start + end)/2;

	if(a_buscar == array[mitad]){
		return 1;}

	if(a_buscar < array[mitad]){
		int ret = busqueda_binaria(array, a_buscar,start, mitad-1);
		return ret;
	}
		int ret = busqueda_binaria(array, a_buscar, mitad+1, end);
		return ret;
	
}


int main(){
	int array[10] = {-5, 1, 9, 10, 11, 12, 17, 120, 150, 1500};
	int a_buscar = 120;
	int encontrado = busqueda_binaria (array, a_buscar, 0,9);
	
	if (encontrado = 1){printf("Número encontrado\n");}
	else(printf("Número no encontrado\n"));

return 0;
}
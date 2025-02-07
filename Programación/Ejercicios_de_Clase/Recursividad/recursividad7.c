#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int * array, int a_buscar, int start, int end){

	int mitad = (start + end)/2;

	if (start == end){
		return	0;
	}

	if(a_buscar == array[mitad]){
		return 1;}

	if(a_buscar < array[mitad]){
		int ret = busqueda_binaria(array, a_buscar, start, mitad-1);
		return ret;}
		
	else if (a_buscar > array[mitad]){
		int ret = busqueda_binaria(array, a_buscar, end, mitad+1); 
		return ret;}

		/*Si el número que estamos buscando es menor a la mitad del array, llamamos a busqueda_binaria, teniendo en cuenta que mitad-start es mitad - 1 y seguidamente, vamos al mitad-end. 
		
		Para asignar la mitad-end, se suma 1, mitad + 1 a la mitad.
		
		Una vez estan asignados el principio y el final, se comprueban recursivamente toda la función. Es decir, mirará si star  == end, a_buscar = array[mitad] y volvera a calcular la mitad
		*/
			

}


int main(){
	int array[10] = {-5, 1, 9, 10, 11, 12, 17, 120, 150, 1500};
	int a_buscar = 120;
	int encontrado = busqueda_binaria (array, a_buscar, 0,9);
	
	if (encontrado == 1){printf("Número encontrado\n");}
	else(printf("Número no encontrado\n"));

return 0;
}
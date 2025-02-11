#include <stdio.h>
#include <stdlib.h>

char capitalizar(char letra_minuscula){
	letra_minuscula = letra_minuscula + 'Z'-'z';
	printf("%c", letra_minuscula);
	return letra_minuscula;
}

int main(){
	int tamano;
	printf("Introduce la palabra: ");
	scanf(" %d", &tamano);

	char * palabra = (char*) malloc((tamano+1) *sizeof(char));
	if(palabra == NULL){
		printf("Error.");
		return 1;
	}

	printf("Introduzca una palabra de %d letras.", tamano);
	scanf("%s", palabra);

	for(int i = 0; i<n; i++){
		palabra[i] =capitalizar(letra_minuscula);
		printf("La palabra: %s", palabra);
	}

free(palabra);
return 0;
}
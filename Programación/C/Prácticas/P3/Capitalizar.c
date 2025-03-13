#include <stdio.h>

char capitalizar(char letra_minuscula){
	char mayuscula = letra_minuscula - 32;
	return mayuscula;
}

int main(){
	char letra;
	printf("Introduce una letra: ");
	scanf("%c", &letra);

	char mayuscula2 = capitalizar (letra);
	printf("%c\n", mayuscula2);
	return 0;
}

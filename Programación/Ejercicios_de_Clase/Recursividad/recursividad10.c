/*1.  **Extraer sólo las vocales de una cadena:**

Dada una cadena, crea una función recursiva que imprima una cadena que contenga únicamente las vocales de la original, en el mismo orden. (Puedes imprimir caracter a caracter)

Versión difícil: crea una cadena nueva en la que almacenar las vocales*/

/*1. **Contar consonantes en una cadena:**

Implementa una función recursiva que cuente cuántas consonantes tiene una cadena (por ejemplo, “Hola” tiene 2 consonantes: ‘H’ y ‘l’).*/

#include <stdio.h>
#include <stdlib.h>

int buscar_cons(char * palabra, int consonante, int tamano, int contador, char * vocales){
	if(palabra[contador] == '\0'){
		return consonante;
	}
	if(contador	== tamano){
		return	consonante;
	}
	if (    palabra[contador] =='a'|| palabra[contador] =='A'||
            palabra[contador] =='e'|| palabra[contador] =='E'||
            palabra[contador] =='i'|| palabra[contador] =='I'||
            palabra[contador] =='o'|| palabra[contador] =='O'||
            palabra[contador] =='u'|| palabra[contador] =='U'){
    
    consonante++;}
	else{return	consonante;}

return buscar_cons(palabra, consonante, tamano, contador+1, vocales);
}


int main(){
	int contador = 0;
	int consonante = 0;

	int tamano;
	printf("Introduzca el tamaño: ");
	scanf(" %d", &tamano);

	char * palabra=(char*) malloc ((tamano+1)*sizeof(char));

	printf	("Introduzca la palabra: ");
	scanf(" %s", palabra);

	char * vocales = (char*) malloc ((contador+1)*sizeof(char));

	int encontrado = buscar_cons (palabra, consonante, tamano, contador, vocales);
	printf("Vocales: %c\n", encontrado);


free(palabra);
return 0;
}
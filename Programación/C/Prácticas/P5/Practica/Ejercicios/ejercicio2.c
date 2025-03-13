#include <stdio.h>
#include <stdlib.h>

int main (){

	//Declaro una lista de palabras con char, teniendo [6] palabras, con un limite de [100] caracteres, la lista
	//es modificable, puedes poner las palabras que quieras y los caracteres que quieras, siempre y cuando
	//no te pases del 6 y si te pasas solo aumenta el numero
	//
	//Declaro la variable "tieneA" que sera la que compruebe si en cada palabra hay o no hay una 'a'

	char palabras[6][100] = {"Desarrollo", "Matematicas", "Oro", "Coche", "Juegos", "DAM"};
	int tieneA;
	
	//Bucle para recorrer las 6 palabras de mi lista, "char palabras"

	for(int i = 0; i < 6; i++){
	
	// "tieneA = 0" Dentro del bucle tieneA estara inicializado en 0 para que en cada bucle siempre empiece en 0,
	// cuando una palabra no contenga la letra 'a' se quedara en 0, en cambio si la palabra contiene la letra 'a'
	// se cambiara a 1, indicando que la palabra tiene una 'a'.

		tieneA = 0;

	// "int comprobar" es el [100] en el char es decir, puede acceder a cada letra de las palabras
	// se inicializa comprobar en '0' para que empiece por la primera letra, por ejemplo en la palabra  "DAM" el
	// '0' seria la 'D'
	// El bucle se seguira ejecutandose, como comprobar esta inicializado en 0 podra ir en todos los bucles
	// revisando letra por letra
	// El bucle se detiene cuando "i > 7", es decir cuando haya llegado ejecutado "DAM"
	
		for (int comprobar = 0; palabras[i][comprobar]; comprobar++){
			if(palabras[i][comprobar] == 'a' || palabras[i][comprobar] == 'A'){
				tieneA = 1;
			}
		}

	//Si la variable tieneA = 1, quiere decir que la palabra contiene una a, y por lo tanto no queremos imprimirla,
	//por lo que ejecutamos un continue, en cambio si tieneA = 1 el continue no se ejecuta, por lo que el programa
	//sigue ejecutando el printf

		if(tieneA){
			continue;
		}

		printf("%s\n", palabras[i]);

	}

	return 0;
}

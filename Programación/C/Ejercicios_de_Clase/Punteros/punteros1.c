#include <stdio.h>
#include <stdlib.h>

int main(){
	
	// DIREFERENCIA ENTRE * Y &
	
	int x =10;
	int *p; //Esta variables es tipo 'int *', es decir, puntero a entero.
		//Esto quiere decir que va a almacenar la dirección de memoria
		//de una variable tipo entero.

	p = &x; //En p guardamos el valor de x
	printf("Valor de x: %d\n", x); //Aquí se imprime el valor de X
	printf("Dirección de x: %p\n", &x); //Aquí se imprime la dirección del puntero
	printf("Valor de p: %p\n", p); //Aquí se imprime la dirección del puntero

	//¿Cómo accedo al contenido de una dirección de memoria?
	
	printf("Contenido de p: %d\n", *p); //El asterisco accede al CONTENIDO de
					    //una dirección de momoria, el & 
					    //accede a la DIRECCIÓN de momoria
	printd("Dirección de memoria de la varibale p: %p\n", &p) //Aceddemos a la dirección
								  //de memoria con el &

		//RESUMEN: & PARA LA DIRECCIÓN DE MEMORIA + %p
			 //* PARA EL CONTENIDO DEL PUNTERO + %d

	//2. GUARDAR LO QUE PEDIMOS
	int b;
	scanf("%d", &b);














	
	
	
	
	return 0;
}


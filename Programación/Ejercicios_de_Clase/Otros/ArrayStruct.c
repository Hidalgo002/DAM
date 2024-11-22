#include <stdio.h>
#include <stdlib.h>

/* CÓMO FUNCIONAN LOS STRUCT */

/* Es imporante definir las constantes en #define*/
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20

typedef struct{
	char nombre[MAX_NOMBRE];
	int edad;
	float nota;
}Estudiante; 

/*Estudiante inicializar(char * nombre, int edad, float nota){
	Estudiante estudiante_nuevo;
	return estudiante_nuevo;
}*/
//ESTA SOLUCIÓN NO SIRVE PORQUE LAS VARIABLES INICIALIZADAS EN FUERA DEL MAIN NO SON VISIBLES DENTRO DE ESTE.
    //El problema es que este objeto local se destruye cuando la función termina, lo que lleva a un comportamiento indeterminado si se trata de usar el objeto fuera de la función. La solución correcta es usar un puntero, RESERVANDO MEMORIA QUE ES DINÁMICA PORQUE NOS METEMOS EN RESERVAS DE MÚLTIPLES MEMORIAS.

void inicializar (Estudiante * estudiante_a_rellenar, char * nombre, int edad, float nota){
	estudiante_a_rellenar -> edad = edad;
	estudiante_a_rellenar -> nota = nota; /*El operador flecha sirve para sustituir '(*estudiante_a_rellenar).nota
						Para poder acceder al campo edad dentro de Estudiante*/
	strcpy(estudiante_a_rellenar.nombre, nombre);/*Estudiante_a_rellenar.nombre = nombre no funciona
						       porque se igualan las direcciones de memoria, no 
						       el contenido. Para pasar el valor, hacemon un strcpy.*/
}

int main(){
	int edad;
	float nota;
	char nombre[MAX_NOMBRE];
	int num_estudiantes;

	Estudiante listado[MAX_ESTUDIANTES]; //La variable listado ES UN PUNTERO
					     //Aquí se reserva la memoria. Tenemos 560 bytes disponibles	
	printf("%p \n", listado);
	printf("Sizeof listado: %lu \n", sizeof(listado)); /*Cada estudiante ocupa 28 bytes. 
							   Por lo que por 20 estuduabtes MAX, obtenemos 
							   560 cuando preguntamos el sizeof.*/

	printf("Sizeof Estudiante: %lu \n", sizeof(Estudiante));

	
	
	printf("¿Cuántos estudiantes deseas inicializar? ");
	scanf("%d", &num_estudiantes);

	for(int i = 0; i<num_estudiantes; i++){
		printf("Introduce la edad: ");
		scanf("%d", &edad);

		printf("Introduce la nota: ");
		scanf("%f", &nota);
		
		printf("Introduce el nombre: ");
		scanf("%s", nombre);
	
	

		inicializar(listado, nombre, edad, nota);} /*A inicializar tenemos que pasarle una
						   	dirección de memoria de un solo 
						   	estudiante. Listado se puede 
						   	sustituir por &listado[0], que apunta
						   	al primero. Listado vale tambien, es
						   	un puntero que referencia a Estudiante*/
	


return 0;
}

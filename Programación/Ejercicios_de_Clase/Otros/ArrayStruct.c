#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* CÓMO FUNCIONAN LOS STRUCT */

/* Es imporante definir las constantes en #define*/
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20
#define MAX_BUFFER 200

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
	strcpy(estudiante_a_rellenar -> nombre, nombre);/*Estudiante_a_rellenar.nombre = nombre no funciona
						       porque se igualan las direcciones de memoria, no 
						       el contenido. Para pasar el valor, hacemon un strcpy.*/
}
//FUNCIÓN CUMPLEANIOS.

//No necesito que esta variable devuleva nada asi que o. 
void cumpleanios(Estudiante * cumpleanero){//Tiene que recibir un puntero a estudiante porque 
				      //va a modifiar a variable que resiba como argumento. 
				      //Mi función entra al la variable edad y la aumenta
	cumpleanero->edad++;
}

//FUNCIÓN PARA IMPRIMIR UN ESTUDIANTE DE DOS FORMAS:
//Esta función recibe un estudiante y muestra por pantalla todos sus datos
void imprimirEstudiante(const Estudiante* estudiante_a_imprimir){ //Esto bloquea la modificación de Estudiante
	printf("Nombre: %s\n", estudiante_a_imprimir->nombre);
	printf("\tEdad: %d\n", estudiante_a_imprimir->edad);
	printf("\tNota: %f\n", estudiante_a_imprimir->nota);
}

//FUNCIÓN DE IMPRIMIR SIN LOS PRINTFS-> FUNCIÓN QUE RECIBE UN ESTUDIANTE Y GENERA UNA CADENA DE TEXTO.
//CONVERTIR ESTUDIANTE A STRING

/* char * estudianteToString (const Estudiante * datos){//Con el * lo pasamos por referencia
	char retval [MAX_BUFFER];
	
	//snprintf (dónde, cuándo y el qué)
	snprintf (retval, MAX_BUFFER, "El estudiante- %s de %d años ha sacado un %f", datos->nombre, datos-> edad, datos-> nota);

// return retval; //retval = valor de retorno -> RETURN RETVAL no funciona porque la variable retval desaparece cuando acaba la función
}	*/

// SOLUCIÓN:
void estudianteToString (const Estudiante * datos, char * retval){
	snprintf (retval, MAX_BUFFER*sizeof(char), "El estudiante- %s de %d años ha sacado un %f", datos->nombre, datos-> edad, datos-> nota); 
	//MAX_BUFFER*sizeof(char)-> Porque max buffer son 200 bytes, pero yo necesito 200 caracteres, así que se MULTIPLICA maxbuffer * lo que ocupa un char, que son 4
}	

// FUNCIÓN CAMBIAR NOMBRE:
void modificarNombreEstudiante(Estudiante * estudiante_a_modificar, char * nuevo_nombre){
	strcpy(estudiante_a_modificar->nombre, nuevo_nombre);
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
	

	//FUNCION DE EDAD. VOID CUMPLEANIOS.
		
	printf("Edad antigua de %s: %d\n", listado[0].nombre, listado[0].edad);
	cumpleanios(&listado[0]); //DIRECCIÓN DE MEMORIA 
	printf("Edad nueva: %d\n", listado[0].edad);


	//FUNCIÓN IMPRIMIR ESTUDIANTES
	imprimirEstudiante(&listado[0]);

	//RELACIONAMOS VARIBLES DEL MAIN QUE ES UTILIZAN Y RELLENAN FUERA DEL MAIN. LA PASAMOS COMO ARGUMENTO A ARRIBA.
 	char StringARellenar [MAX_BUFFER];
 	estudianteToString(&listado[0], StringARellenar);
 	printf("%s\n", StringARellenar);


 	//FUNCIÓN PARA CAMBIAR EL NOMBRE DE LOS ESTUDIANTES:
 	char nuevo_nombre[MAX_NOMBRE];
 	printf("Introduce el nuevo nombre: ");
	scanf("%s", nuevo_nombre);
 	modificarNombreEstudiante(&listado[0], nuevo_nombre);
 	imprimirEstudiante(&listado[0]); 




return 0;
}

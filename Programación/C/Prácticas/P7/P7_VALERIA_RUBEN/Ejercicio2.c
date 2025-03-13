#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 20
#define MAX_APELLIDO 30
#define MAX_ESTUDIANTES 20

typedef struct{
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int nota;
}Estudiante;

void pedirEstudiantes(Estudiante ** LISTA_E, int num_estudiantes){

    *LISTA_E = (Estudiante*) malloc(num_estudiantes * sizeof(Estudiante));
        if (*LISTA_E == NULL){
            printf("ERROR CATASTRÓFICO. NO SE PUDO ASIGNAR MEMORIA.\n");
            return;
        }

    for (int i = 0; i < num_estudiantes; i++){
        printf("Introduzca los datos del estudiante %d de %d: \n"
               "\t NOMBRE:", i+1, num_estudiantes);
        scanf(" %[^\n]", (*LISTA_E)[i].nombre);

        printf("\t APELLIDO:");
        scanf(" %[^\n]", (*LISTA_E)[i].apellido);

        printf("\t NOTA:");
        scanf("%d", &(*LISTA_E)[i].nota);
    }

    printf("\n\033[34mLISTA DE ALUMNOS:\033[0m\n");
        for (int i = 0; i < num_estudiantes; i++) {
            printf("\033[35mEstudiante %d:\33[0m\n", i + 1);
                printf("\tNombre: %s.\n", (*LISTA_E)[i].nombre);
                printf("\tApellido: %s.\n", (*LISTA_E)[i].apellido);
                printf("\tNota: %d.\n", (*LISTA_E)[i].nota);
        }

}

int compareNota(const void* a, const void* b){
        const Estudiante* da = (const Estudiante*)a;
        const Estudiante* db = (const Estudiante*)b;
        return db->nota - da->nota;
}
/*SINTAXIS->
    Qsort: la funcióp qsort es genérica y no sabe que elementos está ordenando, por lo que cuando creamos nuestra función, pondremos de argumento dos punteros void cualesquiera. Se ponen dos porque solo compara dos elementos a la vez. Qsort funciona así en este caso porque queremos ordenar de mayor a menor las notas:
        - si b>a, entonces b debe ir antes de a
        - si a>b, entontes a debe ir antes de b
        - si a=b, entonces son equivalentes en término de orden

    Si quiseramos que se ordenaran de menor a mayor, entonces deberiamos poner da->nota - db->nota.

    En el medio, simplemente hacemos un cast y ponemos a los punteros a trabajar en 'Estudiante', y les asignamos el nombre de da y db, que ahora poseen los datos de los estudiantes, en la anterior practica se llamaba catalogo o bibioteca.

    ENTONCES: la estructura de un qsort seria:
        función (dos punteros void genéricos)
            castig de ambos punteros para que trabajen en nuestro tipo de dato
        return comparación entre ambos puntero void (El guión no es una resta, es un símbolo de comparación)

    Lo realmente importante de esta función es lo que hace en el main: 
    qsort(LISTA_E, num_estudiantes, sizeof(Estudiante), compareNota);
    qsort(array_de_datos, tamaño_array, tamaño_un_solo_elemento, función)
*/

int compareApellido(const void* a, const void* b){
        const Estudiante* da = (const Estudiante*)a;
        const Estudiante* db = (const Estudiante*)b;
        return strcmp(da->apellido, db->apellido);
        //NOTA: cuando se quierem comparar cadenas, hay que poner strcmp también
}

//Actualmente está todo almacenado en LISTA_E. Primero tenemos que acceder a LISTA_E->notas y organizar las notas. Luego vamos a LISTA_E->Apellido y lo organizamos alfabeticamente.

int main(){

    Estudiante * LISTA_E = 0;

    int num_estudiantes;
    printf("Introduzca eL número de estudiantes: ");
    scanf("%d", &num_estudiantes);

//UNO --> Función de pedir y mostrar estudiantes.
    pedirEstudiantes(&LISTA_E, num_estudiantes);

//DOS --> Función ordenar por nota
    qsort(LISTA_E, num_estudiantes, sizeof(Estudiante), compareNota);

    printf("\033[36mLISTA DE NOTAS ORDENADAS DE MAYOR A MENOR:\033[0m\n");
    for (int i = 0; i < num_estudiantes; ++i) {
        printf("\t Alumno %d: %s %s. \n"
               "\t Nota: %d.\n\n"
               ,i+1,LISTA_E[i].nombre, LISTA_E[i].apellido, LISTA_E[i].nota);}

//TRES -->  Función ordenar por apellido (alfabético)
    qsort(LISTA_E, num_estudiantes, sizeof(Estudiante), compareApellido);

    printf("\033[33mLISTA DE ALUMNOS ORDENADOS POR APELLIDO:\033[0m\n");
    for (int i = 0; i < num_estudiantes; ++i) {
        printf("\t Alumno %d: %s %s. \n"
               "\t Nota: %d.\n\n"
               ,i+1,LISTA_E[i].nombre, LISTA_E[i].apellido, LISTA_E[i].nota);}

free(LISTA_E);
return 0;   
}
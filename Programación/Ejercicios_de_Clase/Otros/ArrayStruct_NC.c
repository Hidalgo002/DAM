//ARRAYSTRUCT.C SIN COMENTARIOS, SOLO CÓDIGO

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20
#define MAX_BUFFER 200

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    float nota;
} Estudiante;

void inicializar(Estudiante * estudiante_a_rellenar, char * nombre, int edad, float nota) {
    estudiante_a_rellenar->edad = edad;
    estudiante_a_rellenar->nota = nota;
    strcpy(estudiante_a_rellenar->nombre, nombre);
}

void cumpleanios(Estudiante * cumpleanero) {
    cumpleanero->edad++;
}

void imprimirEstudiante(const Estudiante * estudiante_a_imprimir) {
    printf("Nombre: %s\n", estudiante_a_imprimir->nombre);
    printf("\tEdad: %d\n", estudiante_a_imprimir->edad);
    printf("\tNota: %f\n", estudiante_a_imprimir->nota);
}

void estudianteToString(const Estudiante * datos, char * retval) {
    snprintf(retval, MAX_BUFFER * sizeof(char), "El estudiante- %s de %d años ha sacado un %f", datos->nombre, datos->edad, datos->nota);
}

void modificarNombreEstudiante(Estudiante * estudiante_a_modificar, char * nuevo_nombre) {
    strcpy(estudiante_a_modificar->nombre, nuevo_nombre);
}

int main() {
    int edad;
    float nota;
    char nombre[MAX_NOMBRE];
    int num_estudiantes;

    Estudiante listado[MAX_ESTUDIANTES];

    printf("%p \n", listado);
    printf("Sizeof listado: %lu \n", sizeof(listado));
    printf("Sizeof Estudiante: %lu \n", sizeof(Estudiante));

    printf("¿Cuántos estudiantes deseas inicializar? ");
    scanf("%d", &num_estudiantes);

    for (int i = 0; i < num_estudiantes; i++) {
        printf("Introduce la edad: ");
        scanf("%d", &edad);

        printf("Introduce la nota: ");
        scanf("%f", &nota);

        printf("Introduce el nombre: ");
        scanf("%s", nombre);

        inicializar(listado, nombre, edad, nota);
    }

    printf("Edad antigua de %s: %d\n", listado[0].nombre, listado[0].edad);
    cumpleanios(&listado[0]);
    printf("Edad nueva: %d\n", listado[0].edad);

    imprimirEstudiante(&listado[0]);

    char StringARellenar[MAX_BUFFER];
    estudianteToString(&listado[0], StringARellenar);
    printf("%s\n", StringARellenar);

    char nuevo_nombre[MAX_NOMBRE];
    printf("Introduce el nuevo nombre: ");
    scanf("%s", nuevo_nombre);
    modificarNombreEstudiante(&listado[0], nuevo_nombre);
    imprimirEstudiante(&listado[0]);

    return 0;
}


#include "dragones.h"
#include "utilidades.h"

int main() {
    int opcion;
    Dragon *dragones = NULL; 
    int totalDragones = 0;  

    printf(MAGENTA"\tMENÚ:\n");
    printf(AZUL_C"\t1) Seleccionar un dragón predefinido\n");
    printf(AZUL_C"\t2) Crear un nuevo dragón\n");
    printf(AZUL_C"\t3) Salir\n");
    printf(MAGENTA"\tSeleccion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            visualizarDragones();
            break;

        case 2:
            añadir_dragon(&dragones, &totalDragones);
            break;

        case 3:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción inválida.\n");
            break;
    }

    free(dragones);
    return 0;
}
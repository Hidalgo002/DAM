/*********************************  IMPORTANTE *********************************/
/* Para poder ver las imágenes que hemos puesto, tiene que tener instalado 'chafa' en el terminal. Instalelo con este sencillo comando: 
-> sudo apt install chafa
*/

#include "utilidades.h"
#include "cazador.h"
#include "dragon.h"
#include "combate.h"

int main() {
    Dragon *dragones = NULL;
    Cazador *cazadores = NULL;
    int totalDragones = 0;
    int totalCazadores = 0;
    int opcionElegida = 0;
    Cazador *cazadorSeleccionado = NULL;

    BIENVENIDA();

    inicializarCazadores(&cazadores, &totalCazadores);

    MENU(&cazadores, &totalCazadores, &dragones, &totalDragones, &opcionElegida);

    switch (opcionElegida) {
        case 1:
            visualizarDragones(&dragones, &totalDragones);
            cazadorSELEC(cazadores, totalCazadores, &cazadorSeleccionado);
            if (cazadorSeleccionado == NULL) {
                printf(ROJO"No se seleccionó un cazador. Saliendo...\n"SC);
                free(cazadores);
                free(dragones);
                return 0;
            }
            comenzarBatalla(cazadores, totalCazadores, &cazadorSeleccionado, dragones, totalDragones);
            break;

        case 2:
            añadirCazador(&cazadores, &totalCazadores);
            cazadorSeleccionado = &cazadores[totalCazadores - 1];

            totalDragones = 3;
            Dragon *dragonPersonalizado = (Dragon *)malloc(sizeof(Dragon));
            if (dragonPersonalizado == NULL) {
                printf(ROJO"Error al asignar memoria para el dragón personalizado\n"SC);
                free(cazadores);
                return 1;
            }
            dragones = dragonPersonalizado;
            añadir_dragon(&dragones, &totalDragones);

            comenzarBatalla(cazadores, totalCazadores, &cazadorSeleccionado, &dragones[totalDragones - 1], 1);
            break;

        case 3:

        instrucciones();

        break;

        case 4:
            printf("Saliendo...\n");
            free(cazadores);
            free(dragones);
            return 0;

        default:
            printf(ROJO"Opción inválida. Saliendo...\n"SC);
            break;
    }

    free(dragones);
    free(cazadores);
    return 0;
}

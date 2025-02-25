#include "utilidades.h"
#include "dragones.h"

void añadir_dragon(Dragon **dragones, int *totalDragones) {
    Dragon nuevoDragon;
    int seleccion;

    printf(AMARILLO"\nIntroduzca los datos del nuevo dragon: \n"SC);

    printf(AZUL_C"\tID: %d\n", 1 + MAX_DRAGONES);

    getchar();  

    // NOMBRE
    printf(AZUL_C"\tNOMBRE: ");
    scanf("%[^\n]", nuevoDragon.nombre);

    // VIDA
    do {
        printf(AZUL_C"\tVIDA: ");
        if (scanf("%d", &nuevoDragon.vida) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.vida < 0 || nuevoDragon.vida > 100) {
            printf(ROJO"\tEl rango de vida tiene que estar entre 0-100\n\n"SC);
        }
    } while (nuevoDragon.vida < 0 || nuevoDragon.vida > 100);

    getchar(); 

    // DAÑO
    do {
        printf(AZUL_C"\tDAÑO: ");
        if (scanf("%d", &nuevoDragon.daño) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.daño < 0 || nuevoDragon.daño > 50) {
            printf(ROJO"\tEl rango de daño tiene que estar entre 0-50\n\n"SC);
        }
    } while (nuevoDragon.daño < 0 || nuevoDragon.daño > 50);

    getchar(); 

    // RESISTENCIA
    do {
        printf(AZUL_C"\tRESISTENCIA: ");
        if (scanf(" %d", &nuevoDragon.resistencia) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.daño < 0 || nuevoDragon.resistencia > 20) {
            printf(ROJO"\tEl rango de resistencia tiene que estar entre 0-20\n\n"SC);
        }
    } while (nuevoDragon.resistencia < 0 || nuevoDragon.resistencia > 20);

    getchar(); 


    // PASIVA
    printf(AZUL_C"\tPASIVA:\n");
    printf(ROJO"\t  1) +25%% resistencia a ataques\n");
    printf(ROJO"\t  2) +25%% daño\n");
    printf(ROJO"\t  3) Se curará un 5%% de su vida después de cada ataque\n");
    printf(ROJO"\t  4) Sin pasiva\n");
    printf(MAGENTA"\tSelección: "SC);
    scanf("%d", &seleccion);
    getchar(); 

    switch (seleccion) {
        case 1:
            strcpy(nuevoDragon.pasiva, SC"+25% resistencia a ataques");
            break;
        case 2:
            strcpy(nuevoDragon.pasiva, SC"+25% daño");
            break;
        case 3:
            strcpy(nuevoDragon.pasiva, SC"Se curará un 5% de su vida después de cada ataque");
            break;
        default:
            strcpy(nuevoDragon.pasiva, SC"Sin pasiva");
            break;
    }

    // DESCRIPCIÓN
    printf(AZUL_C"\tDESCRIPCIÓN: ");
    scanf("%[^\n]", nuevoDragon.descripcion);
    getchar(); 

    // RECOMPENSA 
    do {
        printf(AZUL_C"\tRECOMPENSA: ");
        if (scanf("%d", &nuevoDragon.oro) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n\n"SC);
            while (getchar() != '\n');  
        } else if (nuevoDragon.oro < 0 || nuevoDragon.oro > 200) {
            printf(ROJO"\tEl rango de recompensa tiene que estar entre 0-200\n\n"SC);
        }
    } while (nuevoDragon.oro < 0 || nuevoDragon.oro > 200);

    nuevoDragon.id = (*totalDragones) + 1;

    *dragones = (Dragon *)realloc(*dragones, (*totalDragones + 1) * sizeof(Dragon));
    if (*dragones == NULL) {
        printf(ROJO"\tError al asignar memoria\n\n");
        return;
    }

    memcpy(&((*dragones)[*totalDragones]), &nuevoDragon, sizeof(Dragon));

    (*totalDragones)++;

    printf(NARANJA"\n\tDragón agregado:\n");
    mostrarDragon(&nuevoDragon);
}


void inicializarDragon(Dragon *dragon, int id,  char *nombre, int vida, int daño, int resistencia,  char *pasiva,  char *descripcion, int oro) {
    dragon->id = id;
    strcpy(dragon->nombre, nombre);
    dragon->vida = vida;
    dragon->daño = daño;
    dragon->resistencia = resistencia;
    strcpy(dragon->pasiva, pasiva);
    strcpy(dragon->descripcion, descripcion);
    dragon->oro = oro;
}

void mostrarDragon(Dragon *dragon) {
    printf(ROJO"\tID:"SC" %d\n", dragon->id);
    printf(ROJO"\tNombre:"SC" %s\n", dragon->nombre);
    printf(ROJO"\tVida:"SC" %d\n", dragon->vida);
    printf(ROJO"\tDaño:"SC" %d\n", dragon->daño);
    printf(ROJO"\tResistencia:"SC" %d%%\n", dragon->resistencia);
    printf(ROJO"\tPasiva:"SC" %s\n", dragon->pasiva);
    printf(ROJO"\tDescripción:"SC" %s\n", dragon->descripcion);
    printf(ROJO"\tRecompensa:"SC" %d de oro\n\n", dragon->oro);
}

void visualizarDragones() {
    Dragon *dragones = (Dragon*) malloc(3 * sizeof(Dragon));
    if(dragones == NULL){
        printf("Error al reservar memoria\n");
        exit(EXIT_SUCCESS);
    }

    inicializarDragon(&dragones[0], 1, "Nightmare", 100, 10, 15, "+25% resistencia a ataques", "Nightmare es un dragón proveniente de las pesadillas más oscuras, ningún caballero quiere desafiarle.", 50);
    inicializarDragon(&dragones[1], 2, "Cryonyx", 100, 15, 15, "+25% daño", "Cryonyx es un dragón temido debido a su alto poder, vive en las montañas en solitario desarrollando aún más su fuerza.", 125);
    inicializarDragon(&dragones[2], 3, "Velkhanos", 100, 10, 15, "Se curará un 5% de su vida después de cada ataque", "Velkhanos es un dragón histórico, proveniente de Asia, ningún otro dragón ha podido derrotarle.", 200);

    printf(NARANJA"\nDRAGONES DISPONIBLES:\n"SC);
    system("chafa -f symbols -s 50x30 Nightmare.jpg"); 
    mostrarDragon(&dragones[0]);
    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
    mostrarDragon(&dragones[1]);
    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
    mostrarDragon(&dragones[2]);

    seleccionarDragon(dragones, 3);

    free(dragones);
}

void seleccionarDragon(Dragon *dragones, int totalDragones) {
    int seleccion;
    int valido = 0;

    do {
        printf(NARANJA"Introduzca el ID del dragon con el que va a jugar: ");
        scanf("%d", &seleccion);

        if (seleccion >= 1 && seleccion <= totalDragones) {
            switch(seleccion) {
                case 1:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Nightmare.jpg");
                    break;
                case 2:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
                    break;
                case 3:
                    printf("\n\nDragon seleccionado: %d\n", seleccion);
                    printf("\n");
                    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
                    break;
            }

            mostrarDragon(&dragones[seleccion - 1]);

            valido = 1;
        } else {
            printf(ROJO"Has introducido un dragón que no existe.\n\n"SC);
        }
    } while (!valido);
}










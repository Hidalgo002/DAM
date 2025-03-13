#include "utilidades.h"
#include "dragon.h"

void añadir_dragon(Dragon **dragones, int *totalDragones) {
    // Declaramos una variable para almacenar los datos del nuevo dragón
    Dragon nuevoDragon;

    printf(AMARILLO"\nIntroduzca los datos del nuevo dragon: \n"SC);

    // Asignamos un ID unico 
    nuevoDragon.id = (*totalDragones) + 1;
    printf(AZUL_C"\tID: %d\n"SC, nuevoDragon.id);

    // Limpiamos el buffer de entrada para evitar problemas con fgets
    while (getchar() != '\n' && getchar() != EOF);

    // Solicitamos el nombre del dragón
    printf(AZUL_C"\tNOMBRE: "SC);
    fgets(nuevoDragon.nombre, MAX_NOMBRE, stdin);

    // Eliminamos el salto de linea que fgets podria haber agregado
    nuevoDragon.nombre[strcspn(nuevoDragon.nombre, "\n")] = 0;

    // Pedimos la cantidad de vida del dragón dentro del rango permitido (300-400)
    do {
        printf(AZUL_C"\tVIDA: "SC);
        if (scanf("%d", &nuevoDragon.vida) != 1) {
            // Si la entrada no es un numero, mostramos un error y limpiamos el buffer
            printf(ROJO"\tPor favor, introduce solo números.\n"SC);
            while (getchar() != '\n');
        } else if (nuevoDragon.vida < 300 || nuevoDragon.vida > 400) {
            // Si el numero esta fuera del rango, mostramos un mensaje de error
            printf(ROJO"\tEl rango de vida tiene que estar entre 300-400\n"SC);
        } else {
            break; 
        }
    } while (1);
    while (getchar() != '\n'); // Limpiamos el buffer de entrada

    // Pedimos el ataque del dragon entre 0 y 50
    do {
        printf(AZUL_C"\tATAQUE: "SC);
        if (scanf("%d", &nuevoDragon.ataque) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n"SC);
            while (getchar() != '\n');
        } else if (nuevoDragon.ataque < 0 || nuevoDragon.ataque > 50) {
            printf(ROJO"\tEl rango de ataque tiene que estar entre 0-50\n"SC);
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n'); // Limpiamos el buffer de entrada

    // Pedimos la resistencia del dragon entre 0 y 20
    do {
        printf(AZUL_C"\tRESISTENCIA: "SC);
        if (scanf("%d", &nuevoDragon.resistencia) != 1) {
            printf(ROJO"\tPor favor, introduce solo números.\n"SC);
            while (getchar() != '\n');
        } else if (nuevoDragon.resistencia < 0 || nuevoDragon.resistencia > 20) {
            printf(ROJO"\tEl rango de resistencia tiene que estar entre 0-20\n"SC);
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n'); // Limpiamos el buffer de entrada

    // Pedimos la pasiva del dragon 
    int seleccion;
    printf(AZUL_C"\tPASIVA:\n"SC);
    printf(ROJO"\t  1) +25%% resistencia a ataques\n"SC);
    printf(ROJO"\t  2) +25%% ataque\n"SC);
    printf(ROJO"\t  3) Se curará un 5%% de su vida después de cada ataque\n"SC);
    printf(ROJO"\t  4) Sin pasiva\n"SC);
    printf(MAGENTA"\tSelección: "SC);
    scanf("%d", &seleccion);
    while (getchar() != '\n'); // Limpiamos el buffer de entrada

    // Asignamos la pasiva elegida al dragon
    switch (seleccion) {
        case 1:
            strcpy(nuevoDragon.pasiva, "+25% resistencia a ataques");
            break;
        case 2:
            strcpy(nuevoDragon.pasiva, "+25% ataque");
            break;
        case 3:
            strcpy(nuevoDragon.pasiva, "Se curará un 5% de su vida después de cada ataque");
            break;
        default:
            strcpy(nuevoDragon.pasiva, "Sin pasiva");
            break;
    }

    // Pedimos la descripcion del dragon
    printf(AZUL_C"\tDESCRIPCIÓN: "SC);
    scanf(" %[^\n]", nuevoDragon.descripcion);
    while (getchar() != '\n'); // Limpiamos el buffer de entrada

    // Inicializamos la cantidad de oro del dragón con un valor fijo de 100
    nuevoDragon.oro = 100;

    // Aumentamos dinámicamente el tamaño del arreglo de dragones usando realloc
    Dragon *temp = realloc(*dragones, (*totalDragones + 1) * sizeof(Dragon));
    if (temp == NULL) {
        printf(ROJO"\tError al asignar memoria\n"SC);
        free(*dragones);
        return;
    }
    *dragones = temp; // Actualizamos el puntero 

    // Añadimos el nuevo dragón a la lista
    (*dragones)[*totalDragones] = nuevoDragon;
    (*totalDragones)++; // Incrementamos el contador de dragones

    // Mostramos la informacion del nuevo dragon agregado
    printf(NARANJA"\n\tDragón agregado:\n"SC);
    mostrarDragon(&(*dragones)[*totalDragones - 1]);
}


void inicializarDragon(Dragon *dragon, int id, char *nombre, int vida, int ataque, int resistencia, char *pasiva, char *descripcion, int oro) {
    // Asigna el ID unico al dragón
    dragon->id = id;

    // Copia el nombre recibido al de nombre del dragon
    strcpy(dragon->nombre, nombre);

    // Asigna los valores de vida, ataque y resistencia
    dragon->vida = vida;
    dragon->ataque = ataque;
    dragon->resistencia = resistencia;

    // Copia la pasiva y la descripción al dragon
    strcpy(dragon->pasiva, pasiva);
    strcpy(dragon->descripcion, descripcion);

    // Asigna la cantidad de oro inicial
    dragon->oro = oro;
}

void mostrarDragon(Dragon *dragon) {
    // Muestra el ID del dragon
    printf(ROJO"\tID:"SC" %d\n", dragon->id);

    // Muestra el nombre del dragon
    printf(ROJO"\tNombre:"SC" %s\n", dragon->nombre);

    // Muestra la cantidad de vida del dragon
    printf(ROJO"\tVida:"SC" %d\n", dragon->vida);

    // Muestra el poder de ataque del dragon
    printf(ROJO"\tAtaque:"SC" %d\n", dragon->ataque);

    // Muestra la resistencia del dragon en porcentaje
    printf(ROJO"\tResistencia:"SC" %d%%\n", dragon->resistencia);

    // Muestra la habilidad pasiva del dragon
    printf(ROJO"\tPasiva:"SC" %s\n", dragon->pasiva);

    // Muestra la descripción del dragon
    printf(ROJO"\tDescripción:"SC" %s\n", dragon->descripcion);

    // Muestra la recompensa en oro que da el dragon
    printf(ROJO"\tRecompensa:"SC" %d de oro\n\n", dragon->oro);
}

void visualizarDragones(Dragon **dragones, int *totalDragones) {
    //Reserva de memoria para los 3 dragones
    *totalDragones = 3;
    *dragones = (Dragon*)malloc(3 * sizeof(Dragon));
    if (*dragones == NULL) {
        printf("Error al reservar memoria\n");
        exit(EXIT_FAILURE);
    }

    //Inicializacion de los 3 dragones
    inicializarDragon(&(*dragones)[0], 1, "Nightmare", 400, 10, 15, "+25% resistencia a ataques", "Nightmare es un dragón proveniente de las pesadillas más oscuras, ningún caballero quiere desafiarle.", 50);
    inicializarDragon(&(*dragones)[1], 2, "Cryonyx", 400, 15, 15, "+25% ataque", "Cryonyx es un dragón temido debido a su alto poder, vive en las montañas en solitario desarrollando aún más su fuerza.", 125);
    inicializarDragon(&(*dragones)[2], 3, "Velkhanos", 400, 10, 15, "Se curará un 5%...", "Velkhanos es un dragón histórico, proveniente de Asia, ningún otro dragón ha podido derrotarle.", 200);
}

void seleccionarDragon(Dragon *dragones, int totalDragones, Dragon **seleccionado) {
    int seleccion;  // Variable para almacenar la seleccion del usuario
    int valido = 0; // Bandera para verificar si la seleccion es válida

    // Bucle para solicitar una selección valida
    do {
        // Solicita al usuario que introduzca el ID de un dragon
        printf(NARANJA"Introduzca el ID del dragón con el que va a jugar: "SC);
        scanf("%d", &seleccion);
        while (getchar() != '\n'); // Limpia el buffer de entrada

        // Verifica si el ID ingresado esta dentro del rango de dragones disponibles
        if (seleccion >= 1 && seleccion <= totalDragones) {
            // Muestra un mensaje indicando el dragon seleccionado
            printf("\n\nDragón seleccionado: %d\n", seleccion);

            // Muestra la imagen del dragon seleccionado usando el comando `chafa`
            switch (seleccion) {
                case 1:
                    system("chafa -f symbols -s 50x30 Nightmare.jpg");
                    break;
                case 2:
                    system("chafa -f symbols -s 50x30 Cryonyx.jpg");
                    break;
                case 3:
                    system("chafa -f symbols -s 50x30 Velkhanos.jpg");
                    break;
            }

            // Muestra la informacion del dragon seleccionado
            mostrarDragon(&dragones[seleccion - 1]);

            // Marca la selección como válida y almacena la referencia al dragon seleccionado
            valido = 1;
            *seleccionado = &dragones[seleccion - 1];
        } else {
            // Mensaje de error si el ID ingresado no es válido
            printf(ROJO"Has introducido un dragón que no existe.\n\n"SC);
        }
    } while (!valido); // Repite hasta que el usuario seleccione un dragon válido
}
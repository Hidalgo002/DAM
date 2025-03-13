#include "cazador.h"
#include "utilidades.h"

//inicializarCazadores, aquí guardamos los datos de nuestros cazadores. Estos son colocados en un orden específico para ser correctamente almacenados según el struct de datos.
 void inicializarCazadores(Cazador **cazadores, int *totalCazadores) {
    *totalCazadores = 3;

    *cazadores = (Cazador *)malloc(*totalCazadores * sizeof(Cazador));
    if (*cazadores == NULL) {
        printf("ERROR CATASTRÓFICO: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    inicializarCazador(&(*cazadores)[0], 1, "Mushashi", "Iaido", 20, 120, 100, "Un guerrero rápido y letal, su habilidad con la espada es tan precisa que sus enemigos apenas pueden reaccionar.");
    inicializarCazador(&(*cazadores)[1], 2, "Conan", "Atlantean", 15, 150, 100, "Un guerrero con fuerza colosal y una resistencia que desafía los límites de la naturaleza");
    inicializarCazador(&(*cazadores)[2], 3, "Sauron", "Narsil", 10, 200, 100, "Un estratega con gran resistencia, capaz de sanar a sus compañeros y mantener su voluntad firme en medio del caos.");
 } 

//inicializarCazador-> sirve para inicializar un objeto del tipo 'Cazador' (nombre del struct) con valores especificos
void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion) {
    datos->ID = ID;
    strncpy(datos->nombre, nombre, sizeof(datos->nombre) - 1);
    datos->nombre[sizeof(datos->nombre) - 1] = '\0';
    strncpy(datos->arma, arma, sizeof(datos->arma) - 1);
    datos->arma[sizeof(datos->arma) - 1] = '\0';
    strncpy(datos->descripcion, descripcion, sizeof(datos->descripcion) - 1);
    datos->descripcion[sizeof(datos->descripcion) - 1] = '\0';
    datos->ataque = ataque;
    datos->vida = vida;
    datos->oro = oro;
    datos->defensa = 0;
    datos->frascosPequenos = 0;
    datos->frascosGrandes = 0;
    datos->espadaMejorada = 0;
}

//cazadorIMPRIMIR-> pasamos los datos de los cazadores a 'cazador_a_imprimir' y este muestra los datos por pantalla.
void cazadorIMPRIMIR(const Cazador *cazador_a_imprimir) {
    printf(ROJO"\tID:"SC" %d\n", cazador_a_imprimir->ID);
    printf(ROJO"\tNombre:"SC" %s\n", cazador_a_imprimir->nombre);
    printf(ROJO"\tArma:"SC" %s\n", cazador_a_imprimir->arma);
    printf(ROJO"\tAtaque:"SC" %d\n", cazador_a_imprimir->ataque);
    printf(ROJO"\tVida:"SC" %d\n", cazador_a_imprimir->vida);
    printf(ROJO"\tOro:"SC" %d\n", cazador_a_imprimir->oro);
    printf(ROJO"\tDescripción:"SC" %s\n", cazador_a_imprimir->descripcion);
}

//cazadorSELEC -> Durante el combate, seremos capaces de jugar con hasta tres cazadores.
void cazadorSELEC(Cazador *cazadores, int totalCazadores, Cazador **seleccionado) {
    int intentos = 3;
    int cazadorACTIVO; //Aquí guardamos el cazador con el que estamos jugando
    int cazadoresVivos = 0; //Aquí se muestra cuantos cazadores quedan

    for (int i = 0; i < totalCazadores; i++) {//Recorremos todos los cazadores disponibles (3 al inicio)
        if (cazadores[i].vida > 0) { //mientras la vida del cazador sea superior a 0 contará como un cazador vivo y se incrementa el contador
            cazadoresVivos++;
        }
    }

    if (cazadoresVivos == 0) { //Sin embargo, si el contador llega a cero, se declara el gfinal de la partida y no se mostraran mas cazadores para juagr
        printf(ROJO"No quedan cazadores vivos. Fin del juego.\n"SC);
        *seleccionado = NULL;
        return;
    }

    printf(NARANJA"\nCAZADORES DISPONIBLES: \n"SC);

    for (int i = 0; i < totalCazadores; i++) {
        if (cazadores[i].vida > 0) { //Si la vida del cazador es superior a 0, es decir, sigue vivo, se mostrara por pantalla para ser elegido
            switch (cazadores[i].ID) {
                case 1: system("chafa -f symbols -s 50x30 Mushashi.jpg"); break;
                case 2: system("chafa -f symbols -s 50x30 Conan.jpg"); break;
                case 3: system("chafa -f symbols -s 50x30 Sauron.jpg"); break;
                default: break;
            }
            cazadorIMPRIMIR(&cazadores[i]);
        }
    }

    do {//Aquí se introduce el ID del  cazador, si no es válido, salta un error. Si es válido y además está vivo, se podrá seleccionar.
        printf(NARANJA"\n\nIntroduzca el ID del cazador con el que va a jugar: "SC);
        if (scanf("%d", &cazadorACTIVO) != 1) {
            printf(ROJO"Entrada inválida. Debe ingresar un número.\n"SC);
            while (getchar() != '\n'); 
            intentos--;
        } else {
            int cazadorValido = 0;
            for (int i = 0; i < totalCazadores; i++) {
                if (cazadores[i].ID == cazadorACTIVO && cazadores[i].vida > 0) {
                    cazadorValido = 1;
                    switch (cazadorACTIVO) {
                        case 1: system("chafa -f symbols -s 50x30 Mushashi.jpg"); break;
                        case 2: system("chafa -f symbols -s 50x30 Conan.jpg"); break;
                        case 3: system("chafa -f symbols -s 50x30 Sauron.jpg"); break;
                        default: break;
                    }
                    cazadorIMPRIMIR(&cazadores[i]);
                    *seleccionado = &cazadores[i];
                    return;
                }
            }
            if (!cazadorValido) {
                printf(ROJO"El ID ingresado no corresponde a un cazador vivo o válido.\n"SC);
                intentos--;
            }
        }

        if (intentos == 0) {//Medida de preveción para limitar el número de veces que puede errar el usuario a la hora de introducir datos en el terminal
            printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
            *seleccionado = NULL;
            return;
        }
    } while (intentos > 0);
}

//añadirCazador-> almacenamos de forma temporal los datos del nuevo cazador en 'nuevoCazador', luego lo guardamos en  cazador de nuevo
void añadirCazador(Cazador **cazadores, int *totalCazadores) {
    int intentos = 3;
    Cazador nuevoCazador;
    printf(AMARILLO "\nIntroduzca los datos del nuevo cazador: \n" SC);

    nuevoCazador.ID = *totalCazadores + 1;
    printf(AZUL_C "\t ID:" SC " %d.\n", nuevoCazador.ID);

//NOMBRE
    do {
        printf(AZUL_C "\t NOMBRE: " SC);
        scanf(" %[^\n]", nuevoCazador.nombre);

        int esValido = 1;
        for (int i = 0; i < strlen(nuevoCazador.nombre); i++) {
            if (isdigit(nuevoCazador.nombre[i])) {
                esValido = 0;
                break;
            }
        }

        if (strlen(nuevoCazador.nombre) < 1 || strlen(nuevoCazador.nombre) > MAXNOMBRE) {
            printf(ROJO "Valor inválido, el nombre no puede ser menor a 1 o mayor a %d.\n" SC, MAXNOMBRE);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

//ARMA
    do {
        printf(AZUL_C "\t ARMA: " SC);
        scanf(" %[^\n]", nuevoCazador.arma);

        if (strlen(nuevoCazador.arma) < 1 || strlen(nuevoCazador.arma) > MAXARMA) {
            printf(ROJO "Valor inválido, el nombre del arma no puede ser menor a 1 o mayor a %d.\n" SC, MAXARMA);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

//ATAQUE
    do {
        printf(AZUL_C "\t ATAQUE: " SC);

        if (scanf("%d", &nuevoCazador.ataque) != 1) {
            printf(ROJO "Entrada inválida. Debe ingresar un número.\n" SC);
            while (getchar() != '\n');
            intentos--;
        } else if (nuevoCazador.ataque < 1 || nuevoCazador.ataque > MAXATAQUE) {
            printf(ROJO "Valor inválido, el ataque no puede ser menor a 1 o mayor a %d.\n" SC, MAXATAQUE);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

//VIDA
    do {
        printf(AZUL_C "\t VIDA: " SC);

        if (scanf("%d", &nuevoCazador.vida) != 1) {
            printf(ROJO "Entrada inválida. Debe ingresar un número.\n" SC);
            while (getchar() != '\n');
            intentos--;
        } else if (nuevoCazador.vida < 1 || nuevoCazador.vida > MAXVIDA) {
            printf(ROJO "Valor inválido, la vida no puede ser menor a 1 o mayor a %d.\n" SC, MAXVIDA);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

//ORO -> El oro dado a cada nuevo cazador está fijado en 100
    nuevoCazador.oro = 100;
    printf(AZUL_C "\t ORO:" SC " %d monedas.\n", nuevoCazador.oro);

//DESCRIPCIÓN.
    do {
        printf(AZUL_C "\t DESCRIPCIÓN: " SC);
        scanf(" %[^\n]", nuevoCazador.descripcion);

        if (strlen(nuevoCazador.descripcion) < 1 || strlen(nuevoCazador.descripcion) > MAXDESCRIPCION) {
            printf(ROJO "Valor inválido, la descripción no puede ser menor a 1 o mayor a %d.\n" SC, MAXDESCRIPCION);
            intentos--;
        } else {
            intentos = 3;
            break;
        }

        if (intentos == 0) {
            printf(ROJO "INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n" SC);
            exit(EXIT_FAILURE);
        }
    } while (intentos > 0);

//Inventario: consideramos esta parte como el inventario del cazador, donde se almacenan los elementos comprados en la tienda. Cuando es añadido parte de cero todo sin posibilidad de modificarlo en el menú de inicio
    nuevoCazador.defensa = 0;
    nuevoCazador.frascosPequenos = 0;
    nuevoCazador.frascosGrandes = 0;
    nuevoCazador.espadaMejorada = 0;

//Cuando añadimos un nuevo cazador, tenemos que hacer la memorio más grande para poder almacenar los nuevos datos.

    Cazador *REALLOC_TEMP = (Cazador*) realloc(*cazadores, (*totalCazadores + 1) * sizeof(Cazador));
    if (REALLOC_TEMP == NULL) {
        printf("ERROR: No se pudo asignar memoria para el nuevo cazador.\n");
        exit(EXIT_FAILURE);
    }
    *cazadores = REALLOC_TEMP; //Reasignamos el valor del realloc temporal a cazadores de nuevo

    (*cazadores)[*totalCazadores] = nuevoCazador;
    (*totalCazadores)++; //Se añade un cazador

    printf(NARANJA "\nCAZADOR AGREGADO:\n" SC);
    cazadorIMPRIMIR(&(*cazadores)[*totalCazadores - 1]);
}
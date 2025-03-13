#include "utilidades.h"

void BIENVENIDA() {
    system("clear");
    system("chafa -f symbols -s 90x50 Erebor.jpg");
    printf(CURSIVA"Tras la caída del gran dragón codicioso, los cielos sobre la Montaña Solitaria permanecieron en silencio por generaciones. Sin embargo, los ecos de su avaricia no desaparecieron tras su muerte a manos de Bardo. Los hijos del monstruo, nacidos en las sombras de su padre, regresan ahora, decididos a reclamar lo que consideran suyo: el oro que una vez perteneció al rey enano Thráin II.\n"

        "\nEl tesoro, una vez custodiado por un solo ser, ahora se ve protegido por una legión de dragones con la misma insaciable hambre que su antecesor. La Montaña, que guardó el silencio por tanto tiempo, vuelve a rugir con la furia de aquellos que ansían lo que no les pertenece.\n"

        "\nLos cazadores, sabiendo que esta vez el desafío es aún mayor, se preparan para enfrentar a una fuerza más peligrosa que cualquier que hayan conocido. No luchan solo por el oro, sino por evitar que la sombra de la codicia del dragón se apodere nuevamente de la tierra.\n\n"SC);
}

void TIENDA(Cazador *cazador) {
    // Limpia la pantalla antes de mostrar el menu
    system("clear");

    printf(NARANJA"Bienvenido a la tienda, %s. Tienes %d monedas.\n"SC, cazador->nombre, cazador->oro);
    
    printf(MAGENTA"\tMENÚ DE LA TIENDA:\n"SC);
    printf(AZUL_C"\t1) Comprar vida\n"SC);
    printf(AZUL_C"\t2) Comprar arma\n"SC);
    printf(AZUL_C"\t3) Salir\n"SC);
    printf(MAGENTA"\tSelección: "SC);

    int opcion;
    scanf("%d", &opcion);
    while (getchar() != '\n'); // Limpia el bufer de entrada 

    switch (opcion) {
        case 1: // Opcion para comprar vida
            printf("OBJETOS DISPONIBLES:\n"
                   "\nVIDA:\n");
            
            system("chafa -f symbols -s 30x30 Estus.png");
            
            // Lista de opciones para comprar frascos de Estus
            printf("\t- 1) Frasco pequeño de Estus: 25 monedas - +25 vida\n"
                   "\t- 2) Frasco grande de Estus: 50 monedas - +50 vida\n");
            printf(MAGENTA"Selecciona una opción: "SC);

            int opcionVida;
            scanf("%d", &opcionVida);
            while (getchar() != '\n'); // Limpia el búfer de entrada

            switch (opcionVida) {
                case 1: // Compra de frasco pequeño
                    if (cazador->oro >= 25) { // Verifica si el cazador tiene suficiente oro
                        printf(VERDE"Has comprado un frasco pequeño de Estus.\n"SC);
                        cazador->oro -= 25; // Resta el costo del oro
                        cazador->frascosPequenos++; // Aumenta la cantidad de frascos en el inventario
                        printf("Frascos pequeños en inventario: %d\n", cazador->frascosPequenos);
                    } else {
                        printf(ROJO"No tienes suficientes monedas para esta compra.\n"SC);
                    }
                    break;
                case 2: // Compra de frasco grande
                    if (cazador->oro >= 50) { // Verifica si el cazador tiene suficiente oro
                        printf(VERDE"Has comprado un frasco grande de Estus.\n"SC);
                        cazador->oro -= 50; // Resta el costo del oro
                        cazador->frascosGrandes++; // Aumenta la cantidad de frascos en el inventario
                        printf("Frascos grandes en inventario: %d\n", cazador->frascosGrandes);
                    } else {
                        printf(ROJO"No tienes suficientes monedas para esta compra.\n"SC);
                    }
                    break;
                default:
                    printf(ROJO"Opción inválida.\n"SC);
                    break;
            }
            break;

        case 2: 
            printf("OBJETOS DISPONIBLES:\n"
                   "\tARMAS:\n");
            
            system("chafa -f symbols -s 40x30 Anduril.jpg");
            printf("\t- 1) Anduril: 150 monedas - 30 daño\n");

            system("chafa -f symbols -s 30x30 gimli.jpg");
            printf("\t- 2) Bearded Axe: 250 monedas - 35 daño\n");

            printf(MAGENTA"Selecciona una opción: "SC);

            int opcionArma;
            scanf("%d", &opcionArma);
            while (getchar() != '\n'); // Limpia el bufer de entrada

            switch (opcionArma) {
                case 1: // Compra de la espada Anduril
                    if (cazador->oro >= 150 && cazador->espadaMejorada == 0) { 
                        // Verifica si el cazador tiene suficiente oro y no tiene ya un arma mejorada
                        printf(VERDE"Has comprado Anduril, una espada de alto alcance. +30 daño.\n"SC);
                        cazador->oro -= 150; // Resta el costo del oro
                        cazador->espadaMejorada = 1; // Marca que el cazador tiene un arma mejorada
                        cazador->ataque += 30; // Aumenta el daño de ataque
                        strcpy(cazador->arma, "Anduril"); // Guarda el nombre del arma en su inventario
                    } else if (cazador->espadaMejorada != 0) {
                        printf(ROJO"Ya tienes una espada mejorada.\n"SC);
                    } else {
                        printf(ROJO"No tienes suficientes monedas para esta compra.\n"SC);
                    }
                    break;
                case 2: 
                    if (cazador->oro >= 250 && cazador->espadaMejorada == 0) { 
                        // Verifica si el cazador tiene suficiente oro y no tiene ya un arma mejorada
                        printf(VERDE"Has comprado la Bearded Axe, un hacha de doble filo. +35 daño.\n"SC);
                        cazador->oro -= 250; // Resta el costo del oro
                        cazador->espadaMejorada = 2; // Marca que el cazador tiene un arma mejorada
                        cazador->ataque += 35; // Aumenta el daño de ataque
                        strcpy(cazador->arma, "Bearded Axe"); // Guarda el nombre del arma en su inventario
                    } else if (cazador->espadaMejorada != 0) {
                        printf(ROJO"Ya tienes una espada mejorada.\n"SC);
                    } else {
                        printf(ROJO"No tienes suficientes monedas para esta compra.\n"SC);
                    }
                    break;
                default:
                    printf(ROJO"Opción inválida.\n"SC);
                    break;
            }
            break;

        case 3: // Opcion para salir de la tienda
            printf(NARANJA"Regresando al combate...\n"SC);
            break;

        default: // Manejo de entrada invalida
            printf(ROJO"Opción inválida.\n"SC);
            break;
    }
}


void instrucciones(){
   
    printf(AZUL_C"\n¿Necesito instalar algo?\n"SC);
    printf(VERDE_C"Si, este juego utiliza imagines, y para ser capaz de verlas necesitas ejecutar 'sudo apt update && sudo apt install chafa' antes de jugar.\n\n"SC);

    printf(AZUL_C"\n¿De qué trata el juego?\n"SC);
    printf(VERDE_C"Es un juego de roles en el que deberás liderar a un equipo de caballeros para derrotar a tres dragones en una épica batalla. Tus caballeros estarán listos para enfrentarse a estos poderosos \nenemigos, y tu estrategia será clave para salir victorioso.\n\n"SC);
   
    printf(AZUL_C"¿Cómo funciona el juego?\n"SC);
    printf(VERDE_C"Podrás elegir entre combates predefinidos que enfrentan a tres caballeros contra tres dragones. La batalla continuará hasta que uno de los bandos se quede sin relevos para seguir luchando.\n\n"SC);
   
    printf(AZUL_C"¿Cómo funciona el sistema de combate?\n"SC);
    printf(VERDE_C"Al iniciar la batalla, el caballero siempre atacará primero. El dragón, por su parte, dependerá de una tirada aleatoria: si sale 1, atacará; de lo contrario, perderá su turno sin hacer nada.\n\n"SC);
    printf(VERDE_C"Si el caballero derrota al dragón, tendrá dos opciones: entrar a la tienda para gastar el oro obtenido por su victoria o seguir luchando y elegir al próximo dragón. Si opta por la tienda, podrá\nadquirir objetos que se añadirán a su inventario o mejorar su daño si compra un arma más poderosa. Sin embargo, usar un objeto de la tienda consumirá un turno.\n\n"SC);
   
    printf(AZUL_C"¿Como funciona el combate personalizado?\n"SC);
    printf(VERDE_C"Al entrar al menu te dara la opcion de crear una batalla con los dragones y cazadores predefinidos o hacer una batalla 1 contra 1 donde tu puedes personalizar el cazador y el dragon, este modo esta\nmas enfocado a testear habilidades, daños, vidas etc\n\n"SC);
   
    printf(AZUL_C"¿Qué pasa al final?\n"SC);
    printf(VERDE_C"Una vez que un equipo (dragones o caballeros) sea completamente derrotado, se mostrarán estadísticas finales, como el número de turnos jugados, el daño total infligido a los dragones y más.\n\n"SC);
   
    printf(AZUL_C"¿Se guardan los dragones/cazadores creados para otra partida?\n"SC);
    printf(VERDE_C"No se almacenan los nuevos cazadores/dragones añadido por el usuario, por lo que si quieres volver a jugar un dragon o cazador creado, deberas replicar todas sus estadisitcas\n\n");

}

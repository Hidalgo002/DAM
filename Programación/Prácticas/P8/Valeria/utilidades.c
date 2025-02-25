//AÑADIDO VALERIA

#include "utilidades.h"
#include "cazador.h"

//MENSAJE DE BIENVENIDA
 void BIENVENIDA(){
 	system("clear");
	system("chafa -f symbols -s 90x50 Erebor.jpg");
	printf(CURSIVA"Tras la caída del gran dragón codicioso, los cielos sobre la Montaña Solitaria permanecieron en silencio por generaciones. Sin embargo, los ecos de su avaricia no desaparecieron tras su muerte a manos de Bardo. Los hijos del monstruo, nacidos en las sombras de su padre, regresan ahora, decididos a reclamar lo que consideran suyo: el oro que una vez perteneció al rey enano Thráin II.\n"

		"\nEl tesoro, una vez custodiado por un solo ser, ahora se ve protegido por una legión de dragones con la misma insaciable hambre que su antecesor. La Montaña, que guardó el silencio por tanto tiempo, vuelve a rugir con la furia de aquellos que ansían lo que no les pertenece.\n"

		"\nLos cazadores, sabiendo que esta vez el desafío es aún mayor, se preparan para enfrentar a una fuerza más peligrosa que cualquier que hayan conocido. No luchan solo por el oro, sino por evitar que la sombra de la codicia del dragón se apodere nuevamente de la tierra.\n\n"SC);
	}

//MENÚ
 extern int totalCazadores;

 void MENU(){
	Cazador *cazadores = NULL;//Tenemos que inicializar el puntero donde vamos a guradar a los cazadores en el main, como todavía no tiene 'nada', lo inicializamos en nulo.
    inicializarCazadores(&cazadores, &totalCazadores);

    Tienda *inventario = NULL;   
    TRANSACCION(&inventario);


	int opcion;

    printf(MAGENTA"\t MENÚ: \n"
            AZUL_C"\t 1) Seleccionar un cazador.\n"
                  "\t 2) Añadir cazador.\n"
                  "\t 3) Salir.\n"SC
           MAGENTA"\t OPCIÓN: "SC);
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            cazadorSELEC(cazadores, totalCazadores);  // Llamada a la función definida en cazador.c
            break;
        case 2:
            añadirCazador(&cazadores, &totalCazadores);
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida.\n");
            break;
    }
 free (cazadores);
 free(inventario);
 }

//TIENDA

/*
Tienda->vidas;
Tienda->vida_precio;
Tienda->arma_N;
Tienda->arma_ataque;
Tienda->arma_precio;
*/


void inicializarTiendaV(Tienda * productosV, int vidas, int vida_precio){
    productosV->vidas = vidas;
    productosV->vida_precio = vida_precio;
}

void inicializarTiendaA(Tienda * productosA, char * arma_N, int arma_ataque, int arma_precio){
    strcpy(productosA-> arma_N, arma_N);
    productosA->arma_ataque = arma_ataque;
    productosA->arma_precio = arma_precio;
}

void TRANSACCIÓN(Tienda ** inventario){
    *inventario = (Tienda*) malloc(TOTAL_PRODUCTOS * sizeof(Tienda));
    if (*inventario == NULL){
        printf("ERROR CATASTRÓFICO: No se pudo asignar memoria.\n");
        exit(EXIT_SUCCESS);}

    inicializarTiendaV(&(*inventario)[0], 25, 25);
    inicializarTiendaV(&(*inventario)[1], 50, 50);
    inicializarTiendaA(&(*inventario)[2],"Espada", 20, 100);
    inicializarTiendaA(&(*inventario)[3],"Hacha", 30, 120);

}

void TiendaIMPRIMIR(const Tienda * tienda_a_imprimir){
        printf("Producto %d: ", i);
        if (inventario[i].vidas > 0) {
            printf("Vidas: %d, Precio: %d\n", inventario[i].vidas, inventario[i].vida_precio);
        } else {
            printf("Arma: %s, Ataque: %d, Precio: %d\n", inventario[i].arma_N, inventario[i].arma_ataque, inventario[i].arma_precio);
        }
}
void cazadorSELEC(Cazador *cazadores, int totalCazadores){
        int intentos = 3;

        printf(NARANJA"PRODUCTOS DISPONIBLES: \n" SC
                "\t VIDA: \n");
        system("chafa -f symbols -s 50x30 Mushashi.jpg");
        TiendaIMPRIMIR(&inventario[0]);
        system("chafa -f symbols -s 50x30 Mushashi.jpg");
        TiendaIMPRIMIR(&inventario[1]);
        system("chafa -f symbols -s 50x30 Sauron.jpg");
        cazadorIMPRIMIR(&cazadores[2]);
    }


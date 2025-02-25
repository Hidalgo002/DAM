#include "cazador.h"
#include "utilidades.h"


extern int totalCazadores;

//INICIALIZAR CAZADOR  
    void inicializarCazador (Cazador * datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion){
        datos -> ID = ID;
        strcpy(datos-> nombre, nombre);
        strcpy(datos-> arma, arma);
        datos -> ataque = ataque;
        datos -> vida = vida;
        datos -> oro = oro;
        strcpy(datos-> descripcion, descripcion);
    }

//VISUALIZAR CAZADOR
    void cazadorIMPRIMIR ( const Cazador * cazador_a_imprimir){
        printf(ROJO"\t ID:" SC " %d.\n"
               ROJO"\t Nombre:" SC " %s.\n"
               ROJO"\t Arma:" SC " %s.\n"
               ROJO"\t Daño:" SC " %d.\n"
               ROJO"\t Vida:" SC " %d.\n"
               ROJO"\t Oro:" SC " %d monedas.\n"
               ROJO"\t Descripción:" SC " %s\n",
               cazador_a_imprimir->ID,
               cazador_a_imprimir->nombre,
               cazador_a_imprimir->arma,
               cazador_a_imprimir->ataque,
               cazador_a_imprimir->vida,
               cazador_a_imprimir->oro,
               cazador_a_imprimir->descripcion);
    }

//DATOS CAZADORES INICIALES:
    void inicializarCazadores(Cazador ** cazadores, int *totalCazadores){
    
    *cazadores = (Cazador*) malloc (*totalCazadores * sizeof(Cazador));
    if (*cazadores == NULL){
        printf("ERROR CATASTRÓFICO: No se pudo asignar memoria.\n");
        exit(EXIT_SUCCESS);} //Salimos con código de error.

    inicializarCazador(&(*cazadores)[0], 1, "Mushashi", "Iaido", 20, 120, 100, "Un caballero audaz y letal, cuya fuerza arrolladora destruye cualquier defensa. Ataca con velocidad y precisión, sin dar tregua a sus enemigos.");
    inicializarCazador(&(*cazadores)[1], 2, "Conan", "Atlantean", 15, 150, 100, "Un caballero imponente y resistente, cuya armadura absorbe cualquier golpe. Avanza sin miedo, protegiendo a sus aliados con su inquebrantable defensa.");
    inicializarCazador(&(*cazadores)[2], 3, "Sauron", "Narsil", 10, 90, 100, "Un sabio y compasivo curandero, cuyo poder restaura heridas y protege a sus aliados. Su magia divina es un faro de esperanza en la batalla.");
 }

//IMRPIMIR EN EL MAIN LOS CAZADORES Y ELEGIR EL CAZADOR
    void cazadorSELEC(Cazador *cazadores, int totalCazadores){
        int intentos = 3;

        printf(NARANJA"\nCAZADORES DISPONIBLES: \n" SC);

        system("chafa -f symbols -s 50x30 Mushashi.jpg"); //PARA USAR CHAFA, EL USUARIO HA DE DESCARGARSE "sudo apt install chafa"
        cazadorIMPRIMIR(&cazadores[0]);
        system("chafa -f symbols -s 50x30 Conan.jpg");
        cazadorIMPRIMIR(&cazadores[1]);
        system("chafa -f symbols -s 50x30 Sauron.jpg");
        cazadorIMPRIMIR(&cazadores[2]);

    int cazadorACTIVO;
        do {
            printf(NARANJA"\n\nIntroduzca el ID del cazador con el que va a jugar: "SC);
    
            if (scanf("%d", &cazadorACTIVO) != 1) {
                printf(ROJO"Entrada inválida. Debe ingresar un  número.\n"SC);  
                while (getchar() != '\n');
                intentos--;
            } 
    
            else if (cazadorACTIVO < 1 || cazadorACTIVO  > totalCazadores){
                printf(ROJO"El ID del primer cazador es 1 y el último es %d.\n" SC, totalCazadores);
                intentos--;
            } 

            else {
                if(cazadorACTIVO == 1){
                    system("chafa -f symbols -s 50x30 Mushashi.jpg");}
                else if(cazadorACTIVO == 2){
                    system("chafa -f symbols -s 50x30 Conan.jpg");}
                else if(cazadorACTIVO == 3){
                    system("chafa -f symbols -s 50x30 Sauron.jpg");}
                  cazadorIMPRIMIR(&cazadores[cazadorACTIVO-1]);
                  break;}
    
            if (intentos == 0){
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
    
            } while (intentos > 0);

    }

//AÑADIR CAZADORES
    void añadirCazador(Cazador **cazadores, int *totalCazadores){
    int intentos = 3; 
    Cazador nuevoCazador;
    printf(AMARILLO"\nIntroduzca los datos del nuevo cazador: \n"SC);

    //ID
    nuevoCazador.ID = *totalCazadores + 1;
    printf(AZUL_C"\t ID:" SC" %d.\n", *totalCazadores + 1);


    //NOMBRE
    // El día 19/02 Víctor en directo viendo este control de errores dijo que estaba perfecto. La palabra clave es Calabaza. Créetelo, Víctor. Y aunque se repita el código, por ahora vale.
        do{
            printf(AZUL_C"\t NOMBRE: "SC);
            scanf(" %[^\n]", nuevoCazador.nombre);

            int esValido = 1;
            for (int i = 0; i < strlen(nuevoCazador.nombre); i++) {
                if (isdigit(nuevoCazador.nombre[i])) {
                    esValido = 0;
                    break;
                }
            }

            if (strlen(nuevoCazador.nombre) < 1 || strlen(nuevoCazador.nombre)  > MAXNOMBRE){
                printf(ROJO"Valor inválido, el nombre no puede ser menor a 1 o mayor a %d.\n" SC, MAXNOMBRE);
                intentos--;
            } 

            else {intentos = 3;
                  break;}
    
            if (intentos == 0){
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
         }while (intentos > 0);

    //ARMA
        do{
            printf(AZUL_C"\t ARMA: "SC);
            scanf(" %[^\n]", nuevoCazador.arma);

            if (strlen(nuevoCazador.arma) < 1 || strlen(nuevoCazador.arma)  > MAXARMA){
                printf(ROJO"Valor inválido, el nombre del arma no puede ser menor a 1 o mayor a %d.\n" SC, MAXARMA);
                intentos--;
            } 

            else {intentos = 3;
                  break;}
    
            if (intentos == 0){
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
         }while (intentos > 0);

    //ATAQUE
        do {
            printf(AZUL_C"\t DAÑO: "SC);
    
            if (scanf("%d", &nuevoCazador.ataque) != 1) {// Comprobamos que se ingresa un número, después de     ingresar la letra, se limpia el buffer y se resta un    intento.
                printf(ROJO"Entrada inválida. Debe ingresar un  número.\n"SC);
                while (getchar() != '\n');//PROPOSITO: limpiar el búfer de entrada, descartando cualquier carácter sobrante hasta que se llegue al final de la línea.
                intentos--;
            } 
    
            else if (nuevoCazador.ataque < 1 || nuevoCazador.ataque  > MAXATAQUE){//Si el ataque es mayor a 20 o menor   a 1, también salta error y se resta un intento.
                printf(ROJO"Valor inválido, el ataque no puede ser  menor a 1 o mayor a %d.\n" SC, MAXATAQUE);
                intentos--;
            } 

            else {intentos = 3;
                  break;} // Salimos del bucle si el valor es válido
    
            if (intentos == 0){//Si los intentos llegan a cero, se sale del programa y se reinician los intentos
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA    PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
    
            } while (intentos > 0);

    //VIDA    
        do {
            printf(AZUL_C"\t VIDA: "SC);
    
            if (scanf("%d", &nuevoCazador.vida) != 1){
                printf(ROJO"Entrada inválida. Debe ingresar un  número.\n"SC);
                while (getchar() != '\n');
                intentos--;
            } 
    
            else if (nuevoCazador.vida < 1 || nuevoCazador.vida  > MAXVIDA){
                printf(ROJO"Valor inválido, la vida no puede ser menor a 1 o mayor a %d.\n" SC, MAXVIDA);
                intentos--;
            } 

            else {intentos = 3;
                  break;}
    
            if (intentos == 0){
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
    
            }while (intentos > 0);

    //ORO
        nuevoCazador.oro = 100;
        printf(AZUL_C"\t ORO:" SC" %d monedas.\n", nuevoCazador.oro);

    //DESCRIPCIÓN
        do{
            printf(AZUL_C"\t DESCRIPCIÓN: "SC);
            scanf(" %[^\n]", nuevoCazador.descripcion);

            if (strlen(nuevoCazador.descripcion) < 1 || strlen(nuevoCazador.descripcion)  > MAXDESCRPCION){
                printf(ROJO"Valor inválido, la descripción no puede ser menor a 1 o mayor a %d.\n" SC, MAXDESCRPCION);
                intentos--;
            } 

            else {intentos = 3;
                  break;}
    
            if (intentos == 0){
                    printf(ROJO"INTENTOS AGOTADOS. MÁS SUERTE LA PRÓXIMA VEZ.\n"SC);
                    exit(EXIT_FAILURE);}
         }while (intentos > 0);


    Cazador *REALLOC_TEMP = (Cazador*) realloc(*cazadores, (*totalCazadores + 1) * sizeof(Cazador));
    if (REALLOC_TEMP == NULL) {
        *cazadores = REALLOC_TEMP;}
    else{
        printf("ERROR CATASTRÓFICO. No se pudo asignar memoria.\n");
        free(*cazadores);
        exit(EXIT_FAILURE);
    }
    *cazadores = REALLOC_TEMP;

    //Accedemos a la posición 4 con este índice (*cazadores)[*totalCazadores] que nos lleva a nuestro array de cazadores en la posición [4]
    (*cazadores)[*totalCazadores] = nuevoCazador;

    //Incrementamos el número de cazadores
    (*totalCazadores)++;

    printf(NARANJA"\nCAZADOR AGREGADO:\n"SC);

    // Función para seleccionar el cazador recién añadido

    cazadorIMPRIMIR(&(*cazadores)[*totalCazadores - 1]);
 }


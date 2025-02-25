#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXNOMBRE 50
#define MAXARMA 20
#define MAXATAQUE 20
#define MAXVIDA 100
#define MAXORO 600
#define MAXDESCRPCION 200


//STRUCT DATOS CAZADOR;   
    typedef struct{
        int ID;
        char nombre[MAXNOMBRE + 1];
        char arma[MAXARMA + 1];
        int ataque;
        int vida;
        int oro;
        char descripcion[MAXDESCRPCION + 1];
    } Cazador;

void inicializarCazador (Cazador * datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion);

void cazadorIMPRIMIR (const Cazador * cazador_a_imprimir);

void inicializarCazadores(Cazador ** cazadores, int *totalCazadores);

void cazadorSELEC(Cazador *cazadores, int totalCazadores);

void añadirCazador(Cazador **cazadores, int *totalCazadores);


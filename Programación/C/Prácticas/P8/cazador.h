#ifndef CAZADOR_H
#define CAZADOR_H

//Máximo de dragones y cazadores
#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 1000
#define MAX_DRAGONES 3
#define MAXNOMBRE 50
#define MAXARMA 20
#define MAXATAQUE 20
#define MAXVIDA 100
#define MAXORO 600
#define MAXDESCRIPCION 200
#define MAXDESC 256 


//STRUCT DATOS CAZADOR;   
    typedef struct {
    int ID;
    char nombre[MAXNOMBRE + 1];
    char arma[MAXARMA + 1];
    int ataque;
    int vida;
    int oro;
    int defensa;
    char descripcion[MAXDESCRIPCION + 1];
    int frascosPequenos;
    int frascosGrandes;
    int espadaMejorada;
} Cazador;

void inicializarCazador(Cazador *datos, int ID, const char *nombre, const char *arma, int ataque, int vida, int oro, const char *descripcion);
void cazadorIMPRIMIR(const Cazador *cazador_a_imprimir);
void inicializarCazadores(Cazador **cazadores, int *totalCazadores);
void cazadorSELEC(Cazador *cazadores, int totalCazadores, Cazador **seleccionado);
void añadirCazador(Cazador **cazadores, int *totalCazadores);

#endif
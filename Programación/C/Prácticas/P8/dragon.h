#ifndef DRAGON_H
#define DRAGON_H


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


typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    int vida;
    int ataque;
    int resistencia;
    char pasiva[MAX_DESCRIPCION];
    char descripcion[MAX_DESCRIPCION];
    int oro;
} Dragon;

void inicializarDragon(Dragon *dragon, int id, char *nombre, int vida, int ataque, int resistencia, char *pasiva, char *descripcion, int oro);
void mostrarDragon(Dragon *dragon);
void seleccionarDragon(Dragon *dragones, int totalDragones, Dragon **seleccionado);
void visualizarDragones(Dragon **dragones, int *totalDragones);
void añadir_dragon(Dragon **dragones, int *totalDragones);

#endif
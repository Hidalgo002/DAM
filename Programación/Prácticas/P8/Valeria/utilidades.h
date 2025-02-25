// Colores estándar ANSI
#define NEGRO     "\033[30m"
#define ROJO      "\033[31m"
#define VERDE     "\033[32m"
#define AMARILLO  "\033[33m"
#define AZUL      "\033[34m"
#define MAGENTA   "\033[35m"
#define CIAN      "\033[36m"
#define BLANCO    "\033[37m"

// Colores personalizados RGB
#define NARANJA   "\033[38;2;255;128;0m"
#define ROSA      "\033[38;2;255;151;203m"
#define AZUL_C    "\033[38;2;53;149;240m"
#define VERDE_C   "\033[38;2;17;245;120m"
#define GRIS      "\033[38;2;176;174;174m"
#define VIOLETA   "\033[38;2;148;0;211m"
#define MARRON    "\033[38;2;139;69;19m"
#define TURQUESA  "\033[38;2;64;224;208m"
#define DORADO    "\033[38;2;255;215;0m"
#define LIMA      "\033[38;2;50;205;50m"
#define CELESTE   "\033[38;2;135;206;250m"
#define LAVANDA   "\033[38;2;230;230;250m"
#define SALMON    "\033[38;2;250;128;114m"
#define CHOCOLATE "\033[38;2;210;105;30m"

// Reset (para volver al color original)
#define SC        "\033[0m"

//AÑADIDO VALERIA

#include <stdio.h>
#include <stdlib.h>

void BIENVENIDA();
void MENU();

//Cursiva:
#define CURSIVA "\033[3m"

//TIENDA
#define TOTAL_PRODUCTOS 4 

typedef struct{
    	int vidas;
    	int vida_precio;
		char arma_N [MAXARMA + 1];
		int arma_ataque;
		int arma_precio;
    } Tienda;






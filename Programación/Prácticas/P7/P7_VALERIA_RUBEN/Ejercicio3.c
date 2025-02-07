#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LARGO 10 //i
#define MAX_ANCHO 10 //j

int main(){
    int i = MAX_LARGO / 2; 
	int j = MAX_ANCHO / 2;  // Inicialización de la posición del # en la mitad del tablero
	char tablero[MAX_LARGO][MAX_ANCHO]; //Marcamos las medidas del tablero

	for(int i = 0; i<MAX_LARGO;i++){
		for(int j = 0; j<MAX_ANCHO;j++){ //MATRIZ
			//PIEZA EN EL MEDIO
			if(i == MAX_LARGO/2 && j == MAX_ANCHO/2){ //Colocamos la pieza en el medio
				tablero[i][j] = '#'; //Pieza posicionada
			}
			else{
				tablero[i][j] = '*'; //El resto de casillas serán rellanadas con asteriscos
			}
	}
}
while(1){

	int bandera = 0;

	for(int i = 0; i<MAX_LARGO;i++){ //Impresión del tablero
			for(int j = 0; j<MAX_ANCHO;j++){
				printf("%c", tablero[i][j]);
			}
		printf("\n");
	}

	char mov;
	printf("Elija su próximo movimiento(W,S,A,D)(Pulse Q si desea salir): ");
	scanf(" %c", &mov);

	if (mov == 'Q' || mov == 'q' ){
		printf("¡GRACIAS POR JUGAR!\n");
			break;
		}

	tablero[i][j] = '*'; //Limpia la celda anterior rellenandola con un asterisco.

		if ((mov == 'W' || mov == 'w') && i > 0 ){//0 porque el borde al que puede acceder w es 0
			i--;
		}
		else if ((mov == 'S' || mov == 's') && i < MAX_ANCHO - 1){//i<MX_Acnho -1 es 9. cuando i sea menor a 9, entonces parará el programa de admitir el movimiento
			i++;
		}
		else if ((mov == 'A' || mov == 'a') && j > 0){
			j--;
		}
		else if ((mov == 'D' || mov == 'd') && j < MAX_LARGO - 1){
			j++;
		}
		else{bandera = 1;}

		tablero[i][j] = '#';
		system("clear"); //Despues de cada iteración del bucle, empezamos limpiando el tablero}

	if(bandera == 1){
		printf("MOVIMIENTO NO VÁLIDO. JUEGA LIMPIO. \n");
	}


	}//Cierre While
return 0;
}


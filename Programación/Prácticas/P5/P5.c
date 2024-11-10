#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCTOS 10
#define LONGITUD_NOMBRE 21
#define MAX_PROD 1000
int main(){
	int num;
	char nombre[PRODUCTOS][LONGITUD_NOMBRE];	
	int cantidad[MAX_PROD];

	//1.Pedimos al usuario la cantidad de productos que va a gestionar
	printf("Introduce el número de prodcutos que va a gestionar: ");
	scanf(" %d", &num); 
	
	//2.
	if(num >= 10){
		printf("Solo se pueden gestionar 10 productos a la vez.\n");}
	else{
		for(int i = 0; i<num; i++){
	printf("Introduce el nombre del producto %d: ", i + 1);
	scanf(" %s", nombre[i]);

	printf("Introduce la cantidad de %s: ", nombre[i]);
        scanf(" %d", &cantidad[i]);}
	
	
	//INVENTARIO:
	char* ud;
	printf("Inventario Completo:\n");
		//Declara unidad o unidades
		for(int i = 0; i<num; i++){
		ud = (cantidad[i]==1) ?"unidad" : "unidades";	
		printf("\tProducto %d: %s - %d %s\n", i + 1, nombre[i], cantidad[i], ud);}

	//REABASTECIMIENTO DE UN PRODUCTO
	char respuesta[3];
	printf("¿Desea reabastecer algún producto? (sí/no): ");
	scanf(" %s", respuesta);
	
	int mod; //Almacena el número de objetos a modificar en el inventario.
	if (strcmp(respuesta, "no") == 0 || strcmp(respuesta, "No") == 0){
	printf("No se procederá al reabastecimiento del producto.\n");}
	
	else if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Sí") == 0 || strcmp(respuesta, "Sí")|| strcmp(respuesta, "Sí")){
		printf("Introduzca el número de productos que va a modificar:  ");
		scanf(" %d", &mod);}
		
		if (mod >= 10){
                printf("Solo se pueden gestionar 10 productos a la vez.\n");}
        	else{
                	for(int i = 0; i<mod; i++){
        		printf("Introduce el nombre del producto %d: ", i + 1 );
        		scanf(" %s", nombre[i]);

        		printf("Introduce la cantidad de %s: ", nombre[i]);
       			scanf(" %d", &cantidad[i]);}}

	
	
	}	
return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PRODUCTOS 10
#define LONGITUD_NOMBRE 21
#define MAX_PROD 1000
#define STOCK_MIN 5


int main(){
	int num; //Número de productos que se pide al usuario
	char nombre2[LONGITUD_NOMBRE]; // Nombre de producto para reabastecer
	char nombre[PRODUCTOS][LONGITUD_NOMBRE]; // Lista de productos
	int cantidad[MAX_PROD]; // Cantidad de productos en stock
	int cantidadnueva[MAX_PROD]; // Cantidad a añadir en el reabastecimiento
	char respuesta[3]; // Respuesta del usuario para reabastecer

    // 1. Pedimos al usuario la cantidad de productos que va a gestionar
	printf("Introduce el número de productos que va a gestionar: ");
	scanf("%d", &num);

	if (num > PRODUCTOS){
		printf("Solo se pueden gestionar 10 productos a la vez.\n");}
	else {
	for (int i = 0; i < num; i++){ //Pedimos en bucle el nombre del producto + la cantidad hasta el número ingresado por el usuario
	printf("Introduce el nombre del producto %d: ", i + 1);
	scanf(" %s", nombre[i]);
	    
	printf("Introduce la cantidad de %s: ", nombre[i]);
	scanf(" %d", &cantidad[i]);}

        // INVENTARIO:
	printf("Inventario Completo:\n");

	for (int i = 0; i < num; i++){ //Ternario para determinirar Unidad o Unidades
		char *ud = (cantidad[i] == 1) ? "unidad" : "unidades";
		printf("\tProducto %d: %s - %d %s\n", i + 1, nombre[i], cantidad[i], ud);}

        //3. REABASTECIMIENTO DE PRODUCTOS:

	printf("¿Desea reabastecer algún producto? (sí/no): ");
	scanf(" %s", respuesta);

	if (strcmp(respuesta, "sí") == 0){ //Solo acepta el si con tilde, otra cosa no.
		printf("Ingrese el nombre del producto a reabastecer: ");
		scanf(" %s", nombre2);
	
	//Abrimos una variable nueva para guardar la cantidad del producto a añadir
	int productoNuevo = 0; 
		for (int i = 0; i < num; i++){
			if (strcmp(nombre[i], nombre2) == 0){ //Se compara el nombre ingresado con los que tenemos almacenados en el array de nombre. Si no está, se salta esta parte
			printf("Cantidad a añadir: "); //Pedimos la cantidad nueva
			scanf(" %d", &cantidadnueva[i]);//Guardamos en la cantidad a sumar
			cantidad[i] += cantidadnueva[i]; // Sumamos la cantidad nueva a la cantidad anterior. Se guarda en cantidadnueva[i]
		} //Cerramos el ir del comparación de nombres
		} //Cerramos el bucle for
		} //Cerramos el if de responder que si al reabastecimiento de productos  

	else{ //cualquier cosa que no sea sí con tilde, será que no.
	printf("No se procederá al reabastecimiento de ningún producto.\n");}

        // 4.CÁLCULO DE PRODUCTOS EN BAJA EXISTENCIA
	printf("\nProductos en baja existencia (menos de 5 unidades):\n");
	for (int i = 0; i < num; i++){
		if (cantidad[i] < STOCK_MIN){ //Recorremos el array de nuestras cantidades, actualizado de la suma anterior, si hay un producto por debajo de DEFINE STOCK_MIN 5, saldrá aquí
		char *ud = (cantidad[i] == 1) ? "unidad" : "unidades";
		printf("\tProducto %d: %s - %d %s\n", i + 1, nombre[i], cantidad[i], ud);}
	}// \t para espacio antes del la linea

        //5. BÚSQUEDA DE PRODUCTOS ESPECÍFICA
	printf("Ingrese el nombre del producto a buscar: ");
	scanf(" %s", nombre2);

	int producto_buscar = 0; // Inicializamos en 0 la variable de producto_buscar, el bucle irá comparando los nombres de los productos hasta que sea igual al nombre ingresado en nombre2
	for (int i = 0; i < num; i++){
	if (strcmp(nombre[i], nombre2) == 0){ //Se comparan los nombres dentro del bucle
	char *ud = (cantidad[i] == 1) ? "unidad" : "unidades"; //Hemos utilizado un * que es un puntero por comodidad.
	printf("Cantidad en stock: %d %s\n",  cantidad[i], ud);
	producto_buscar = 1;} // Producto encontrado

	else{
	printf("NO EXISTE.\n");}

	}//cerrar for
	//6.EXAMEN
	int cantidadnueva2[MAX_PROD];	
	char nombre3[LONGITUD_NOMBRE];
	printf("¿Desea eliminar algún producto? (sí/no): ");
	scanf(" %s", respuesta);
	if (strcmp(respuesta, "sí") == 0){
		printf("Ingrese el nombre del producto a eliminar: ");
		scanf(" %s", nombre3); 
		int productoNuevo2 = 0;

		for (int i = 0; i < num; i++){

		if (strcmp(nombre[i], nombre3) == 0){
			printf("Cantidad a restar: ");
			scanf(" %d", &cantidadnueva2[i]);
		if(cantidadnueva2[i] > cantidad[i]);
			printf("ERROR \n");} 
		else{
			cantidad[i] -= cantidadnueva2[i];
			printf("La cantidad nueva es: %d \n)", cantidad[i]);
		}}}
	else{printf("ERROR.\n");}
	}//CERRAR LA FUNCIÓN DEL INICIO, EL ELSE PARA PEDIR CANTIDAD	
return 0;
}


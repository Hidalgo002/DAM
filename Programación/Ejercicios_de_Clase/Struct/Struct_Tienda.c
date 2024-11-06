#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Proveedor{
	char nombre[20];
	char direccion[20];
	char telefono[15];
} Proveedor;

typedef struct Articulo{
	char nombre[20];
	float precio;
	Proveedor proveedor;
} Articulo;

typedef struct Inventario{
	Articulo articulos[MAX_ITEMS];
	int totalArticulos;
	int cantidades[MAX_ITEMS];
} Inventario;

int main(){
	Articulo articulo = {"nombre", 10,{"nombre", "direccion", "telefono"}}; //Metido a mano. Lo que se imprime en el terminal
	Inventario miInventario; //Variable tipo Inventario llamada miInventario
	
	miInventario.articulos[0] = articulo; //Inicializamos el artículo en 0, siendo artículo los datos que hemos metido en Articulo articulo = {...}
	miInventario.cantidades[0] = 10; //Asignar un valor al array de cantidades
	
	printf("Nombre artículo: %s\n", miInventario.articulos[0].nombre);
	printf("Cantidades: %d\n", miInventario.cantidades[0]);
	printf("Nombre proveedor: %s\n", miInventario.articulos[0].proveedor.nombre);


return 0;
}

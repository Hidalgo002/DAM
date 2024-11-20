#include <stdio.h>
#include <stdlib.h>

// Definición de dimensiones
 #define CONTINENTES 2     // Maximo 2, pq el ejercicio te dice America y Europa
 #define SEDES 3           // Maximo 3,"                                        "
 #define CATEGORIAS 4      // Maximo 4 pq en el ejercicio solo hay 4 categorias(Televisores, Telefonos, Ordenadores, Electrodomesticos)
 #define MODELOS 5         // ...
 #define LOTES 10          // ...

 int main() {
    	
	 // Declaro el array de 5 dimensiones para almacenar el inventario y el 0 es para inicializar, es decir todas comienzan desde el 0.

         int inventario[CONTINENTES][SEDES][CATEGORIAS][MODELOS][LOTES] = {0};

             // El valor no importa siempre y cuando no supere el limite declarado en #define, las unidades pueden ser numeros muy
	     // grande ya que su limite no esta definido.
	     // Como son 5 dimensiones, necesitaremos si o si 5 ejemplos, ni 4 ni 6, 5.
	     // Se leeria asi: inventario[continente][sedes][categorias][modelos][lotes] = {0}  
	  

	   //inventario[America][segunda sede][categoria tv][modelo3][lote1] = 150 unidades
	   
             inventario[0][1][0][3][1] = 150;   
             inventario[1][0][1][3][2] = 20;  
             inventario[0][2][2][1][5] = 100;  
             inventario[1][0][3][4][9] = 175;   
             inventario[0][1][1][2][4] = 130;
	     inventario[1][1][0][1][10] = 200;   

             
             printf("Unidades en America(0), sede 2, categoria televisores, modelo 3, lote 1: %d\n", inventario[0][1][0][3][1]);
             printf("Unidades en Europa(1), sede 1, categoria teléfonos, modelo 3, lote 2: %d\n", inventario[1][0][1][3][2]);
             printf("Unidades en America(0), sede 3, categoria ordenadores, modelo 1, lote 5: %d\n", inventario[0][2][2][1][5]);
             printf("Unidades en Europa(1), sede 1, categoria electrodomésticos, modelo 4, lote 9: %d\n", inventario[1][0][3][4][9]);
             printf("Unidades en America(0), sede 2, categoria teléfonos, modelo 2, lote 4: %d\n", inventario[0][1][1][2][4]);
	     printf("Unidades en Europa(1), sede 2, categoria teléfonos, modelo 1, lote 10: %d\n", inventario[1][1][0][1][10]);
             

	     //AUMENTAR EL STOCK
	     int cantidadnueva;
		printf("Introduzca una cantidad para reabastecer los teléfonos: ");
	   	scanf("%d", &cantidadnueva);
		inventario[1][1][0][1][10] = 200 + cantidadnueva;
		printf("La cantidad nueva es: %d\n", inventario[1][1][0][1][10]);	
	     return 0;
 }

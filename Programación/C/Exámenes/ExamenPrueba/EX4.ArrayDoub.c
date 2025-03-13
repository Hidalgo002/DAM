#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Solicitar al usuario un número entero positivo
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);
    
    // Verificar que el número sea positivo
    if (n <= 0) {
        printf("El número debe ser un entero positivo.\n");
        return 1;
    }
    
    // Reservar memoria dinámicamente para el array
    double *array = (double *)malloc(n * sizeof(double));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    // Inicializar el array con la fórmula valor[i] = 1 / (i + 1)
    for (int i = 0; i < n; i++) {
        array[i] = 1.0 / (i + 1);
    }
    
    // Imprimir el contenido del array
    printf("Contenido del array inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %lf\n", i, array[i]);
    }
    
    // Aumentar el tamaño del array al doble
    int nuevo_tamano = 2 * n;
    double *nuevo_array = (double *)realloc(array, nuevo_tamano * sizeof(double));
    if (nuevo_array == NULL) {
        printf("Error al reasignar memoria.\n");
        free(array);
        return 1;
    }
    array = nuevo_array;
    
    // Completar los nuevos valores con la misma fórmula
    for (int i = n; i < nuevo_tamano; i++) {
        array[i] = 1.0 / (i + 1);
    }
    
    // Imprimir el contenido del array después de la expansión
    printf("Contenido del array expandido:\n");
    for (int i = 0; i < nuevo_tamano; i++) {
        printf("array[%d] = %lf\n", i, array[i]);
    }
    
    // Liberar la memoria asignada dinámicamente
    free(array);
    
    return 0;
}

/*1. ¿Qué ocurre en la memoria cuando usamos `realloc()` para expandir un array? ¿Se conservan los valores anteriores? ¿Siempre se puede expandir en el mismo bloque de memoria o se busca un espacio nuevo obligatoriamente? Consulta las direcciones de memoria para consultarlo.
    1. *Pista:  printf(”%p” , direccion_de_memoria);  para imprimir direcciones de memoria.**/

 /*RESPUESTA: 
 Cuando usamos realloc() para expandir un array en C, ocurren varias cosas a nivel de memoria:

Conservación de valores:

Si realloc() puede expandir el bloque de memoria en su ubicación actual, los valores anteriores se conservan.
Si realloc() no puede expandir el bloque en su ubicación actual (porque el espacio contiguo está ocupado), se asigna un nuevo bloque de memoria en otro lugar, se copian los datos al nuevo bloque y el anterior se libera automáticamente.
¿Siempre se expande en el mismo bloque?

No, realloc() intenta expandir en el mismo bloque si hay espacio contiguo disponible.
Si no hay suficiente espacio contiguo, busca una nueva ubicación con suficiente memoria. */   

/*Si la dirección es la misma antes y después de realloc(), significa que la memoria se expandió en el mismo lugar.
Si la dirección cambió, significa que se asignó un nuevo bloque y se copiaron los datos.*/
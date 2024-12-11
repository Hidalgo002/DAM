#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
    /*int *p = (int *)malloc(sizeof(int));
    Aquí hay un casting implícito. malloc devuelve un void*. Hay que convertirlo
    para poder utilizarlo
    */

    //ESTA ES LA BUENA PRÁCTICA:
    int *p = (int *)malloc(sizeof(int)); // Reservar espacio para un int
    
    *p = 42; // Usamos la memoria
    printf("El valor es: %d\n", *p);

    if (p == NULL){//Malloc ha fallado porque no hay memoria disponible
        printf("Error: no se pudo asignar memoria.\n");
        return 1; //EL programa ha fallado
    }

free(p); // Liberamos la memoria reservada
return 0;
}



#include <stdio.h>
#include <stdlib.h>


/*7. **Lectura de una cadena desconocida:**
    
    Pide al usuario que introduzca una cadena sin límite fijo, asígnale memoria de forma dinámica y luego imprímela.*/

int main(){

	int n;

	printf("Introduce el tamaño de la cadena: ");
	scanf("%d",&n);

	char * cadena = (char *) malloc((n+1)*sizeof(char));//+1 por el cero del final

	if (cadena == NULL) {
        printf("ERROR: no se pudo asignar memoria.\n");
        return 1;
    }
   
	printf("Introduce una cadena de carácteres: ");
	scanf("%s", cadena);

	printf("Cadena: %s\n", cadena);


free(cadena);

return 0;
}

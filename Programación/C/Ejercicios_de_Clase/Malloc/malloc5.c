#include <stdio.h>
#include <stdlib.h>


/*8. **Reasignación con realloc (aumento):**
    
    Crea un arreglo dinámico pequeño y luego usa `realloc` para aumentarlo y agregar más datos*/

int main(){
	int n; //Número de alumnos
	printf("Vamos a guardar las edades de una clase.\n");
	printf("Introduce el número de alumnos: ");
	scanf("%d", &n);

	int * arr = (int *) malloc(n*sizeof(int));

	if(arr == NULL){
		printf("ERROR: no se pudo asignar memoria.\n");
		return 1;
	}
	printf("CLASE A.\n");
	for(int i = 0; i<n;i++){
		printf("Alumno Nº %d: ",i+1);
		scanf("%d", arr);
	}

	printf("Vamos a pasar al siguiente curso.\n");
	int n2 = n*2;
	int * arr2 = (int *) realloc(arr, n2*sizeof(int));


	if(arr == NULL){
			printf("ERROR: no se pudo asignar memoria.\n");
			free(arr);
			return 1;
		}

	arr = arr2;
		printf("CLASE B.\n");
		for(int i = 0; i<n2;i++){
		printf("Alumno Nº %d: ",i+1);
		scanf("%d", arr);
		
	}

free(arr);
return 0;
}	
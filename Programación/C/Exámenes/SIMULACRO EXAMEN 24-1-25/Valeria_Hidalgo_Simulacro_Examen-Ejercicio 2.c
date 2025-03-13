#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main(){
	float n;
	printf("Introduzca el tamaño del array: ");
	scanf("%f", &n);

		float *ARR;

		ARR = (float*) malloc(n*sizeof(float));
		
		printf("\33[35mArray solicitado:\33[0m \n");

		for(int i =0; i<n; i++){
			ARR[i] = i/n;
			printf("\tPosición %d: %d/%.0f = %.4f\n", i,i,n, ARR[i]);
		}


		ARR = (float*) realloc(ARR, (n/2)*sizeof(float));

		printf("\33[36mArray reducido:\33[0m \n");

		for(int i =0; i<n; i++){
			ARR[i] = i/n;
			printf("\tPosición %d: %d/%.0f = %.4f\n", i,i,n, ARR[i]);
		}

	

	free(ARR);

return 0;
}
#include <stdio.h>
#include <stdlib.h>

void rellenar_array(int * arr, int tamano, int multiplo){
    for (int i = 0; i < tamano; i++){
        arr[i] = (i + 1) * multiplo;
    }
}

void imprimir_array(int * arr, int tamano){
    for (int i = 0;i < tamano;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tamano1;
    int tamano2;
    int multiplo1 = 1;
    int multiplo2 = 2;
    char opcion;

    //ARRAY 1
    printf("Introduzca el tamaño del primer array: ");
    scanf("%d", &tamano1);

    int *ARR1 = (int*) malloc (tamano1 * sizeof(int));
        if (ARR1 == NULL) {
                printf("ERROR CATASTRÓFICO, NO SE PUDO RESERVAR MEMORIA.\n");
                return 1;
            }

    rellenar_array(ARR1, tamano1, multiplo1);

    printf("ARRAY 1: ");

    imprimir_array(ARR1, tamano1);

    //ARRAY 2
    printf("Introduzca el tamaño del segundo array: ");
    scanf("%d", &tamano2);

    int *ARR2 = (int*) malloc (tamano2 * sizeof(int));
        if (ARR2 == NULL) {
            printf("ERROR CATASTRÓFICO, NO SE PUDO RESERVAR MEMORIA.\n");
            free(ARR1);
            return 1;
        }

    rellenar_array(ARR2, tamano2, multiplo2);

    printf("ARRAY 2: ");

    imprimir_array(ARR2, tamano2);

//FUNCIONES
    printf("¿Quiere concatenar o sumar los arrays?: ('s' o 'c'): ");
    scanf(" %c", &opcion);

// SUMAR
    if (opcion == 's') {

        int tamanoC;
            if(tamano1>tamano2){
                tamanoC = tamano1;
            }
            else (tamanoC = tamano2);

        int * Suma_ARR = (int*) malloc (tamanoC * sizeof(int));
            if  (Suma_ARR == NULL){
                printf("ERROR CATASTRÓFICO, NO SE PUDO RESERVAR MEMORIA.\n");
                free(ARR1);
                free(ARR2);
                return 1;
            }
        for (int i = 0; i < tamanoC; i++) {
            Suma_ARR[i] = ARR1[i] + ARR2[i];
        }
        printf("Resultado de la suma coordenada a coordenada: ");
        imprimir_array (Suma_ARR, tamanoC);

    free (Suma_ARR);} 


 // CONCATENAR   
    else if (opcion == 'c') {
     
        int *Concat_ARR = (int*) malloc ((tamano1 + tamano2) * sizeof(int));
            if (Concat_ARR == NULL){
                printf("ERROR CATASTRÓFICO, NO SE PUDO RESERVAR MEMORIA.\n");
                free(ARR1);
                free(ARR2);
                return 1;
            }

                for (int i = 0;i < tamano1;i++) {
                    Concat_ARR[i] = ARR1[i];}

                for (int i = 0; i < tamano2;i++) {
                    Concat_ARR[tamano1 + i] = ARR2[i];}


        printf("CONCATENACIÓN: ");
        imprimir_array(Concat_ARR, tamano1 + tamano2);
    
    free(Concat_ARR);} 

    
    else{printf("Opcion no válida. Saliendo del programa.\n");}


free(ARR1);
free(ARR2);
return 0;
}


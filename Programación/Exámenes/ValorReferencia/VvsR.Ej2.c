#include <stdio.h>
#include <stdlib.h>

//PASAR POR REFERENCIA

void duplicarReferencia(int *num){
    *num = *num * 2;
    printf("Referencia duplicada: %d\n", *num);
}
int main(){
    int num;
    printf("Introduzca un número para duplicarlo: ");
    scanf("%d",  &num);

    duplicarReferencia(&num);//Buscamos la dirección nueva de num

    printf("Num después de la función: %d\n", num);

return 0;  
}
/*Pregunta: ¿Cambia el valor original de la variable en main()?
    SÍ. Cuando trabajamos con punteros en el void, estamos buscando en todo
    momento trabajar con el mismo valor original, no con una copia.
    De echo, cuando llamamaos a la función en el main, buscamos la dirección
    nueva de num porque esta cambia su valor.
    
*/
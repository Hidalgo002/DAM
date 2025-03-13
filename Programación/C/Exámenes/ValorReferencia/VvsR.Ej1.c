#include <stdio.h>
#include <stdlib.h>

//PASAR POR VALOR:

void duplicarNum(int num){
    num = num *2;
    printf("Valor duplicado: %d\n", num);
}

int main(){
    int num;
    printf("Introduzca un número para duplicarlo: ");
    scanf("%d",  &num);

    duplicarNum(num);

    printf("Num después de la función: %d\n", num);
return 0;  
}

/*Pregunta: ¿Cambia el valor original de la variable en main()?
    NO. Realmente solo cambia en la función, una vez terminada el valor
    vuelve a su original. No tenemos que buscar los cambios ocn & ni punteros
    porque no se modifica el valor original
*/
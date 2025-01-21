#include <stdio.h>

int suma_recursiva(int arr[], int n) {
    // Caso base: si el arreglo tiene 0 elementos, la suma es 0
    if (n == 0) {
        return 0;//ESTE ES EL CASO BASE
    }
    // Caso recursivo: suma el último elemento y llama a la función con un elemento menos
    return arr[n - 1] + suma_recursiva(arr, n - 1);
}


int main() {


    int valores[] = {2, 4, 6, 8, 10, 20};

    int n = sizeof(valores) / sizeof(valores[0]);


    int resultado = suma_recursiva(valores, n);

    printf("La suma es: %d\n", resultado);


return 0;
}
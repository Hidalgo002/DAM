#include <stdio.h>

//6. Búsqueda binaria en un array ordenado


// Busca x en arr[l..r], devuelve la posición o -1 si no se encuentra
int busquedaBinaria(int arr[], int l, int r, int x) {
    if (l > r) return -1; // Caso base: no encontrado
    int m = (l + r) / 2;
    if (arr[m] == x) return m;
    else if (x < arr[m])
        return busquedaBinaria(arr, l, m-1, x);
    else
        return busquedaBinaria(arr, m+1, r, x); v
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    int pos = busquedaBinaria(arr, 0, n-1, x);
    if (pos != -1)
        printf("Encontrado %d en posicion %d\n", x, pos);
    else
        printf("No se encontro %d\n", x);
    return 0;
}


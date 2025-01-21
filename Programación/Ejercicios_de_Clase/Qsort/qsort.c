#include <stdio.h>
#include <stdlib.h> //Se incluye para usar funciones relacionadas con la memoria dinámica, conversiones, y, en este caso

// Comparison function
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);

  /*
  *(int*)a - *(int*)b: Devuelve:
    Un número negativo si a < b.
    Cero si a == b.
    Un número positivo si a > b.
  */
   /*
  EJEMPLO: 
  typedef struct {
      int id;
      float value;
      char name[50];
    } Data;

  Data* arr = malloc(n * sizeof(Data))
*/
  }
  /*ORDENAR POR ENTEROS
  int compareById(const void* a, const void* b) {
    const Data* da = (const Data*)a;
    const Data* db = (const Data*)b;
    return da->id - db->id;
}
*/
  /*ORDENAR POR FLOAT
  int compareByValue(const void* a, const void* b) {
    const Data* da = (const Data*)a;
    const Data* db = (const Data*)b;
    if (da->value < db->value) return -1;
    if (da->value > db->value) return 1;
    return 0;
}

  */

  /* ORDENAR POR CHAR
  #include <string.h> // Necesario para strcmp

  int compareByName(const void* a, const void* b) {
    const Data* da = (const Data*)a;
    const Data* db = (const Data*)b;
    return strcmp(da->name, db->name);
}

  */



int main() {
   int arr[] = {10, 5, 4, 6, 9};
   int n = sizeof(arr) / sizeof(arr[0]); //Almacenamos el número de elementos a tratar. LISTA_E->Notas

   qsort(arr, n, sizeof(int), compare);
   /*
    arr: Puntero al arreglo que se va a ordenar.
    n: Número de elementos en el arreglo.
    sizeof(int): Tamaño de cada elemento en el arreglo.
    compare: Puntero a la función de comparación que define el criterio de orden.

    INT-> qsort(arr, n, sizeof(Data), compareById);
    FLOAT-> qsort(arr, n, sizeof(Data), compareByValue);
    CHAR-> qsort(arr, n, sizeof(Data), compareByName);
*/

   printf("Following is the sorted array: ");
   
   for (int i = 0; i < n; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return 0;
}

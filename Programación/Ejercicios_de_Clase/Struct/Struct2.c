#include <stdio.h>
#include <string.h>

typedef struct Vehiculo{
	char marca [20];
	char modelo [20];
	int anio;
	int kilometraje;
}; Vehiculo;

int main() {

    struct Vehiculo miVehiculo;

    strcpy(miVehiculo.marca, "Toyota");
    strcpy(miVehiculo.modelo, "Corolla");
    miVehiculo.anio = 2021;
    miVehiculo.kilometraje = 15000;

    printf("Marca: %s\n", miVehiculo.marca);
    printf("Modelo: %s\n", miVehiculo.modelo);
    printf("Año: %d\n", miVehiculo.anio);
    printf("Kilometraje: %d km\n", miVehiculo.kilometraje);

    return 0;
}

#ifndef COMBATE_H
#define COMBATE_H

void MENU(Cazador **cazadores, int *totalCazadores, Dragon **dragones, int *totalDragones, int *opcionElegida);

void comenzarBatalla(Cazador *cazadores, int totalCazadores, Cazador **cazadorActivo, Dragon *dragones, int totalDragones);

#endif
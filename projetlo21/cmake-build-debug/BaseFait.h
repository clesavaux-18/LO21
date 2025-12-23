//
// Created by micro on 24/12/2025.
//

#ifndef BASEFAIT_H
#define BASEFAIT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem {
    int value;
    struct elem *next;
}element;
typedef element* listf;

listf insererQueue(listf l, int e);
listf supprimertout(listf l);
listf supprimer_element(listf l, int e);
listf insererTete (listf l, int e);
bool siVide(listf l);
bool recherche(listf l, int e);

#endif //BASEFAIT_H

//
// Created by micro on 24/12/2025.
//

#ifndef BASEFAIT_H
#define BASEFAIT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem {
    char value[1000];
    struct elem *next;
}element;
typedef element* listf;

listf insererQueue(listf l, char e[1000]);
listf supprimertout(listf l);
listf supprimer_element(listf l, char e[1000]);
listf insererTete (listf l, char e[1000]);
bool siVide(listf l);
bool recherche(listf l, char e[1000]);

#endif //BASEFAIT_H

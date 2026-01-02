//
// Created by aysse on 29/12/2025.
//

#ifndef BASEFAIT_H
#define BASEFAIT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemf {
    char value[1000];
    struct elemf *next;
}elementf;
typedef elementf* listf;

listf creeListeFaitVide();
listf insererQueue(listf l, char e[1000]);
listf supprimertout(listf l);
listf supprimer_element(listf l, char e[1000]);
listf insererTete (listf l, char e[1000]);
bool siVide(listf l);
bool recherche(listf l, char e[1000]);
void afficherListeFait(listf l);

#endif //BASEFAIT_H

//
// Created by aysse on 29/12/2025.
//

#ifndef BASECONNAISSANCE_H
#define BASECONNAISSANCE_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "regle.h"

typedef struct elemBC {
    regle *connaissance;
    struct elemBC *next;
} elementBC;

typedef elementBC * BaseConnaissance;

BaseConnaissance creerBaseConnaissanceVide();
bool estVideBaseConnaissance(BaseConnaissance BC);
BaseConnaissance insererQueueBaseConnaissance(BaseConnaissance BC, regle *e);
BaseConnaissance supprimerUNEBaseConnaissance(BaseConnaissance BC, regle *e);
BaseConnaissance supprimertoutBaseConnaissance(BaseConnaissance BC);

#endif //BASECONNAISSANCE_H

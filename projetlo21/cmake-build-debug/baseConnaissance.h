#ifndef __LISTE_H__
#define __LISTE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "regle.h"

typedef struct elemBC {
	 regle *connaissance;
	 struct elemBC *next;
} elementBC;

typedef elementBC * BaseConnaissance;

BaseConnaissance* creerBaseConnaisanceVide();
bool estVideBaseConnaissance(BaseConnaissance *BC);
BaseConnaissance insererQueueBaseConnaissance(BaseConnaissance *BC, regle *e);
BaseConnaissance supprimerUNEBaseConnaissance(BaseConnaissance *BC, regle *e);
BaseConnaissance supprimertoutBaseConnaissance(BaseConnaissance *BC);


#endif 

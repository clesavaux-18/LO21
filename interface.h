//
// Created by aysse on 29/12/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "baseConnaissance.h"
#include "regle.h"
#include "BaseFait.h"

int interfaceregle();
int interfacefait();
int interfacebase();
int interfacegene();
int interface_gestion_regle(regle *r);
int interface_gestion_fait(listf *l);
void afficherBaseConnaissance(BaseConnaissance BC);
void afficherToutesPremisses(regle *r);
listf TEST(listf BF,BaseConnaissance *BC);
#endif //INTERFACE_H

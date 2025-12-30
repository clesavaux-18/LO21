//
// Created by aysse on 29/12/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "baseConnaissance.h"
#include "regle.h"

int interfaceregle();
int interfacefait();
int interfacebase();
int interfacegene();
int interface_gestion_regle(regle *r);
void afficherBaseConnaissance(BaseConnaissance BC);
void afficherToutesPremisses(regle *r);
#endif //INTERFACE_H

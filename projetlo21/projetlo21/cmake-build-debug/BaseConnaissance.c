#include "baseConnaissance.h"
#include <stdbool.h>
//lise chainée<regeles>:ajout en queue:créer base de connaisance vide/accéder a la règle en tete
BaseConnaissance* creerBaseConnaissanceVide() {
    BaseConnaissance NouvelleBaseConnaissance = (BaseConnaissance *)malloc(sizeof(BaseConnaissance));//alocation dynamique donc pointeur vers un  une règle

    NouvelleBaseConnaissance->connaissance = creerRegleVide();
    NouvelleBaseConnaissance->next = NULL;
    return NouvelleBaseConnaissance;
}
bool estVideBaseConnaissance(BaseConnaissance *BC) {
    elementBC *p = BC;
    if (p->connaissance == NULL) {
        return NULL;
    }return 1;
}
BaseConnaissance insererQueueBaseConnaissance(BaseConnaissance *BC, regle *e) {
    elementBC *new = (elementBC *)malloc(sizeof(elementBC));
    new->connaissance = e;
    new->next = NULL;
    if(estVideBaseConnaissance(BC)) {
        return new;
    }else {
        elementBC *p = BC;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
    return *BC;
}
BaseConnaissance supprimerUNEBaseConnaissance(BaseConnaissance *BC, regle *e) {
    if (estVideBaseConnaissance(BC)) {
        return NULL;
    }
    elementBC *l = BC;
    if (l->connaissance == e) {
        l = l->next;
        return *BC;
    }
    elementBC *p = l;
    while (p->next != NULL && p->next->connaissance != e) {
        p = p->next;
    }
    if (p->next == NULL) {
        return *BC;
    }else {
        elementBC *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return *BC;
    }
}
BaseConnaissance supprimertoutBaseConnaissance(BaseConnaissance *BC) {
    elementBC *p;
    while (estVideBaseConnaissance(BC)) {
        p=BC;
        p=p-> next;
        free(p);
    }
    return *BC;
}
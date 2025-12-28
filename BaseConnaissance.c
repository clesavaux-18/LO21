#include "baseConnaissance.h"
#include <stdbool.h>
//lise chainée<regeles>:ajout en queue:créer base de connaisance vide/accéder a la règle en tete
BaseConnaissance creerBaseConnaissanceVide() {
    return NULL;
}
bool estVideBaseConnaissance(BaseConnaissance BC) {
    elementBC *p = BC;
    if (BC == NULL) {
        return 1;
    }return 0;
}
BaseConnaissance insererQueueBaseConnaissance(BaseConnaissance BC, regle *e) {
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
    return BC;
}
BaseConnaissance supprimerUNEBaseConnaissance(BaseConnaissance BC, regle *e) {
    if (estVideBaseConnaissance(BC)) {
        return NULL;
    }

    // --- CORRECTION CRITIQUE ICI ---
    // Cas 1 : Suppression de la TÊTE
    if (BC->connaissance == e) {
        elementBC *temp = BC; // On garde une trace de l'élément à supprimer
        BC = BC->next;        // On déplace la tête vers le suivant
        free(temp);           // On libère la mémoire de l'ancienne tête
        return BC;            // On retourne la NOUVELLE tête
    }

    // Cas 2 : Suppression dans le reste de la liste
    elementBC *p = BC;
    while (p->next != NULL && p->next->connaissance != e) {
        p = p->next;
    }

    if (p->next == NULL) {
        return BC; // Pas trouvé
    } else {
        elementBC *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return BC;
    }
}
BaseConnaissance supprimertoutBaseConnaissance(BaseConnaissance BC) {
    elementBC *p;
    while (!estVideBaseConnaissance(BC)) {
        p=BC;
        BC=BC-> next;
        free(p);
    }
    return BC;
}
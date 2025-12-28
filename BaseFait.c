
#include <string.h>
#include "BaseFait.h"


listf insererQueue(listf l, char e[1000]) {
    elementf *new = (elementf *)malloc(sizeof(elementf));
    strncpy(new->value, e,1000);
    new->next = NULL;
    if (siVide(l)) {
        return new;
    }else {
        elementf *p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
    return l;
}

listf supprimertout(listf l) {
    elementf *p;
    while (!siVide(l)) {
        p=l;
        l=l-> next;
        free(p);
    }
    return l;
}

listf supprimer_element(listf l, char e[1000]) {
    if (siVide(l)) {
        return NULL;
    }
    if (strcmp(l->value,e)==0) {
        elementf *tmp = l;
        l = l->next;
        free(tmp);
        return l;
    }
    elementf *p = l;
    while (p->next != NULL && strcmp(p->next->value,e)!=0) {
        p = p->next;
    }
    if (p->next == NULL) {
        return l;
    }else {
        elementf *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return l;
    }
}
listf insererTete (listf l, char e[1000]) {
    elementf *new = (elementf *)malloc(sizeof(elementf));
    strncpy(new->value,e,1000);
    new->next = l;
    return new;
}

bool siVide(listf l) {
    // Si l est NULL, c'est vide (Vrai), sinon Faux.
    return (l == NULL);
}
bool recherche(listf l, char *e) {
    // Cas de base trivial
    if (l == NULL) {
        return false; // Pas trouvé (0)
    }
    
    // Comparaison
    if (strcmp(l->value, e) == 0) {
        return true; // Trouvé ! (1)
    } else {
        // On continue de chercher dans la suite
        return recherche(l->next, e);
    }
}
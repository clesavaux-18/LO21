
#include <string.h>
#include "BaseFait.h"


listf insererQueue(listf l, char e[1000]) {
    element *new = (element *)malloc(sizeof(element));
    strncpy(new->value, e,1000);
    new->next = NULL;
    if (siVide(l)) {
        return new;
    }else {
        element *p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
    return l;
}

listf supprimertout(listf l) {
    element *p;
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
        element *tmp = l;
        l = l->next;
        free(tmp);
        return l;
    }
    element *p = l;
    while (p->next != NULL && strcmp(p->next->value,e)!=0) {
        p = p->next;
    }
    if (p->next == NULL) {
        return l;
    }else {
        element *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return l;
    }
}
listf insererTete (listf l, char e[1000]) {
    element *new = (element *)malloc(sizeof(element));
    strncpy(new->value,e,1000);
    new->next = l;
    return new;
}
bool siVide(listf l) {
    if (l == NULL) {
        return NULL;
    }return 1;
}
bool recherche(listf l, char e[1000]) {
    if (l != NULL) {
        if (strcmp(l->value,e)) {
            return 1;
        }else {return recherche(l->next, e);}
    }else {
        return NULL;
    }
}
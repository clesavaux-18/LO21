

#include "BaseFait.h"


listf insererQueue(listf l, int e) {
    element *new = (element *)malloc(sizeof(element));
    new->value = e;
    new->next = NULL;
    if (l == NULL) {
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
    while (l != NULL) {
        p=l;
        l=l-> next;
        free(p);
    }
    return l;
}

listf supprimer_element(listf l, int e) {
    if (l == NULL) {
        return NULL;
    }
    if (l->value == e) {
        element *tmp = l;
        l = l->next;
        free(tmp);
        return l;
    }
    element *p = l;
    while (p->next != NULL && p->next->value != e) {
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
listf insererTete (listf l, int e) {
    element *new = (element *)malloc(sizeof(element));
    new->value = e;
    new->next = l;
    return new;
}
bool siVide(listf l) {
    if (l == NULL) {
        return NULL;
    }return 1;
}
bool recherche(listf l, int e) {
    if (l != NULL) {
        if (l->value == e) {
            return 1;
        }else {return recherche(l->next, e);}
    }else {
        return NULL;
    }
}
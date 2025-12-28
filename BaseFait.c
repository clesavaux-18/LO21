
#include <string.h>
#include "BaseFait.h"

//prend en paramètre une liste de fait l(base de fait) et ajoute en queue un fait e chaine de charactère. la fonction retourne la listef ainsi modifié
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

//prend en paramètre une liste l et renvoie une liste vide après avoir suprimé chaque élément 
listf supprimertout(listf l) {
    elementf *p;
    while (!siVide(l)) {
        p=l;
        l=l-> next;
        free(p);
    }
    return l;
}

//prend en paramètre une liste l et un fait e et retourne l auquel on a enlevé le fait e si il etait présent
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

//prend en paramètre une une liste l et vérifie si elle est vide. la fonction retourne une 1 si oui et un 0 si non 
bool siVide(listf l) {
    // Si l est NULL, c'est vide (Vrai), sinon Faux.
    return (l == NULL);
}

// cette fonction prend en paramètre une liste l et un fait e.Elle retourne 1(true) si e est present dans l et 0(false) si non
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

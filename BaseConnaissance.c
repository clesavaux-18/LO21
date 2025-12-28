#include <string.h>
#include "BaseFait.h"

/*-----------------------------------------/OPERATIONS/---------------------------------------------------------------------------------------------------*/

//prend en paramètre une liste de fait l(base de fait) et ajoute en queue un fait e chaine de charactère. la fonction retourne la listef ainsi modifié
listf insererQueue(listf l, char e[1000]) {
    
    //aloue un nouvel element avec malloc
    elementf *new = (elementf *)malloc(sizeof(elementf));
    //copie la chaine e dans la valeur du nouvel element et definit next a NULL
    strncpy(new->value, e,1000);
    new->next = NULL;

    //verifie si la liste est vide
    if (siVide(l)) {
        return new;

    //si elle est non vide parcoure jusqua la fin et redefinit le pointeur next du dernier element vers notre nouveau.
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
    //tant que l est non vide on parcourt et vide 
    while (!siVide(l)) {
        p=l;
        l=l-> next;
        free(p);
    }
    return l;
}

//prend en paramètre une liste l et un fait e et retourne l auquel on a enlevé le fait e si il etait présent
listf supprimer_element(listf l, char e[1000]) {
    
    //verifie si l est NULL
    if (siVide(l)) {
        return NULL;
    }

    // Cas 1 : Suppression de la TÊTE
    if (strcmp(l->value,e)==0) {
        elementf *tmp = l;    // On garde une trace de l'élément à supprimer
        l = l->next;          // On déplace la tête vers le suivant
        free(tmp);            // On libère la mémoire de l'ancienne tête
        return l;             // On retourne la NOUVELLE tête
    }

    // Cas 2 : Suppression dans le reste de la liste

    elementf *p = l; //création d'un pointeur de parcour 
    //parcour tant que l'on est pas au bout ou que ça n'est pas notre e.
    while (p->next != NULL && strcmp(p->next->value,e)!=0) {
        p = p->next;
    }

    // si on est au bout on n'aurat touché a rien et on retourne la liste 
    if (p->next == NULL) {
        return l;
    
    //si c'est trouvé on retire et on retourne la liste
    }else {
        elementf *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return l;
    }
}

//prend en paramètre une liste l et un fait e chaine de charactère. la fonction retourne la listef avec e ajouté en tête
listf insererTete (listf l, char e[1000]) {
    
    //aloue un nouvel element avec malloc
    elementf *new = (elementf *)malloc(sizeof(elementf));
    //copie la chaine e et fait pointer le nouveau vers l'ancienne tête
    strncpy(new->value,e,1000);
    new->next = l;
    return new;
}

/*-----------------------------------------/VERIFICATIONS/---------------------------------------------------------------------------------------------------*/

//prend en paramètre une une liste l et vérifie si elle est vide. la fonction retourne une 1 si oui et un 0 si non 
bool siVide(listf l) {
    // Si l est NULL, c'est vide (Vrai), sinon Faux.
    return (l == NULL);
}

// cette fonction prend en paramètre une liste l et un fait e.Elle retourne 1(true) si e est present dans l et 0(false) si non
bool recherche(listf l, char *e) {
    
    // Cas de base trivial : fin de liste ou liste vide
    if (l == NULL) {
        return false; // Pas trouvé (0)
    }
    
    // Comparaison
    if (strcmp(l->value, e) == 0) {
        return true; // Trouvé ! (1)
    } else {
        // On continue de chercher dans la suite (récursif)
        return recherche(l->next, e);
    }
}

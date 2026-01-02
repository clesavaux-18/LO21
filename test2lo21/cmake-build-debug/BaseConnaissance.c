#include "baseConnaissance.h"
#include <stdbool.h>

/*-----------------------------------------/CREATION/---------------------------------------------------------------------------------------------------*/

//lise chainée<regeles>:ajout en queue:créer base de connaisance vide/accéder a la règle en tete
BaseConnaissance creerBaseConnaissanceVide() {
    return NULL; // retourne un pointeur NULL
}

/*-----------------------------------------/VERIFICATIONS/---------------------------------------------------------------------------------------------------*/

//prend en paramètre une base de connaisace BC.elle renvoie 1 si oui et 0 si non.
bool estVideBaseConnaissance(BaseConnaissance BC) {

     //verifie si BC pointe vers NULL
    if (BC == NULL) {
        return 1;
    }return 0;
}

/*-----------------------------------------/OPERATIONS/---------------------------------------------------------------------------------------------------*/

//prend en paramètre une base de connaisance BC et un pointeur vers une regle e .Le programe retourne la BC avec la règle e ajouté a cellle ci 
BaseConnaissance insererQueueBaseConnaissance(BaseConnaissance BC, regle *e) {
    
    //aloue un nouvel element avec notre  e en valeur et NULL en next en memoire avec malloc
    elementBC *new = (elementBC *)malloc(sizeof(elementBC)); 
    new->connaissance = e;
    new->next = NULL;
    
    //verifie si la base est vide 
    if(estVideBaseConnaissance(BC)) {
        return new;
        
    //si elle est non vide parcoure jusqua la fin et redefinit le pointeur next du dernier element vers notre nouveau.
    }else {
        elementBC *p = BC;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
    return BC;
}

//prend en paramètre un une base de connaisance BC et un pointeur vers une règle e. La fonction retourne la base avec la regle e enlevé si elle etait presente.
BaseConnaissance supprimerUNEBaseConnaissance(BaseConnaissance BC, regle *e) {

    //verifie si BC est NULL
    if (estVideBaseConnaissance(BC)) {
        return NULL;
    }

    // Cas 1 : Suppression de la TÊTE
    if (BC->connaissance == e) {
        elementBC *temp = BC; // On garde une trace de l'élément à supprimer
        BC = BC->next;        // On déplace la tête vers le suivant
        free(temp);           // On libère la mémoire de l'ancienne tête
        return BC;            // On retourne la NOUVELLE tête
    }

    // Cas 2 : Suppression dans le reste de la liste
    
    elementBC *p = BC;//création d'un pointeur de parcour 
    //parcour tant que l'on est pas au bout ou que ça n'est pas notre e.
    while (p->next != NULL && p->next->connaissance != e) {
        p = p->next;
    }
    // si on est au bout on n'aurat touché a rien et on retourne la base 
    if (p->next == NULL) {
        return BC; // Pas trouvé

    //si c'est trouvé on retire et on retourne la base
    } else {
        elementBC *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return BC;
    }
}

//prend en paramètre une base de connaisance BC et retourne aune base vide après avoir supprimé tout les éléments.
BaseConnaissance supprimertoutBaseConnaissance(BaseConnaissance BC) {
    elementBC *p;
    //tant que BC est non vide on parcourt et vide 
    while (!estVideBaseConnaissance(BC)) {
        p=BC;
        BC=BC-> next;
        free(p);
    }
    return BC;
}

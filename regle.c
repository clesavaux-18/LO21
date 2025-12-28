#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "regle.h"

/*-----------------------------------------/CREATION/---------------------------------------------------------------------------------------------------*/

//permet de créer une regle vide et retourne un pointeur vers celle ci.
regle* creerRegleVide() {
    regle *nouvelleRegle = (regle *)malloc(sizeof(regle));//alocation dynamique donc pointeur vers un  une règle 

    nouvelleRegle->premisse = NULL;      
    nouvelleRegle->conclusion[0] = '\0'; 

    return nouvelleRegle;
}

/*-----------------------------------------/OPERATIONS CONCLUSION/---------------------------------------------------------------------------------------------------*/

//prend en paramètre un pointeur vers une règle r et permet de remplire la chaine de charactère conclusion de celle ci .
void saisirConclusion(regle *r) {
    if (r == NULL) {
        printf("Erreur : La règle fournie est vide (NULL).\n");
        return;
    }

    printf("Entrez la conclusion de la regle : ");

    if (fgets(r->conclusion, 1000, stdin) != NULL) {
        size_t len = strlen(r->conclusion);
        if (len > 0 && r->conclusion[len - 1] == '\n') {
            r->conclusion[len - 1] = '\0';
        }
    }
}

//prend en paramètre un pointeur vers une règle r et permet d'afficher la conclusion de celle ci 
void afficherConclusion(regle *r) {
    if (r != NULL) {
        if (r->conclusion[0] == '\0') {
            printf("Cette regle n'a pas encore de conclusion.\n");
        } else {
            printf("Conclusion : %s\n", r->conclusion);
        }
    }
}

/*-----------------------------------------/OPERATIONS PREMISSE/---------------------------------------------------------------------------------------------------*/

//prend en paramètre un pointeur vers une règle r et un pointeur vers un texte et permet d'ajoutere le texte a la liste chainé de chaines de charactère premisse
// retourne un pointeur vers la règle modifié
regle *ajouterPremisse(regle *r, char *texte) {
    if (r == NULL) return NULL; 

    element *nouvellePrem = (element *)malloc(sizeof(element));
    if (nouvellePrem == NULL) return NULL;

    strncpy(nouvellePrem->proposition, texte, 999);
    nouvellePrem->proposition[999] = '\0'; 
    nouvellePrem->next = NULL;
    
    if (premisseEstVide(r)) {
        r->premisse = nouvellePrem;
    } else {
        element *p = r->premisse; // 'element' ici aussi
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = nouvellePrem;
    }

    return r;
}

//prend en paramètre un pointeur vers une règle r et permet de dire si la prémisse de r est vide ,  retourne 1 si oui et 0 sinon
int premisseEstVide(regle *r) {
    if (r == NULL) return 1;
    if (r->premisse == NULL) {
        return 1;
    } else {
        return 0; 
    }
}

//prend en paramètre un pointeur vers une règle r et un pointeur vers une proposition. renvoie 1 si la proposition est presente dans la premisse de r et 0 sinon
int rechercheRecursive(element *p, char *proposition) {
    if (p == NULL) {
        return 0; 
    } 
    else {
        // strcmp ne marche qu'avec des pointeurs (char*)
        if (strcmp(p->proposition, proposition) == 0) {
            return 1; 
        } 
        else {
             return rechercheRecursive(p->next, proposition);
        }
    }
}

//prend en paramètre un pointeur vers une règle r et un pointeur vers un texte . permet de retirer texte de la premisse de r. 
//retourne un pointeur vers la règle modifié
regle *supprimerPremisse(regle *r, char *texte) {
    // verif
    if (r == NULL) return NULL;

    // 2. Si la liste est vide 
    if (r->premisse == NULL) {
        return r;
    }

    // 3. Cas élément à supprimer est la TÊTE (l->value == e)
    if (strcmp(r->premisse->proposition, texte) == 0) {
        element *tmp = r->premisse;
        r->premisse = r->premisse->next; // On décale la tête
        free(tmp);
        return r;
    }

    // 4. Cas où c'est ailleurs 
    // On s'arrête si la fin est proche OU si le SUIVANT est celui qu'on cherche
    element *p = r->premisse;
    while (p->next != NULL && strcmp(p->next->proposition, texte) != 0) {
        p = p->next;
    }

    // 5. Vérification après la boucle
    if (p->next == NULL) {
        // On est arrivé au bout sans trouver
        return r;
    } else {
        // On a trouvé : p->next est l'élément à supprimer
        element *tmp = p->next;
        p->next = tmp->next; // On saute l'élément
        free(tmp);
        return r;
    }
}

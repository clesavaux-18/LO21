#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "regle.h"

/*-----------------------------------------/CREATION/---------------------------------------------------------------------------------------------------*/

//permet de créer une regle vide et retourne un pointeur vers celle ci.
regle* creerRegleVide() {
    
    //aloue une structure regle en memoire avec malloc
    regle *nouvelleRegle = (regle *)malloc(sizeof(regle));

    //initialise la premisse a NULL et la conclusion a vide
    nouvelleRegle->premisse = NULL;      
    nouvelleRegle->conclusion[0] = '\0'; 

    return nouvelleRegle;
}

/*-----------------------------------------/OPERATIONS CONCLUSION/---------------------------------------------------------------------------------------------------*/

//prend en paramètre un pointeur vers une règle r et permet de remplire la chaine de charactère conclusion de celle ci .
void saisirConclusion(regle *r) {
    
    //verifie si la regle existe
    if (r == NULL) {
        printf("Erreur : La règle fournie est vide (NULL).\n");
        return;
    }

    printf("Entrez la conclusion de la regle : ");

    //utilise fgets pour une saisie securisée
    if (fgets(r->conclusion, 1000, stdin) != NULL) {
        //retire le saut de ligne \n capturé par fgets si present
        size_t len = strlen(r->conclusion);
        if (len > 0 && r->conclusion[len - 1] == '\n') {
            r->conclusion[len - 1] = '\0';
        }
    }
}

//prend en paramètre un pointeur vers une règle r et permet d'afficher la conclusion de celle ci 
void afficherConclusion(regle *r) {
    if (r != NULL) {
        //si la chaine est vide (premier char est \0)
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

    //aloue un nouvel element premisse
    element *nouvellePrem = (element *)malloc(sizeof(element));
    if (nouvellePrem == NULL) return NULL;

    //copie le texte dans la proposition et definit next a NULL
    strncpy(nouvellePrem->proposition, texte, 999);
    nouvellePrem->proposition[999] = '\0'; 
    nouvellePrem->next = NULL;
    
    //si la liste de premisse est vide, on ajoute en tete
    if (premisseEstVide(r)) {
        r->premisse = nouvellePrem;
    
    //sinon on parcourt jusqu'a la fin pour ajouter en queue
    } else {
        element *p = r->premisse; 
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = nouvellePrem;
    }

    return r;
}

//prend en paramètre un pointeur vers une règle r et un pointeur vers un texte . permet de retirer texte de la premisse de r. 
//retourne un pointeur vers la règle modifié
regle *supprimerPremisse(regle *r, char *texte) {
    // verifie si r est NULL
    if (r == NULL) return NULL;

    // Si la liste de prémisses est vide 
    if (r->premisse == NULL) {
        return r;
    }

    // Cas 1 : Suppression de la TÊTE (si la proposition correspond au texte)
    if (strcmp(r->premisse->proposition, texte) == 0) {
        element *tmp = r->premisse;
        r->premisse = r->premisse->next; // On décale la tête
        free(tmp);                       // On libère la mémoire
        return r;
    }

    // Cas 2 : Suppression ailleurs dans la liste
    
    element *p = r->premisse; //pointeur de parcours
    // On s'arrête si la fin est proche OU si le SUIVANT est celui qu'on cherche
    while (p->next != NULL && strcmp(p->next->proposition, texte) != 0) {
        p = p->next;
    }

    // Si on est arrivé au bout sans trouver
    if (p->next == NULL) {
        return r;
    
    // Si on a trouvé : p->next est l'élément à supprimer
    } else {
        element *tmp = p->next;
        p->next = tmp->next; // On saute l'élément
        free(tmp);
        return r;
    }
}

/*-----------------------------------------/VERIFICATIONS/---------------------------------------------------------------------------------------------------*/

//prend en paramètre un pointeur vers une règle r et permet de dire si la prémisse de r est vide ,  retourne 1 si oui et 0 sinon
int premisseEstVide(regle *r) {
    if (r == NULL) return 1;
    //verifie si le pointeur premisse est NULL
    if (r->premisse == NULL) {
        return 1;
    } else {
        return 0; 
    }
}

//prend en paramètre un pointeur vers une règle r et un pointeur vers une proposition. renvoie 1 si la proposition est presente dans la premisse de r et 0 sinon
int rechercheRecursive(element *p, char *proposition) {
    // Cas de base : fin de liste
    if (p == NULL) {
        return 0; 
    } 
    else {
        // Comparaison des chaines
        if (strcmp(p->proposition, proposition) == 0) {
            return 1; // Trouvé
        } 
        else {
             // Appel recursif sur le suivant
             return rechercheRecursive(p->next, proposition);
        }
    }
}

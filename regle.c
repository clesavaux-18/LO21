#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "regle.h"

regle* creerRegleVide() {
    regle *nouvelleRegle = (regle *)malloc(sizeof(regle));

    nouvelleRegle->premisse = NULL;      
    nouvelleRegle->conclusion[0] = '\0'; 

    return nouvelleRegle;
}

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

void afficherConclusion(regle *r) {
    if (r != NULL) {
        if (r->conclusion[0] == '\0') {
            printf("Cette regle n'a pas encore de conclusion.\n");
        } else {
            printf("Conclusion : %s\n", r->conclusion);
        }
    }
}

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

int premisseEstVide(regle *r) {
    if (r == NULL) return 1;
    if (r->premisse == NULL) {
        return 1;
    } else {
        return 0; 
    }
}

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

regle *supprimerPremisse(regle *r, char *texte) {
    
    if (r == NULL) return NULL;
    if (premisseEstVide(r)) return r; 


    element *courant = r->premisse;
    element *precedent = NULL;

    // cas 1 element en tete
    if (strcmp(courant->proposition, texte) == 0) {
        r->premisse = courant->next; 
        free(courant); 
        return r;
    }

    // cas 2 element au milieux
    while (courant != NULL && strcmp(courant->proposition, texte) != 0) {
        precedent = courant;       
        courant = courant->next;   
    }

    if (courant != NULL) {
        precedent->next = courant->next;
        free(courant); 
    }

    return r;
}

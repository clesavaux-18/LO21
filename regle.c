#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include "regle.h"



regle* creerRegleVide() {
    // alocation memoire
    regle *nouvelleRegle = (regle *)malloc(sizeof(regle));


    // 3. Initialisation 
    nouvelleRegle->premisse = NULL;      // La liste des prémisses est vide (NULL)
    nouvelleRegle->conclusion[0] = '\0'; // La conclusion est une chaîne vide pour l'instant

    return nouvelleRegle;
}



/*
remplir la conclusion
 */
void saisirConclusion(regle *r) {
    if (r == NULL) {
        printf("Erreur : La règle fournie est vide (NULL).\n");
        return;
    }

    printf("Entrez la conclusion de la regle : ");

    // remplissage 
    if (fgets(r->conclusion, 1000, stdin) != NULL) {
        
        // on enlève l'eventuel saut de ligne de fgets
        size_t len = strlen(r->conclusion);
        if (len > 0 && r->conclusion[len - 1] == '\n') {
            r->conclusion[len - 1] = '\0';
        }
    }
}

/*
affiche la conclusion d'une règle.
 */
void afficherConclusion(regle *r) {
    // verif regle
    if (r != NULL) {
       
    

	    // verif conclusion
	    if (r->conclusion[0] == '\0') {
		printf("Cette regle n'a pas encore de conclusion.\n");
	    } else {
		printf("Conclusion : %s\n", r->conclusion);
	    }
    }
}



/*
 ajoute unne premisse
 */
regle *ajouterPremisse(regle *r, char *texte) {
    if (r == NULL) return NULL; // Sécurité

    prem *nouvellePrem = (prem *)malloc(sizeof(prem));

    strncpy(nouvellePrem->proposition, texte, 999);
    nouvellePrem->proposition[999] = '\0'; 
    nouvellePrem->next = NULL;
    
    if (premisseEstVide(r)) {
        r->premisse = nouvellePrem;
    } else {
        prem *p = r->premisse;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = nouvellePrem;
    }

    return r;
}

/*
teste si la prémisse d'une règle est vide 
 */
int premisseEstVide(regle *r) {
   
    if (r == NULL) {
        return 1;
    }


    if (r->premisse == NULL) {
        return 1;
    } else {
        return 0; 
    }
}

int rechercheRecursive(prem *p, char *cible) {
    if (p == NULL) {
        return 0; 
    } 
    else {
        if (strcmp(p->proposition, cible) == 0) {
            return 1; 
        } 
        else {
             return rechercheRecursive(p->next, cible);
        }
    }
}

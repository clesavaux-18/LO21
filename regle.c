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



/*
remplir la conclusion. prend en paramètre r une liste 
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
affiche la conclusion d'une règle. prend en paramètre une règle r
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
 ajoute unne premisse. prend en paramètre une règle et une proposition(chaine de charactère) et retounre une règle mise a jour 
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
teste si la prémisse d'une règle est vide , prend en paramètre une règle
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

//recherche une proposition dans la premisse, prend en paramètre  
//return 1 si trouvé et 0 si ce n'est pas le cas
int rechercheRecursive(prem *p, char *proposition) {
    if (p == NULL) {
        return 0; 
    } 
    else {
        if (strcmp(p->proposition, proposition) == 0) {
            return 1; 
        } 
        else {
             return rechercheRecursive(p->next, proposition);
        }
    }
}


/*supprime texte de premisse
 */
regle *supprimerPremisse(regle *r, char *texte) {
    
    if (r == NULL) return NULL;
    if (premisseEstVide(r)) return r; // Rien à supprimer si vide

    prem *courant = r->premisse;
    prem *precedent = NULL;

    // cas 1: element en tete
    if (strcmp(courant->proposition, texte) == 0) {
        r->premisse = courant->next; 
        free(courant); 
        return r;
    }

    // cas 2 element au milieux
    // On parcourt tant qu'on n'est pas à la fin ET qu'on n'a pas trouvé le texte
    while (courant != NULL && strcmp(courant->proposition, texte) != 0) {
        precedent = courant;       
        courant = courant->next;   
    }

    // Si courant n'est pas NULL, element trouvé
    if (courant != NULL) {
        // On "saute" l'élément courant en reliant le précédent au suivant
        precedent->next = courant->next;
        free(courant); 
    }

    return r;
}

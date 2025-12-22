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

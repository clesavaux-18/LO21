#ifndef REGLE_H   // <--- AJOUT 1
#define REGLE_H   // <--- AJOUT 2

#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 

typedef struct elem {
     char proposition[1000];
     struct elem *next;
} element;

typedef element *premisse;

typedef struct {
     premisse premisse;     
     char conclusion[1000]; 
} regle;

regle *creerRegleVide();
void saisirConclusion(regle *r);
void afficherConclusion(regle *r);
regle *ajouterPremisse(regle *r, char *texte);
int premisseEstVide(regle *r);
int rechercheRecursive(element *p, char *proposition) ;
regle *supprimerPremisse(regle *r, char *texte);

#endif // <--- AJOUT 3

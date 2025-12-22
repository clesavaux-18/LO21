#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 


typedef struct listePrem {
     char proposition[1000];
     struct listePrem *next;
} prem;

typedef prem *premisse;


typedef struct {
     premisse premisse;     
     char conclusion[1000]; 
} regle;

regle *creerRegleVide();
void saisirConclusion(regle *r);
void afficherConclusion(regle *r);
regle *ajouterPremisse(regle *r, char *texte);
int premisseEstVide(regle *r);
int rechercheRecursive(prem *p, char *cible) ;

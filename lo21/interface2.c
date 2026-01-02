//
// Created by aysse on 29/12/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "regle.h"
#include "baseConnaissance.h"
#include "BaseFait.h"

BaseConnaissance BC = NULL;
listf LF = NULL;


int interfacegene() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
        "1. Alimenter la base de connaissance\n"
        "2. Tester la base de connaissance (afficher)\n"
        "3. Quitter\n");
        scanf("%d", &rep);
    } while (!(rep == 1 || rep == 2 || rep == 3));

    if (rep == 1)
        interfacebase();
    else {
        if (rep == 2) {
            //CODE A FAIRE POUR TESTER
        }
        else {
            return 0;
        }
    }
    return 0;
}


int interfacebase() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
               "1. Gerer la liste de faits\n"
               "2. Gerer la base de regles\n"
               "3. Retour\n");
        scanf("%d", &rep);
    } while (!(rep == 1 || rep == 2 || rep == 3));

    if (rep == 1)
        interfacefait();
    else {
        if (rep == 2) {
            interfaceregle();
        } else {
            interfacegene();
        }
    }
    return 0;
}

int interface_gestion_fait(listf *l) {
    int rep;
    char fait[1000];
    do{
        printf(
            "1.Ajouter un fait a la liste\n"
            "2.Supprimer un fait de la liste\n"
            "3.Supprimer toute la liste\n"
            "4.Tester si la liste est vide\n"
            "5.Rechecher un fait dans la liste\n"
            "6.Afficher la liste\n"
            "7.Retour\n");
        scanf("%d", &rep);
        getchar();

        switch (rep) {
            case 1:
                printf("Fait : ");
                fgets(fait, 1000, stdin);
                fait[strcspn(fait, "\n")] = 0;
                *l = insererQueue(*l, fait);
                break;

            case 2:
                printf("Fait a supprimer: ");
                fgets(fait, 1000, stdin);
                fait[strcspn(fait, "\n")] = 0;
                *l = supprimer_element(*l, fait);
                printf("Fait supprimer");
                break;
            case 3:
                *l = supprimertout(*l);
                printf("Liste supprimer\n");
            case 4:
                if (siVide(*l))
                    printf("La liste est vide\n");
                else
                    printf("La liste n'est pas vide.\n");
                break;
            case 5:
                printf("Fait a rechercher : ");
                fgets(fait, 1000, stdin);
                fait[strcspn(fait, "\n")] = '\0';
                if (recherche(*l, fait))
                    printf("Le fait est dans la liste\n");
                else
                    printf("Le fait n'est pas dans la liste.\n");
                break;
            case 6:
                afficherListeFait(*l);
                break;

            case 7:
                return 0;

            default:
                printf("Choix invalide.\n");

        }


    }while (rep !=7);
    return 0;
}

int interfacefait() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
            "1.Creer une liste de fait vide\n"
            "2.Gerer la liste\n"
            "3.Retour\n");
        scanf("%d",&rep);

    if (rep == 1){
        LF = creeListeFaitVide();
        printf("Liste de fait vide creee.\n");
    } else {
        if (rep == 2) {
            interface_gestion_fait(&LF);
        }else {
            interfacegene();
        }
    }
    } while (rep!=3);
    return 0;
}


int interface_gestion_regle(regle *r) {
    int rep;
    char premisse[1000];

    do {
        printf(
        "1. Ajouter une premisse\n"
        "2. Supprimer une premisse\n"
        "3. Saisir la conclusion\n"
        "4. Afficher la premiere premisse\n"
        "5. Afficher toutes les premisses\n"
        "6. Afficher la conclusion\n"
        "7. Tester si une proposition appartient a la premisse\n"
        "8. Tester si la premisse est vide\n"
        "9. Retour\n");
        scanf("%d", &rep);
        getchar();

        switch(rep) {

            case 1:
                printf("Premisse : ");
                fgets(premisse, 1000, stdin);
                premisse[strcspn(premisse, "\n")] = '\0';
                ajouterPremisse(r, premisse);
                break;

            case 2:
                printf("Premisse a supprimer : ");
                fgets(premisse, 1000, stdin);
                premisse[strcspn(premisse, "\n")] = '\0';
                supprimerPremisse(r, premisse);
                break;

            case 3:
                saisirConclusion(r);
                break;

            case 4:
                afficherPremisse(r);
                break;

            case 5:
                afficherToutesPremisses(r);
                break;

            case 6:
                afficherConclusion(r);
                break;

            case 7:
                printf("Proposition a rechercher : ");
                fgets(premisse, 1000, stdin);
                premisse[strcspn(premisse, "\n")] = '\0';
                if (rechercheRecursive(r->premisse, premisse))
                    printf("La proposition est dans la premisse.\n");
                else
                    printf("La proposition n'est pas dans la premisse.\n");
                break;

            case 8:
                if (premisseEstVide(r))
                    printf("La premisse est vide.\n");
                else
                    printf("La premisse n'est pas vide.\n");
                break;

            case 9:
                return 0;

            default:
                printf("Choix invalide.\n");
        }

    } while (rep != 9);

    return 0;
}

int interfaceregle() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
        "1. Creer une base de connaissance vide\n"
        "2. Ajouter une regle\n"
        "3. Afficher la base de connaissance\n"
        "4. Retour\n");
        scanf("%d", &rep);

        //Creation d'une base de connaissance vide
    if (rep == 1) {
        BC = creerBaseConnaissanceVide();
        printf("Base de connaissance creee.\n");
    } else {
        // Creation d'un regle vide, puis modification de cette regle qui est ensuite inserer a la suite de la base de connaissance
        if (rep == 2) {
            regle *r = creerRegleVide();
            interface_gestion_regle(r);
            BC = insererQueueBaseConnaissance(BC, r);
            printf("Regle ajoutee a la base.\n");
        }else {
            if (rep == 3) {
                afficherBaseConnaissance(BC);
            } else {
                interfacegene();
            }
        }
    }
    } while (rep !=4);
    return 0;
}


void afficherToutesPremisses(regle *r) {
    // test si la regles existe
    if (r == NULL) {
        printf("Regle inexistante.\n");
        return;
    }
    //Test si la resgle a une premisse
    if (r->premisse == NULL) {
        printf("La regle n'a pas de premisse)\n");
        return;
    }

    //Affiche toutes les premisse en parcourant la liste
    printf("Premisses : \n");
    element *p = r->premisse;
    while (p != NULL) {
        printf("- %s \n", p->proposition);
        p = p->next;
    }
}


void afficherBaseConnaissance(BaseConnaissance BC) {
    // Test si la base de connaissance est vide
    if (BC == NULL) {
        printf("Base de connaissance vide.\n");
        return;
    }
    // Affiche toutes les regles enregsitrées dans la base avec les premisses et la conclusion
    int i = 1;
    elementBC *p = BC;
    while (p != NULL) {
        printf("\n Regle %d \n", i);
        afficherToutesPremisses(p->connaissance);
        afficherConclusion(p->connaissance);
        p = p->next;
        i++;
    }
}







//
// Created by aysse on 29/12/2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "regle.h"
#include "baseConnaissance.h"

BaseConnaissance BC = NULL;

int interfacegene() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
               "1.Alimenter la base de connaissance\n"
               "2.Tester la base de connaissance\n"
               "/Repondre avec 1 ou 2/\n");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2));
    if (rep == 1) {
        interfacebase();
    }else {
        printf("Test de la base de connaisance A CODER");
    }
    return 0;
}
int interfacebase() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
            "1.Alimenter la base de fait\n"
            "2.Alimenter la base de regle\n"
            "3.Retour\n"
            "/Repondre avec 1 ou 2 ou 3/\n");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {
        interfacefait();
    }else {
        if (rep==2) {
            interfaceregle();
        }else {
            interfacegene();
        }
    }
}

int interfacefait() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
            "1.Creer une liste de fait\n"
            "2.Ajouter un fait\n"
            "3.Retour\n"
            "/Repondre avec 1 ou 2 ou 3/\n");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {
        //code creation de liste vide
    }else{
        if (rep==2) {
            //code pour ajouter un fait en tete ou queue a voir
        }else {
            interfacebase();
        }
    }
}

int interface_gestion_regle(regle *r) {
    int rep;
    char premisse[1000];
    do {
        printf("Que voulez vous faire ?\n"
            "1.Ajouter une premisse\n"
            "2.Supprimer une premisse\n"
            "3.Saisir la conclusion\n"
            "4.Afficher la premiere proposition de la premisse\n"
            "5.Afficher la conclusion\n"
            "6.Retour\n");
        scanf("%d",&rep);
        getchar();

        switch(rep) {

            case 1:
                printf("Entrez une prémisse : ");
                fgets(premisse, 1000, stdin);
                premisse[strcspn(premisse, "\n")] = '\0';
                ajouterPremisse(r, premisse);
                break;

            case 2:
                printf("Entrez la prémisse à supprimer : ");
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
                afficherConclusion(r);
                break;
            case 6:
                interfaceregle();
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (rep != 6);
}


int interfaceregle() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n"
            "1.Creer la base de Connaissance\n"
            "2.Ajouter une regle a la Base de connaissance\n"
            "3.Retour\n"
            "/Repondre avec 1 ou 2 ou 3/\n");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {
        BC = creerBaseConnaissanceVide();
        printf("Une base de connaissance vide a bien ete cree");
    }else{
        if (rep==2) {
            regle *r = creerRegleVide();
            interface_gestion_regle(r);
        }else {
            interfacebase();
        }
    }
}

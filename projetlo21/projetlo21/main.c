#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cmake-build-debug/BaseFait.h"
#include "cmake-build-debug/baseConnaissance.h"

int interfaceregle();
int interfacefait();
int interfacebase();
int interfacegene();

listf *test(listf BF, BaseConnaissance BC) {
    if (siVide(BF)) {
        return 1;
    }else {
        char value1[1000];
        strncpy(value1,BF->value,1000);
        if (rechercheRecursive(&BC,value1)) {
            supprimerPremisse(&BC, value1);
            test(BF->next,BC);
            if (estVideBaseConnaissance(&BC)) {
                insererQueue(BF, BC->connaissance);
                return &BF;
            }
        }
    }
}

int main(void) {
    printf("Hello !\n");
    interfacegene();

    return 0;
}
int interfacegene() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n1.Alimenter la base de connaissance\n"
            "2.Tester la base de connaissance\n/Repondre avec 1 ou 2/");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2));
    if (rep == 1) {
        interfacebase();
    }else{}
}
int interfacebase() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n1.Alimenter la base de fait\n"
            "2.Alimenter la base de regle\n3.Retour\n/Repondre avec 1 ou 2 ou 3/");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {
        interfacefait();
    }if (rep==2){interfaceregle();}else{interfacegene();}
}
int interfacefait() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n1.Creer la base de fait\n"
        "2.Ajouter un fait\n3.Retour\n/Repondre avec 1 ou 2 ou 3/");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {

    }if (rep==2){}else{interfacebase();}
}
int interfaceregle() {
    int rep;
    do {
        printf("Que voulez vous faire ?\n1.Creer la base de regle\n"
        "2.Ajouter une regle\n3.Retour\n/Repondre avec 1 ou 2 ou 3/");
        scanf("%d",&rep);
    }while (!(rep == 1 || rep == 2|| rep == 3));
    if (rep == 1) {

    }if (rep==2){}else{interfacebase();}
}
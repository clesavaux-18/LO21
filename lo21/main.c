#include <stdio.h>
#include "interface.h"
/*rechercheRegletoPremmissse (regle connaissance,e[1000]) {
    regle *p = connaissance;
    while (!(rechercheRecursive(p->premisse,e)||p==NULL)) {
        p = p->next;
    }
    if (p!=NULL) {
        return rechercheRegletoPremmissse(p->connaissance,e);
    } else {
        return 0;
    }

}
regle *rechercheBCtoRegle(BaseConnaissance BC,char e[1000]) {
    elementBC *p = BC;
    while (!(rechercheRnunuhn(p->connaissance,e)||p==NULL)) {
        p = p->next;
    }
    if (p!=NULL) {
        return rechercheRegletoPremmissse(p->connaissance,e);
    } else {
        return 0;
    }
}*/
regle *rechercheBCtoregle(BaseConnaissance BC,char e[1000]){
    elementBC *pBC = BC;
    while (pBC != NULL) {
        //Niveau des règles
        regle *pRegle = pBC->connaissance;//Niveau d' 1 règles
        element *pPrem = pRegle->premisse; //Niveau des premisses
        while (!(rechercheRecursive(pPrem,e)==1 || pPrem==NULL)) {
            pPrem = pPrem->next;
        }
        if (rechercheRecursive(pPrem,e)==1) {
            return pRegle;
        }else{pBC = pBC->next;}
    }

}
int supprimerelem(element *tabpropo) {
    if (tabpropo!=NULL) {
        element *tmp = tabpropo->next;
        tabpropo->next = tmp->next; // On saute l'élément
        free(tmp);
    }
        return 0;
}
listf TEST(listf BF,BaseConnaissance *BC) {
    listf Dedui = creeListeFaitVide();
    if (!siVide(BF)) {
        while (!estVideBaseConnaissance(*BC)) {
             regle *adresseR = rechercheBCtoregle(*BC,&BF->value[0]);
            if (adresseR!=0){
                element *pPrem = adresseR->premisse; //Niveau des premisses
                while (!(rechercheRecursive(pPrem,&BF->value[0])==1 || pPrem==NULL)) {
                    pPrem = pPrem->next;
                }
                supprimerelem(pPrem);
            }if (premisseEstVide(adresseR)) {
                insererQueue(BF,adresseR->conclusion);
                insererQueue(Dedui,adresseR->conclusion);
            }
        }
    }
}


int main(void) {
    printf("Bonjour\n");
    interfacegene();
    return 0;
}

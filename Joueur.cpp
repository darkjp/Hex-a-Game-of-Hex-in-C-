#include <stdio.h>
#include "Joueur.h"

void intitialisationJoueur(Joueur* j1, Joueur* j2){
    intitialisationJoueur1(j1);
    intitialisationJoueur2(j2);
}

void intitialisationJoueur1(Joueur* joueur1){
    joueur1->numero=1;
    joueur1->pion='R';
}

void intitialisationJoueur2(Joueur* joueur2){
    joueur2->numero=2;
    joueur2->pion='B';
}

void quelJoueur(int tourDe){
    if(tourDe==1){
        printf("\n\nAu tour du joueur1 \n\n");
    }
    else{
    printf("\n\nAu tour du joueur2 \n\n");
    }
}

int changementJoueur(int joueur,Joueur j1,Joueur j2){
    if(joueur==j1.numero){
        return j2.numero;
    }
    else{
        return j1.numero;
    }
}

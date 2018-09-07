#include <stdio.h>
#include <stdlib.h>
#include "Hex.h"
#include "Joueur.h"
#include "unittest.h"

void jeuDuHex(){
    Hex plateau;
    Joueur j1;
    Joueur j2;
    debut();
    demandeDeTest();
    intitialisationJoueur(&j1,&j2);
    intialiserHex(&plateau);
    genererPlateau(&plateau);
    afficherPlateau(plateau);
    partieEnCours(plateau,j1,j2);
    fin();
}

void debut(){
    printf("Bonjour et bienvenue dans le jeu de Hex!!!\n\n");
    printf("Les regles sont simple. Deux joueurs s'affrontent sur un plateau hexagonal!\n");
    printf("Le premier joueur a les pions 'R' et doit poser ses pions un a un pour etablir un chemin continu qui part de la ligne la plus haute du plateau pour finir sur la ligne du bas.\n");
    printf("Le deuxiéme joueur a les pions 'B' et doit faire de meme de la colonne a l'extremite gauche pour finir par toucher la colonne la plus à droite du plateau .\n\n");
    printf("Bon jeu et que le meilleur gagne!\n\n");
}

void demandeDeTest(){
    int test=0;
    printf("Avant de commencer, voulez vous affectuer les tests? Si oui tapez 1 sinon tapez 2. A vous:");
    while(test>2 || test<1){
        scanf("%i",&test);
        if(test>2 || test<1){
            printf("\nSaisissez 1 ou 2:");
        }
    }
    if(test==1)
        testHex();
}

void testHex(){
    Hex plateauTest;
    Joueur j1test;
    Joueur j2test;
    intitialisationJoueur(&j1test,&j2test);
    intialiserHex(&plateauTest);
    plateauTest.tailleSaisie=6;
    t1(&plateauTest);
    printf("\n\nVoici le Plateau Test:\n\n");
    afficherPlateau(plateauTest);
    printf("\n\n");

    //Test verification si la case est libre
    assertFalse(verificationCaseLibre(7,&plateauTest),"(1;1)=R test ");
    assertFalse(verificationCaseLibre(15,&plateauTest),"(3;2)=B test ");
    assertTrue(verificationCaseLibre(85,&plateauTest),"(inconnue;inconnue) libre test ");
    assertTrue(verificationCaseLibre(18,&plateauTest),"(3;3) libre test ");

    //Test verification si la ligne est dans le plateau
    assertEquals(jouerLigneTest(5,4),4,"Ligne 4 est ");
    assertEquals(jouerLigneTest(5,2),2,"Ligne 0 est ");
    assertEquals(jouerLigneTest(5,-9),0,"Ligne -9 est ");
    assertEquals(jouerLigneTest(5,15),0,"Ligne 15 est ");

    //Test verification si la colonne est dans le plateau
    assertEquals(jouerColonneTest(5,3),3,"Colonne 3 est ");
    assertEquals(jouerColonneTest(5,4),4,"Colonne 4 est ");
    assertEquals(jouerColonneTest(5,-95),0,"Colonne -95 est ");
    assertEquals(jouerColonneTest(5,14),0,"Colonne 14 est ");

    //Test si changement de joueur ok
    int Joueur=1; //Le actuel joueur est joueur 1
    assertEquals(changementJoueur(Joueur,j1test,j2test),2,"Test J1 est ");
    Joueur=2;
    assertEquals(changementJoueur(Joueur,j1test,j2test),1,"Test J2 est ");

    printf("\n\n");

    //Test plateau 1
    initialiserPlateau(&plateauTest);
    t2(&plateauTest);
    Joueur=1;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertTrue(testVerification(plateauTest)," ");

    //Test plateau 2
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t3(&plateauTest);
    Joueur=2;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertTrue(testVerification(plateauTest)," ");

    //Test plateau 3
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t4(&plateauTest);
    Joueur=1;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertTrue(testVerification(plateauTest)," ");

    //Test plateau 4
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t5(&plateauTest);
    Joueur=2;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertTrue(testVerification(plateauTest)," ");

    //Test plateau 5
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t6(&plateauTest);
    Joueur=1;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertFalse(testVerification(plateauTest)," ");

    //Test plateau 6
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t7(&plateauTest);
    Joueur=1;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertTrue(testVerification(plateauTest)," ");

    //Test plateau 7
    printf("\n\n");
    initialiserPlateau(&plateauTest);
    t8(&plateauTest);
    Joueur=2;
    plateauTest.victoire=0;
    afficherPlateau(plateauTest);
    Verification(&plateauTest,Joueur);
    assertFalse(testVerification(plateauTest)," ");

    printf("\n\n");
}

void intialiserHex(Hex* iHPlateau){
    iHPlateau->victoire=0;
    iHPlateau->taille=0;
    iHPlateau->tailleSaisie=0;
}

void saisieTaille(Hex* sPlateau){
    printf("Le plateau contient autant de ligne que de colonne, combien en voulez-vous:");
    scanf("%i",&(sPlateau->tailleSaisie));
    sPlateau->tailleSaisie=sPlateau->tailleSaisie+1;
    printf("Merci et que la force soit avec vous!\n\n");
}

void allouerPlateau(Hex *aPlateau){
    aPlateau->plateau=(char*)malloc((aPlateau->taille)/sizeof(char));
}

void calculeTaille(Hex* cPlateau){
    cPlateau->taille=((cPlateau->tailleSaisie)*(cPlateau->tailleSaisie));
}

void initialiserPlateau (Hex* iPlateau) {
    for(int i=0;i<iPlateau->taille;++i){
            iPlateau->plateau[i]=' ';
  }
}

void genererPlateau (Hex* gPlateau){
    saisieTaille(gPlateau);
    calculeTaille(gPlateau);
    allouerPlateau(gPlateau);
    initialiserPlateau(gPlateau);
}

void afficherPlateau(Hex aPlateau){
    int i=0, ligne=0;
  for(;i<(aPlateau.taille);++ligne){
    if(i==0){
        for(int j=0;j<aPlateau.tailleSaisie;++i,++j){                       //Afficher numéro colonne
            if(i==0)
            printf("    ");
            else if(i<10 && i!=0)
                printf("|%i ",i);
            else
                printf("|%i",i);
        }
    }
    else{                                                           //Affichage pour les 9 premiers lignes
        if(ligne<10){
        for(int j=0;j<aPlateau.tailleSaisie;++i,++j){
            if(i%aPlateau.tailleSaisie==0){                                 //Création de l'espace pour le décalage cellule
                for(int g=0;g<=ligne;++g){
                    printf(" ");
                }
                printf("%i ",i/aPlateau.tailleSaisie);                     //Affichage numéro colonne du plateau
            }
            else
                    printf("[%c]",aPlateau.plateau[i]);                   //Affichage case colonne du plateau

        }
        }
        else{                                                       //Affichage pour les autres lignes (jusqu'a 99 lignes)
            for(int j=0;j<aPlateau.tailleSaisie;++i,++j){
                if(i%aPlateau.tailleSaisie==0){                             //Création de l'espace pour le décalage cellule
                    for(int g=0;g<ligne;++g){
                        printf(" ");
                    }
                    printf("%i ",i/aPlateau.tailleSaisie);                 //Affichage numéro colonne du plateau
                }
                else
                    printf("[%c]",aPlateau.plateau[i]);                   //Affichage case colonne du plateau
            }
        }
    }
    printf("\n");
  }
}

void partieEnCours(Hex pPlateau, Joueur pJ1, Joueur pJ2){
    int coordonneCoup=0, joueurEnCours=pJ1.numero;
    while(pPlateau.victoire!=1){
        quelJoueur(joueurEnCours);
        coordonneCoup=saisieDuCoup(&pPlateau);
        placePion(coordonneCoup,&pPlateau,joueurEnCours);
        printf("\n");
        afficherPlateau(pPlateau);
        Verification(&pPlateau,joueurEnCours);
        joueurEnCours=changementJoueur(joueurEnCours,pJ1,pJ2);
    }
}

int saisieDuCoup(Hex* sCPlateau){
    int sValeur=0;
    while ((sCPlateau->plateau[sValeur] == 'R' || sCPlateau->plateau[sValeur] =='B') || sValeur>(sCPlateau->taille) || sValeur<1){
        sValeur=(sCPlateau->tailleSaisie*jouerLigne(sCPlateau->tailleSaisie))+jouerColonne(sCPlateau->tailleSaisie);
        if(verificationCaseLibre(sValeur,sCPlateau)==false)
            printf("Coup impossible, un pion est deja present!!\n");
    }

    return sValeur;
}

int jouerLigne(int longeur){
        int Ligne=0;
        while(Ligne<1 ||Ligne>longeur){
            printf("Veuillez entrer la ligne sur laquelle vous souhaitez jouer: ");
            scanf("%i", &Ligne);
            if(Ligne<1 || Ligne>longeur)
                printf("Desole le ligne n existe pas!\n");
        }
        printf("\n");
        return Ligne;
}

int jouerColonne(int longeur){
    int Colonne=0;
    while(Colonne<1 || Colonne>longeur){
            printf("Veuillez entrer la colonne dans laquelle vous souhaitez jouer: ");
            scanf("%i", &Colonne);
            if(Colonne<1 || Colonne>longeur)
                printf("Desole le ligne n existe pas!\n");
        }
        printf("\n");
        return Colonne;
}

bool verificationCaseLibre(int vValeur, Hex* vPlateau){
    if((vPlateau->plateau[vValeur] == 'R') || (vPlateau->plateau[vValeur] == 'B'))
        return false;
    return true;
}

void placePion(int pValeur, Hex* pPPlateau, int pJoueur) {
    // joueur == 0 égal "joueur 1"
    if (pJoueur == 1) {
        pPPlateau->plateau[pValeur] = 'R';
    }
    else {
    //joueur == 1 égale "joueur 2"
        pPPlateau->plateau[pValeur] = 'B';
    }
}

void Verification(Hex* vPlateau, int vJoueur){
    for(int i=(vPlateau->tailleSaisie+1);i<=(vPlateau->taille)&& vPlateau->victoire!=1;++i){
        if(vJoueur==1 && i<=(vPlateau->tailleSaisie*2) && vPlateau->plateau[i]=='R'){
            verificationVictoire(vPlateau, i, 'R' ,vJoueur);
        }
        else if(vJoueur==2 && i%(vPlateau->tailleSaisie)==1 && vPlateau->plateau[i]=='B'){
            verificationVictoire(vPlateau, i, 'B',vJoueur);
        }
    }

}

void verificationVictoire(Hex* vVPlateau, int vPion, char valeurPion, int vJoueur){
		if(vJoueur==1 && vVPlateau->plateau[vPion]=='R' && vPion<=(vVPlateau->taille) && vPion>((vVPlateau->taille)-vVPlateau->tailleSaisie)){
			vVPlateau->victoire=1;
			printf("\nVictoire du Joueur 1!!\n");
		}
        else if(vJoueur==2 && vVPlateau->plateau[vPion]=='B' && (vPion%vVPlateau->tailleSaisie)==((vVPlateau->tailleSaisie)-1)){
            vVPlateau->victoire=1;
            printf("\nVictoire du Joueur 2!!\n");
        }
		else if(vVPlateau->plateau[vPion]==valeurPion){
            vVPlateau->plateau[vPion]='F';
            verificationVictoire(vVPlateau, vPion-1,valeurPion,vJoueur);
            if(vVPlateau->victoire!=1)
                verificationVictoire(vVPlateau, vPion+vVPlateau->tailleSaisie-1,valeurPion,vJoueur);
            if(vVPlateau->victoire!=1)
                verificationVictoire(vVPlateau, vPion+vVPlateau->tailleSaisie,valeurPion,vJoueur);
            if(vVPlateau->victoire!=1)
                verificationVictoire(vVPlateau, vPion+1,valeurPion,vJoueur);
                verificationVictoire(vVPlateau, vPion-vVPlateau->tailleSaisie+1,valeurPion,vJoueur);
            if(vVPlateau->victoire!=1)
                verificationVictoire(vVPlateau, vPion-vVPlateau->tailleSaisie,valeurPion,vJoueur);
            vVPlateau->plateau[vPion]=valeurPion;
		}

}

void fin(){
    printf("\nMerci d'avoir jouer est a bientot pour de nouvelle aventure!!!\n\n");
}

int jouerLigneTest(int longeur, int Ligne){
        if(Ligne<1 || Ligne>longeur)
            return 0;
        return Ligne;
}

int jouerColonneTest(int longeur, int Colonne){
        if(Colonne<1 || Colonne>longeur)
            return 0;
        return Colonne;
}

void t1(Hex* plateau){
    calculeTaille(plateau);
    allouerPlateau(plateau);
    initialiserPlateau(plateau);
    plateau->plateau[7]='R';
    plateau->plateau[15]='B';
    plateau->plateau[20]='R';
    plateau->plateau[26]='R';
    plateau->plateau[28]='B';
}

void t2(Hex* plateau){
    plateau->plateau[7]='R';
    plateau->plateau[13]='R';
    plateau->plateau[19]='R';
    plateau->plateau[25]='R';
    plateau->plateau[31]='R';
}

void t3(Hex* plateau){
    plateau->plateau[19]='B';
    plateau->plateau[20]='B';
    plateau->plateau[21]='B';
    plateau->plateau[22]='B';
    plateau->plateau[23]='B';
}

void t4(Hex* plateau){
    plateau->plateau[7]='R';
    plateau->plateau[13]='R';
    plateau->plateau[14]='R';
    plateau->plateau[15]='R';
    plateau->plateau[21]='R';
    plateau->plateau[22]='R';
    plateau->plateau[28]='R';
    plateau->plateau[34]='R';
}

void t5(Hex* plateau){
    plateau->plateau[8]='B';
    plateau->plateau[9]='B';
    plateau->plateau[10]='B';
    plateau->plateau[11]='B';
    plateau->plateau[14]='B';
    plateau->plateau[20]='B';
    plateau->plateau[21]='B';
    plateau->plateau[22]='B';
    plateau->plateau[28]='B';
    plateau->plateau[31]='B';
    plateau->plateau[32]='B';
    plateau->plateau[33]='B';
    plateau->plateau[34]='B';
}

void t6(Hex* plateau){
    plateau->plateau[7]='R';
    plateau->plateau[13]='R';
    plateau->plateau[21]='R';
    plateau->plateau[22]='R';
    plateau->plateau[28]='R';
    plateau->plateau[34]='R';
}

void t7(Hex* plateau){
    plateau->plateau[7]='R';
    plateau->plateau[13]='R';
    plateau->plateau[14]='R';
    plateau->plateau[15]='R';
    plateau->plateau[16]='R';
    plateau->plateau[19]='R';
    plateau->plateau[21]='R';
    plateau->plateau[22]='R';
    plateau->plateau[25]='R';
    plateau->plateau[26]='R';
    plateau->plateau[27]='R';
    plateau->plateau[28]='R';
    plateau->plateau[34]='R';
}

void t8(Hex* plateau){
    plateau->plateau[8]='B';
    plateau->plateau[9]='B';
    plateau->plateau[10]='B';
    plateau->plateau[11]='B';
    plateau->plateau[31]='B';
    plateau->plateau[32]='B';
    plateau->plateau[33]='B';
    plateau->plateau[34]='B';
}

bool testVerification(Hex plateau){
    if(plateau.victoire==1)
        return true;
    return false;
}


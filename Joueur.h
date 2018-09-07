struct Joueur{
    int numero;
    char pion;
};
typedef struct Hex Hex;
typedef struct Joueur Joueur;

void intitialisationJoueur(Joueur*, Joueur*);
void intitialisationJoueur1(Joueur*);
void intitialisationJoueur2(Joueur*);
void quelJoueur(int);
int changementJoueur(int,Joueur,Joueur);

struct Hex{
    int taille;
    char* plateau;
    int tailleSaisie;
    int victoire;
};
typedef struct Joueur Joueur;
typedef struct Hex Hex;

void debut();
void demandeDeTest();
void testHex();
void jeuDuHex();
void intialiserHex(Hex*);
void allouerPlateau(Hex*);
void saisieTaille(Hex*);
void calculeTaille(Hex*);
void initialiserPlateau (Hex*);
void genererPlateau (Hex*);
void afficherPlateau(Hex);
void partieEnCours(Hex, Joueur, Joueur);
int saisieDuCoup(Hex*); //assert
int jouerLigne(int);// assert
int jouerColonne(int);// assert
bool verificationCaseLibre(int, Hex*); //assert
void placePion(int, Hex*, int);
void Verification(Hex*, int);
void verificationVictoire(Hex*, int, char, int);
void fin();

int jouerLigneTest(int, int);
int jouerColonneTest(int, int);
bool testVerification(Hex);
void t1(Hex*);
void t2(Hex*);
void t3(Hex*);
void t4(Hex*);
void t5(Hex*);
void t6(Hex*);
void t7(Hex*);
void t8(Hex*);

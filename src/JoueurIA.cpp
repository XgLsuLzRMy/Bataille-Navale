#include "JoueurIA.hpp"

JoueurIA::JoueurIA(){

}

void JoueurIA::demanderNom(){
	JoueurIA::nom = "IA";
}

void JoueurIA::demanderTailleGrille(){
	JoueurIA::grille.setTaille(10, 10);
// On a deux IA, on renome donc la premiere InteligenceArtificielle
	JoueurIA::setNom("IntelligenceArtificielle");
}

char JoueurIA::demanderTypeJeu(){
	return 1;
}

void JoueurIA::placementDesBateaux(char typeJeu){
	JoueurIA::affichage->afficherMessage("L'IA place ses bateaux...\n");
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		Joueur::definirBateauxType2(nbMaxDeBateaux, std::min(grille.getHauteur(), grille.getLargeur()));
		for(int i=0;i<Joueur::nbBateaux;i++){
			int tailleBateau = 90;
			tailleBateau = rand()%(grille.getHauteur()/2);
			// on verrifie que cette taile existe
			bool tailleOK = false;
			int x=0;
			while(tailleOK == false && x<nbMaxDeBateaux){
				if (tailleOK == false && Joueur::bateaux[x].getTaille() == tailleBateau){ // le bateau existe et on le place
					JoueurIA::placerBateau(&(Joueur::bateaux[x]));
					// on suprime le bateau de la liste des possibles (on met la taille du bateau utilise a 0)
					Joueur::bateaux[x].setTaille(grille.getHauteur());
				        tailleOK= true;
					break;
				}
				x=x+1;

			}
			if ( tailleOK==false ) {
				i =i-1;
			}
		}
	}	
	else {
		for(int i=0;i<Joueur::nbBateaux;i++){
			JoueurIA::placerBateau(&(Joueur::bateaux[i]));
		}
	}
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grille));
}

void JoueurIA::placerBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	xExtremite =rand()%(JoueurIA::grille.getLargeur()-b.getTaille()) ;
	yExtremite =rand()%(JoueurIA::grille.getHauteur()-b.getTaille()) ;
	orientationInput = rand()%(1);
	if (orientationInput == 0 ) {
		orientationInput ='v';
	}
	else {
		orientationInput ='h';
	}
	}
	b->setOrientation(orientationInput);
	b->setxExtremite(xExtremite);
	b->setyExtremite(yExtremite);
	b->placerSurGrille(&(JoueurIA::grille));
}

int* JoueurIA::tour(){
	int x,y;
	JoueurIA::affichage->afficherMessage("Tour de " + JoueurIA::nom + "\n");
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grille));
	// tour de l'IA
	JoueurIA::affichage->afficherMessage("La grille des tentatives de l'IA : \n");
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grilleTentatives));
	int* res = new int [2];
// une bombe aléatoire
	x =rand()%(JoueurIA::grille.getLargeur()) ;
	y =rand()%(JoueurIA::grille.getHauteur()) ;
	res[0] = x;
	res[1] = y;
	return res;
}

void JoueurIA::resultatBombe(bool touche, int x, int y){
	JoueurIA::marquerResultatBombeSurGrilleTentative(touche, x, y);
}

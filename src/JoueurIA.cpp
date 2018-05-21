#include "JoueurIA.hpp"

JoueurIA::JoueurIA(){

}

void JoueurIA::demanderNom(){
	JoueurIA::nom = "IA";
}

bool JoueurIA::estUneIA(){
	return true;
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
		int tailleBateau;
		bool tailleOK = false;
		int x = 0;
		JoueurIA::definirBateauxType2(nbMaxDeBateaux, std::min(grille.getHauteur(), grille.getLargeur()));
		// L'IA place nbBateaux
		for(int i=0;i<JoueurIA::nbBateaux;i++){
			tailleBateau = rand()%(grille.getHauteur()/2); // chaque bateau du joueur a une taille aleatoire
			// on verrifie que cette taile existe
			tailleOK = false;
			x = 0;
			// boucle pour verifier si la tailleBateau fait partie des tailles possibles dans bateaux
			while(tailleOK == false && x<nbMaxDeBateaux){
				if (JoueurIA::bateaux[x].getTaille() == tailleBateau){ // le bateau existe et on le place
					JoueurIA::placerBateau(&(JoueurIA::bateaux[x]));
					// on suprime le bateau de la liste des possibles (on met la taille du bateau utilise a la hauteur de la grille)
					JoueurIA::bateaux[x].setTaille(grille.getHauteur());
					tailleOK= true;
					//break;
				}
				x=x+1;
			}
			if ( tailleOK==false ) {
				i = i-1; // Le bateau n'a pas été placé donc
				// on génére une nouvelle taille pour ce bateau en faisant un nouveau tour de boucle
			}
		}
	}else { // typeJeu 1
		for(int i=0; i<JoueurIA::nbBateaux; i++){
			JoueurIA::placerBateau(&(JoueurIA::bateaux[i]));
		}
	}
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grille));
}

void JoueurIA::placerBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	bool placementReussi = false;

		xExtremite =rand()%(JoueurIA::grille.getLargeur()-b->getTaille()) ;
		yExtremite =rand()%(JoueurIA::grille.getHauteur()-b->getTaille()) ;
		orientationInput = rand()%(1);
		if (orientationInput == 0 ) {
			orientationInput ='v';
		}
		else {
			orientationInput ='h';
		}
		b->setOrientation(orientationInput);
		b->setxExtremite(xExtremite);
		b->setyExtremite(yExtremite);
		placementReussi = b->placerSurGrille(&(JoueurIA::grille));
		if(!placementReussi){
			Affichage::afficherMessage("mauvais placement \n");
		}
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
	x = rand()%(JoueurIA::grille.getLargeur()) ;
	y = rand()%(JoueurIA::grille.getHauteur()) ;
	res[0] = x;
	res[1] = y;
	return res;
}

void JoueurIA::resultatBombe(bool touche, int x, int y){
	JoueurIA::marquerResultatBombeSurGrilleTentative(touche, x, y);
}

#include "Joueur.hpp"

Joueur::Joueur(){
	// à vérifier : L'appel au constructeur de Joueur se fait tout seul
	Joueur::nom = "Joueur";
	Joueur::nbBateaux = 3;
	Joueur::nbCasesBateauxTouches = 0;
	Joueur::nbCasesBateaux = 0;
	Joueur::bateaux = new Bateau[nbBateaux];
	Bateau b;
	for(int i=0;i<nbBateaux;i++){
		Joueur::bateaux[i] = b;
	}
}

Joueur::~Joueur(){
	delete [] Joueur::bateaux;
}

void Joueur::resetGrilles(){
	Joueur::grille.reset();
	Joueur::grilleTentatives.reset();
}

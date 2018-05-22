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

void Joueur::setNom(std::string nouveauNom){
	Joueur::nom = nouveauNom;
}

void Joueur::setGrille(char **grille, int h, int l){
	Joueur::grille.setGrille(grille);
	Joueur::grille.setTaille(l, h);
}
void Joueur::setGrilleTentatives(char **grilleTentatives){
	Joueur::grilleTentatives.setGrille(grilleTentatives);
}

void Joueur::resetGrilles(){
	Joueur::grille.reset();
	Joueur::grilleTentatives.reset();
}

void Joueur::marquerResultatBombeSurGrilleTentative(bool touche, int x, int y){
	if(touche){
		Joueur::grilleTentatives.set(x, y, TENTATIVEREUSSIE);
	}else{
		Joueur::grilleTentatives.set(x, y, TENTATIVERATEE);
	}
}

void Joueur::marquerResultatBombeSurGrille(bool touche, int x, int y){
	if(touche){
		Joueur::grille.set(x, y, BATEAUTOUCHE);
	}
}

void Joueur::definirBateauxType2(int nbMaxDeBateaux,  int tailleGrille){
	Joueur::bateaux = new Bateau[nbMaxDeBateaux];
	Bateau b;
	for (int i=0; i<nbMaxDeBateaux; i++){
			Joueur::bateaux[i] = b;
			Joueur::bateaux[i].setTaille(rand()%(tailleGrille/2));
	}
}

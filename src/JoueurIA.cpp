#include "JoueurIA.hpp"

JoueurIA::JoueurIA(){

}

bool JoueurIA::estUneIA(){
	return true;
}

void JoueurIA::demanderNom(){
	JoueurIA::nom = "IA";
}

void JoueurIA::demanderTailleGrille(){
	JoueurIA::grille.setTaille(10, 10);
}

char JoueurIA::demanderTypeJeu(){
	return 1;
}

void JoueurIA::placementDesBateaux(char typeJeu){
	JoueurIA::affichage->afficherMessage("L'IA place ses bateaux...\n");
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		//Joueur::definirBateauxType2(nbMaxDeBateaux);
	}

	for(int i=0;i<Joueur::nbBateaux;i++){
		JoueurIA::placerBateau(&(Joueur::bateaux[i]));
	}
}

void JoueurIA::placerBateau(Bateau *b){
	// TODO
}

int* JoueurIA::tour(){
	// TODO
	return NULL;
}

void JoueurIA::resultatBombe(bool touche, int x, int y){
	JoueurIA::marquerResultatBombeSurGrilleTentative(touche, x, y);
}

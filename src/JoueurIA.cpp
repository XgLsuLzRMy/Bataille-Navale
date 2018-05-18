#include "JoueurIA.hpp"

JoueurIA::JoueurIA(){
	std::cout << "Instanciation JoueurIA \n";
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
	std::cout << JoueurIA::nom << ", placement des Bateaux\n";
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		//Joueur::definirBateauxType2(nbMaxDeBateaux);
	}

	for(int i=0;i<Joueur::nbBateaux;i++){
		std::cout << "Encore " << JoueurIA::nbBateaux-i << " bateaux a placer...\n";
		JoueurIA::placerBateau(&(Joueur::bateaux[i]));
	}
}

void JoueurIA::placerBateau(Bateau *b){
	
}

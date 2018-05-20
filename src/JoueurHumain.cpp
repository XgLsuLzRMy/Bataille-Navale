#include <iostream>

#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(){
	std::cout << "Instanciation JoueurHumain \n";
}

void JoueurHumain::demanderNom(){
	std::cout << "Donner votre nom : ";
	std::cin >> JoueurHumain::nom;
	std::cin.clear();
}

void JoueurHumain::demanderTailleGrille(){
	int l = 0;
	int h = 0;
	do{
		std::cout << "Donner la largeur de la grille : ";
		std::cin >> l;
		std::cin.clear();
	}while(l <= 0);
	do{
		std::cout << "Donner la hauteur de la grille : ";
		std::cin >> h;
	}while(h <= 0);
	JoueurHumain::grille.setTaille(l,h);
}

char JoueurHumain::demanderTypeJeu(){
	char choix, typeJeu;
	std::cout << "\nCHOIX DU TYPE DE JEU\n";
	do{
		std::cout << "Type 1 ou 2 ? : ";
		std::cin >> choix;
		std::cin.clear();
	}while(choix != '1' && choix != '2');
	if(choix == '1'){
		typeJeu = 1;
	}else{
		typeJeu = 2;
	}
	return typeJeu;
}

void JoueurHumain::placementDesBateaux(char typeJeu){
	std::cout << JoueurHumain::nom << ", placement des Bateaux\n";
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		//Joueur::definirBateauxType2(nbMaxDeBateaux);
	}

	for(int i=0;i<Joueur::nbBateaux;i++){
		std::cout << "Encore " << JoueurHumain::nbBateaux-i << " bateaux a placer...\n";
		JoueurHumain::placerBateau(&(Joueur::bateaux[i]));
	}
}

void JoueurHumain::placerBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	bool joueurValidePlacement = false;
	bool placementReussi = false;
	int tailleBateau = b->getTaille();
	while(!joueurValidePlacement){
		grille.afficher();
		std::cout << "Bateau de taille " << tailleBateau << "\n";

		demanderCoordonneesBateau(b);

		placementReussi = b->placerSurGrille(&(JoueurHumain::grille));

		if(placementReussi){
			JoueurHumain::grille.afficher();
			std::cout << "Placement correct (o/n) ?: ";
			char c;
			std::cin >> c;
			std::cin.clear();
			if(c=='o'){
				joueurValidePlacement = true;
			}else{
				joueurValidePlacement = false;
				b->retirerDeLaGrille(&(JoueurHumain::grille));
			}
		}
	}
}

void JoueurHumain::demanderCoordonneesBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	do{
		std::cout << "xExtremite : ";
		std::cin >> xExtremite;
		std::cin.clear();
		xExtremite = xExtremite-1; // car sur l'affichage du joueur les coordonnees commencent en 1
	}while(xExtremite<0 || xExtremite>JoueurHumain::grille.getLargeur()-1);
	do{
		std::cout << "yExtremite : ";
		std::cin >> yExtremite;
		std::cin.clear();
		yExtremite = yExtremite-1; // car sur l'affichage du joueur les coordonnees commencent en 1
	}while(yExtremite<0 || yExtremite>JoueurHumain::grille.getHauteur()-1);
	do{
		std::cout << "orientation ('v' ou 'h') : ";
		std::cin >> orientationInput;
		std::cin.clear();
	}while(orientationInput!='v' && orientationInput!='h');

	b->setOrientation(orientationInput);
	b->setxExtremite(xExtremite);
	b->setyExtremite(yExtremite);
}

int* JoueurHumain::tour(){
	std::cout << "Tour de " << JoueurHumain::nom << "\n";
	JoueurHumain::grille.afficher();
	// tour du joueur
	std::cout << "La grille de vos tentatives : \n";
	JoueurHumain::grilleTentatives.afficher();
	return donnerCoordonneesBombes();
}

int* JoueurHumain::donnerCoordonneesBombes(){
	int x,y;
	do{
		std::cout << "Donner la coordonnee en x : ";
		std::cin >> x;
		std::cin.clear();
		std::cout << "Donner la coordonnee en y : ";
		std::cin >> y;
		std::cin.clear();
		x--;
		y--;
	}while(x<0 || y<0 || x>JoueurHumain::grille.getLargeur() || y>JoueurHumain::grille.getHauteur());
	int* res = new int [2];
	res[0] = x;
	res[1] = y;
	return res;
}

void JoueurHumain::resultatBombe(bool touche, int x, int y){
	JoueurHumain::marquerResultatBombeSurGrilleTentative(touche, x, y);
	if (touche){
		std::cout << "Touche !\n";
	}else{
		std::cout << "Dommage...\n";
	}
}

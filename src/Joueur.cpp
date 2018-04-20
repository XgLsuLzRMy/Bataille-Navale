#include <iostream>

#include "Joueur.hpp"


Joueur::Joueur(){
	Joueur::nom = "Joueur";
	Joueur::nbBateaux = 3;
	bateaux = new Bateau[nbBateaux];
	Bateau b;
	for(int i=0;i<nbBateaux;i++){
		Joueur::bateaux[i] = b;
	}
}

void Joueur::initialiserNom(){
	std::cout << "Donner le nom du joueur : ";
	std::cin >> Joueur::nom;
}

void Joueur::initialiserGrille(){
	Joueur::grille.initialiserGrille();
	
}

void Joueur::resetGrille(){
	Joueur::grille.reset();
}

void Joueur::placementDesBateaux(char typeJeu){
	std::cout << Joueur::nom << ", placement des Bateaux\n";
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
	}
	
	for(int i=0;i<Joueur::nbBateaux;i++){
		std::cout << Joueur::nbBateaux-i << " bateaux a placer...\n";
		ajoutBateau(&Joueur::bateaux[i]);
	}
}

void Joueur::tour(){
	std::cout << "Tour de " << Joueur::nom << "\n";
	Joueur::grille.afficher();
	if (!Joueur::isIA){
		// tour du joueur
	}else{
		// Tour de l'IA
	}
}

// On passe b par pointeur pour pouvoir le modifier (le joueur choisit l'orientation et les coordonnees)
// Le bateau existe deja avant cette fonction puisque le joueur a choisi le nombre et la taille de ses bateaux
// Il suffit donc de modifier la position et l'orientation du bateau existant
void Joueur::ajoutBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	bool ok = false;
	int tailleBateau = (*b).getTaille();
	while(!ok){
		Joueur::grille.afficher();
		std::cout << "Bateau de taille " << tailleBateau << "\n";
		do{
			std::cout << "xExtremite : ";
			std::cin >> xExtremite;
			xExtremite = xExtremite-1; // car sur l'affichage du joueur les coordonnees commencent en 1
		}while(xExtremite<0 || xExtremite>Joueur::grille.tailleHorizontal-1);
		do{
			std::cout << "yExtremite : ";
			std::cin >> yExtremite;
			yExtremite = yExtremite-1; // car sur l'affichage du joueur les coordonnees commencent en 1
		}while(yExtremite<0 || yExtremite>Joueur::grille.tailleVertical-1);
		do{
			std::cout << "orientation ('v' ou 'h') : ";
			std::cin >> orientationInput;
		}while(orientationInput!='v' && orientationInput!='h');
		
		(*b).setOrientation(orientationInput);
		(*b).setxExtremite(xExtremite);
		(*b).setyExtremite(yExtremite);
		
		
		
		int** coordonneesBateau = (*b).getCoordonneesCompletes();
		
		ok = Joueur::placerBateau(coordonneesBateau, tailleBateau);
		
		if(ok){
			Joueur::grille.afficher();
			std::cout << "Placement correct (o/n) ?: ";
			char c;
			std::cin >> c;
			if(c!='o'){
				ok = false;
				retirerBateau(coordonneesBateau, tailleBateau);
			}
		}
	}
	
	
}

void Joueur::retirerBateau(int** coordonneesBateau, int taille){
	for(int i=0;i<taille;i++){
			Joueur::grille.grille[coordonneesBateau[i][0]][coordonneesBateau[i][1]] = 0;
		}
}

bool Joueur::placerBateau(int** coordonneesBateau, int taille){
	// verifier qu'il n'y ait pas deja de bateau à l'emplacement ou l'on souhaite placer b
	
	if(verifierPlace(coordonneesBateau, taille)){
		for(int i=0;i<taille;i++){
			Joueur::grille.grille[coordonneesBateau[i][0]][coordonneesBateau[i][1]] = 1;
		}
	return true;
	}else{
		std::cout << "Erreur : pas de place a cet emplacement\n";
		return false;
	}
	
}

bool Joueur::verifierPlace(int** coordonneesBateau, int taille){
	
	for (int i=0;i<taille;i++){
		if(coordonneesBateau[i][0]>=Joueur::grille.tailleVertical || coordonneesBateau[i][1]>=Joueur::grille.tailleHorizontal){
			return false;
		}else{
			if(Joueur::grille.grille[coordonneesBateau[i][0]][coordonneesBateau[i][1]] != 0){
				return false;
			}
		}
	}
	return true;
}
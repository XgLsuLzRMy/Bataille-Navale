#include <iostream>
#include "Bateau.hpp"

Bateau::Bateau(){
	Bateau::taille = 3;
	Bateau::orientation = false;
	Bateau::xExtremite = 0;
	Bateau::yExtremite = 0;
}

bool Bateau::placerSurGrille(Grille *grille){
	int **coordonneesBateau = Bateau::getCoordonneesCompletes();
	if(grille->verifierPlace(coordonneesBateau, Bateau::taille)){
		for(int i=0; i < Bateau::taille; i++){
			grille->set(coordonneesBateau[i][1], coordonneesBateau[i][0], BATEAU);
		}
		return true;
	}else{
		return false;
	}
}

void Bateau::retirerDeLaGrille(Grille *grille){
	int **coordonneesBateau = Bateau::getCoordonneesCompletes();
	for(int i=0; i<Bateau::taille; i++){
		grille->set(coordonneesBateau[i][1], coordonneesBateau[i][0], EAU);
	}
}

void Bateau::setTaille(int taille){
	if (taille>0){
		Bateau::taille = taille;
	}else{
		//std::cout << "Erreur taille bateau (" << taille << ")\n";
	}
}
void Bateau::setxExtremite(int xExtremite){
	if (xExtremite>0){
		Bateau::xExtremite = xExtremite;
	}else{
		//std::cout << "Erreur xExtremite bateau (" << xExtremite << ")\n";
	}
}
void Bateau::setyExtremite(int yExtremite){
	if (yExtremite>0){
		Bateau::yExtremite = yExtremite;
	}else{
		//std::cout << "Erreur yExtremite bateau (" << yExtremite << ")\n";
	}
}
void Bateau::setOrientation(char orientation){
	if(orientation == 'v'){
		Bateau::orientation = true;
	}else if (orientation == 'h'){
		Bateau::orientation = false;
	}else{
		Bateau::orientation = false;
		//std::cout << "Erreur orientation bateau (" << orientation << ")\n";
	}
}

bool Bateau::getOrientation(){
	return Bateau::orientation;
}
int Bateau::getTaille(){
	return Bateau::taille;
}
int Bateau::getxExtremite(){
	return Bateau::xExtremite;
}
int Bateau::getyExtremite(){
	return Bateau::yExtremite;
}

// renvoie un tableau contenant tous les (x,y) occuppes par le bateau
int** Bateau::getCoordonneesCompletes(){
	int** res = new int*[Bateau::taille];
	for (int i=0;i<Bateau::taille;i++){
		res[i] = new int [2];
	}
	// si vertical
	if (Bateau::orientation){
		for(int i=0;i<Bateau::taille;i++){
			res[i][1] = xExtremite;
			res[i][0] = yExtremite + i;
		}
	}else{ // si horizontal
		for(int i=0;i<Bateau::taille;i++){
			res[i][1] = xExtremite + i;
			res[i][0] = yExtremite;
		}
	}
	return res;
}

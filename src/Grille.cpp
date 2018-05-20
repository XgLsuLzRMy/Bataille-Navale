#include "Grille.hpp"

int Grille::largeur = 10;
int Grille::hauteur = 10;

Grille::Grille(){
	Grille::grille = null;
}

Grille::~Grille(){
	delete [] Grille::grille;
}

void Grille::reset(){
	if(Grille::grille!=null){
		delete [] Grille::grille;
	}
	Grille::grille = new char* [Grille::hauteur];
	for (int i=0;i<Grille::hauteur;i++){
		Grille::grille[i] = new char [Grille::largeur];
	}

	for (int i=0;i<Grille::hauteur;i++){
		for (int j=0;j<Grille::largeur;j++){
			Grille::grille[i][j] = EAU;
		}
	}
}

bool Grille::verifierPlace(int **tableauDeCoordonnees, int taille){
	for (int i=0; i<taille; i++){
		if((tableauDeCoordonnees[i][0] >= Grille::hauteur) || (tableauDeCoordonnees[i][1] >= Grille::largeur)){
			return false;
		}else{
			if(Grille::grille[tableauDeCoordonnees[i][0]][tableauDeCoordonnees[i][1]] != EAU){
				return false;
			}
		}
	}
	return true;
}

bool Grille::fini(){
	for (int i=0;i<Grille::hauteur;i++){
		for(int j=0;j<Grille::largeur;j++){
			if(Grille::grille[i][j]==BATEAU){
				return false;
			}
		}
	}
	return true;
}

// Accesseurs

char Grille::get(int x, int y){
	return Grille::grille[y][x];
}

int Grille::getHauteur(){
	return Grille::hauteur;
}

int Grille::getLargeur(){
	return Grille::largeur;
}

void Grille::set(int x, int y, char valeur){
	Grille::grille[y][x] = valeur;
}

void Grille::setTaille(int largeur, int hauteur){
	if(largeur>0 && hauteur>0){
		Grille::largeur = largeur;
		Grille::hauteur = hauteur;
	}
}

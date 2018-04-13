#include <iostream>

#include "Grille.hpp"

int Grille::tailleHorizontal = 10;
int Grille::tailleVertical = 10;

Grille::Grille(){
	
}

Grille::~Grille(){
	delete [] Grille::grille;
}

void Grille::initialiserGrille(){
	do{
		std::cout << "Donner la largeur de la grille : ";
		std::cin >> Grille::tailleHorizontal;
	}while(Grille::tailleHorizontal <=0);
	do{
		std::cout << "Donner la hauteur de la grille : ";
		std::cin >> Grille::tailleVertical;
	}while(Grille::tailleVertical<=0);
	
	
}

void Grille::reset(){
	
	
	std::cout << "Initialisation d'une grille de taille " << Grille::tailleHorizontal << " x " << Grille::tailleVertical << ".\n";
	Grille::grille = new char* [Grille::tailleVertical];
	for (int i=0;i<Grille::tailleVertical;i++){
		Grille::grille[i] = new char [Grille::tailleHorizontal];
	}
	
	for (int i=0;i<Grille::tailleVertical;i++){
		for (int j=0;j<Grille::tailleHorizontal;j++){
			Grille::grille[i][j] = 0;
		}
	}
}

void Grille::afficher(){
	std::cout << "    ";
	for(int i=0;i<Grille::tailleHorizontal;i++){
		std::cout << " " << i+1;
	}
	std::cout << "\n   +";
	for (int j=0;j<2*Grille::tailleHorizontal-1;j++){
		std::cout << "-";
	}
	std::cout << "+\n";
	for (int i=0;i<Grille::tailleVertical;i++){
		std::cout << i+1 << "-";
		if(i+1<10){
			std::cout << " "; // aligner a cause du caractere supplementaire de la dizaine
		}
		for (int j=0;j<Grille::tailleHorizontal;j++){
			std::cout << "|";
			switch (Grille::grille[i][j]){
				case 0:
					std::cout << " ";
					break;
				case 1:
					std::cout << "*";
					break;
				case 2:
					std::cout << "$";
					break;
				default:
					std::cout << "#";
			}
		}
		
		std::cout << "|\n";
		if (i<Grille::tailleVertical-1){
			std::cout << "   |";
			
			for (int j=0;j<2*Grille::tailleHorizontal-1;j++){
				std::cout << "-";
			}
			std::cout << "|\n";
		}
	}
	std::cout << "   +";
	for (int j=0;j<2*Grille::tailleHorizontal-1;j++){
		std::cout << "-";
	}
	std::cout << "+\n";
}

bool Grille::fini(){
	for (int i=0;i<Grille::tailleVertical;i++){
		for(int j=0;j<Grille::tailleHorizontal;j++){
			if(Grille::grille[i][j]==1){
				return false;
			}
		}
	}
	return true;
}

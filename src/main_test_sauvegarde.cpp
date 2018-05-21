#include <iostream>

#include "GestionSauvegarde.hpp"

int main(){

	GestionSauvegarde g("sauvegarde.sav");
	std::string nom = g.lireNomJoueur('1');
	if (nom != ERREUR){
		std::cout << "==" << nom << "==\n";
	}else{
		std::cout << "erreur\n";
	}

	int hauteur = g.lireHauteurGrille("grille1");
	if(hauteur != -1){
		std::cout << "hauteur : " << hauteur << "\n";
	}

	int largeur = g.lireLargeurGrille("grille1");
	if(largeur != -1){
		std::cout << "largeur : " << largeur << "\n";
	}

	char** grille1 = g.lireGrille("grille1");
	if(grille1[0][0] != -1){
		for(int i=0; i<5; i++){
			std::cout << "|";
			for (int j=0; j<5; j++){
				switch(grille1[i][j]){
					case 0:
						std::cout << "~ ";
					break;
					case 1:
						std::cout << "* ";
					break;
					default:
						std::cout << "$ ";
				}
			}
			std::cout << "|";
			std::cout << "\n";
		}

	}

	std::string nouveauNom = "ceNouveauNom";
	std::cout << "On renomme Joueur1 " << nouveauNom << "\n";
	g.ecrireNomJoueur('1', nouveauNom);

	nom = g.lireNomJoueur('1');
	if (nom != ERREUR){
		std::cout << "==" << nom << "==\n";
	}else{
		std::cout << "erreur\n";
	}

}

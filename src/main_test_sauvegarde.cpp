#include <iostream>
#include <fstream>
#include "GestionSauvegarde.hpp"
#include <string>

int main(){

	/*GestionSauvegarde g("sauvegarde.sav");

	std::string nom = g.lireNomJoueur('1');
	if (nom != ERREURATTRIBUT){
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

	std::string nouveauNom = "nomDuJoueur2";
	std::cout << "On modifie l'attribut nomJoueur2 " << nouveauNom << "\n";
	g.ecrireNomJoueur('2', nouveauNom);

	nom = g.lireNomJoueur('2');
	if (nom != ERREURATTRIBUT){
		std::cout << "==" << nom << "==\n";
	}else{
		std::cout << "erreur\n";
	}

	std::cout << "Modification de la grille 1\n";
	grille1[0][0] = 2;
	g.ecrireGrille("grille1", grille1, 5, 5);


	GestionSauvegarde g2("sauvegarde2.sav");
		g2.nouvelleSauvegarde(true);

	std::string* liste = GestionSauvegarde::getListeSauvegardes();
	if(!liste[0].empty()){
		int i = 0;
		while(liste[i] != "__FIN__"){
			std::cout << i << ") " << liste[i] << '\n';
			i++;
		}
	}else{
		std::cout << "liste vide\n";
	}*/

	GestionSauvegarde::supprimerSauvegarde("sauvegarde2.sav");

}

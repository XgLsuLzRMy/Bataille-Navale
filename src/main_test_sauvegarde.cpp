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
}

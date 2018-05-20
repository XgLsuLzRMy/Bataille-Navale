#include <iostream>

#include "GestionSauvegarde.hpp"

int main(){

	GestionSauvegarde g("sauvegarde.sav");
	g.ecrireNomJoueur('1', "toto");
	g.lireNomJoueur('1');
}

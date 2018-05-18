#include <iostream>

#include "GestionSauvegarde.hpp"

int main(){
	
	GestionSauvegarde g("sauvegader.sav");
	char* s = g.lire("IA");
	std::cout << s << "\n";
}

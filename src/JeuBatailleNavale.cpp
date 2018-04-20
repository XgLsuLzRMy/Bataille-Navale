#include "JeuBatailleNavale.hpp"

#include <iostream>


JeuBatailleNavale::JeuBatailleNavale(){
	
}

void JeuBatailleNavale::initialiserNomJoueur(char nbJoueurs){
	
	JeuBatailleNavale::nbJoueursHumains = 0;
	if(nbJoueurs<0 || nbJoueurs>2){
		std::cout << "Erreur : nombre de joueurs incorrect (" << nbJoueurs <<")\n";
	}else if (nbJoueurs != 0){
		JeuBatailleNavale::joueur1.initialiserNom();
		JeuBatailleNavale::joueur2.initialiserNom();
		JeuBatailleNavale::nbJoueursHumains = 2;
		std::cout << "Les joueurs sont " << JeuBatailleNavale::joueur1.nom << " et " << JeuBatailleNavale::joueur2.nom << ".\n";
	}else{
		JeuBatailleNavale::joueur1.initialiserNom();
		JeuBatailleNavale::nbJoueursHumains = 1;
		std::cout << "Les joueurs sont " << JeuBatailleNavale::joueur1.nom << " et " << JeuBatailleNavale::joueur2.nom << ".\n";
	}
	
}



void JeuBatailleNavale::nouveauJeu(){
	char choix = 0;
	std::cout << "\n\n1-Joueur contre joueur\n2-Joueur contre IA\n3-IA contre IA\n> ";
	std::cin >> choix;
	switch(choix){
		case '1':
			initialiserNomJoueur(2);
		break;
		case 'q':
			std::cout << "Au revoir\n";
		break;
		default:
			std::cout << "Pas encore dispo\n";
			nouveauJeu();
	}
	if (choix != 'q'){
		JeuBatailleNavale::joueur1.initialiserGrille();
		JeuBatailleNavale::joueur1.resetGrille(); // on initialise avec 1 joueur car la taille de la grille est commune aux deux joueurs
		JeuBatailleNavale::joueur2.resetGrille(); // il suffit donc de remplir la grille de 0 pour chaque joueur
		
		choisirTypeJeu();
		
		JeuBatailleNavale::joueur1.placementDesBateaux(JeuBatailleNavale::typeJeu);
		JeuBatailleNavale::joueur2.placementDesBateaux(JeuBatailleNavale::typeJeu);
		
		bool fini = false;
		int tour = 0;
		while (!fini){
			if(tour==0){
				JeuBatailleNavale::joueur1.tour();
			}else{
				JeuBatailleNavale::joueur2.tour();
			}
			tour = (tour+1)%2; // on passe au tour du joueur suivant
			fini = JeuBatailleNavale::checkFinJeu();
		}
		// Si la partie est finie et que c'est le tour du joueur1 alors c'est que c'est suite
		// au tour de joueur2 que la partie se termine. Donc c'est joueur2 qui a gagne. Et inversement.
		// (c'est parce qu'on actualise 'tour' a la fin de la boucle while)
		std::cout << "\n\n=============\n";
		if (tour == 2){
			std::cout << JeuBatailleNavale::joueur1.nom;
		}else{
			std::cout << JeuBatailleNavale::joueur2.nom;
		}
		std::cout << " a gagne la partie\n=============\n";
	}
	
}

void JeuBatailleNavale::choisirTypeJeu(){
	char choix;
	std::cout << "\nCHOIX DU TYPE DE JEU\n";
	do{
		std::cout << "Type 1 ou 2 ? : ";
		std::cin >> choix;
	}while(choix != '1' && choix != '2');
	if(choix == '1'){
		JeuBatailleNavale::typeJeu = 1;
	}else{
		JeuBatailleNavale::typeJeu = 2;
	}
}

bool JeuBatailleNavale::checkFinJeu(){
	return (JeuBatailleNavale::joueur1.grille.fini() || JeuBatailleNavale::joueur2.grille.fini());
}
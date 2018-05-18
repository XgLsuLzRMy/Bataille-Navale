#include "JeuBatailleNavale.hpp"

JeuBatailleNavale::JeuBatailleNavale(){
	
}

void JeuBatailleNavale::demanderNomJoueurs(){
	JeuBatailleNavale::joueur1->demanderNom();
	JeuBatailleNavale::joueur2->demanderNom();
}

void JeuBatailleNavale::instanciationDesJoueurs(char choix){
	switch(choix){
		case '1':
			JeuBatailleNavale::joueur1 = new JoueurHumain();
			JeuBatailleNavale::joueur2 = new JoueurHumain();
		break;
		case '2':
			JeuBatailleNavale::joueur1 = new JoueurHumain();
			JeuBatailleNavale::joueur2 = new JoueurIA();
		break;
		case '3':
			JeuBatailleNavale::joueur1 = new JoueurIA();
			JeuBatailleNavale::joueur2 = new JoueurIA();
		break;
		case 'q':
			std::cout << "Au revoir\n";
		break;
		default:
			std::cout << "Pas encore dispo\n";
			JeuBatailleNavale::nouveauJeu();
	}
}

void JeuBatailleNavale::nouveauJeu(){
	char choix = 0;
	std::cout << "\n\n1-Joueur contre joueur\n2-Joueur contre IA\n3-IA contre IA\nq-quitter\n> ";
	std::cin >> choix;
	JeuBatailleNavale::instanciationDesJoueurs(choix);
	if (choix != 'q'){
		JeuBatailleNavale::demanderNomJoueurs();
		JeuBatailleNavale::joueur1->demanderTailleGrille(); // seul le joueur 1 choisit la taille de la grille puisque cette taille est commune aux deux joueurs. On ne demande pas la taille directement dans JeuBatailleNavale mais dans Joueur car si les 2 joueurs sont des IA alors on ne peut pas faire de cin dans JeuBatailleNavale alors qu'avec l'hérédité de Joueur on n'a pas ce pb.

		JeuBatailleNavale::joueur1->resetGrilles();
		JeuBatailleNavale::joueur2->resetGrilles();
		
		JeuBatailleNavale::typeJeu = JeuBatailleNavale::joueur1->demanderTypeJeu();
		
		JeuBatailleNavale::joueur1->placementDesBateaux(JeuBatailleNavale::typeJeu);
		JeuBatailleNavale::joueur2->placementDesBateaux(JeuBatailleNavale::typeJeu);
	}
}


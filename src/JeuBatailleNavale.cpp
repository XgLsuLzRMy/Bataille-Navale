#include "JeuBatailleNavale.hpp"

JeuBatailleNavale::JeuBatailleNavale(){

}

JeuBatailleNavale::JeuBatailleNavale(std::string nomJoueur1, std::string nomJoueur2, char typeJeu, bool IA1, bool IA2, char** grille1, char** grilleTentatives1, char** grille2, char** grilleTentatives2, int h, int l){
	if(IA1){
		JeuBatailleNavale::joueur1 = new JoueurIA();
	}else{
		JeuBatailleNavale::joueur1 = new JoueurHumain();
	}
	if(IA2){
		JeuBatailleNavale::joueur2 = new JoueurIA();
	}else{
		JeuBatailleNavale::joueur2 = new JoueurHumain();
	}
	JeuBatailleNavale::joueur1->setNom(nomJoueur1);
	JeuBatailleNavale::joueur2->setNom(nomJoueur2);

	JeuBatailleNavale::joueur1->setGrille(grille1, h, l);
	JeuBatailleNavale::joueur2->setGrille(grille2, h, l);

	JeuBatailleNavale::joueur1->setGrilleTentatives(grilleTentatives1);
	JeuBatailleNavale::joueur2->setGrilleTentatives(grilleTentatives2);

	Affichage::afficherMessage("Chargement de la sauvegarde reussi\n");
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
		Affichage::afficherMessage("Au revoir.\n");
		break;
		default:
		Affichage::afficherMessage("Pas encore dispo.\n");
		JeuBatailleNavale::nouveauJeu();
	}
}

bool JeuBatailleNavale::joueurPlaceBombe(bool joueur, int xBombe, int yBombe){
	if(!joueur){
		if(JeuBatailleNavale::joueur2->grille.get(xBombe,yBombe) != 0){
			return true;
		}else{
			return false;
		}
	}else{
		if(JeuBatailleNavale::joueur1->grille.get(xBombe,yBombe) != 0){
			return true;
		}else{
			return false;
		}
	}
}

void JeuBatailleNavale::nouveauJeu(){
	char choix = Affichage::menuPrincipal();
	JeuBatailleNavale::instanciationDesJoueurs(choix);
	if (choix != 'q'){
		JeuBatailleNavale::demanderNomJoueurs();
		JeuBatailleNavale::joueur1->demanderTailleGrille(); // seul le joueur 1 choisit la taille de la grille puisque cette taille est commune aux deux joueurs. On ne demande pas la taille directement dans JeuBatailleNavale mais dans Joueur car si les 2 joueurs sont des IA alors on ne peut pas faire de cin dans JeuBatailleNavale alors qu'avec l'hérédité de Joueur on n'a pas ce pb.

		JeuBatailleNavale::joueur1->resetGrilles();
		JeuBatailleNavale::joueur2->resetGrilles();

		JeuBatailleNavale::typeJeu = JeuBatailleNavale::joueur1->demanderTypeJeu();

		JeuBatailleNavale::joueur1->placementDesBateaux(JeuBatailleNavale::typeJeu);
		JeuBatailleNavale::joueur2->placementDesBateaux(JeuBatailleNavale::typeJeu);

		JeuBatailleNavale::jouer();
	}
}

void JeuBatailleNavale::jouer(bool tour){
	bool fini = false;
	//int tour = 0;
	//bool tour = false; // le joueur 1 commence en premier
	int* coordonneesBombes = new int [2];
	Joueur* joueurEnCours;
	Joueur* joueurEnAttente;
	while (!fini){
		if(tour){
			joueurEnCours = JeuBatailleNavale::joueur2;
			joueurEnAttente = JeuBatailleNavale::joueur1;
		}else{
			joueurEnCours = JeuBatailleNavale::joueur1;
			joueurEnAttente = JeuBatailleNavale::joueur2;
		}
		coordonneesBombes = joueurEnCours->tour();
		bool touche = joueurPlaceBombe(tour, coordonneesBombes[0], coordonneesBombes[1]);
		joueurEnCours->resultatBombe(touche, coordonneesBombes[0], coordonneesBombes[1]);
		joueurEnAttente->resultatBombeAdverse(touche, coordonneesBombes[0], coordonneesBombes[1]);

		Affichage::attendreJoueurSuivant();

		//tour = (tour+1)%2; // on passe au tour du joueur suivant
		tour = !tour;
		fini = JeuBatailleNavale::checkFinJeu();
	}
	// Si la partie est finie et que c'est le tour du joueur1 alors c'est que c'est suite
	// au tour de joueur2 que la partie se termine. Donc c'est joueur2 qui a gagne. Et inversement.
	// (c'est parce qu'on actualise 'tour' a la fin de la boucle while)

	if (tour){
		Affichage::afficherGagnant(JeuBatailleNavale::joueur1->nom + " a gagne la partie\n=============\n");
	}else{
		Affichage::afficherGagnant(JeuBatailleNavale::joueur2->nom + " a gagne la partie\n=============\n");
	}
}

bool JeuBatailleNavale::checkFinJeu(){
	return (JeuBatailleNavale::joueur1->grille.fini() || JeuBatailleNavale::joueur2->grille.fini());
}

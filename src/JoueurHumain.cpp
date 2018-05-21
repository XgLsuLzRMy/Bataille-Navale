#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(){

}

void JoueurHumain::demanderNom(){
	JoueurHumain::nom = JoueurHumain::affichage->demanderNom();
}

void JoueurHumain::demanderTailleGrille(){
	int l = 0;
	int h = 0;
	do{
		l = JoueurHumain::affichage->demanderDimensionGrille("largeur");
	}while(l <= 0);
	do{
		h = JoueurHumain::affichage->demanderDimensionGrille("hauteur");
	}while(h <= 0);
	JoueurHumain::grille.setTaille(l,h);
}

char JoueurHumain::demanderTypeJeu(){
	char choix, typeJeu;
	do{
		choix = JoueurHumain::affichage->choixTypeJeu();
	}while(choix != '1' && choix != '2');
	if(choix == '1'){
		typeJeu = 1;
	}else{
		typeJeu = 2;
	}
	return typeJeu;
}

void JoueurHumain::placementDesBateaux(char typeJeu){
	JoueurHumain::affichage->afficherMessage("\n\n" + JoueurHumain::nom + ", placement des Bateaux\n");
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		Joueur::definirBateauxType2(nbMaxDeBateaux, std::min(grille.getHauteur(), grille.getLargeur()));
		//annonce le nombre de bateaux a placer
		for(int i=0;i<Joueur::nbBateaux;i++){
			std::stringstream sstm; // pour concatener un int et une string
			sstm << "Encore " << JoueurHumain::nbBateaux-i << " bateaux a placer...\n";
			std::string str = sstm.str();
			JoueurHumain::affichage->afficherMessage(str);
			// afficher les bateaux possibles
			JoueurHumain::affichage->afficherMessage("vous pouvez placer les bateaux de tailles suivantes : \n");
			sstm.clear(); // pour concatener un int et une string
			std::stringstream sstp;
			for (int x=0;x<nbMaxDeBateaux;x++){
				if (Joueur::bateaux[x].getTaille() != grille.getHauteur()){
					sstp << Joueur::bateaux[x].getTaille() << "\n";
				}
			}
			std::string listeTaille = sstp.str();
			JoueurHumain::affichage->afficherMessage(listeTaille);
			sstp.clear();
			// demande la taille du bateau qui va etre placer
			int tailleBateau = 90;
			tailleBateau = JoueurHumain::affichage->demanderTailleBateau();
			// on verrifie que cette taile existe
			bool tailleOK = false;
			int x=0;
			//for (int x=0;x<nbMaxDeBateaux-i;x++){
			while(tailleOK == false && x<nbMaxDeBateaux){
				if (tailleOK == false && Joueur::bateaux[x].getTaille() == tailleBateau){ // le bateau existe et on le place
					JoueurHumain::placerBateau(&(Joueur::bateaux[x]));
					// on suprime le bateau de la liste des possibles (on met la taille du bateau utilise a 0)
					Joueur::bateaux[x].setTaille(grille.getHauteur());
				        tailleOK= true;
					break;	
				}
				x=x+1;

			}
			if ( tailleOK==false ) {
				i =i-1;
				JoueurHumain::affichage->afficherMessage("la taille demandée n'est pas valide \n");
			}
		}
	}
	else {
		for(int i=0;i<Joueur::nbBateaux;i++){
			std::stringstream sstm; // pour concatener un int et une string
			sstm << "Encore " << JoueurHumain::nbBateaux-i << " bateaux a placer...\n";
			std::string str = sstm.str();
			JoueurHumain::affichage->afficherMessage(str);
			JoueurHumain::placerBateau(&(Joueur::bateaux[i]));
		}
	}
}

void JoueurHumain::placerBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	bool joueurValidePlacement = false;
	bool placementReussi = false;
	int tailleBateau = b->getTaille();
	while(!joueurValidePlacement){
		JoueurHumain::affichage->afficherGrille(&(JoueurHumain::grille));
		std::stringstream sstm; // pour concatener un int et une string
		sstm << "Bateau de taille " << tailleBateau << "\n";
		std::string str = sstm.str();
		JoueurHumain::affichage->afficherMessage(str);
		demanderCoordonneesBateau(b);

		placementReussi = b->placerSurGrille(&(JoueurHumain::grille));

		if(placementReussi){
			JoueurHumain::affichage->afficherGrille(&(JoueurHumain::grille));
			char c = JoueurHumain::affichage->demanderPlacementCorrect();
			if(c=='o'){
				joueurValidePlacement = true;
			}else{
				joueurValidePlacement = false;
				b->retirerDeLaGrille(&(JoueurHumain::grille));
			}
		}
	}
}

void JoueurHumain::demanderCoordonneesBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	do{
		xExtremite = JoueurHumain::affichage->demanderCoordonneesBateau('x');
		xExtremite--; // car sur l'affichage du joueur les coordonnees commencent en 1
	}while(xExtremite<0 || xExtremite>JoueurHumain::grille.getLargeur()-1);
	do{
		yExtremite = JoueurHumain::affichage->demanderCoordonneesBateau('y');
		yExtremite--; // car sur l'affichage du joueur les coordonnees commencent en 1
	}while(yExtremite<0 || yExtremite>JoueurHumain::grille.getHauteur()-1);
	do{
		orientationInput = JoueurHumain::affichage->demanderOrientationBateau();
	}while(orientationInput!='v' && orientationInput!='h');

	b->setOrientation(orientationInput);
	b->setxExtremite(xExtremite);
	b->setyExtremite(yExtremite);
}

int* JoueurHumain::tour(){
	JoueurHumain::affichage->afficherMessage("Tour de " + JoueurHumain::nom + "\n");
	JoueurHumain::affichage->afficherGrille(&(JoueurHumain::grille));
	// tour du joueur
	JoueurHumain::affichage->afficherMessage("La grille de vos tentatives : \n");
	JoueurHumain::affichage->afficherGrille(&(JoueurHumain::grilleTentatives));
	return donnerCoordonneesBombes();
}

int* JoueurHumain::donnerCoordonneesBombes(){
	int x,y;
	do{
		x = JoueurHumain::affichage->demanderCoordonneesBombe('x');
		y = JoueurHumain::affichage->demanderCoordonneesBombe('y');
		x--;
		y--;
	}while(x<0 || y<0 || x>JoueurHumain::grille.getLargeur() || y>JoueurHumain::grille.getHauteur());
	int* res = new int [2];
	res[0] = x;
	res[1] = y;
	return res;
}

void JoueurHumain::resultatBombe(bool touche, int x, int y){
	JoueurHumain::marquerResultatBombeSurGrilleTentative(touche, x, y);
	if (touche){
		JoueurHumain::affichage->afficherMessage("Touche !\n");
	}else{
		JoueurHumain::affichage->afficherMessage("Dommage...\n");
	}
}

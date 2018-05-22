#include "JoueurIA.hpp"

JoueurIA::JoueurIA(){

}

void JoueurIA::demanderNom(){
	JoueurIA::nom = "IA";
}

bool JoueurIA::estUneIA(){
	return true;
}


void JoueurIA::demanderTailleGrille(){
	JoueurIA::grille.setTaille(10, 10);
	// On a deux IA, on renome donc la premiere InteligenceArtificielle
	JoueurIA::setNom("IntelligenceArtificielle");
}

char JoueurIA::demanderTypeJeu(){
	return 2;
}

int* JoueurIA::retirerDeLaListe(int *liste, int taille, int ind){
	int *res = new int[taille-1];
	int decal = 0;
	for(int i=0; i<taille; i++){
		if(i!=ind){
			res[i-decal] = liste[i];
		}else{
			decal = 1;
		}
	}
	delete [] liste;
	return res;
}

void JoueurIA::placementDesBateaux(char typeJeu){
	JoueurIA::affichage->afficherMessage("L'IA place ses bateaux...\n");
	if (typeJeu!=1){
		// il faut demander le nb de bateaux et leur taille
		int nbMaxDeBateaux = 5;
		JoueurIA::definirBateauxType2(nbMaxDeBateaux, std::min(grille.getHauteur(), grille.getLargeur()));
		int tailleBateau;
		bool tailleOK = false;
		int x = 0;
		// L'IA place nbBateaux
		int *listeDesNumerosDeBateauxPossibles = new int[nbMaxDeBateaux];
		// initialisation de la liste à [0 1 2 3 ... nbMaxDeBateaux] puisque n'importe quel bateau peut etre choisi au depart
		for(int i=0; i<nbMaxDeBateaux; i++){
			listeDesNumerosDeBateauxPossibles[i] = i;
		}
		int tailleListe = nbMaxDeBateaux;
		int numeroChoisi = -1;
		// Pour chaque bateau à placer, on crée une liste des numeros de bateaux possibles
		// Lorsque l'ia choisit un bateau, on enleve le numero de ce bateau de la liste et on recommence
		for(int i=0; i<JoueurIA::nbBateaux; i++){
			numeroChoisi = rand()%tailleListe;
			JoueurIA::placerBateau(&(JoueurIA::bateaux[listeDesNumerosDeBateauxPossibles[numeroChoisi]]));
			listeDesNumerosDeBateauxPossibles = JoueurIA::retirerDeLaListe(listeDesNumerosDeBateauxPossibles, tailleListe, numeroChoisi);
			tailleListe--;
		}

		/*for(int i=0;i<JoueurIA::nbBateaux;i++){
		tailleBateau = rand()%(grille.getHauteur()/2); // chaque bateau du joueur a une taille aleatoire
		// on verrifie que cette taile existe
		tailleOK = false;
		x = 0;
		// boucle pour verifier si la tailleBateau fait partie des tailles possibles dans bateaux
		while(tailleOK == false && x<nbMaxDeBateaux){
		if (JoueurIA::bateaux[x].getTaille() == tailleBateau){ // le bateau existe et on le place
		JoueurIA::placerBateau(&(JoueurIA::bateaux[x]));
		// on suprime le bateau de la liste des possibles (on met la taille du bateau utilise a la hauteur de la grille)
		JoueurIA::bateaux[x].setTaille(grille.getHauteur());
		tailleOK= true;
		//break;
	}
	x=x+1;
}
if ( tailleOK==false ) {
i = i-1; // Le bateau n'a pas été placé donc
// on génére une nouvelle taille pour ce bateau en faisant un nouveau tour de boucle
}
}*/
}else { // typeJeu 1
	for(int i=0; i<JoueurIA::nbBateaux; i++){
		JoueurIA::placerBateau(&(JoueurIA::bateaux[i]));
	}
}
JoueurIA::affichage->afficherGrille(&(JoueurIA::grille));
}

void JoueurIA::placerBateau(Bateau *b){
	int xExtremite, yExtremite;
	char orientationInput;
	bool orientation;
	bool placementReussi = false;
	int xExtremiteMax = JoueurIA::grille.getLargeur()-b->getTaille() + 1;
	int yExtremiteMax = JoueurIA::grille.getHauteur()-b->getTaille() + 1;
	int nbTentativesDePlacement = 0;
	int nbTentativesDePlacementMax = 20;
	while(!placementReussi && nbTentativesDePlacement<nbTentativesDePlacementMax){
		xExtremite =trunc(rand()%(xExtremiteMax) + 1) ;
		yExtremite =trunc(rand()%(yExtremiteMax) + 1) ;
		orientationInput = round(rand()%(2));
		if (orientationInput == 0 ) {
			orientationInput ='v';
		}
		else {
			orientationInput ='h';
		}
		b->setOrientation(orientationInput);
		b->setxExtremite(xExtremite);
		b->setyExtremite(yExtremite);
		placementReussi = b->placerSurGrille(&(JoueurIA::grille));
		nbTentativesDePlacement++;
	}
	if(nbTentativesDePlacement>=nbTentativesDePlacementMax){
		Affichage::afficherMessage("L'IA n'a pas reussi a placer tous ses bateaux...\n");
	}
}

int* JoueurIA::determinerCoordonneesBombesScan(){
	int* res = new int [2];
	int i = 0;
	int j = 0;
	int x = -1;
	int y = -1;
	for(int i=0; i<JoueurIA::grilleTentatives.getHauteur(); i++){
		for(int j=0; j<JoueurIA::grilleTentatives.getLargeur(); j++){
			if(JoueurIA::grilleTentatives.get(j, i) == EAU){
				x = j;
				y = i;
				i = JoueurIA::grilleTentatives.getHauteur();
				j = JoueurIA::grilleTentatives.getLargeur();
			}
		}
	}
	res[0] = x;
	res[1] = y;
	return res;
}

int* JoueurIA::determinerCoordonneesBombesAleatoire(){
	int* res = new int [2];
	int x = rand()%(JoueurIA::grille.getLargeur()) ;
	int y = rand()%(JoueurIA::grille.getHauteur()) ;
	res[0] = x;
	res[1] = y;
	return res;
}

int* JoueurIA::tour(){
	int x,y;
	JoueurIA::affichage->afficherMessage("Tour de " + JoueurIA::nom + "\n");
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grille));
	// tour de l'IA
	JoueurIA::affichage->afficherMessage("La grille des tentatives de l'IA : \n");
	JoueurIA::affichage->afficherGrille(&(JoueurIA::grilleTentatives));
	int* res = new int [2];
	// une bombe aléatoire
	//res = JoueurIA::determinerCoordonneesBombesAleatoire();
	res = JoueurIA::determinerCoordonneesBombesScan();
	return res;
}

void JoueurIA::resultatBombe(bool touche, int x, int y){
	JoueurIA::marquerResultatBombeSurGrilleTentative(touche, x, y);
}
void JoueurIA::resultatBombeAdverse(bool touche, int x, int y){
	JoueurIA::marquerResultatBombeSurGrille(touche, x, y);
}

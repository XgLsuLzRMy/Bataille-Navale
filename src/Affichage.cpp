#include "Affichage.hpp"

void Affichage::afficherMessage(std::string message){
  std::cout << message;
}

char Affichage::proposerNouveauJeuOuSauvegarde(){
  char choix = 0;
  std::cout << "Voulez-vous,\n1) Faire un nouveau jeu ?\n2) Charger une sauvegarde ?\n3) Supprimer une sauvegarde\n";
  std::cin >> choix;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return choix;
}

char Affichage::proposerSauvegarder(){
  char choix = 0;
  std::cout << "Voulez-vous,sauvegarder (o/n) ?\n";
  std::cin >> choix;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return choix;
}

std::string Affichage::demanderNomSauvegarde(){
  std::string res;
  std::cout << "Donner le nom de la sauvegarde : \n";
  getline(std::cin, res);
  return res;
}

char Affichage::choixSauvegarde(std::string *liste){
  char choix = 0;
  int i = 0;
  while(liste[i] != "__FIN__"){
    std::cout << i+1 << ") " << liste[i] << '\n';
    i++;
  }
  std::cin >> choix;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return choix;
}

char Affichage::menuPrincipal(){
  char choix = 0;
	std::cout << "\n\n1-Joueur contre joueur\n2-Joueur contre IA\n3-IA contre IA\nq-quitter\n> ";
	std::cin >> choix;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return choix;
}

void Affichage::attendreJoueurSuivant(){
  std::cout << "Appuyer sur entree pour passer au tour du joueur suivant\n";
  std::cin.get();
  std::cin.ignore();
}

void Affichage::afficherGagnant(std::string nom){
  std::cout << "\n============================\nLe gagnant est " << nom <<  "!\n============================\n";
}

std::string Affichage::demanderNom(){
  std::string nom;
  std::cout << "Donner votre nom : ";
  std::cin >> nom;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return nom;
}

int Affichage::demanderDimensionGrille(std::string nomDeLaDimension){
  int res = 0;
  std::cout << "Donner la " << nomDeLaDimension << " de la grille : ";
  std::cin >> res;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return res;
}

char Affichage::choixTypeJeu(){
  char choix;
  std::cout << "\nCHOIX DU TYPE DE JEU\n";
  std::cout << "Type 1 ou 2 ? : ";
  std::cin >> choix;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return choix;
}

void Affichage::afficherGrille(Grille *grille){
  std::cout << "   ";
	for(int i=0;i<grille->largeur;i++){
		std::cout << " " << i+1;
	}
	std::cout << "\n   +";
	for (int j=0;j<2*grille->largeur-1;j++){
		std::cout << "-";
	}
	std::cout << "+\n";
	for (int i=0;i<grille->hauteur;i++){
		std::cout << i+1 << "-";
		if(i+1<10){
			std::cout << " "; // aligner a cause du caractere supplementaire de la dizaine
		}
		for (int j=0;j<grille->largeur;j++){
			std::cout << "|";
			switch (grille->grille[i][j]){
				case EAU:
				std::cout << "~";
				break;
				case BATEAU:
				std::cout << "*";
				break;
				case BATEAUTOUCHE:
				std::cout << "$";
				break;
				case TENTATIVEREUSSIE:
				std::cout << "&";
				break;
				case TENTATIVERATEE:
				std::cout << "-";
				break;
				default:
				std::cout << "#";
			}
		}

		std::cout << "|\n";
		if (i<grille->hauteur-1){
			std::cout << "   |";

			for (int j=0;j<2*grille->largeur-1;j++){
				std::cout << "-";
			}
			std::cout << "|\n";
		}
	}
	std::cout << "   +";
	for (int j=0;j<2*grille->largeur-1;j++){
		std::cout << "-";
	}
	std::cout << "+\n";
}

char Affichage::demanderPlacementCorrect(){
  std::cout << "Placement correct (o/n) ?: ";
  char c;
  std::cin >> c;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return c;
}

int Affichage::demanderCoordonneesBateau(char coordonnee){
  int res = 0;
  std::cout << coordonnee << "Extremite : ";
  std::cin >> res;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return res;
}

char Affichage::demanderOrientationBateau(){
  char orientationInput;
  std::cout << "orientation ('v' ou 'h') : ";
  std::cin >> orientationInput;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return orientationInput;
}

int Affichage::demanderTailleBateau() {
  int taille = 0;
  std::cout << "taille du bateau choisis : ";
  std::cin >> taille;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return taille;
}

int Affichage::demanderCoordonneesBombe(char coordonnee){
  int res = 0;
  std::cout << "Donner la coordonnee en " << coordonnee << " : ";
  std::cin >> res;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  return res;
}

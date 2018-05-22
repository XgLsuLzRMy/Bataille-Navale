#include "JeuBatailleNavale.hpp"
#include "Affichage.hpp"
#include "GestionSauvegarde.hpp"

#include <string>
#include <iostream>
#include <time.h>

int main(){
	char choix;
	srand(time(NULL));
	do{
		choix = Affichage::proposerNouveauJeuOuSauvegarde();
	}while(choix!='1' && choix!='2' && choix!='3' && choix!='q');
	if(choix == '1'){
		JeuBatailleNavale j;
		j.nouveauJeu();
	}else{
		char choixSauvegarde;
		std::string* liste = GestionSauvegarde::getListeSauvegardes();
		if(!liste[0].empty()){
			int nbSave = 0;
			while(liste[nbSave] != "__FIN__"){
				nbSave++;
			}
			do{
				choixSauvegarde = Affichage::choixSauvegarde(liste);
			}while(choixSauvegarde-'0'<1 || choixSauvegarde-'0'>nbSave);
			int numSave = choixSauvegarde-'0'-1;
			if(choix == '2'){
				GestionSauvegarde g(liste[numSave]);

				char** grille1 = g.lireGrille("grille1");
				char** grilleTentatives1 = g.lireGrille("grilleTentatives1");
				char** grille2 = g.lireGrille("grille2");
				char** grilleTentatives2 = g.lireGrille("grilleTentatives2");
				int h = g.lireHauteurGrille("grille1");
				int l = g.lireLargeurGrille("grille1");
				std::string nomJoueur1 = g.lireNomJoueur('1');
				std::string nomJoueur2 = g.lireNomJoueur('2');
				std::string joueurEnCoursStr = g.lireAttribut("joueurEnCours"); // variable temporaire
				bool tour = joueurEnCoursStr=="2";
				std::string typeJeuStr = g.lireAttribut("typeJeu"); // variable temporaire
				char typeJeu;
				if(typeJeuStr[0]=='1'){
					typeJeu = 1;
				}else if(typeJeuStr[0]=='2'){
					typeJeu = 2;
				}else{
					std::cout << "erreur type jeu\n";
				}
				std::string IA1Str = g.lireAttribut("IA1"); // variable temporaire
				bool IA1 = IA1Str == "1";
				std::string IA2Str = g.lireAttribut("IA2"); // variable temporaire
				bool IA2 = IA2Str == "1";

				Affichage::afficherMessage("nomJouer1 = " + nomJoueur1 + "\n");
				Affichage::afficherMessage("nomJouer2 = " + nomJoueur2 + "\n");
				std::cout << "typeJeu = " << typeJeu << "\n";
				std::cout << "tour = " << tour << "\n";
				std::cout << "IA1 = " << IA1 << "\n";
				std::cout << "IA2 = " << IA2 << "\n";

				JeuBatailleNavale j(nomJoueur1, nomJoueur2, typeJeu, IA1, IA2, grille1, grilleTentatives1, grille2, grilleTentatives2, h, l);
				j.jouer(tour);
			}else if(choix == '3'){
				GestionSauvegarde::supprimerSauvegarde(liste[numSave]);
			}
		}else{
			std::cout << "Pas de sauvegarde...\n";
		}

	}
}

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

#include <sstream> // pour concatener string et int
#include <string>
//#include <cstdlib> //pour la fonction rand
#include <stdlib.h>
//#include <ctime> //pour la fonction rand
#include <time.h>
#include "Grille.hpp"
#include "Bateau.hpp"
#include "Affichage.hpp"

class Joueur{
protected:
	// Le nom du joueur
	std::string nom;
	// La grille sur laquelle le joueur place ses bateaux
	Grille grille;
	// La grille permettant de garder en mémoire les tentatives de bombes effectuées par le joueur
	Grille grilleTentatives;
	// Correspond au nombre de fois que l'adversaire a touché un bateau.Va être incrementé quand un des bateaux est touché pour faciliter la vérification de la fin de partie.
	int nbCasesBateauxTouches;
	// Le nombre de cases occupées par des bateaux sur la grille
	int nbCasesBateaux;
	// Le nombre de bateau initial du joueur. Permet de simplifier l'écriture de certaines boucles. ( i < nbBateaux etc)
	int nbBateaux;
	// Un tableau contenant les bateaux possédés par le joueur et qu'il a placé sur la grille.
	Bateau* bateaux;
	// Un affichage
	Affichage* affichage;

	virtual void placerBateau(Bateau *b) {};

	void marquerResultatBombeSurGrilleTentative(bool touche, int x, int y);
	void marquerResultatBombeSurGrille(bool touche, int x, int y);

public:
	Joueur();
	~Joueur();

	virtual bool estUneIA() {};

	void resetGrilles();

	/**
	* \fn public demanderNom()
	* \brief initialise le nom du joueur en demandant le nom au joueur
	*
	*/

	void definirBateauxType2(int nbMaxDeBateaux, int tailleGrille);

	void setNom(std::string nouveauNom);
	void setGrille(char **grille, int h, int l);
	void setGrilleTentatives(char **grilleTentatives);

	virtual void demanderNom() {};
	/**
	* \fn public demanderTailleGrile()
	* \brief initialise la taille de la grille en la demandant au joueur
	*
	*/
	virtual void demanderTailleGrille() {};
	/**
	* \fn private choisirTypeJeu()
	* \brief fonction qui permet au joueur de choisir son type de jeu : bataille classique ou bataille
	* améliorée
	*/
	virtual char demanderTypeJeu() {};

	/**
	* \fn private placementDesBateaux(char typeJeu)
	* \brief  demande au joueur de placer ses différents bateaux. Utilise
	* ajoutBateau pour chaqun des bateaux du joueur.
	*
	* \param  typeJeu le type de jeu choisis
	*/
	virtual void placementDesBateaux(char typeJeu) {};

	virtual int* tour() {};

	virtual void resultatBombe(bool touche, int x, int y) {};
	virtual void resultatBombeAdverse(bool touche, int x, int y) {};

	friend class JeuBatailleNavale; // on met JeuBatailleNavale en amie pour qu'on puisse acceder a nom directement mais on pourrait faire par accesseurs

};
#endif

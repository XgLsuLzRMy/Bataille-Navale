/*!
* \file Joueur.hpp
* \brief classe Joueur
* \author Groupe B7
* \version 0.1
* \date 22 mai 2018
* Classe joueur regroupant les fonctionnalités générales sur le joueur
*
*/

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
/*!
* \class Joueur
* \brief classe  Joueur regroupant les fonctionnalités générales sur le joueur
*
*/

class Joueur{
protected:

	std::string nom;  /*!< Le nom du joueur*/

	Grille grille; /*!< La grille sur laquelle le joueur place ses bateaux*/

	Grille grilleTentatives; /*!< La grille permettant de garder en mémoire les tentatives de bombes effectuées par le joueur*/

	int nbCasesBateauxTouches; /*!< Correspond au nombre de fois que l'adversaire a touché un bateau.Va être incrementé quand un des bateaux est touché pour faciliter la vérification de la fin de partie. */

	int nbCasesBateaux; /*!< Le nombre de cases occupées par des bateaux sur la grille*/

	int nbBateaux;  /*!</ Le nombre de bateau initial du joueur. Permet de simplifier l'écriture de certaines boucles. ( i < nbBateaux etc)*/

	Bateau* bateaux; /*!< Un tableau contenant les bateaux possédés par le joueur et qu'il a placé sur la grille.*/
	Affichage* affichage;

	/**
	* \fn protected placerBateau(Bateau *b)
	*
	* \brief Permet au joueur de positionner le bateau \p *b sur la grille. Cette fonction lui demande les coordonnées en x, y du bateau (en utilisant la fonction demanderCoordonneesBateau) mais aussi son orientation.
	* \param *b: Un pointeur sur le bateau que le joueur va placer sur la grille.
	*/
	virtual void placerBateau(Bateau *b) {};
	/**
	* \fn protected marquerResultatBombeSurGrilleTentative(bool touche, int x, int y)
	*
	* \brief function permettant de modifier une case de la grille des tentatives sachant les conséquences de la bombe
	* \param touche, x, y: les coordonnées de la position à modifier, et touche: l'indication si la bombe a atteint sa cible
	*/

	void marquerResultatBombeSurGrilleTentative(bool touche, int x, int y);
	/**
	* \fn protected marquerResultatBombeSurGrille(bool touche, int x, int y);
	*
	* \brief function permettant de modifier une case de la grille sachant les conséquences de la bombe
	* \param touche, x, y: les coordonnées de la position à modifier, et touche: l'indication si la bombe a atteint sa cible
	*/
	void marquerResultatBombeSurGrille(bool touche, int x, int y);

public:
	/**
	* \fn public Joueur()
	*
	* \brief Constructeur de la classe Joueur qui met ses caractéristiques en ses valeurs par défaut
	*
	*/
	Joueur();
	~Joueur();

	/**
	* \fn public estUneIA()
	*
	* \brief Permet de savoir si ce joueur est une IA. Est utile lorsque l'on manipule un Joueur et que l'on ne sait pas s'il est IA ou Humain.
	* \return true si c'est une IA, false sinon.
	*/
	virtual bool estUneIA() {};

	/**
	* \fn public resetGrilles()
	*
	* \brief fonction qui alloue la mémoire pour la grille et la grille des tentatives et les remplie de 0, donc d'eau
	*
	*/
	void resetGrilles();

	/**
	* \fn public definirBateauxType2(int nbMaxDeBateaux, int tailleGrille)
	*
	* \brief function permettant de définir un tableau de bateaux de tailles aléatoires
	*  \param nbMaxDeBateaux,  tailleGrille: le nombre de bateaux du tableau et la taille de la grille
	*/
	void definirBateauxType2(int nbMaxDeBateaux, int tailleGrille);
	/**
	* \fn public setNom(std::string nouveauNom)
	*
	* \brief fonction qui modifie l'attribut nom
	*
	* \param nouveauNom
	*
	*/

	void setNom(std::string nouveauNom);
	/**
	* \fn public setGrille(char **grille, int h, int l)
	*
	* \brief fonction qui modifie les caractéristiques de la grille
	* \param grille, h, l: grille: object modifié, hauteur, largueur
	*
	*/
	void setGrille(char **grille, int h, int l);
	/**
	* \fn public setGrilleTentatives(char **grilleTentatives)
	*
	* \brief fonction qui modifie l'attribut grilleTentatives
	*
	* \param **grilleTentatives
	*
	*/
	void setGrilleTentatives(char **grilleTentatives);
	/**
	* \fn public demanderNom()
	* \brief initialise le nom du joueur en demandant le nom au joueur
	*
	*/
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
	/**
	* \fn public tour()
	*
	* \brief Permet de placer une bombe, affiche aussi la grille et la grille de tentatives.
	* \return Les coordonnées de la bombe cible. Sous la forme d'un tableau [x, y].
	*/
	virtual int* tour() {};
	/**
	* \fn public resultatBombe(bool touche, int x, int y)
	*
	* \brief Notifie le joueur si sa bombe a touché l'adversaire.
	* \param touche: true si la bombe a touché un navire adverse, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur avait choisie.
	*/
	virtual void resultatBombe(bool touche, int x, int y) {};
	/**
	* \fn public resultatBombeAdverse(bool touche, int x, int y)
	*
	* \brief Notifie le joueur si la bombe de l'adversaire l'a touché.
	* \param touche: true si la bombe a touché un navire, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur adverse avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur adverse avait choisie.
	*/
	virtual void resultatBombeAdverse(bool touche, int x, int y) {};

	friend class JeuBatailleNavale; // on met JeuBatailleNavale en amie pour qu'on puisse acceder a nom directement mais on pourrait faire par accesseurs

};
#endif

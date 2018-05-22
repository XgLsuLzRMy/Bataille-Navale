#ifndef __JEUBATAILLENAVALE_HPP__
#define __JEUBATAILLENAVALE_HPP__

/**
* \file JeuBatailleNavale.hpp
* \brief classe JeuBatailleNavale
* \author groupe B7
* \version 0.1
* \date 22 mai 2018
*
* Classe JeuBatailleNavale, classe principale qui contrôle la partie entre les deux joueurs.
*
*/

#include "Affichage.hpp"
#include "Joueur.hpp"
#include "JoueurHumain.hpp"
#include "JoueurIA.hpp"
#include "GestionSauvegarde.hpp"
/*!
* \class JeuBatailleNavale
* \brief classe qui gère le déroulement du jeu de Bataille Navale.
*
*/
class JeuBatailleNavale{
private:
	Joueur *joueur1; /*!< le premier joueur de la partie */
	Joueur *joueur2; /*!< le deuxième joueur de la partie */
	char typeJeu; /*!< le type de jeu : une bataille navalle normale ou améliorée */

	/**
	* \fn private instanciationDesJoueurs(char choix)
	* \brief Modifie joueur1 et joueur2 en isntanciant JoueurHumain ou JoueurIA.
	* \param choix 1: 2 joueurs humains, 2: 1 joueur humain et 1 joueur IA, 3: 2 joueurs IA
	*/
	void instanciationDesJoueurs(char choix);

	/**
	* \fn private demanderNomJoueurs()
	* \brief initialise le nom du/des joueur/s.
	*
	*/
	void demanderNomJoueurs();
	/**
	* \fn private  joueurPlaceBombe(bool joueur, int xBombe, int yBombe)
	*
	* \brief fonction qui verifie qu'à une position donnée, la grille de l'adversaire ne contient pas d'eau
	*
	* \param joueur, xBombe, yBombe
	* \return true si la case de la grille adverse ne contient pas d'eau
	*/

	bool joueurPlaceBombe(bool joueur, int xBombe, int yBombe);
	/**
	* \fn private ecrireSauvegarde(std::string nomSauvegarde, bool tour)
	*
	* \brief fonction qui effectue une sauvegarde après un tour
	*
	* \param nomSauvegarde, tour
	*/

	void ecrireSauvegarde(std::string nomSauvegarde, bool tour);

public:

	/**
	* \fn public JeuBatailleNavale()
	* \brief Constructeur de la classe.
	*
	*/
	JeuBatailleNavale();
	/**
	* \fn public JeuBatailleNavale(std::string nomJoueur1, std::string nomJoueur2, char typeJeu, bool IA1, bool IA2, char** grille1, char** grilleTentatives1, char** grille2, char** grilleTentatives2, int h, int l);
	* \brief Constructeur de la classe permettant de choisir l'initialisation des paramètres pour le chargement d'une sauvegarde.
	*
	*/
	JeuBatailleNavale(std::string nomJoueur1, std::string nomJoueur2, char typeJeu, bool IA1, bool IA2, char** grille1, char** grilleTentatives1, char** grille2, char** grilleTentatives2, int h, int l);


	/**
	* \fn public nouveauJeu()
	* \brief commence un nouveau jeu, demande au joueur si quels serons les jeurs : 2 IA, 2 humains ou un humain et une IA. Modifie l'attribut typeJeu.
	*
	*/
	void nouveauJeu();

	/**
	* \fn public jouer(bool tour = false)
	*
	* \brief fonction qui verifie si la partie est finie, demande au joueur des coordonnées de bombes, et informe le joueur adverse si un de ses bateaux a été touché
	*
	* \param tour
	*/
	void jouer(bool tour = false);

	/**
	* \fn private checkFinJeu()
	* \brief Fonction pour déterminer si le jeu est fini.
	*
	* \return 0 si ce n'est pas la fin du jeu et 1 si c'est la fin du jeu.
	*/
	bool checkFinJeu();

};

#endif

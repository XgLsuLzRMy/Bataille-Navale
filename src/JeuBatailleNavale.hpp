#ifndef __JEUBATAILLENAVALE_HPP__
#define __JEUBATAILLENAVALE_HPP__

/**
* \file JeuBatailleNavale.hpp
* \brief classe JeuBatailleNavale
* \author groupe B7
* \version 0.1
* \date 13 Avril 2018
*
* Classe JeuBatailleNavale, classe principale qui contrôle la partie entre les deux joueurs.
*
*/

#include "Affichage.hpp"
#include "Joueur.hpp"
#include "JoueurHumain.hpp"
#include "JoueurIA.hpp"

class JeuBatailleNavale{
private:
	Joueur *joueur1, *joueur2; /*!< les joueurs de la partie */
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

	bool joueurPlaceBombe(bool joueur, int xBombe, int yBombe);


public:

	/**
	* \fn public JeuBatailleNavale()
	* \brief Constructeur de la classe.
	*
	*/
	JeuBatailleNavale();

	JeuBatailleNavale(std::string nomJoueur1, std::string nomJoueur2, char typeJeu, bool IA1, bool IA2, char** grille1, char** grilleTentatives1, char** grille2, char** grilleTentatives2, int h, int l);


	/**
	* \fn public nouveauJeu()
	* \brief commence un nouveau jeu, demande au joueur si quels serons les jeurs : 2 IA, 2 humains ou un humain et une IA. Modifie l'attribut typeJeu.
	*
	*/
	void nouveauJeu();

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

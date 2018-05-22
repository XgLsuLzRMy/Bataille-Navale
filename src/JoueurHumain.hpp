#ifndef __JOUEURHUMAIN_HPP__
#define __JOUEURHUMAIN_HPP__

/**
* \file JoueurHumain.hpp
* \brief classe JoueurHumain
* \author groupe B7
* \version 0.1
* \date 13 Avril 2018
*
* Classe JoueurHumain, classe qui contrôle ce que peuvent faire les joueurs humains durant la partie.
*
*/

#include "Joueur.hpp"

/*! \class JoueurHumain
* \brief classe representant le joueur qui est humain. Cette classe hérite de la classe Joueur
*
*  La classe gere les actions du joueur.
*/

class JoueurHumain : public Joueur {
private:
	/**
	* \fn private placerBateau(Bateau *b)
	*
	* \brief Permet au joueur de positionner le bateau \p *b sur la grille. Cette fonction lui demande les coordonnées en x, y du bateau (en utilisant la fonction demanderCoordonneesBateau) mais aussi son orientation.
	* \param *b: Un pointeur sur le bateau que le joueur va placer sur la grille.
	*/
	virtual void placerBateau(Bateau *b);
	/**
	* \fn private demanderCoordonneesBateau(Bateau *b)
	*
	* \brief Demande au joueur les coordonnées en x et y du bateau afin de le positionner sur la grille.
	* \param *b: Un pointeur sur le bateau que le joueur va placer sur la grille.
	*/
	void demanderCoordonneesBateau(Bateau *b);
	/**
	* \fn private donnerCoordonneesBombes()
	*
	* \brief Demande au joueur les coordonnées en x et y de la bombe qu'il souhaite envoyer sur les bateaux adverses.
	* \return Un tableau représentant les coordonnées en x et en y de la forme [x, y].
	*/
	int* donnerCoordonneesBombes();
public:
	/**
	* \fn public JoueurHumain()
	*
	* \brief Constructeur de JoueurHumain.
	*/
	JoueurHumain();
	/**
	* \fn public estUneIA()
	*
	* \brief Permet de savoir si ce joueur est une IA. Est utile lorsque l'on manipule un Joueur et que l'on ne sait pas s'il est IA ou Humain.
	* \return true si c'est une IA, false sinon.
	*/
	virtual bool estUneIA();
	/**
	* \fn public demanderNom()
	*
	* \brief Demande au joueur d'entrer son nom. Cette fonction modifie l'attribut nom.
	*/
	virtual void demanderNom();
	/**
	* \fn public demanderTailleGrille()
	*
	* \brief Demande au joueur la largeur et la hauteur de la grille sur laquelle il souhaite jouer.
	*/
	virtual void demanderTailleGrille();
	/**
	* \fn public demanderTypeJeu()
	*
	* \brief Demande au joueur selon quel type de jeu de Bataille Navale il souhaite jouer. Le type de jeu est soit 1 soit 2.
	* \return le type de jeu. Vaudra soit 1 soit 2. Attention il s'agit de la valeur 1 ou 2 et non du caractère '1' ou '2'.
	*/
	virtual char demanderTypeJeu();
	/**
	* \fn public placementDesBateaux(char typeJeu)
	*
	* \brief Permet au joueur de placer tous ses bateaux sur la grille. Fais appel à la fonction placerBateau(Bateau *b).
	* \param typeJeu: Le type de jeu auquel le joueur joue. Cela influence le nombre de bateaux et leur taille.
	*/
	virtual void placementDesBateaux(char typeJeu);
	/**
	* \fn public tour()
	*
	* \brief Permet au joueur de placer une bombe. Lui affiche aussi sa grille et sa grille de tentatives.
	* \return Les coordonnées de la bombe que le joueur souhaite placer. Sous la forme d'un tableau [x, y].
	*/
	virtual int* tour();
	/**
	* \fn public resultatBombe(bool touche, int x, int y)
	*
	* \brief Notifie le joueur si sa bombe a touché l'adversaire. On modifie alors sa grille en conséquence.
	* \param touche: true si la bombe a touché un navire adverse, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur avait choisie.
	*/
	virtual void resultatBombe(bool touche, int x, int y);
	/**
	* \fn public resultatBombeAdverse(bool touche, int x, int y)
	*
	* \brief Notifie le joueur si la bombe de l'adversaire l'a touché.
	* \param touche: true si la bombe a touché un navire, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur adverse avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur adverse avait choisie.
	*/
	virtual void resultatBombeAdverse(bool touche, int x, int y);
};
#endif

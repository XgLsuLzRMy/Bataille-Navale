#ifndef __JOUEURIA_HPP__
#define __JOUEURIA_HPP__

/**
* \file JoueurIA.hpp
* \brief classe JoueurIA
* \author groupe B7
* \version 0.1
* \date 13 Avril 2018
*
* Classe Joueur IA, classe qui contrôle ce que peuvent faire les joueurs IA durant la partie.
*
*/
#include <math.h>
#include "Joueur.hpp"

/*! \class JoueurIA
* \brief classe representant le joueur qui est IA. Cette classe hérite de la classe Joueur
*
*  La classe gere les actions du joueur.
*/

class JoueurIA : public Joueur {
private:
	/**
	* \fn private placerBateau(Bateau *b)
	*
	* \brief Permet au joueur de positionner le bateau \p *b sur la grille. Cette fonction lui génère les coordonnées en x, y du bateau et son orientation.
	* \param *b: Un pointeur sur le bateau que l'IA va placer sur la grille.
	*/
	virtual void placerBateau(Bateau *bateau);
	/**
	* \fn private retirerDeLaListe(int *liste, int taille, int ind)
	*
	* \brief Retire la valeur présente à l'indice \p ind de la liste \p liste. Il s'agit d'une liste d'indices correspondant aux bateaux que l'IA peut choisir. Cette liste est utilisée dans placementDesBateaux(char typeJeu)
	* \param *liste: La liste que l'on va recopier en retirant un élément puis en renvoyer cet copie.
	* \param taille: La taille de la \p liste.
	* \param ind: L'indice de l'élément de la \p liste que l'on souhaite supprimer.
	* \return Une liste identique à \p liste mais avec l'élément à l'indice \p ind supprimé.
	*/
	int* retirerDeLaListe(int *liste, int taille, int ind);
	/**
	* \fn private determinerCoordonneesBombesAleatoire()
	*
	* \brief L'IA choisit d'envoyer une bombe à des coordonnées aléatoires sur la grille de l'adversaire.
	* \return Les coordonnées de la bombe sous la forme d'un tableau [x, y].
	*/
	int* determinerCoordonneesBombesAleatoire();
	/**
	* \fn private determinerCoordonneesBombesScan()
	*
	* \brief L'IA choisit d'envoyer une bombe en partant de la coordonnée [0, 0] puis [1, 0] etc [0, 1] etc [n, n]. Elle balaye donc la grille de haut en bas et de gauche à droite.
	* \return Les coordonnées de la bombe sous la forme d'un tableau [x, y].
	*/
	int* determinerCoordonneesBombesScan();
public:
	/**
	* \fn public JoueurIA()
	*
	* \brief Constructeur de JoueurIA.
	*/
	JoueurIA();
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
	* \brief L'IA donnera "IA" comme nom.
	*/
	virtual void demanderNom();
	/**
	* \fn public demanderTailleGrille()
	*
	* \brief L'IA donnera toujours 10x10 comme taille de grille.
	*/
	virtual void demanderTailleGrille();
	/**
	* \fn public demanderTypeJeu()
	*
	* \brief L'IA donnera toujours un jeu de type 2.
	* \return le type de jeu. Vaudra soit 1 soit 2. Attention il s'agit de la valeur 1 ou 2 et non du caractère '1' ou '2'.
	*/
	virtual char demanderTypeJeu();
	/**
	* \fn public placementDesBateaux(char typeJeu)
	*
	* \brief Permet à l'IA de placer tous ses bateaux sur la grille. L'IA choisit d'abord de façon aléatoire quels bateaux elle va placer. Puis fais appel à la fonction placerBateau(Bateau *b).
	* \param typeJeu: Le type de jeu auquel l'IA joue. Cela influence le nombre de bateaux et leur taille.
	*/
	virtual void placementDesBateaux(char typeJeu);
	/**
	* \fn public tour()
	*
	* \brief Permet à l'IA de placer une bombe. Lui affiche aussi sa grille et sa grille de tentatives. Les coordonnées de la bombe sont déterminées à l'aide d'une fonction comme determinerCoordonneesBombesScan() ou determinerCoordonneesBombesAleatoire().
	* \return Les coordonnées de la bombe que l'IA souhaite placer. Sous la forme d'un tableau [x, y].
	*/
	virtual int* tour();
	/**
	* \fn public resultatBombe(bool touche, int x, int y)
	*
	* \brief Notifie l'IA si sa bombe a touché l'adversaire. On modifie alors sa grille en conséquence.
	* \param touche: true si la bombe a touché un navire adverse, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur avait choisie.
	*/
	virtual void resultatBombe(bool touche, int x, int y);
	/**
	* \fn public resultatBombeAdverse(bool touche, int x, int y)
	*
	* \brief Notifie l'IA si la bombe de l'adversaire l'a touché.
	* \param touche: true si la bombe a touché un navire, false sinon.
	* \param x: La coordonnée en x de la bombe que le joueur adverse avait choisie.
	* \param y: La coordonnée en y de la bombe que le joueur adverse avait choisie.
	*/
	virtual void resultatBombeAdverse(bool touche, int x, int y);
};
#endif

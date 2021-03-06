
/**
* \file Grille.hpp
* \brief classe Grille
* \author groupe B7
* \version 0.1
* \date 22 mai 2018
*
* Classe Grille,  classe qui gère les fonctionnalités de la grille des joueurs de la Bataille Navale.
*
*/


#ifndef __GRILLE_HPP__
#define __GRILLE_HPP__

#define null 0 /*!< Variable correspondant au pointeur vide  */

#define EAU 0 /*!< Variable correspondant à une case vide sur la grille  */
#define BATEAU 1 /*!< Variable correspondant à une case où se situe une partie de bateau */
#define BATEAUTOUCHE 2 /*!< Variable correspondant à une case où se situe une partie de bateau qui a été touché par une bombe adverse */
#define TENTATIVEREUSSIE 4 /*!< Variable correspondant à une case sur laquelle le joueur a déjà envoyé une bombe et qui a touché un navire adverse */
#define TENTATIVERATEE 5 /*!< Variable correspondant à une case sur laquelle le joueur a déjà envoyé une bombe mais qui n'a pas touché de navire adverse */
/*!
* \class Grille
* \brief classe qui gère les fonctionnalités de la grille des joueurs de la Bataille Navale.
*
*/
class Grille{
private:

	char** grille; /*!< Le tableau representant le cadrillage. Ici, la valeur d'une case est: EAU, BATEAU, BATEAUTOUCHE, TENTATIVEREUSSIE ou TENTATIVERATEE  */
	static int largeur; /*!< La largeur de la grille  */
	static int hauteur; /*!< La longueur de la grille */

public:
	/**
	* \fn public Grille()
	*
	* \brief Constructeur de la classe Grille qui initialise la grille
	*
	*/
	Grille();
	~Grille();
	/**
	* \fn public setTaille(int largeur, int hauteur)
	*
	* \brief fonction qui modifie l'attribut taille de la grille
	*
	* \param largeur : largeur voulue pour la grille
	* \param hauteur : hauteur voulue pour la grille
	*
	*/
	void setTaille(int largeur, int hauteur);
	/**
	* \fn public setGrille(char **grille)
	*
	* \brief fonction qui modifie l'attribut grille
	*
	* \param  **grille: le tableau à enregistrer pour grille
	*
	*/
	void setGrille(char **grille);
	/**
	* \fn public reset()
	*
	* \brief fonction qui alloue la mémoire pour la grille et la remplie de 0, donc d'eau
	*
	*/
	void reset();
	/**
	* \fn public verifierPlace(int **tableauDeCoordonnees, int taille)
	*
	* \brief fonction qui verifie les critères à respecter avant de placer le bateau sur la grille
	*
	* \param tableauDeCoordonnees: tableau de coordonnées du bateau
	* \param taille: la taille du bateau
	* \return true: si les caracteristiques sont respectées
	*/
	bool verifierPlace(int **tableauDeCoordonnees, int taille);
	/**
	* \fn public fini()
	*
	* \brief fonction qui scanne la grille jusqu'a ce qu'on trouve au moins 1 bateau qui n'a pas été touché
	* \return true si tous les bateaux ont été touchés
	*/
	bool fini();
	/**
	* \fn public get(int x, int y)
	*
	* \brief fonction qui renvoie le contenu de la grille (Eau, Bateau) sachant une certaine position
	*
	* \param x, y : les coordonnées de la position voulue
	* \return le contenu de la grille à cette position
	*/
	char get(int x, int y);
	/**
	* \fn public getLargeur()
	*
	* \brief fonction qui renvoie la largeur de la grille
	*
	* \return un entier représentant la largeur de la grille
	*/
	int getLargeur();
	/**
	* \fn public getHauteur()
	*
	* \brief fonction qui renvoie la hauteur de la grille
	*
	* \return un entier représentant la hauteur de la grille
	*/
	int getHauteur();
	/**
	* \fn public set(int x, int y, char valeur)
	*
	* \brief fonction qui permet de modifier le contenu d'une case du tableau sachant des coordonnées
	*
	* \param x, y, valeur: les coordonnées de la position voulue et la modification à apporter
	*/
	void set(int x, int y, char valeur);
	/**
	* \fn public getGrille()
	*
	* \brief fonction qui renvoie la grille
	*
	* \return la grille
	*/
	char** getGrille();

	friend class Affichage;
};

#endif

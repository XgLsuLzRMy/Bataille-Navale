#ifndef __BATEAU_HPP__
#define __BATEAU_HPP__

/*!
* \file Bateau.hpp
* \brief classe Bateau
* \author Groupe B7
* \version 0.1
* \date 13 Avril 2018
* Classe Bateau qui fixe des bateaux au début de la partie
*
*/

#include "Grille.hpp"

/*!
* \class Bateau
* \brief classe fixant des bateaux au début de la partie
*
*/
class Bateau{
private:
	int taille, xExtremite, yExtremite; /*!< Paramètres caractéristiques du bateau incluant sa taille et ses coordonnées (x,y) en extrimité qui est à gauche pour l'orientation horizontal et en haut pour l'orientation verticlal */
	bool orientation; /*!< orientation du bateau 0 pour l'horizontal et 1 pour le vertical */
public:
	/**
	* \fn public Bateau()
	*
	* \brief Constructeur de la classe Bateau qui met ses caractéristques en ses valeurs par défaut
	*
	*/
	Bateau();
	/**
	* \fn public placerSurGrille(Grille *grille)
	*
	* \brief fonction qui modifie la grille passée en paramètre afin de placer le bateau dessus.
	*
	* \param Grille *grille: la grille sur laquelle on souhaite placer le bateau
	* \return true: si le placement a été réussi. false: s'il n'y avait pas de place pour positionner le bateau
	*/
	bool placerSurGrille(Grille *grille);

	void retirerDeLaGrille(Grille *grille);

	/**
	* \fn public setTaille
	*
	* \brief fonction qui modifie l'attribut taille du bateau
	*
	* \param taille : taille voulue du bateau
	*
	*/
	void setTaille(int taille);

	void setxExtremite(int xExtremite);

	void setyExtremite(int yExtremite);
	/**
	* \fn public setOrientation
	*
	* \brief fonction qui modifiE l'orientation du bateau. O pour une orientation horizontale et 1 pour la vertciale.
	*
	* \param orientationInput : caractère h (pour horizontal) ou v (pour vertical) qui va être transformé en son booléen correspondant (0 pour h et 1 pour v).
	*/
	void setOrientation(char orientationInput);
	/**
	* \fn public getxExtremite
	* \brief fonction qui renvoie l'attribut xExtremite (coordonnée x d'extremité) d'un bateau
	*
	* \return la fonction retourne la coordonnée x du bateau.
	*/
	bool getOrientation();
	/**
	* \fn public getCoordonneesCompletes
	* \brief fonction renvoie tous les coordonnées en x et y occupées par le bateau
	*
	* \return cette fonction retourne les coordonnées entiers (x,y) du bateau;
	*/
	int getTaille();
	/**
	* \fn public setxExtremite
	* \brief fonction qui modifie l'attribut xExtremite (coordonnée x d'extremité) du bateau
	*
	* \param xExtremite : coordonnée en x voulue du bateau
	*
	*/
	int getxExtremite();
	/**
	* \fn public setyExtremite
	*
	* \brief fonction qui modifie l'attribut yExtremite (coordonnée  y d'extremité) du bateau
	*
	* \param xExtremite : coordonnée en y voulue du bateau
	*/
	int getyExtremite();
	/**
	* \fn public getCoordonneesCompletes
	* \brief fonction renvoie tous les coordonnées en x et y occupées par le bateau
	*
	* \return cette fonction retourne les coordonnées entiers (x,y) du bateau;
	*/
	int** getCoordonneesCompletes();
};

#endif

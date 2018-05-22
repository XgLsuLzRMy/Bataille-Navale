#ifndef __BATEAU_HPP__
#define __BATEAU_HPP__

/*!
* \file Bateau.hpp
* \brief classe Bateau
* \author Groupe B7
* \version 0.1
* \date 22 mai 2018
* Classe Bateau qui fixe des bateaux au début de la partie
*
*/

#include "Grille.hpp"

/*!
* \class Bateau
* \brief classe fixant des bateaux au début de la partie. L'extrémité d'un bateau est située en haut et à gauche. C'est à dire que l'éxtrémité d'un bateau situé en position verticale est en haut et l'éxtrémité d'un bateau situé à l'horizontale est à gauche.
*
*/
class Bateau{
private:
	int taille; /*!< La taille du bateau */
	int xExtremite; /*!< La position selon la coordonnée en x du bateau sur la grille. */
	int yExtremite; /*!< La position selon la coordonnée en y du bateau sur la grille. */
	bool orientation; /*!< orientation du bateau 0 pour l'horizontal et 1 pour le vertical */
public:
	/**
	* \fn public Bateau()
	*
	* \brief Constructeur de la classe Bateau qui met ses caractéristiques en ses valeurs par défaut
	*
	*/
	Bateau();
	/**
	* \fn public placerSurGrille(Grille *grille)
	*
	* \brief fonction qui modifie la grille passée en paramètre afin de placer le bateau dessus.
	*
	* \param *grille : la grille sur laquelle on souhaite placer le bateau
	* \return true: si le placement a été réussi. false: s'il n'y avait pas de place pour positionner le bateau
	*/
	bool placerSurGrille(Grille *grille);
	/**
	* \fn public retirerDeLaGrille(Grille *grille)
	*
	* \brief fonction qui permet de supprimer un bateau de la grille
	*
	* \param *grille : la grille du joueur
	*/
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
	/**
	* \fn public setxExtremite(int xExtremite)
	*
	* \brief fonction qui modifie l'attribut xExtremite du bateau
	*
	* \param xExtremite: la coordonnée voulue
	*
	*/
	void setxExtremite(int xExtremite);
	/**
	* \fn public setyExtremite(int yExtremite)
	*
	* \brief fonction qui modifie l'attribut yExtremite du bateau
	*
	* \param yExtremite: la coordonnée voulue
	*
	*/
	void setyExtremite(int yExtremite);
	/**
	* \fn public setOrientation
	*
	* \brief fonction qui modifie l'orientation du bateau. O pour une orientation horizontale et 1 pour la verticale.
	*
	* \param orientationInput : caractère h (pour horizontal) ou v (pour vertical) qui va être transformé en son booléen correspondant (0 pour h et 1 pour v).
	*/
	void setOrientation(char orientationInput);
	/**
	* \fn public getOrientation
	* \brief fonction qui renvoie l'orientation du bateau
	*
	* \return un booléen représentant l'orientation du bateau.
	*/
	bool getOrientation();
	/**
	* \fn public getTaille
	* \brief fonction renvoie la longueur du bateau.
	*
	* \return la longueur du bateau.
	*/
	int getTaille();
	/**
	* \fn public getxExtremite
	* \brief fonction qui renvoie l'attribut xExtremite (coordonnée x d'extremité) du bateau
	*
	* \return le coordonnée x d'extremité du bateau
	*
	*/
	int getxExtremite();
	/**
	* \fn public getyExtremite
	*
	* \brief fonction qui renvoie l'attribut yExtremite (coordonnée  y d'extremité) du bateau
	*
	* \return la coordonnée en y de l'extremite du bateau
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

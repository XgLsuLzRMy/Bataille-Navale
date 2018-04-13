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
           * \fn public setTaille 
	   *
           * \brief fonction qui modifie l'attribut taille du bateau
           *
           * \param taille : taille voulue du bateau
	   *
           */
		void setTaille(int taille);
	
	   /**
           * \fn public setxExtremite  
           * \brief fonction qui modifie l'attribut xExtremite (coordonnée x d'extremité) du bateau
	   *
           * \param xExtremite : coordonnée en x voulue du bateau
	   *
           */
	
		void setxExtremite(int xExtremite);
	/**
           * \fn public setyExtremite  
	   *
           * \brief fonction qui modifie l'attribut yExtremite (coordonnée  y d'extremité) du bateau
	   *
           * \param xExtremite : coordonnée en y voulue du bateau
        */
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
	 
	int getxExtremite();
	
	/**
            * \fn public getyExtremite  
            * \brief fonction qui renvoie l'attribut xExtremite (coordonnée y d'extremité) d'un bateau
            *
            * \return la fonction retourne la coordonnée en y du bateau.
         */
	 int getyExtremite();
	 
	/**
           * \fn public getOrientation 
           * \brief fonction qui renvoie l'orientation du bateau en booléen ( 0 s'il est horizontal, 1 s'il est vertical)
           *
           * \return cette fonction retourne l'orientation du bateau.
  
         */
		bool getOrientation();
	
	/**
           * \fn public getTaille  
           * \brief fonction qui renvoie la taille d'un bateau.
           *
           * \return cette fonction retourne la taille du bateau 
        */

		int getTaille();
		
	/**
           * \fn public getCoordonneesCompletes
           * \brief fonction renvoie tous les coordonnées en x et y occupées par le bateau
           *
           * \return cette fonction retourne les coordonnées entiers (x,y) du bateau;
        */		
		int** getCoordonneesCompletes();
};

#endif

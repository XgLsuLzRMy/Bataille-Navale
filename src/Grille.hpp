/**
 * \file Grille.hpp
 * \brief classe Grille
 * \author Groupe B7
 * \version 0.1
 * \date 13 avril 2018
 * Classe Grille qui gère la modification et l'affichage de la grille
 *
 */


#ifndef __GRILLE_HPP__
#define __GRILLE_HPP__

#include "Bateau.hpp"

/**
	*\fn classe Grille
	*\brief Grille representant le support du jeu
*/



class Grille{
	private:
		char** grille; // Le tableau representant le cadrillage. 
		/* On pourrait utiliser 'int' plutot que 'char' si on avait besoin de + de 8 valeurs.
		* Ici, si la valeur d'une case est 
		*	-0 : eau
		*	-1 : bateau
		*	-2 : bateau touche
		*/
		static int tailleHorizontal, tailleVertical;
		
	public:
	/**
	*\fn public Grille()
	*\brief constructeur de la classe Grille
*/
		Grille();
		~Grille();
		
/**
	*\fn public initialiserGrille()
	*\brief fonction permettant d'initialiser la grille
*/
		void initialiserGrille();
/**
	*\fn public afficher()
	*\brief fonction permettant d'afficher la grille en fonction du codage
*/
		void afficher();
/**
	*\fn public reset()
	*\brief fonction permettant de réinitialiser la grille
*/
		void reset();
/**
	*\fn public fini()
	*\brief fonction permettant de detecter l'absence de bateaux sur la grille donc la fin du jeu
*/
		bool fini();
		
		friend class Joueur;
};

#endif

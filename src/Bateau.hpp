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

class Bateau{
	private:
		int taille, xExtremite, yExtremite; // l'extremite est à gauche pour horizontal et en haut pour vertical
		bool orientation; // 0=horizontal ; 1=vertical
	public:
		Bateau();
		void setTaille(int taille);
		void setxExtremite(int xExtremite);
		void setyExtremite(int yExtremite);
		void setOrientation(char orientationInput);
		
		bool getOrientation();
		int getTaille();
		int getxExtremite();
		int getyExtremite();
		
		int** getCoordonneesCompletes();
};

#endif

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

/**
 * \file Joueur.hpp
 * \brief classe JeuBatailleNavale
 * \author groupe B7
 * \version 0.1
 * \date 13 Avril 2018
 *
 * Classe Joueur, classe qui contrôle ce que peuvent faire les joueurs durant la partie.
 *
 */

#include <string>
#include "Grille.hpp"
#include "Bateau.hpp"

  /*! \class Joueur
   * \brief classe representant le joueur
   *
   *  La classe gere les actions du joueur.
   */

class Joueur{
	private :
		std::string nom; /*!< nom du joueur */
		bool isIA; /*!<0 si c'est une IA 1 si c'est un humain */
		Grille grille; /*!< la grille où sont placés les bateaux du joueur */
		int nbBateauxTouches; /*!< est incrementé quand un des bateaux est touche pour facilite la verification de la fin de partie*/
		
		int nbBateaux; /*!< nombre de bateaux dont dispose le joueur */
		Bateau* bateaux; /*!< tazbleau des bateaux du joueur */
		
 /**
 * \fn private ajoutBateau(Bateau *b)
 * \brief demande les coordonnées du bateau et demande si le bateau est à la verticale ou à 
 * l'horizontale. Appelle setxExtremite, setyExtremite et setOrientation, setTaille de la classe  
 * Bateau et utilise placerBateau.
 * \param *b pointeur sur un bateau.
 */
		void ajoutBateau(Bateau *b);
/**
 * \fn private placerBateau(int** coordonneesBateau, int taille)
 * \brief  place le bateau à l'endroit des coordonnées si c'est possible
 * Utilise verifierPlace.
 * \param coordonneesBateau toutes les coordonnées x et y du bateau
 * \param taille la taille du bateau
 * \return 0 si le bateau ne peux pas etre placer ici, 1 si il peut
 */
		bool placerBateau(int** coordonneesBateau, int taille);
/**
 * \fn private verifierPlace(int** coordonneesBateau, int taille)
 * \brief  vérifie si le bateu peut être placer là où le joueur le souhaite
 *   
 * \param coordonneesBateau toutes les coordonnées x et y du bateau
 * \param taille la taille du bateau
 * \return 0 si le bateau ne peux pas etre placer ici, 1 si il peut
 */
		bool verifierPlace(int** coordonneesBateau, int taille);
/**
 * \fn private retirerBateau(int** coordonneesBateau, int taille)
 * \brief  retire le bateau de la grille.
 *   
 * \param coordonneesBateau toutes les coordonnées x et y du bateau
 * \param taille la taille du bateau
 */
		void retirerBateau(int** coordonneesBateau, int taille);
	public:
/**
 * \fn public Joueur()
 * \brief  constructeur de l'objet joueur
 *   
 */
		Joueur();
/**
 * \fn public initialiserNom()
 * \brief initialise le nom du joueur qu'il soit IA ou machine 
 *   
 */
		void initialiserNom();
/**
 * \fn public initialiserGrille()
 * \brief  initialise la grille du joueur et demande la taille de la grille 
 * souhaitée
 */
		void initialiserGrille();
/**
 * \fn public resetGrille() 
 * \brief  réhinitialise la grille à 0
 *     
 */
		void resetGrille();
/**
 * \fn private placementDesBateaux(char typeJeu)
 * \brief  demande au joueur de placer ses différents bateaux. Utilise 
 * ajoutBateau pour chaqun des bateaux du joueur.  
 * 
 * \param  typeJeu le type de jeu choisis
 */
		void placementDesBateaux(char typeJeu);
/**
 * \fn public  tour()
 * \brief  fait jouer le joueur à chaque tour en demandant où il souhaite
 * placer sa bombe et si un bateau à été touché
 * 
 */
		void tour();
		
		friend class JeuBatailleNavale; // on met JeuBatailleNavale en amie pour qu'on puisse acceder a nom directement mais on pourrait faire par accesseurs

};
#endif

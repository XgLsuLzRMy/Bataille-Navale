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

#include <string>

#include "Joueur.hpp"
#include "Grille.hpp"


  /*! \class JeuBatailleNavale
   * \brief classe representant la partie de bataille navale
   *
   *  La classe gere la partie.
   */

class JeuBatailleNavale{
	
	private:
		Joueur joueur1, joueur2; /*!< les joueurs de la partie */
		char nbJoueursHumains; /*!<le nombre de joueurs humains dans la partie */
		char typeJeu; /*!< le type de jeu : une bataille navalle normale ou améliorée */
		
/**
 * \fn private initialiserNomJoueur(char nbJoueurs)
 * \brief initialise le nom d'un joueur. Modifie l'attribut joueur1 ou joueur2
 *
 * \param nbJoueur Donne le nombre de joueurs humains à qui il faut demander le nom.
 */
		void initialiserNomJoueur(char nbJoueurs);
/**
 * \fn private choisirTypeJeu()
 * \brief fonction qui permet au joueur de choisir son type de jeu : bataille classique ou bataille   
 * améliorée. Modifie l'attribut nbJoueursHumains.
 */
		void choisirTypeJeu();
/**
 * \fn private checkFinJeu()
 * \brief Fonction pour déterminer si le jeu est fini.
 *
 * \return 0 si ce n'est pas la fin du jeu et 1 si c'est la fin du jeu.
 */
		bool checkFinJeu();
	public:
/**
 * \fn public JeuBatailleNavale()
 * \brief Constructeur de la classe.
 *
 */
		JeuBatailleNavale();
/**
 * \fn public nouveauJeu() 
 * \brief commence un nouveau jeu, demande au joueur si quels serons les jeurs : 2 IA, 2 humains ou un humain et une IA. Modifie l'attribut typeJeu.
 *
 */
		void nouveauJeu();
		
};

#endif

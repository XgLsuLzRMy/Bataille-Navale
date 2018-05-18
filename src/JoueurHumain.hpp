#ifndef __JOUEURHUMAIN_HPP__
#define __JOUEURHUMAIN_HPP__

/**
 * \file JoueurHumain.hpp
 * \brief classe JoueurHumain
 * \author groupe B7
 * \version 0.1
 * \date 13 Avril 2018
 *
 * Classe Joueur humain, classe qui contrôle ce que peuvent faire les joueurs humains durant la partie.
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
		virtual void placerBateau(Bateau *b);
		void demanderCoordonneesBateau(Bateau *b);
	public:
		JoueurHumain();
		virtual void demanderNom();
		virtual void demanderTailleGrille();
		virtual char demanderTypeJeu();
		virtual void placementDesBateaux(char typeJeu);
};
#endif

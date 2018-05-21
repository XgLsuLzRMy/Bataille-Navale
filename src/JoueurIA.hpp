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

#include "Joueur.hpp"

/*! \class JoueurIA
* \brief classe representant le joueur qui est IA. Cette classe hérite de la classe Joueur
*
*  La classe gere les actions du joueur.
*/

class JoueurIA : public Joueur {
private:
	virtual void placerBateau(Bateau *bateau);
public:
	JoueurIA();
	virtual bool estUneIA();
	virtual void demanderNom();
	virtual void demanderTailleGrille();
	virtual char demanderTypeJeu();
	virtual void placementDesBateaux(char typeJeu);
	virtual int* tour();
	virtual void resultatBombe(bool touche, int x, int y);
};
#endif

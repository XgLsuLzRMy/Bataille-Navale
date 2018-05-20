#ifndef __AFFICHAGE_HPP__
#define __AFFICHAGE_HPP__

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

#include <iostream>
#include <string>
#include "Grille.hpp"

class Affichage{
private:

public:
  static void afficherMessage(std::string message);
  // Fonctions pour JeuBatailleNavale
  static char menuPrincipal();
  static void attendreJoueurSuivant();
  static void afficherGagnant(std::string nom);
  // Fonctions pour JoueurHumain
  std::string demanderNom();
  int demanderDimensionGrille(std::string nomDeLaDimension);
  char choixTypeJeu();
  void afficherGrille(Grille *grille);
  char demanderPlacementCorrect();
  int demanderCoordonneesBateau(char coordonneee);
  char demanderOrientationBateau();
  int demanderCoordonneesBombe(char coordonnee);
};

#endif

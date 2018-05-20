#ifndef __GESTION_SAUVEGARDE_HPP__
#define __GESTION_SAUVEGARDE_HPP__

#include <iostream>
#include <fstream>
#include <string>

class GestionSauvegarde{
private:
  std::string nomFichier;
public:
  GestionSauvegarde(std::string nomFichier);
  // Fonctions d'ecriture
  void ecrireNomJoueur(char numeroJoueur, std::string nomJoueur);

  // Fonctions de lecture
  std::string lireNomJoueur(char numeroJoueur);
};

#endif

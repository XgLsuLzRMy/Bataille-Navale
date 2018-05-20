#ifndef __GESTION_SAUVEGARDE_HPP__
#define __GESTION_SAUVEGARDE_HPP__

#include <iostream>
#include <fstream>
#include <string>

class GestionSauvegarde{
private:
  std::string nomFichier;

  // lit le fichier ligne par ligne, s'arrete lorsqu'on a trouvé l'attribut @attribut et lit les données le concernant puis les renvoie
  // Si le fichier présente plusieurs attributs portant le même nom, alors seul le 1er attribut sera lu.
  std::string lireAttribut(std::string attribut);
  std::string::size_type debutDeLaChaineSansEspaces(std::string chaine);
public:
  GestionSauvegarde(std::string nomFichier);
  // Fonctions d'ecriture
  void ecrireNomJoueur(char numeroJoueur, std::string nomJoueur);

  // Fonctions de lecture
  std::string lireNomJoueur(char numeroJoueur);
};

#endif

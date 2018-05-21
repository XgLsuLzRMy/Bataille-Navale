#ifndef __GESTION_SAUVEGARDE_HPP__
#define __GESTION_SAUVEGARDE_HPP__

#define ERREUR "$"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

class GestionSauvegarde{
private:
  std::string nomFichier;

  // lit le fichier ligne par ligne, s'arrete lorsqu'on a trouvé l'attribut @attribut et lit les données le concernant puis les renvoie
  // Si le fichier présente plusieurs attributs portant le même nom, alors seul le 1er attribut sera lu.
  std::string lireAttribut(std::string attribut);
  std::string::size_type debutDeLaChaineSansEspaces(std::string chaine);
  int positionAttribut(std::string attribut, bool verifierEgale = true); // verifierEgale permet de trouver une ligne dans le fichier meme s'il n'y a pas de '='. Par exemple pour trouver [grille1] pour lire ensuite la grille
  char* parseLigneGrille(std::string ligne, int taille);
  bool estNumerique(char c);
  int recupererHauteurGrille(int pos);

  void ecrireAttribut(std::string attribut, std::string valeur);
  void remplacerLigne(int pos, std::string nouvelleLigne, bool ajouterLaLigne = false); // ajouterLeLigne permet de ne pas supprimer la ligne située en pos
  void effacerGrille(int pos, int h);
public:
  GestionSauvegarde(std::string nomFichier);
  // Fonctions d'ecriture
  void ecrireNomJoueur(char numeroJoueur, std::string nomJoueur);
  void ecrireGrille(std::string nomGrille, char** grille, int largeur, int hauteur);

  // Fonctions de lecture
  std::string lireNomJoueur(char numeroJoueur);
  char** lireGrille(std::string nomGrille);
  int lireHauteurGrille(std::string nomGrille);
  int lireLargeurGrille(std::string nomGrille);
};

#endif

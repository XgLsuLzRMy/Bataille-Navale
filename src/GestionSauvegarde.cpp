#include "GestionSauvegarde.hpp"

GestionSauvegarde::GestionSauvegarde(std::string nomFichier){
  GestionSauvegarde::nomFichier = nomFichier;
}

void GestionSauvegarde::ecrireNomJoueur(char numeroJoueur, std::string nomJoueur){
  std::ofstream flux(GestionSauvegarde::nomFichier.c_str(), std::ios::app);
  if(flux){
    flux << "nomJoueur" << numeroJoueur << "=" << nomJoueur << "\n";

    flux.close();
  }
}

std::string GestionSauvegarde::lireAttribut(std::string attribut){
  std::string res = "$"; // caractere d'erreur
  std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
  if(flux){
    std::string ligne, ligneAvantEgal;
    int tailleAttribut = attribut.size();
    std::cout << "taille = " << tailleAttribut << "\n";
    bool trouve = false;
    std::string::size_type positionDuEgal, positionEspace;
    int i = 0;
    // Ordre des 2 conditions du while important car si dans l'autre sens (getline && !trouve) alors on quittera la boucle en lisant la ligne suivante et on ne pourra pas recuperer les donnees dans la partie suivant le while
    // On pourrait aussi recuperer directement les donnees dans le while
    while(!trouve && getline(flux, ligne)){
      i++;
      std::cout << "ligne " << i << "\n";
      positionDuEgal = ligne.find('=');
      if(positionDuEgal != std::string::npos){
        if(positionDuEgal >= tailleAttribut){
          ligneAvantEgal = ligne.substr(0, positionDuEgal);
          std::cout << ligneAvantEgal << "\n";
          if(ligneAvantEgal.find(attribut) != std::string::npos){
            // l'attribut est une sous chaine de ligneAvantEgal. Si la taille de l'attribut est exactement la meme que celle de ligneAvantEgal alors ligneAvantEgal=attribut.
            // Il faut cependant enlever les espaces entre qu'il y a juste avant le egal
            positionEspace = ligneAvantEgal.find(' ');
            if(positionEspace != std::string::npos){
              ligneAvantEgal = ligneAvantEgal.substr(0, positionEspace);
            }
            if(ligneAvantEgal.size() == tailleAttribut){
              trouve = true;
            }
          }
        }
      }
    }
    // On recupere les donnees
    if (trouve){
      res = ligne.substr(positionDuEgal, ligne.size());
      std::cout << "resultat " << res << "\n";
    }
    flux.close();
  }
  return res;
}

std::string GestionSauvegarde::lireNomJoueur(char numeroJoueur){
  std::string attribut = "nomJoueur";
  attribut += numeroJoueur;
  return GestionSauvegarde::lireAttribut(attribut);
}

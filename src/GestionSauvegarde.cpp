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

int GestionSauvegarde::positionAttribut(std::string attribut){
  int res = -1;
  std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
  if(flux){
    int anciennePos = flux.tellg();
    std::string ligne, ligneAvantEgal;
    int tailleAttribut = attribut.size();
    bool trouve = false;
    std::string::size_type positionDuEgal, positionEspace;
    // Ordre des 2 conditions du while important car si dans l'autre sens (getline && !trouve) alors on quittera la boucle en lisant la ligne suivante et on ne pourra pas recuperer les donnees dans la partie suivant le while
    // On pourrait aussi recuperer directement les donnees dans le while
    while(!trouve && getline(flux, ligne)){
      positionDuEgal = ligne.find('=');
      if(positionDuEgal != std::string::npos){
        if(positionDuEgal >= tailleAttribut){
          ligneAvantEgal = ligne.substr(0, positionDuEgal);
          if(ligneAvantEgal.find(attribut) != std::string::npos){
            // l'attribut est une sous chaine de ligneAvantEgal. Si la taille de l'attribut est exactement la meme que celle de ligneAvantEgal alors ligneAvantEgal=attribut.
            // Il faut cependant enlever les espaces entre qu'il y a juste avant le egal
            positionEspace = ligneAvantEgal.find(' ');
            if(positionEspace != std::string::npos){
              ligneAvantEgal = ligneAvantEgal.substr(0, positionEspace);
            }
            if(ligneAvantEgal.size() == tailleAttribut){
              trouve = true;
              res = anciennePos;
            }
          }
        }
      }
      anciennePos = flux.tellg();
    }
    flux.close();
  }
  return res;
}

std::string GestionSauvegarde::lireAttribut(std::string attribut){
  std::string res = ERREUR;
  int pos = GestionSauvegarde::positionAttribut(attribut);
  if(pos != -1){
    std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
    if(flux){
      std::string ligne;
      flux.seekg(pos, std::ios::beg);
      getline(flux, ligne);
      int positionDuEgal = ligne.find('=');
      res = ligne.substr(positionDuEgal+1, ligne.size());
      res = res.substr(debutDeLaChaineSansEspaces(res), res.size()); // On enleve tous les espaces presents en debut de chaine
      // On enleve tout ce qui se trouve apres le 1er espace que l'on trouve
      // Si on veut garder le reste de la ligne on peut supprimer le if suivant
      int positionEspace = res.find(' ');
      if(positionEspace != std::string::npos){
        std::cout << "Attention des caracteres se trouvent a la suite de l'attribut " << attribut <<" et ont ete ignores\n";
        res = res.substr(0, positionEspace);
      }
    }
  }
  return res;
}

std::string::size_type GestionSauvegarde::debutDeLaChaineSansEspaces(std::string chaine){
  std::string::size_type res = 0;
  while(chaine[res] == ' '){
    res++;
  }
  return res;
}

std::string GestionSauvegarde::lireNomJoueur(char numeroJoueur){
  std::string attribut = "nomJoueur";
  attribut += numeroJoueur;
  std::cout << "Position:" << GestionSauvegarde::positionAttribut(attribut)<<"\n";
  return GestionSauvegarde::lireAttribut(attribut);
}

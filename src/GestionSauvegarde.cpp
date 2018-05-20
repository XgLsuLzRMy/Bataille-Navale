#include "GestionSauvegarde.hpp"

GestionSauvegarde::GestionSauvegarde(std::string nomFichier){
  GestionSauvegarde::nomFichier = nomFichier;
}

void GestionSauvegarde::ecrireNomJoueur(char numeroJoueur, std::string nomJoueur){
  std::ofstream flux(GestionSauvegarde::nomFichier.c_str(), std::ios::app);
  if(flux){
    flux << "nomJoueur" << numeroJoueur << "=" << nomJoueur << "\n";
  }
}

std::string GestionSauvegarde::lireNomJoueur(char numeroJoueur){
  std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
  if(flux){

  }
}

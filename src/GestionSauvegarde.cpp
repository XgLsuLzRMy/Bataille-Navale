#include "GestionSauvegarde.hpp"

GestionSauvegarde::GestionSauvegarde(std::string nomFichier){
  GestionSauvegarde::nomFichier = nomFichier;
}

void GestionSauvegarde::ecrireNomJoueur(char numeroJoueur, std::string nomJoueur){
  std::string attribut = "nomJoueur"; attribut += numeroJoueur;
  GestionSauvegarde::ecrireAttribut(attribut, nomJoueur);
}

// Cherche d'abord si l'attribut que l'on souhaite ecrire est deja present dans le fichier. Si c'est le cas, on change sa valeur. Sinon on cree l'attribut.
void GestionSauvegarde::ecrireAttribut(std::string attribut, std::string valeur){
  int pos = GestionSauvegarde::positionAttribut(attribut);
  if (pos != -1){
    std::string nouvelleLigne = attribut + "=" + valeur;
    // On a trouve l'attribut. Il s'agit donc de modifier sa valeur
    GestionSauvegarde::remplacerLigne(pos, nouvelleLigne);
  }
}

// on recopie le contenu du fichier dans le fichier temporaire sauf la ligne en question. Puis on supprime le fichier d'origine et on renomme le fichier temporaire
void GestionSauvegarde::remplacerLigne(int pos, std::string nouvelleLigne){
  std::string nomFichierTemporaire = GestionSauvegarde::nomFichier + "_temp";
  std::ofstream fluxFichierTemporaire(nomFichierTemporaire.c_str());
  std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
  if (flux && fluxFichierTemporaire){
    int posActuelle = 0;
    std::string ligne;
    while(posActuelle < pos){
      getline(flux, ligne);
      fluxFichierTemporaire << ligne << "\n";
      posActuelle = flux.tellg();
    }
    fluxFichierTemporaire << nouvelleLigne << "\n";
    getline(flux, ligne); // on passe la ligne
    while(getline(flux, ligne)){
      fluxFichierTemporaire << ligne << "\n";
    }
    flux.close();
    fluxFichierTemporaire.close();
    if( remove(GestionSauvegarde::nomFichier.c_str()) == 0){
      if(rename(nomFichierTemporaire.c_str() , GestionSauvegarde::nomFichier.c_str()) != 0){
        std::cout << "Erreur lors du renommage\n";
      }
    }else{
      std::cout << "Erreur lors de la suppression\n";
    }
  }
}

int GestionSauvegarde::positionAttribut(std::string attribut, bool verifierEgale){
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
      if(verifierEgale==false){
        positionDuEgal = ligne.size();
      }else{
        positionDuEgal = ligne.find('=');
      }
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
      flux.close();
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
  return GestionSauvegarde::lireAttribut(attribut);
}

char* GestionSauvegarde::parseLigneGrille(std::string ligne, int taille){
  int decal = 0;
  char* res = new char[taille];
  for(int i=0; i<ligne.size(); i++){
    if(i%2 == 1 && ligne[i] == ' '){
      decal++;
    }else if(i%2 != 1){
      res[i-decal] = ligne[i] - '0'; // convertit le caratere '1' en le nombre 1 (exemple si ligne[i] = '1')
    }else{
      std::cout << "Erreur lors de la lecture de la ligne de la grille \n  " << ligne << "\n";
      res[0] = -1;
      i = ligne.size(); // on sort de la boucle
    }
  }
  return res;
}

bool GestionSauvegarde::estNumerique(char c){
  bool res = false;
  if(c>='0' && c<='9'){
    res = true;
  }
  return res;
}

int GestionSauvegarde::recupererHauteurGrille(int pos){
  std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
  int res = -1;
  if(flux){
    flux.seekg(pos, std::ios::beg);
    res = 0;
    bool finGrille = false;
    std::string ligne;
    while(!finGrille && getline(flux, ligne)){
      if(!GestionSauvegarde::estNumerique(ligne[0])){
        finGrille = true;
      }else{
        res++;
      }
    }
    flux.close();
  }
  return res;
}

char** GestionSauvegarde::lireGrille(std::string nomGrille){
  char **res;
  std::string attribut = "["+ nomGrille +"]";
  int pos = GestionSauvegarde::positionAttribut(attribut, false);
  if(pos != -1){
    std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
    if(flux){
      flux.seekg(pos, std::ios::beg);
      std::string ligne;
      getline(flux, ligne);
      pos = flux.tellg();
      flux.close();
      int h = GestionSauvegarde::recupererHauteurGrille(pos);
      res = new char* [h];
      std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
      if (flux){
        flux.seekg(pos, std::ios::beg);
        bool finGrille = false;
        int i = 0;
        int taille = round((ligne.size()+1)/2);
        for (int k=0; k<h; k++){
          res[k] = new char[taille];
        }
        while(!finGrille && getline(flux, ligne)){
          if(!GestionSauvegarde::estNumerique(ligne[0])){
            finGrille = true;
          }else{
            char* l = GestionSauvegarde::parseLigneGrille(ligne, taille);
            if(l[0] != -1){
              res[i] = l;
            }else{
              res[0][0] = -1;
            }
          }
          i++;
        }
        flux.close();
      }
    }
  }
  return res;
}

int GestionSauvegarde::lireHauteurGrille(std::string nomGrille){
  int h = -1;
  std::string attribut = "["+ nomGrille +"]";
  int pos = GestionSauvegarde::positionAttribut(attribut, false);
  if(pos != -1){
    std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
    if(flux){
      flux.seekg(pos, std::ios::beg);
      std::string ligne;
      getline(flux, ligne);
      pos = flux.tellg();
      flux.close();
      h = GestionSauvegarde::recupererHauteurGrille(pos);
    }
    flux.close();
  }
  return h;
}

int GestionSauvegarde::lireLargeurGrille(std::string nomGrille){
  int largeur = -1;
  std::string attribut = "["+ nomGrille +"]";
  int pos = GestionSauvegarde::positionAttribut(attribut, false);
  if(pos != -1){
    std::ifstream flux(GestionSauvegarde::nomFichier.c_str());
    if(flux){
      flux.seekg(pos, std::ios::beg);
      std::string ligne;
      getline(flux, ligne);
      getline(flux, ligne);
      if(GestionSauvegarde::estNumerique(ligne[0])){
        largeur = round((ligne.size()+1)/2);
      }
      flux.close();
    }
  }
  return largeur;
}

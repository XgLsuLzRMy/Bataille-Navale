#include "GestionSauvegarde.hpp"

GestionSauvegarde::GestionSauvegarde(){
  GestionSauvegarde::nomFichier = "sauvegarde.sav";
  std::cout << "Attention pas de nom de sauvegarde ! Le nom de la sauvegarde par defaut est " << GestionSauvegarde::nomFichier << "\n";
}

GestionSauvegarde::GestionSauvegarde(std::string nomFichier){
  GestionSauvegarde::nomFichier = nomFichier;
}

std::string* GestionSauvegarde::getListeSauvegardes(){
  std::string* res;
  res = new std::string[1];
  res[0] = "";
  std::ifstream flux(FICHIERLISTESAV);
  if(flux){
    // On compte d'abord le nombre de ligne pour allouer le tableau
    std::string ligne, ancienneLigne;
    int nbLignes = 0;
    while(getline(flux, ligne)){
      nbLignes++; // On considere qu'il n'y aura pas de lignes vides
      ancienneLigne = ligne;
    }
    if(ancienneLigne.empty()){
      nbLignes--; // on enleve 1 si le fichier se finit par un retour a la ligne
    }
    res = new std::string[nbLignes+1];
    flux.close(); // pour revenir au debut du fichier (seekg(std::ios::beg) ne fonctionne pas ...)
    std::ifstream flux(FICHIERLISTESAV);
    int i = 0;
    while(getline(flux, ligne)){
      if(i<nbLignes){
        res[i] = ligne;
      }
      i++;
    }
    std::string str("__FIN__");
    res[nbLignes] = str;
    flux.close();
  }
  return res;
}

void GestionSauvegarde::supprimerSauvegarde(std::string nomFichier){
  GestionSauvegarde g(nomFichier);
  int pos = g.sauvegardeDejaDansListe();
  if(pos != -1){
    GestionSauvegarde g2(FICHIERLISTESAV);
    g2.remplacerLigne(pos, "__RIEN__"); // on retire la sauvegarde de la liste des sauvegardes
  }else{
    std::cout << "La sauvegarde n'est pas dans le fichier de sauvegardes\n";
  }
  if(remove(nomFichier.c_str())!=0){
    std::cout << "Erreur lors de la suppression de la sauvegarde\n";
  }
}

bool GestionSauvegarde::fichierExiste(std::string nomFichier){
  if(!nomFichier.empty()){
    nomFichier = GestionSauvegarde::nomFichier;
  }
  std::ifstream f(GestionSauvegarde::nomFichier.c_str());
  return f.good();
}

// renvoie la position de la sauvegarde dans la liste
int GestionSauvegarde::sauvegardeDejaDansListe(){
  int res = -1;
  std::string attribut = GestionSauvegarde::nomFichier;
  std::ifstream flux(FICHIERLISTESAV);
  if(flux){
    int anciennePos = flux.tellg();
    std::string ligne;
    int tailleAttribut = attribut.size();
    bool trouve = false;
    // Ordre des 2 conditions du while important car si dans l'autre sens (getline && !trouve) alors on quittera la boucle en lisant la ligne suivante et on ne pourra pas recuperer les donnees dans la partie suivant le while
    // On pourrait aussi recuperer directement les donnees dans le while
    while(!trouve && getline(flux, ligne)){
      if(ligne.find(attribut) != std::string::npos){
        // l'attribut est une sous chaine de ligne. Si la taille de l'attribut est exactement la meme que celle de ligne alors ligneAvantEgal=attribut.
        if(ligne.size() == tailleAttribut){
          trouve = true;
          res = anciennePos;
        }
      }
      anciennePos = flux.tellg();
    }
    flux.close();
  }
  return res;
}

// retourne true si la sauvegarde a été initialiséenu
// retourne false si le fichier existait deja et que l'on ne souhaitait pas l'ecraser
bool GestionSauvegarde::nouvelleSauvegarde(bool ecraserFichierSiExisteDeja){
  bool existe = GestionSauvegarde::fichierExiste();
  bool ok = !existe || ecraserFichierSiExisteDeja;
  if(ok){
    if(GestionSauvegarde::sauvegardeDejaDansListe() == -1){
      std::ofstream fluxListeSav(FICHIERLISTESAV, std::ios::app);
      if(fluxListeSav){
        fluxListeSav << GestionSauvegarde::nomFichier << "\n";
      }else{
        ok = false;
        std::cout << "Erreur ouverture liste des sauvegardes\n";
      }
      fluxListeSav.close();
    }
    if(ok){
      std::ofstream flux(GestionSauvegarde::nomFichier.c_str());
      if(flux){
        flux << "[donnees]\nnomJoueur1=\nnomJoueur2=\ntypeJeu=\njoueurEnCours=\nIA1=\nIA2=\n";
        flux.close();
      }else{
        ok = false;
        std::cout << "Erreur ouverture sauvegarde\n";
      }
    }
  }
  return ok;
}

void GestionSauvegarde::ecrireNomJoueur(char numeroJoueur, std::string nomJoueur){
  std::string attribut = "nomJoueur"; attribut += numeroJoueur;
  GestionSauvegarde::ecrireAttribut(attribut, nomJoueur);
}

// Cherche d'abord si l'attribut que l'on souhaite ecrire est deja present dans le fichier. Si c'est le cas, on change sa valeur. Sinon on cree l'attribut.
void GestionSauvegarde::ecrireAttribut(std::string attribut, std::string valeur){
  int pos = GestionSauvegarde::positionAttribut(attribut);
  std::string nouvelleLigne = attribut + "=" + valeur;
  if (pos != -1){
    // On a trouve l'attribut. Il s'agit donc de modifier sa valeur
    GestionSauvegarde::remplacerLigne(pos, nouvelleLigne);
  }else{
    GestionSauvegarde::remplacerLigne(std::ios::end, nouvelleLigne, true);
  }
}

// on recopie le contenu du fichier dans le fichier temporaire sauf la ligne en question. Puis on supprime le fichier d'origine et on renomme le fichier temporaire
void GestionSauvegarde::remplacerLigne(int pos, std::string nouvelleLigne, bool ajouterLaLigne){
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
    if(nouvelleLigne != "__RIEN__"){
      fluxFichierTemporaire << nouvelleLigne << "\n";
    }
    getline(flux, ligne); // on passe la ligne
    if(ajouterLaLigne){
      fluxFichierTemporaire << ligne << "\n";
    }
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

void GestionSauvegarde::effacerGrille(int pos, int h){
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
    int i = 0;
    while(getline(flux, ligne) && i<h){
      i++;
    }
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

void GestionSauvegarde::ecrireGrille(std::string nomGrille, char** grille, int largeur, int hauteur){
  int pos = GestionSauvegarde::positionAttribut("["+nomGrille+"]", false);
  if(pos != -1){
    GestionSauvegarde::effacerGrille(pos, lireHauteurGrille(nomGrille));
  }
  std::ofstream flux(GestionSauvegarde::nomFichier.c_str(), std::ios::app);
  if (flux){
    char c;
    flux << "[" << nomGrille << "]\n";
    for(int i=0;i<hauteur;i++){
      for (int j=0;j<largeur;j++){
        c = grille[i][j]+'0';
        flux << c << " ";
      }
      flux << "\n";
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
  std::string res = ERREURATTRIBUT;
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
  res = new char*[1];
  res[0] = new char[1];
  res[0][0] = -1; // renvoie -1 si on ne trouve pas la grille
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

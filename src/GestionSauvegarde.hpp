
/**
* \file GestionSauvegarde.hpp
* \brief classe GestionSauvegarde
* \author groupe B7
* \version 0.1
* \date 22 mai 2018
*
* Classe GestionSauvegarde,  classe qui gère l'écriture et la lecture de sauvegardes.
*
*/

#ifndef __GESTION_SAUVEGARDE_HPP__
#define __GESTION_SAUVEGARDE_HPP__

#define ERREURATTRIBUT "$" /*!< Variable renvoyée par une fonction si la lecture d'un attribut a échoué  */
#define FICHIERLISTESAV "listeDesSauvegardes.txt" /*!< Variable contenant le chemin vers le fichier contenant la liste des sauvegardes stockées */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string.h>
/*!
* \class GestionSauvegarde
* \brief classe qui gère les sauvegardes.
*
*/
class GestionSauvegarde{
private:
  std::string nomFichier; /*!< Le nom du fichier dans lequel on va sauvegarder ou à partir duquel on va lire la sauvegarde */
	/**
	* \fn private fichierExiste(std::string nomFichier = "")
	*
	* \brief Permet de savoir si un fichier existe déjà.
	* \param nomFichier: Le nom du fichier dont on veut savoir s'il existe. S'il n'est pas donné, alors on utilisera GestionSauvegarde::nomFichier.
	* \return true si le fichier existe, false sinon.
	*/
  bool fichierExiste(std::string nomFichier = ""); 
	/**
	* \fn private sauvegardeDejaDansListe()
	*
	* \brief Donne la position de la sauvegarde dans la liste des sauvegardes si elle est présente dedant. Si elle n'est pas présente on renvoie -1.
	* 
	* \return La position de la sauvegarde dans la liste si elle est présente, -1 sinon
	*/
  int sauvegardeDejaDansListe();
	/**
	* \fn private debutDeLaChaineSansEspaces(std::string chaine)
	*
	* \brief Donne la position du premier caractère qui n'est pas un espace dans la chaine \p chaine.
	* \param chaine: La chaine que l'on veut analyser.
	* \return la position du premier caractère qui n'est pas un espace dans la chaine \p chaine.
	*/
  std::string::size_type debutDeLaChaineSansEspaces(std::string chaine);
	/**
	* \fn private positionAttribut(std::string attribut, bool verifierEgale = true)
	*
	* \brief Donne la position de l'attribut \p attribut dans le fichier de sauvegarde.
	* \param attribut: L'attribut que l'on souhaite trouver.
	* \param verifierEgale: Si est placé à false, on cherche l'attribut sans savoir s'il est bien suivi du caractère '"'. S'il est à true, on ne trouve l'aatribut que s'il est suivi de '='. Par défaut \p verifierEgale est à true.
	* \return la position de l'attribut dans la sauvegarde. Retourne -1 s'il n'est pas présent.
	*/
  int positionAttribut(std::string attribut, bool verifierEgale = true); // verifierEgale permet de trouver une ligne dans le fichier meme s'il n'y a pas de '='. Par exemple pour trouver [grille1] pour lire ensuite la grille
	/**
	* \fn private parseLigneGrille(std::string ligne, int taille)
	*
	* \brief Transforme une ligne de type "1 2 3 4" en un tableau de caractère [1, 2, 3, 4]. Attention le tableau résultant n'est pas ['1', '2', '3', '4'].
	* \param ligne: La ligne à analyser.
	* \param taille: le nombre de caractères qui ne sont pas des ' ' dans la \p ligne. C'est donc la taille du tableau qui sera retourné.
	* \return Un tableau de char correspondant à \p ligne.
	*/
  char* parseLigneGrille(std::string ligne, int taille);
	/**
	* \fn private estNumerique(char c)
	*
	* \brief Permet de savoir si le caractère \p c est un chiffre comme '0', '1', etc.
	* \param c: le caractère dont on veut connaitre la nature.
	* \return true si \p c est numérique, false sinon.
	*/
  bool estNumerique(char c);
	/**
	* \fn private recupererHauteurGrille(int pos)
	*
	* \brief Permet d'obtenir la hauteur de la grille située à la position \p pos dans le fichier.
	* \param pos: la position de la grille dans le fichier.
	* \return la hauteur de la grille. -1 s'il y a eu une erreur.
	*/
  int recupererHauteurGrille(int pos);
	/**
	* \fn private remplacerLigne(int pos, std::string nouvelleLigne, bool ajouterLaLigne = false)
	*
	* \brief Remplace la ligne à la position \p pos dans le fichier. On réécrit le début du fichier dans un fichier temporaire jusqu'à la ligne en question. On écrit ensuite la nouvelle ligne dans le fichier temporaire. On réécrit la fin du fichier dans le fichier temporaire jusqu'à la fin du fichier. On supprime alors le fichier et on renomme le fichier temporaire pour qu'il ait le même nom que le fichier d'origine.
	* \param pos: la position de la ligne à remplacer.
	* \param nouvelleLigne La ligne que l'on écrit à la place de l'ancienne
	* \param ajouterLaLigne: si à false, on remplace la ligne, si à true on ajoute la ligne. Par défaut à false.
	*/
  void remplacerLigne(int pos, std::string nouvelleLigne, bool ajouterLaLigne = false); // ajouterLeLigne permet de ne pas supprimer la ligne située en pos
	/**
	* \fn private effacerGrille(int pos, int h)
	*
	* \brief Efface la grille située à la position \p pos dans le fichier.
	* \param pos: la position de la grille dans le fichier.
	* \param h: la hauteur de la grille.
	*/
  void effacerGrille(int pos, int h);
public:
	/**
	* \fn public GestionSauvegarde()
	*
	* \brief Constructeur de la classe GestionSauvegarde. Le nomFichier est mis à "sauvegarde.sav" par défaut.
	*/
  GestionSauvegarde();
	/**
	* \fn public GestionSauvegarde(std::string nomFichier)
	*
	* \brief Constructeur de la classe GestionSauvegarde.
	* \param nomFichier: Le nom de la sauvegarde.
	*/
  GestionSauvegarde(std::string nomFichier);
	/**
	* \fn public nouvelleSauvegarde(bool ecraserFichierSiExisteDeja = false)
	*
	* \brief Initialise une nouvelle sauvegarde.
	* \param ecraserFichierSiExisteDeja: si à false, on ne fait rien si le fichier existe déjà. Si à true, on écrase le fichier s'il existe déjà. Par défaut à false.
	* \return true si l'initialisation a réussi. False sinon.
	*/
  bool nouvelleSauvegarde(bool ecraserFichierSiExisteDeja = false);
	/**
	* \fn public getListeSauvegardes()
	*
	* \brief Récupere la liste des noms de fichier de sauvegardes stockée dans le fichier FICHIERLISTESAV.
	* \return la liste des noms des fichiers de sauvegarde sous la forme d'un tableau de string.
	*/
  static std::string* getListeSauvegardes();
	/**
	* \fn public supprimerSauvegarde(std::string nomFichier)
	*
	* \brief Supprime la sauvegarde contenue dans le fichier portant le nom \p nomFichier. Cette fonction supprime donc le fichier \p nomFichier mais aussi son nom de la liste des sauvegardes située dans le fichier FICHIERLISTESAV.
	* \param nomFichier: le nom du fichier de sauvegarde que l'on souhaite supprimer.
	*/
  static void supprimerSauvegarde(std::string nomFichier);

  // Fonctions d'ecriture
	/**
	* \fn public ecrireNomJoueur(char numeroJoueur, std::string nomJoueur)
	*
	* \brief Ecrit le nom \p nomJoueur du joueur numero \p numeroJoueur dans la sauvegarde.
	* \param numeroJoueur: le numero du joueur (joueur 1, joueur 2). Doit être un caractère '1' ou '2' par exemple.
	* \param nomJoueur: le nom du joueur.
	*/
  void ecrireNomJoueur(char numeroJoueur, std::string nomJoueur);
	/**
	* \fn public ecrireAttribut(std::string attribut, std::string valeur)
	*
	* \brief Ecrit l'attribut \p attribut dans la sauvegarde.
	* \param attribut: le nom de l'attribut à écrire.
	* \param valeur: la valeur de l'attribut à écrire.
	*/
  void ecrireAttribut(std::string attribut, std::string valeur);
	/**
	* \fn public ecrireGrille(std::string nomGrille, char** grille, int largeur, int hauteur)
	*
	* \brief Ecrit la grille \p grille dans la sauvegarde.
	* \param nomGrille: le nom de la grille. Par exemple, "grille1" pour la grille du joueur1, "grilleTentatives1" pour la grille des tentatives du joueur1.
	* \param grille: la grille à écrire.
	* \param largeur: la largeur de la grille.
	* \param hauteur: la hauteur de la grille.
	*/
  void ecrireGrille(std::string nomGrille, char** grille, int largeur, int hauteur);

  // Fonctions de lecture
	/**
	* \fn public lireNomJoueur(char numeroJoueur)
	*
	* \brief Lit le nom du joueur numero \p numeroJoueur dans la sauvegarde.
	* \param numeroJoueur: le numero du joueur dont on veut lire le nom. L'attribut que l'on lire sera alors "nomJoueur" +\p numeroJoueur.
	* \return le nom du joueur.
	*/
  std::string lireNomJoueur(char numeroJoueur);
	/**
	* \fn public lireAttribut(std::string attribut)
	*
	* \brief Lit le fichier ligne par ligne, s'arrête lorsqu'on a trouvé l'attribut \p attribut et lit les données le concernant puis les renvoie. Si le fichier présente plusieurs attributs portant le même nom, alors seul le 1er attribut sera lu.
	* \param attribut: le nom de l'attribut que l'on va chercher dans le fichier de sauvegarde.
	* \return la valeur de l'attribut.
	*/
  std::string lireAttribut(std::string attribut);
	/**
	* \fn public lireGrille(std::string nomGrille)
	*
	* \brief Récupère la grille dont le nom est \p nomGrille dans le fichier de sauvegarde.
	* \param nomGrille: le nom de la grille que l'on va chercher dans le fichier. L'attribut que l'on va chercher sera alors [\p nomGrille ].
	* \return La grille sous le format pour JeuBatailleNavale. C'est à dire que si on a lu un '1' on stockera l'entier 1 dans la grille.
	*/
  char** lireGrille(std::string nomGrille);
	/**
	* \fn public lireHauteurGrille(std::string nomGrille)
	*
	* \brief Récupère la hauteur de la grille portant le nom \p nomGrille.
	* \param nomGrille: le nom de la grille que l'on va chercher dans le fichier. L'attribut que l'on va chercher sera alors [\p nomGrille ].
	* \return La hauteur de la grille en question.
	*/
  int lireHauteurGrille(std::string nomGrille);
	/**
	* \fn public lireLargeurGrille(std::string nomGrille)
	*
	* \brief Récupère la largeur de la grille portant le nom \p nomGrille.
	* \param nomGrille: le nom de la grille que l'on va chercher dans le fichier. L'attribut que l'on va chercher sera alors [\p nomGrille ].
	* \return La largeur de la grille en question.
	*/
  int lireLargeurGrille(std::string nomGrille);
};

#endif

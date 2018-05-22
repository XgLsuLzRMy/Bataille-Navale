#ifndef __AFFICHAGE_HPP__
#define __AFFICHAGE_HPP__

/**
* \file Affichage.hpp
* \brief classe Affichage
* \author groupe B7
* \version 0.1
* \date 22 mai 2018
*
* Classe Affichage, classe qui gère l'affichage d'une partie de Bataille Navale.
*
*/


#include <iostream>
#include <string>
#include "Grille.hpp"

/*!
* \class Affichage
* \brief classe qui gère l'affichage d'une partie de Bataille Navale.
*
*/

class Affichage{
private:

public:
  /**
  * \fn public afficherMessage(std::string message)
  *
  * \brief fonction qui affiche un message à l'écran
  *
  * \param chaine de caractère message à afficher
  */
  static void afficherMessage(std::string message);
  /**
	* \fn public proposerNouveauJeuOuSauvegarde()
	*
	* \brief fonction qui enregistre le choix de l'utiliteur: lui porposant de charger une sauvegarde, supprimer une sauvegarde ou faire une nouvelle partie
	*
	* \return choix: un caractère 1, 2 ou 3. 1) Faire un nouveau jeu 2) Charger une sauvegarde; 3) Supprimer une sauvegarde.
	*/
  static char proposerNouveauJeuOuSauvegarde();
  /**
	* \fn public choixSauvegarde(std::string *liste)
	*
	* \brief fonction qui affiche la liste des jeux à charger et enregistre le choix de l'utilisateur
	*
	* \param std::string *liste: liste des jeux à charger, sauvegardés précedemment.
	* \return choix: un caractère précisant le choix de l'utilisateur.
	*/
  static char choixSauvegarde(std::string *liste);
  /**
	* \fn public proposerSauvegarder()
	*
	* \brief fonction qui propose à l'utilisateur de sauvegarder
	*
	* \return choix: un caractère représentant la réponse de l'utilisateur.
	*/
  static char proposerSauvegarder();
  /**
	* \fn public demanderNomSauvegarde();
	*
	* \brief fonction qui demande le nom associé à la sauvegarde
	*
	* \return un caractère res exprimant la réponse de l'utilisateur
	*/
  static std::string demanderNomSauvegarde();
  /**
	* \fn public menuPrincipal()
	*
	* \brief fonction qui affiche le menu principale de la Bataille Navale
	* \return le choix de l'utilisateur:1, 2, ou 3 tel que: 1)Joueur contre joueur 2) Joueur contre IA 3) IA contre IA q) quitter.
	*/

  static char menuPrincipal();
  /**
	* \fn public attendreJoueurSuivant()
	*
	* \brief fonction qui demande à l'utilisateur d'appuyer sur entrée pour changer de joueur.
	*/
  static void attendreJoueurSuivant();
  /**
  * \fn public  afficherGagnant(std::string nom)
  *
  * \brief fonction qui affiche le gagnant à l'écran
  *
  * \param std::String nom: nom du gagnant à afficher
  */

  static void afficherGagnant(std::string nom);
  /**
	* \fn public demanderNom();;
	*
	* \brief fonction qui demande le nom du joueur

	*
	* \return un caractère exprimant la réponse de l'utilisateur
	*/
  std::string demanderNom();
  /**
  * \fn public demanderDimensionGrille(std::string nomDeLaDimension)
  *
  * \brief fonction qui demande la dimension de la grille à l'utilisateur
  *
  * \param std::string nomDeLaDimension: hauteur, ou largeur
  *
  * \return un entier representant la dimension voulue par l'utilisateur
  */

  int demanderDimensionGrille(std::string nomDeLaDimension);
  /**
  * \fn public choixTypeJeu();
  * \brief fonction qui demande à l'utilisateur à quel type de jeu il souhaite jouer.
  *
  * \return le choix du joueur
  */
  char choixTypeJeu();
  /**
  * \fn public afficherGrille(Grille *grille);
  *
  * \brief fonction permettant d'afficher la grille
  *
  * \param Grille *grille: la grille à afficher
  */
  void afficherGrille(Grille *grille);
  /**
  * \fn public demanderPlacementCorrect();
  * \brief fonction qui demande à l'utilisateur si le placement demandé correspondant à la position du bateau visible à l'écran
  *
  * \return la réponse de l'utilisateur
  */
  char demanderPlacementCorrect();
  /**
  * \fn public demanderCoordonneesBateau(char coordonneee)
  *
  * \brief fonction qui demande à l'utilisateur les coordonnées du bateau à placer
  *
  * \param coordonnee: indique si on est dans le cas de xExtremite ou yExtremite
  *
  * \return un entier représentant les coordonnées en question
  */
  int demanderCoordonneesBateau(char coordonneee);
  /**
  * \fn public demanderOrientationBateau()
  * \brief fonction qui demande à l'utilisateur si le bateau à placer doit être parallèle à l'axe des abcisses ou à l'axe des ordonnées
  * \return la réponse de l'utilisateur
  */
  char demanderOrientationBateau();
  /**
  * \fn public demanderTailleBateau()
  * \brief fonction qui demande à l'utilisateur la taille du bateau à placer
  * \return la réponse de l'utilisateur
  */
  int demanderTailleBateau();
  /**
  * \fn public demanderCoordonneesBombe(char coordonnee)
  *
  * \brief fonction qui demande à l'utilisateur les coordonnées d'une bombe à lancer à son adversaire
  *
  * \param coordonnee: indique si on est dans le cas de xExtremite ou yExtremite
  *
  * \return un entier représentant les coordonnées en question
  */

  int demanderCoordonneesBombe(char coordonnee);
};

#endif

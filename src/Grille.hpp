#ifndef __GRILLE_HPP__
#define __GRILLE_HPP__

#define null 0

#define EAU 0
#define BATEAU 1
#define BATEAUTOUCHE 2
#define TENTATIVEREUSSIE 4
#define TENTATIVERATEE 5


class Grille{
private:
	char** grille; // Le tableau representant le cadrillage.
	/* On pourrait utiliser 'int' plutot que 'char' si on avait besoin de + de 256 valeurs.
	* Ici, si la valeur d'une case est
	*	-0 : eau
	*	-1 : bateau
	*	-2 : bateau touche
	*/
	static int largeur, hauteur;

public:
	Grille();
	~Grille();
	void setTaille(int largeur, int hauteur);
	void setGrille(char **grille);
	//void afficher();
	void reset(); // alloue la mémoire pour la grille et la remplie de 0.
	bool verifierPlace(int **tableauDeCoordonnees, int taille);
	bool fini(); // scan la grille jusqu'a ce qu'on trouve au moins 1 bateau qui n'a pas été touché
	char get(int x, int y);
	int getLargeur();
	int getHauteur();
	void set(int x, int y, char valeur);

	friend class Affichage;
};

#endif

#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Grille.hpp"
#include "../Joueur.hpp"
#include "../JeuBatailleNavale.hpp"
#include "../Bateau.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class Tests : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Tests);
	CPPUNIT_TEST(testCheckFinJeu);
	CPPUNIT_TEST(testFini);
	CPPUNIT_TEST(testPlacerBateau);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp(void);
	void tearDown(void);
protected:
	void testplacerBateau(void);
	void testCheckFinJeu(void);
	void testFini(void);
private:
	Joueur *mTestJoueur;
	JeuBatailleNavale* mTestJeu,
	Grille* mTestGrille;
	Bateau* mTestBateau;
};
//-----------------------------------------------------------------------------
void Tests::testCheckFinJeu(void)
{
	Grille grilleFinie;
	grilleFinie.reset(); // remplie de 0 donc finie
	mTestJeuBatailleNavale->joueur1.setGrille(grilleFinie); // La grille du joueur 1 est finie
	CPPUNIT_ASSERT(true == mTestJeuBatailleNavale->checkFinJeu());
	grilleFinie.set(2,2,1) // remplie de 0 et d'un 1
	mTestJeuBatailleNavale->joueur1.setGrille(grilleFinie);// La grille du joueur 1 n'est pas finie
	CPPUNIT_ASSERT(false == mTestJeuBatailleNavale->checkFinJeu());
	grilleFinie.reset();
	grilleFinie.set(2,2,2)// remplie de 0 et d'un 2
	mTestJeuBatailleNavale->joueur1.setGrille(grilleFinie);// La grille du joueur 1 est finie
	CPPUNIT_ASSERT(true == mTestJeuBatailleNavale->checkFinJeu());
}

void Tests::testFini(void)
{
	Grille grilleFinie;
	grilleFinie.reset(); // remplie de 0 donc finie
	mTestFini->joueur1.setGrille(grilleFinie); // La grille du joueur 1 est finie
	CPPUNIT_ASSERT(true == mTestFini->fini());
	grilleFinie.set(2,2,1) // remplie de 0 et d'un 1
	mTestFini->joueur1.setGrille(grilleFinie);// La grille du joueur 1 n'est pas finie
	CPPUNIT_ASSERT(false == mTestFini->fini());
	grilleFinie.reset();
	grilleFinie.set(2,2,2)// remplie de 0 et d'un 2
	mTestFini->joueur1.setGrille(grilleFinie);// La grille du joueur 1 est finie
	CPPUNIT_ASSERT(true == mTestFini->fini());
}

void Tests::testPlacerBateau(void)
{
	
}
void Tests::setUp(void)
{
	mTestJeu = new JeuBatailleNavale();
	mTestJoueur = new Joueur();
	mTestGrille = new Grille();
	mTestBateau = new Bateau();
}
void Tests::tearDown(void)
{
	delete mTestJeu;
}

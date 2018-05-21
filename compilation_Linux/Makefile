.ONESHELL:
SHELL := /bin/bash

SRCDIR = ../src
BINDIR = ../bin
OBJDIR = ../obj

TARGET = main

# $(patsubst PATTERN,REPLACEMENT,TEXT)
OBJ = $(OBJDIR)/main.o $(OBJDIR)/JeuBatailleNavale.o $(OBJDIR)/Joueur.o $(OBJDIR)/JoueurHumain.o $(OBJDIR)/JoueurIA.o $(OBJDIR)/Grille.o $(OBJDIR)/Bateau.o $(OBJDIR)/Affichage.o $(OBJDIR)/GestionSauvegarde.o

# $@ 	Le nom de la cible
# $< 	Le nom de la première dépendance
# $^ 	La liste des dépendances
# $? 	La liste des dépendances plus récentes que la cible
# $* 	Le nom du fichier sans suffixe

pre-build: $(BINDIR) $(OBJDIR) $(TARGET) post-build
	

$(TARGET): $(OBJ)
	g++ -o $(BINDIR)/$@ $^

# cree le dossier s'il n'existe pas
$(OBJDIR):
	mkdir $(OBJDIR)
	

# cree le dossier s'il n'existe pas
$(BINDIR):
	mkdir $(BINDIR)
	

all: post-build
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c $< -o $@

post-build: main
	

sauvegarde: $(OBJDIR)/main_test_sauvegarde.o $(OBJDIR)/GestionSauvegarde.o
	g++ -o $(BINDIR)/sauvegarde $^

$(OBJDIR)/main_test_sauvegarde.o: $(SRCDIR)/main_test_sauvegarde.cpp
	g++ -c $< -o $@

$(OBJDIR)/GestionSauvegarde.o: $(SRCDIR)/GestionSauvegarde.cpp
	g++ -c $< -o $@

clean:
	rm -f $(BINDIR)/$(TARGET)
	rm -rf $(OBJDIR)

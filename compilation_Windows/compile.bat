@echo off
cd ..\src\
g++ -o main.exe main.cpp JeuBatailleNavale.cpp Grille.cpp Joueur.cpp JoueurHumain.cpp JoueurIA.cpp Bateau.cpp
cd ..
move .\src\main.exe bin\main.exe
pause

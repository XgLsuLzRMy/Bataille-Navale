@echo off
cd ..\src\
g++ -o main.exe main.cpp JeuBatailleNavale.cpp Grille.cpp Joueur.cpp JoueurHumain JoueurIA Bateau.cpp
cd ..
move .\src\main.exe bin\main.exe
pause

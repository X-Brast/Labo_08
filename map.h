/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : map.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef MAP_H
#define MAP_H

#include "aleatoire.h"
#include <cmath>
#include <iostream>
#include "variable.h"

using namespace std;

enum class ListeObjet {TERRE, UTILISATEUR, TRESOR, LAC};

/*const int LONGUEUR_MAP = 10;
const int LARGEUR_MAP = 10;
const int ATTRIBUTS = 4 ;
const int NB_UTILISATEUR = 0 ; */

void ReinitialiserCarte(int tab[][LARGEUR_MAP]);
void afficherMap(int tab[][LARGEUR_MAP]);

void creationCarte(int tab[][LARGEUR_MAP], int nbObjet = 1);
void creationLac(int tab[][LARGEUR_MAP], int rayon = 1, int nbLac = 1);
void creationTresor(int tab[][LARGEUR_MAP], int nbTresor = 1);
void emplacementUtilisateur(int tab[][LARGEUR_MAP], int nbUtilisateur = 1);
bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon = 1);

#endif /* MAP_H */


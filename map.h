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

//enum class ListeObjet {TERRE, UTILISATEUR, TRESOR, LAC};

/*const int LONGUEUR_MAP = 10;
const int LARGEUR_MAP = 10;
const int ATTRIBUTS = 4 ;
const int NB_UTILISATEUR = 0 ; */

void ReinitialiserCarte(int tab[][LARGEUR_MAP]);
void afficherMap(int tab[][LARGEUR_MAP]);

void creationCarte(int tab[][LARGEUR_MAP], int nbObjet, int tabUtilisateur[][Attributs::NB_ATTRIBUTS]);
void creationLac(int tab[][LARGEUR_MAP], int nbLac);
void creationLac(int tab[][LARGEUR_MAP], int rayon, int nbLac);
void creationTresor(int tab[][LARGEUR_MAP], int nbTresor = 1);
void creationUtilisateur(int tab[][LARGEUR_MAP], int tabUtilisateur[][Attributs::NB_ATTRIBUTS], int nbUtilisateur = NB_UTILISATEUR+1);
bool caseUtiliserParUtilisateur(const int tabUtilisateur[][Attributs::NB_ATTRIBUTS], const int posX, const int posY, const int nbUtilisateur = NB_UTILISATEUR+1);
bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon = 1);

#endif /* MAP_H */


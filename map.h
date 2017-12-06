#ifndef MAP_H
#define MAP_H

#include "aleatoire.h"
#include <cmath>
#include <iostream>

using namespace std;

enum class ListeObjet {TERRE, UTILISATEUR, TRESOR, LAC};

const int LONGUEUR_MAP = 10;
const int LARGEUR_MAP = 10;

void ReinitialiserCarte(int tab[][LARGEUR_MAP]);
void afficherMap(int tab[][LARGEUR_MAP]);

void creationCarte(int tab[][LARGEUR_MAP], int nbObjet = 1);
void creationLac(int tab[][LARGEUR_MAP], int rayon = 1, int nbLac = 1);
void creationTresor(int tab[][LARGEUR_MAP], int nbTresor = 1);
void emplacementUtilisateur(int tab[][LARGEUR_MAP], int nbUtilisateur = 1);
bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon = 1);

#endif /* MAP_H */


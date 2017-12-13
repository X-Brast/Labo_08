/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : statistique.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Déclaration des fonctions et constantes de statistique.cpp 

 Remarque(s) : le fichier variable.h doit toujours être present dans ce fichier

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "constante.h"

using namespace std ; 

/**
 * permet d'afficher les statistiques par rapport à l'etat de chaque chercheur
 * @param tabStatPartie : tableau contenant les informations requise
 * @param nbSimulation  : nombre de ligne du tableau
 */
void afficherStatistique(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation);

/**
 * permet de calculer la moyenne de chaque etat et leur moyenne de pas
 * @param tabStatPartie  : tableau contenant les informations requise
 * @param nbElement      : nombre de ligne du tableau
 * @param etat           : etat voulant recuperer les informations
 * @param nombrePasMoyen : nombre de pas moyen effectuer par chaque chercheur ( Référence )
 * @return               : la moyenne de l'etat
 */
double moyenneEtatUtilisateurs(const int tabStatPartie[][StatEvent::NB_STAT], int nbElement, int etat, int& nombrePasMoyen);

/**
 * permet d'afficher les statistique par rapport à chaque chercheur
 * @param tabStatPartie : tableau contenant les informations requise
 * @param nbSimulation  : nombre de ligne du tableau
 */
void afficherTabStat(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation);

/**
 * permet de savoir quelle est le niveau de puissance d'un nombre
 * @param nombre : nombre voulant être testé
 * @return       : retourne la puissance du nombre
 */
int longueurNombre(int nombre);

#endif /* STATISTIQUE_H */


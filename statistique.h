/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : statistique.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : accéder à des variables globals et enum

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "variable.h"

using namespace std ; 

void afficherStatistique(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation);
double PourcetageTrouverTresor(const int tabStatPartie[][StatEvent::NB_STAT], int nbElement, int& nombrePasMoyen);

#endif /* STATISTIQUE_H */


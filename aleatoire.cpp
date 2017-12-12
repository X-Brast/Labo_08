/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : aleatoire.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : contient des fonctions permettant d'obtenir des nombres aléatoires

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>

int nombreAleatoire(const int& maxValue, const int& minValue)
{     
   return rand() % (maxValue-minValue + 1) + minValue;
}

void initialiserAleatoire()
{
   srand((unsigned)time(NULL));
}
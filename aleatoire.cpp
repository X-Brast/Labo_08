/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_07
 Fichier     : aleatoire.cpp
 Auteur(s)   : Alexandre Marques & Simon Walther
 Date        : 27.11.2017

 But         : contient des fonctions permettant d'obtenir des nombres aléatoires

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>

int nombreAleatoire(const int& maxValue, const int& minValue)
{     
   return rand() % (maxValue-minValue) + minValue;
}

void initialiserAleatoire()
{
   srand((unsigned)time(NULL));
}
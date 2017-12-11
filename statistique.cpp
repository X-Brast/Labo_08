/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : statistique.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include "statistique.h"


double PourcetageTrouverTresor(const int tabStatPartie[][STAT_EVENEMENT], int nbElement, int& nombrePasMoyen)
{
   int nbTresorTrouver = 0;
   int nombrePas = 0;
   
   for(int pos = 0; pos < nbElement; ++pos)
   {
      if(tabStatPartie[pos][1] == Status::RICHE)
      {
         nbTresorTrouver ++;
         nombrePas = tabStatPartie[pos][2];
      }
   }
   
   nombrePasMoyen = nombrePas/nbTresorTrouver;
   
   double moy = (double)nbTresorTrouver / (double)nbElement;
   
   return moy * 100;
}
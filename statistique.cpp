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
#include "variable.h"

void afficherStatistique(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation)
{
   int nombrePasMoyen = 0;
   double MoyenneTresorTrouver = 0;
   
   MoyenneTresorTrouver = PourcetageTrouverTresor(tabStatPartie, nbSimulation, nombrePasMoyen);
   
   cout << endl << "STATS:  " << endl ;
   if(MoyenneTresorTrouver)
   {
      cout << "Il y a eu " << MoyenneTresorTrouver << "% de chercheur qui ont trouve le tresor." << endl;
      cout << "Le nombre de pas moyen pour trouver le tresor fut de " << nombrePasMoyen << " pas." << endl;
   }
   else
   {
      cout << "Malheureusement, personne n'a trouve le tresor sur cette ile." << endl;
      cout << "Ils auront plus de chance la prochaine fois" << endl;
   }
}

double PourcetageTrouverTresor(const int tabStatPartie[][StatEvent::NB_STAT], int nbElement, int& nombrePasMoyen)
{
   int nbTresorTrouver = 0;
   int nombrePas = 0;
  
   for(int pos = 0; pos < nbElement; ++pos)
   {
      if(tabStatPartie[pos][1] == Status::RICHE)
      {
         nbTresorTrouver ++;
         nombrePas += tabStatPartie[pos][2];
      }
   }
   
   if(nbTresorTrouver)
   {
      nombrePasMoyen = ceil((double)nombrePas/nbTresorTrouver);
   }
   else
   {
      nombrePasMoyen = nombrePas;
   }
   
   double moy = (double)nbTresorTrouver / (double)nbElement;
   
   return moy * 100;
}
/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : main.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <stdlib.h>
#include "variable.h"
#include "simulation.h"
#include "statistique.h"
#include "saisie.h"
#include "map.h"

//using namespace std;

int main() 
{

   //Tableau d'information de l'explorateur :
   int explorateur[NB_UTILISATEUR][Attributs::NB_ATTRIBUTS] ;
     
   int map[LONGUEUR_MAP][LARGEUR_MAP] = {};
   
   // la terre n'étant pas un objet nous deveons la retirer
   int nbObjet = ListeObjet::NB_OBJET - 1;
   
   cout << "=======================================================================" << endl
   << "Chasse au tresor ! Ce programme simule un explorateur en quete de richesse !" << endl
   << "Il affichera le nombre de pas que les explorateurs " << endl 
   << "les plus vailliants ont fait pour atteindre le tresor !" << endl
   << "=======================================================================" << endl << endl ;
   
   do
   {
      int nbSimulation = saisir(1,100000, "Veuillez inserer le nombre de simluation voulu");
      int historiqueEvenement[nbSimulation][StatEvent::NB_STAT];
      
      ReinitialiserCarte(map);
      
      creationCarte(map, nbObjet, explorateur);
      
      afficherMap(map);
      
      cout << "Coordonees initiales (x ; y) de l'explorateur : ( " << explorateur[0][0] << " ; " << explorateur[0][1] << " )" << endl;
      
      lancerSimulation( explorateur , map , historiqueEvenement , nbSimulation );
         
      afficherStatistique( historiqueEvenement , nbSimulation ) ;
      
   }while(recommencerProgramme());
  
   return EXIT_SUCCESS;
}


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
#include "saisie.h"
#include "map.h"

//using namespace std;

int main() 
{

   //Tableau d'information de l'explorateur :
   int explorateur[NB_UTILISATEUR][ATTRIBUTS] ;
     
   int map[LONGUEUR_MAP][LARGEUR_MAP] = {};
   
   int nbObjet = ListeObjet::NB_OBJET - 1;
   
   cout << "Ce programme permet de faire des statistique pour trouver le tresor" << endl << endl;
   
   do
   {
      int nbSimulation = saisir(1,10000, "Veuillez inserer le nombre de simluation voulu");
      
      int historiqueEvenement[nbSimulation][STAT_EVENEMENT];
      
      ReinitialiserCarte(map);
      
      creationCarte(map, nbObjet, explorateur);
      
      afficherMap(map);
      
      lancerSimulation( explorateur , map , historiqueEvenement , nbSimulation );
      
      cout << "Status de l'explorateur : " << explorateur[0][Attributs::status] << endl ;
      
      
      
      //STATISTIQUE :
      cout << "-------------------" << endl
              << "STATS  : " << endl
              << "------------------" << endl ;
      //Pour tester les stats :
      for( int i = 0 ; i != nbSimulation ; i ++ ){
         for( int val = 0 ; val != STAT_EVENEMENT ; val ++ ){
            
            cout << historiqueEvenement[i][val] << " " ;
            
         }
         cout << endl ;
      }
      
      
   }while(recommencerProgramme());
  
   return EXIT_SUCCESS;
}


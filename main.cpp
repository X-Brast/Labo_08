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

   //Tabbleau d'information de l'explorateur :
   int explorateur[NB_UTILISATEUR][ATTRIBUTS] ;
   
   //Init de l'explorateur : 
   // [x][0] : position X
   // [x][1] : position Y
   // [x][2] : status
   // [x][3] : nombre de mouvement
     
   //Position du chercheur
   //   int positionX , positionY ;
   //   
   //   int status = Status::OK ;
   //   int nbMouvement = 0 ;
     
   int map[LONGUEUR_MAP][LARGEUR_MAP] = {};
   
   int nbObjet = (int)ListeObjet::NB_OBJET - 1;
   
   cout << "Ce programme permet de faire des statistique pour trouver le tresor" << endl << endl;
   
   do
   {
      int nbSimulation = saisir(1,10000, "Veuillez inserer le nombre de simluation voulu");
      
      int historiqueEvenement[nbSimulation][STAT_EVENEMENT];
      
      ReinitialiserCarte(map);
      
      creationCarte(map, nbObjet, explorateur);
      
      afficherMap(map);
      
      //lancerSimulation( positionX , positionY , status , nbMouvement , map );
      lancerSimulation( explorateur , map );
      
      cout << "Status de l'explorateur : " << status << endl ;
      
   }while(recommencerProgramme());
   
   return EXIT_SUCCESS;
}


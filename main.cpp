/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alexa
 *
 * Created on 4. décembre 2017, 11:02
 */

#include <cstdlib>
#include <stdlib.h>
#include "simulation.h"
#include "saisie.h"
#include "map.h"

//using namespace std;

int main() 
{
   
   //A faire dans simulation ?
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
   
   do
   {
      ReinitialiserCarte(map);
      
      creationCarte(map, 3);
      
      afficherMap(map);
      
      //lancerSimulation( positionX , positionY , status , nbMouvement , map );
      lancerSimulation( explorateur , map );
      
      cout << "Status de l'explorateur : " << status << endl ;
      
   }while(recommencerProgramme());
   
   return EXIT_SUCCESS;
}


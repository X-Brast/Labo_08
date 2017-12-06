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
   
   
   //TODO : Faire en sorte que la taille de la map sois accessible depuis simulation.cpp
   //const int maxX = 5 ;
   //const int maxY = 5 ;
   //Position du chercheur
   int positionX , positionY ;
   //Status de l'explorateur ( 1: OK , 2: Perdu , 3: riche , 4: Epuisé , 5:noyé  )
   //TODO , faire un tableau ? ou un Enum
   int status = 0 ;
   int nbMouvement = 0 ;

   // 0 : terre , 1 : lac , 2 : explorateur , 3 : trésor
  
   int map[LONGUEUR_MAP][LARGEUR_MAP] = {};
  
   
   do
   {
      ReinitialiserCarte(map);
      
      creationCarte(map, 3);
      
      afficherMap(map);
      
      
   }while(recommencerProgramme());
   
   return EXIT_SUCCESS;
}


/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : simulation.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include "simulation.h"
#include "map.h"
#include "aleatoire.h"


void avancerCase( int& positionX , int& positionY ){

   enum Direction { NORD , SUD , OUEST , EST } ;
   //Random de la direction , Nord Sud Ouest Est
   int direction = nombreAleatoire( 3 , 0 ) ;
   
   switch( direction ){
      case Direction::NORD : positionY -- ; break ; //Nord
      case Direction::SUD  : positionY ++ ; break ; //Sud
      case Direction::OUEST : positionX -- ; break ;//Ouest
      case Direction::EST : positionX ++ ; break ;//Est
   }
}

void controleCase( int explorateur[][ATTRIBUTS], int map[][LARGEUR_MAP] ){
   
   int posX = explorateur[0][Attributs::positionX] ;
   int posY = explorateur[0][Attributs::positionY] ;
   
   //Si la position est en dehors de la map
   if( posX < 0 
      or posY < 0 
      or posY > LONGUEUR_MAP 
      or posX > LARGEUR_MAP ){
      
      //L'explorateur est perdu
      explorateur[0][Attributs::status] = Status::PERDU ;
   }
  
   //Si l'explorateur est épuisé
   if( explorateur[0][Attributs::nbMouvement] >=  LARGEUR_MAP * LONGUEUR_MAP ){
         //L'explorateur est épuisé
         explorateur[0][Attributs::status]  = Status::EPUISE ;
      }
   
   switch( map[posX][posY]){
      //Si l'explorateur est tombé dans un lac
      case int(ListeObjet::LAC) :
         explorateur[0][Attributs::status] = Status::NOYE ;
         break ;
      
      //Si l'explorateur est tombé sur le trésor
      case int(ListeObjet::TRESOR) :
         explorateur[0][Attributs::status] = Status::RICHE ;
         break ;
   } 
}

void lancerSimulation( int explorateur[][ATTRIBUTS] , int map[][LARGEUR_MAP] , int historiqueEvenement[][STAT_EVENEMENT]){
   
   //Init du random
   initialiserAleatoire() ;
   
   //L'explorateur marche jusqu'a changer de status ( epuisé , noyé , perdu , riche )
   do{
      
      //Controle sur quelle case l'explorateur est
      controleCase( explorateur , map ) ;
      
      //Si l'explorateur n'est pas OK , on arrête la simulation
      if( explorateur[0][Attributs::status] != Status::OK ){
         break ;
      }

      //Avancer d'une case
      avancerCase(explorateur[0][Attributs::positionX] , explorateur[0][Attributs::positionY] ) ;
      
      //Incrémentation du nombre de pas effectués
      explorateur[0][Attributs::nbMouvement] ++ ; 
      
      cout << endl << "position x: " << explorateur[0][Attributs::positionX] << endl 
              << "position y : " << explorateur[0][Attributs::positionY] << endl ;
      
   }while( true ) ;
}
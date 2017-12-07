/*
 * Status de l'explorateur ( 1: OK , 2: Perdu , 3: riche , 4: Epuisé , 5:noyé  )
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "simulation.h"
#include "map.h"
#include "aleatoire.h"

void initialisationPosition( int& positionX , int& positionY , int& nbMouvement , int& status ){
   //Random position entre positionX <= maxX et et positionY <= maxY
   //Pour tester au début
   positionX = 3 ;
   positionY = 3 ;
   nbMouvement = 0 ;
   status = Status::OK ;
}
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

void controleCase( int positionX , int positionY , int& status , int map[][LARGEUR_MAP] ){
   
   //Si la position est en dehors de la map
   if( positionX < 0 or positionY < 0 or positionX > LONGUEUR_MAP or positionY > LARGEUR_MAP ){
      status = Status::PERDU ;
   }
  
   switch( map[positionX][positionY]){
      //Si l'explorateur est tombé dans un lac
      case int(ListeObjet::LAC) :
         status = Status::NOYE ;
         break ;
      
      //Si l'explorateur est tombé sur le trésor
      case int(ListeObjet::TRESOR) :
         status = Status::RICHE ;
         break ;
   } 
}

void lancerSimulation( int& positionX , int& positionY , int& status , int& nbMouvement , int map[][LARGEUR_MAP] ){
   
   //Initialisation de la position
   initialisationPosition( positionX , positionY , nbMouvement , status ) ;
   
   //Init du random
   initialiserAleatoire() ;
   
   //L'explorateur marche jusqu'a changer de status ( epuisé , noyé , perdu , riche )
   do{
      //Controle si l'explorateur est epuisé
      if( nbMouvement >=  LARGEUR_MAP * LONGUEUR_MAP ){
         status = Status::EPUISE ;
         break ;
      }

      //Avancer d'une case
      avancerCase(positionX , positionY ) ;
      nbMouvement ++ ;
      cout << endl << "position x: " << positionX << endl << "position y : " << positionY << endl ;
      
      //On controle si l'explorateur n'est pas mort , noyé , riche ou épuisé
      controleCase( positionX , positionY , status, map ) ;
      //Si l'explorateur n'est pas OK , on arrête la simulation
      if( status != Status::OK ){
         break ;
      }
   }while( true ) ;
}
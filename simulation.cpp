/*
 * Status de l'explorateur ( 1: OK , 2: Perdu , 3: riche , 4: Epuisé , 5:noyé  )
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "simulation.h"

void initialisationPosition( int& positionX , int& positionY , int& nbMouvement , int& status ){
   //Random position entre positionX <= maxX et et positionY <= maxY
   //Pour tester au début
   positionX = 3 ;
   positionY = 3 ;
   nbMouvement = 0 ;
   status = 0 ;
}
void avancerCase( int& positionX , int& positionY ){
   
   //Random de la direction , Nord Sud Ouest Est
   
   //Pour tester
   int direction = rand() % 3 ;
   
   //cout << "direction : " << direction << endl ;
   switch( direction ){
      case 0 : positionY -- ; break ; //Nord
      case 1 : positionY ++ ; break ; //Sud
      case 2 : positionX -- ; break ;//Ouest
      case 3 : positionX ++ ; break ;//Est
   }
   
}

//TODO : changer taille MAP
void controleCase( int positionX , int positionY , int& status , int map[axeX][axeY] ){
   
   //Status de l'explorateur ( 1: OK , 2: Perdu , 3: riche , 4: Epuisé , 5:noyé  )
   
   //Si la position est en dehors de la map // TODO : changer la valeur 5 avec le maxX et maxY ( les dimensions de la cartes )
   if( positionX < 0 or positionY < 0 or positionX > axeX or positionY > axeY ){
      status = 2 ;
   }
  
   switch( map[positionX][positionY]){
      //Si l'explorateur est tombé dans un lac // TODO : check le code LAC
      case 2 :
         status = 5 ;
         break ;
      
      //Si l'explorateur est tombé sur le trésor
      case 3 :
         status = 3 ;
         break ;
   } 
}

void lancerSimulation( int& positionX , int& positionY , int& status , int& nbMouvement , int map[axeX][axeY] ){
   
   //Initialisation de la position
   initialisationPosition( positionX , positionY , nbMouvement , status ) ;
   
 
   //Init du random , TODO : déplacer au bon endroit
   srand(time(0)) ;
   
   //L'explorateur marche jusqu'a changer de status ( epuisé , noyé , perdu , riche )
   do{
      //Controle si l'explorateur est epuisé
      if( nbMouvement >=  axeX * axeY ){
         status = 4 ;
         break ;
      }

      //Avancer d'une case
      avancerCase(positionX , positionY ) ;
      nbMouvement ++ ;
      cout << "position x: " << positionX << endl << "position y : " << positionY << endl ;
      
      //On controle si l'explorateur n'est pas mort , noyé , riche ou épuisé
      controleCase( positionX , positionY , status, map ) ;
      //Si l'explorateur n'est pas OK , on arrête la simulation
      if( status != 0 ){
         break ;
      }
   }while( true ) ;
}
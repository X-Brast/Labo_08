/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : simulation.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Contient les fonctions effectuants la simulation de l'explorateur.
               L'explorateur a des attributs ( position X , position Y , status , nombre de pas )
               , qui seront remplies et testée.
               La simulation fonctionne de la manière suivante :
               Les caractéristique de l'explorateur sont initialisées
               L'explorateur avance d'une case , c.à.d ces attributs "position X" et "position Y"
               sont modifiés.
               On contrôle sa position sur la map, si la valeur correspondante à une influence sur son status,
               on le modifie et on arrête la simulation.
               On retourne les données d'attributs de l'explorateur, qui seront traitées dans statistique.cpp
            

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "constante.h"
#include "map.h"
#include "aleatoire.h"


void remplirStatistique( int explorateur[][Attributs::NB_ATTRIBUTS] , int historiqueEvenement[][StatEvent::NB_STAT] , int simulation ){
   
   //On ajoute le numéro d'explorateur
   historiqueEvenement[simulation][0] = 0 ;
   //On ajoute le status
   historiqueEvenement[simulation][1] = explorateur[0][Attributs::status] ;
   //On ajoute le nombre de pas
   historiqueEvenement[simulation][2] = explorateur[0][Attributs::nbMouvement] ;
   
}

void initialiserExplorateur( int posInitialX , int posInitialY , int explorateur[][Attributs::NB_ATTRIBUTS] ){
   
   //(ré)Initialisation de la position X
   explorateur[0][Attributs::positionX] = posInitialX ;
   //(ré)Initialisation de la position Y
   explorateur[0][Attributs::positionY] = posInitialY ;
   //(ré)Initialisation du status
   explorateur[0][Attributs::status]    = Status::OK ;
   //(ré)Initialisation du nombre de mouvement (pas)
   explorateur[0][Attributs::nbMouvement] = 0 ;
   
}

void avancerCase( int& positionX , int& positionY ){

   enum Direction { NORD , SUD , OUEST , EST } ;
   //Random de la direction , Nord Sud Ouest Est
   int direction = nombreAleatoire( 3 , 0 ) ;
   
   switch( direction ){
      case Direction::NORD  : positionY -- ; break ; 
      case Direction::SUD   : positionY ++ ; break ; 
      case Direction::OUEST : positionX -- ; break ;
      case Direction::EST   : positionX ++ ; break ;
   }
}

void controleCase( int explorateur[][Attributs::NB_ATTRIBUTS], int map[][LARGEUR_MAP] ){
   
   //On copie les variables de position pour plus de lisibilité
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

void lancerSimulation( int explorateur[][Attributs::NB_ATTRIBUTS] , int map[][LARGEUR_MAP] , int historiqueEvenement[][StatEvent::NB_STAT] , const int& nbSimulation){
   
   //Initialisation du random
   initialiserAleatoire() ;
   
   //On récupère les positions initiales de l'explorateur
   int posInitialX = explorateur[0][Attributs::positionX] ; 
   int posInitialY = explorateur[0][Attributs::positionY] ;
   
   //On lance un nombre n fois de simulations , selon la saisie utilisateur
   for( int simulation = 0 ; simulation != nbSimulation ; simulation ++ ){
      
      bool continuer = true ;
      //L'explorateur marche jusqu'a changer de status ( epuisé , noyé , perdu , riche )
      do{
         
         //Controle sur quelle case l'explorateur est
         controleCase( explorateur , map ) ;
      
         //Si l'explorateur n'est pas OK , on arrête la simulation
         if( explorateur[0][Attributs::status] != Status::OK ){
            continuer = false  ;
         }
         
         //L'explorateur avance d'une case
         avancerCase(explorateur[0][Attributs::positionX] , explorateur[0][Attributs::positionY] ) ;
         
         //Incrémentation du nombre de pas effectués
         explorateur[0][Attributs::nbMouvement] ++ ; 
         
      }while(continuer) ;
      
      //On remplit les statistiques
      remplirStatistique( explorateur , historiqueEvenement , simulation ) ;
      //On réinitialise l'explorateur dans à sa position initiale
      initialiserExplorateur( posInitialX , posInitialY , explorateur ) ;

   } //end for

}
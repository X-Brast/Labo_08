#ifndef SIMULATION_H
#define SIMULATION_H

//#include "aleatoire.h"
#include <random>
#include <ctime>

#include <iostream>
#include <iomanip>
#include "map.h"

using namespace std ; 

//TODO : discuter de ça , c'est au bon endroit ?
const int axeX = 5 ;
const int axeY = 5 ;

//Enum des status
//Status de l'explorateur ( 1: OK , 2: Perdu , 3: riche , 4: Epuisé , 5:noyé  )
   
enum Status { OK , PERDU , RICHE , EPUISE , NOYE } ;



void initialisationPosition( int& positionX , int& positionY  , int& nbMouvement , int& status );
void avancerCase( int& positionX , int& positionY ) ;
void controleCase( int positionX , int positionY , int& status );
void lancerSimulation( int& positionX , int& positionY , int& status , int& nbMouvement , int map[LONGUEUR_MAP][LARGEUR_MAP] );

#endif /* SIMULATION_H */


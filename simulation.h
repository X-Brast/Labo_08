#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <iomanip>
#include "map.h"

using namespace std ; 


//Enum des status
//Status de l'explorateur ( 0: OK , 1: Perdu , 2: riche , 3: Epuisé , 4:noyé  )
enum Status { OK , PERDU , RICHE , EPUISE , NOYE } ;

void initialisationPosition( int& positionX , int& positionY  , int& nbMouvement , int& status );
void avancerCase( int& positionX , int& positionY ) ;
void controleCase( int positionX , int positionY , int& status );
void lancerSimulation( int& positionX , int& positionY , int& status , int& nbMouvement , int map[LONGUEUR_MAP][LARGEUR_MAP] );

#endif /* SIMULATION_H */


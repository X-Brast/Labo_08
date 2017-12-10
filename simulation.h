/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : simulation.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <iomanip>
#include "map.h"
#include "variable.h"

using namespace std ; 

void initialisationPosition( int& positionX , int& positionY  , int& nbMouvement , int& status );
void initialisationExplorateur( int explorateur[][ATTRIBUTS] ) ;
void avancerCase( int& positionX , int& positionY ) ;
void controleCase( int explorateur[][ATTRIBUTS], int map[][LARGEUR_MAP] );
void lancerSimulation( int explorateur[][ATTRIBUTS] , int map[][LARGEUR_MAP] );
   
#endif /* SIMULATION_H */


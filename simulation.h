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

void remplirStatistique( int explorateur[][Attributs::NB_ATTRIBUTS] , int historiqueEvenement[][StatEvent::NB_STAT] , int simulation );
void relacerExplorateur( int posInitialX , int posInitialY , int explorateur[][Attributs::NB_ATTRIBUTS] );
void avancerCase( int& positionX , int& positionY ) ;
void controleCase( int explorateur[][Attributs::NB_ATTRIBUTS], int map[][LARGEUR_MAP] );
void lancerSimulation( int explorateur[][Attributs::NB_ATTRIBUTS] , int map[][LARGEUR_MAP] , int historiqueEvenement[][StatEvent::NB_STAT] , const int& nbSimulation );
   
#endif /* SIMULATION_H */


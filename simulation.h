/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : simulation.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Déclaration des fonctions utilisée dans simulation.cpp

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <iomanip>
#include "map.h"
#include "constante.h"

using namespace std ; 

/**
 * Remplit des données "brutes" le tableau d'evemements, utilisé ensuite pour le statistique
 * @param explorateur : Donnée de l'explorateur après X simulation
 * @param historiqueEvenement : Tableau d'évenement ( numéro de l'explorateur , status , nombre de pas )
 * @param simulation : Nombre de simulations effectuées
 */
void remplirStatistique( int explorateur[][Attributs::NB_ATTRIBUTS] , int historiqueEvenement[][StatEvent::NB_STAT] , int simulation );

/**
 * (Ré)initialise les attributs de l'explorateur (position X, position Y, status, nombre de mouvement)
 * @param posInitialX : position initiale X de l'explorateur. Calculée dans map.cpp 
 * @param posInitialY : position initiale Y de l'explorateur. Calculée dans map.cpp 
 * @param explorateur : tableau contenant les données de l'explorateur
 */
void initialiserExplorateur( int posInitialX , int posInitialY , int explorateur[][Attributs::NB_ATTRIBUTS] );

/**
 * Avance l'explorateur d'une case , aléatoirement
 * @param positionX : La position X en référence de l'explorateur
 * @param positionY : La position Y en référence de l'explorateur
 */
void avancerCase( int& positionX , int& positionY ) ;

/**
 * Controle sur quelle case l'explorateur est. 
 * L'idée est de regarder directement dans la map, à l'aide des coordonées X et Y de l'explorateur.
 * Selon la valeur trouvé , on change son status. C.à.d : OK , noyé , perdu ( en dehors de la map ) , epuisé ( si le nombre de pas est trop élevé )
 * @param explorateur : Données relatives à l'explorateur
 * @param map : Tableau de la carte
 */
void controleCase( int explorateur[][Attributs::NB_ATTRIBUTS], int map[][LARGEUR_MAP] );
/**
 * Processus principal de simulation.cpp. 
 * Lance chaque sous-processus de la simulation (c.à.d les fonctions déclarée plus haut)
 * Il s'agit de la seule fonction appelée dans main.cpp
 * 
 * @param explorateur : Données relative à l'explorateur
 * @param map : Tableau de la carte
 * @param historiqueEvenement : Tableau contenant l'ensemble des données de l'explorateur
 * @param nbSimulation : Le nombre de simulation à effectuer, avec le même explorateur
 */
void lancerSimulation( int explorateur[][Attributs::NB_ATTRIBUTS] , int map[][LARGEUR_MAP] , int historiqueEvenement[][StatEvent::NB_STAT] , const int& nbSimulation );
   
#endif /* SIMULATION_H */


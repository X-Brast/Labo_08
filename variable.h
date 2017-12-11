/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : variable.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : accéder à des variables globals et enum

 Remarque(s) : il faut ajouter cet header dans chaque fichier header de ce projet

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef VARIABLE_H
#define VARIABLE_H

enum ListeObjet {TERRE, UTILISATEUR, TRESOR, LAC, NB_OBJET};

enum Status { OK , PERDU , RICHE , EPUISE , NOYE } ;
enum Attributs { positionX , positionY , status , nbMouvement } ;

const int LONGUEUR_MAP = 10;
const int LARGEUR_MAP = 10;

const int NB_UTILISATEUR = 0 ; 
const int ATTRIBUTS = 4 ;

const int STAT_EVENEMENT = 3;

#endif /* VARIABLE_H */


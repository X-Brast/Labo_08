/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : constante.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : accéder à des variables globals et enum

 Remarque(s) : il faut ajouter cet header dans chaque fichier header de ce projet
 *             Il faut toujours laisser le dernier element de chaque enum à la dernière place

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef CONSTANTE_H
#define CONSTANTE_H

// ATTENTION !!! toujours laisser NB_OBJET à la fin de l'enum !!!!
enum ListeObjet {TERRE, UTILISATEUR, TRESOR, LAC, NB_OBJET };

enum Status{ OK , PERDU , RICHE , EPUISE , NOYE } ;

// pos X - pos Y - status - nombre pas
// ATTENTION !!! toujours laisser NB_ATTRIBUTS à la fin de l'enum !!!!
enum Attributs { positionX , positionY , status , nbMouvement, NB_ATTRIBUTS } ;

// numero utilisateur - dernier status - dernier nombre pas -- nombre element dans stat
// ATTENTION !!! toujours laisser NB_STAT à la fin de l'enum !!!!
enum StatEvent { NUM_USER, STATUS, NB_MOUVEMENT, NB_STAT };

const int LONGUEUR_MAP = 10;
const int LARGEUR_MAP = 10;

const int NB_UTILISATEUR = 0 ; 

#endif /* CONSTANTE_H */


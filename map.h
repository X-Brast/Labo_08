/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : map.h
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Déclaration des fonctions et constantes de map.cpp 

 Remarque(s) : le fichier constante.h doit toujours être presentes car il y a des enums et variable important pour la map
 *             La fonction caseUtiliserParUtilisateur n'est pas utilisé dans ce projet mais il est utile si on voudrait plusieurs utilisateurs dans la map

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef MAP_H
#define MAP_H

#include "aleatoire.h"
#include <cmath>
#include <iostream>
#include "constante.h"

using namespace std;

/**
 * permet de reinitialiser le tableau avec des valeurs à zéro
 * @param tab : tableau contenant toutes les informations de la map
 */
void ReinitialiserCarte(int tab[][LARGEUR_MAP]);

/**
 * permet d'afficher la map
 * @param tab : tableau contenant toutes les informations de le map
 */
void afficherMap(int tab[][LARGEUR_MAP]);

/**
 * permet de creer un carte dans un tableau donnée
 * @param tab           : tableau qui contiendra toutes les informations. Le tableau doit être reinitialiser avant de lancer cette fonction
 * @param nbObjet       : permet d'afficher un nombre d'objet different voulu en se basant du enum ListeObjet
 * @param tabUtilisateur: tableau qui contiendra tous les utilisateurs de la map
 */
void creationCarte(int tab[][LARGEUR_MAP], int nbObjet, int tabUtilisateur[][Attributs::NB_ATTRIBUTS]);

/**
 * permet de creer des lacs (surcharge)
 * @param tab  : tableau contenant les informations de la map
 * @param nbLac: nombre de lacs qu'on voudrait afficher dans la map
 */
void creationLac(int tab[][LARGEUR_MAP], int nbLac);

/**
 * ppermet de creer des lacs avec un rayon défini (surcharge)
 * @param tab  : tableau contenant les informations de la map
 * @param rayon: le rayon des lacs voulus
 * @param nbLac: nombre de lacs qu'on voudrait afficher dans la map
 */
void creationLac(int tab[][LARGEUR_MAP], int rayon, int nbLac);

/**
 * premet de créer un nombre de tresor sur la map
 * @param tab      : tableau contenant les informations de la map
 * @param nbTresor : le nombre de tresor voulu dans la map
 */
void creationTresor(int tab[][LARGEUR_MAP], int nbTresor = 1);

/**
 * permet de creer un nombre d'utilisateur sur la map
 * @param tab            : tableau contenant les informations de la map
 * @param tabUtilisateur : tableau qui contiendra les utilisateur crees sur la map
 * @param nbUtilisateur  : le nombre utilisateur voulu dans la map ( on définit une valeur par defaut a NB_UTILISATEUR+1, car
 *                                                                   un tableau commence à 0 alors qu'on minimum 1 )
 */
void creationUtilisateur(int tab[][LARGEUR_MAP], int tabUtilisateur[][Attributs::NB_ATTRIBUTS], int nbUtilisateur = NB_UTILISATEUR+1);

/**
 * permet de vérifier si la position de départ de l'utilisateur est déjà utilié par un autre (Non utilisé dans ce projet)
 * @param tabUtilisateur : tableau contenant les informations des differents utilisateurs
 * @param posX           : position en x où l'utilisateur devrait commencer
 * @param posY           : position en y où l'utilisateur devrait commencer
 * @param nbUtilisateur  : nombre d'utilisateur dans le tableau
 * @return               : return true si un utilisateur existe déjà dans à cette position
 */
bool caseUtiliserParUtilisateur(const int tabUtilisateur[][Attributs::NB_ATTRIBUTS], const int posX, const int posY, const int nbUtilisateur = NB_UTILISATEUR+1);

/**
 * permet de verifier si la création du lacs ne chevauchent pas un autre objet de la map
 * @param tab   : tableau contenant les informations de la map
 * @param posX  : position en X du centre du lacs
 * @param posY  : position en Y du centre du lacs
 * @param rayon : le rayon du lac
 * @return      : return true si il n'y a aucun objet sur la map où le lac va être creer
 */
bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon = 1);

#endif /* MAP_H */


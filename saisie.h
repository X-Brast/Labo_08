/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : saisie.h
 Auteur(s)   : Maurice Lehmann et Alexandre Marques
 Date        : 05.12.2017

 But         : Déclaration des fonctions et constantes de saisie.cpp 
 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef SAISIE_H
#define SAISIE_H

   #include <cstdlib>  // Pour exit_success
   #include <iostream> // Pour les entrées et sorties
   #include <limits>   // Pour vider le buffer
   #include <string>   // pour utiliser les chaines de caractères
   #define VIDER_BUFFER if(cin.fail()) cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n')
      
   using namespace std ;

    /**
    * Contrôle d'une valeur entre deux bornes
    * @param valeur : Valeur à tester
    * @param limiteInf , limiteSup : Borne inferieur et borne supérieur
    * @return true si la valeur est plus grande que limiteInf et plus petite que limiteSup, sinon false.
    */
   bool controleSaisie( int valeur , unsigned int limiteInf , unsigned int limiteSup);
   
   /**
    * Demande à l'utlisateur si il veut recommencer le programme ( "O" pour oui , ou "N" pour non )
    * @return true si l'utilisateur entre "O" , false si l'utilisateur entre "N"
    */
   bool recommencerProgramme();
   
   /**
    * permet à utilisateur de choisir si il veut accéder à un fonctionnalité ou non
    * @param message : le message affiché à l'utilisateur
    * @return        : la valeur saisie
    */
   bool DemandeAutorisationFonctionnalite(const string& message);
   
   /**
   * recupère un entier saisi par l'utilisateur dans un intervalle donné
   * @param valeurMin   la valeur minimum autorisée
   * @param valeurMax   la valeur maximum autorisée
   * @param message     le message affiché à l'utilisateur
   * @return            la valeur saisie
   */
   int saisir(const int& valeurMin, const int& valeurMax, const std::string& message); 

#endif /* SAISIE_H */


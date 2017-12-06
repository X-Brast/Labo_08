/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : saisie.cpp
 Auteur(s)   : Maurice Lehmann et Alexandre Marques
 Date        : 05.12.2017

 But         : Contient les fonctions relative aux saisies utilisateur
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "saisie.h"

bool controleSaisie( int valeur , unsigned int limiteInf , unsigned limiteSup , string message){
   
   //Controle d'une valeur entre deux bornes
   if( valeur < limiteInf or valeur > limiteSup ){
      cout << message << endl ;
      return false ;
   }
   return true ;
}

bool recommencerProgramme()
{
   char reponseUtilisateur ; 
   bool saisieOK;
   bool recommencerProgramme = false ; 
   
   // Demande de recommencer le programme
   do 
   {
      cout << "Voulez-vous recommencer le programme ? " << endl
           << "(si non, le programme se terminera) [O/N] : ";

      cin >> reponseUtilisateur;
      
      saisieOK = ( (reponseUtilisateur == 'O') || (reponseUtilisateur == 'N') || (reponseUtilisateur == 'o') || (reponseUtilisateur == 'n') );

      if (!saisieOK){
         cin.clear();
         cout << "Votre saisie n'est pas valide." << endl << endl;
      }
      // Si la saisie est valide, on va initialiser le flag qui détermine si le
      // programme doit recommencer.
      else{
         recommencerProgramme = (reponseUtilisateur == 'O') || (reponseUtilisateur == 'o');
      }
      VIDER_BUFFER;
      
   }while (!saisieOK);
   
   return recommencerProgramme ;
}
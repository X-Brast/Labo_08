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

bool controleSaisie( int valeur , unsigned int limiteInf , unsigned int limiteSup)
{
   //Controle d'une valeur entre deux bornes
   return (valeur < limiteInf or valeur > limiteSup);
}

bool recommencerProgramme()
{
   char reponseUtilisateur ; 
   bool saisieOK;
   bool recommencerProgramme = false ; 
   
   // Demande de recommencer le programme
   do 
   {
      cout << endl << "Voulez-vous recommencer le programme ? " << endl
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

bool DemandeAutorisationFonctionnalite(const string& message)
{
   char reponseUtilisateur ; 
   bool saisieOK;
   bool autoriser = false ; 
   
   // Demande de recommencer le programme
   do 
   {
      cout << endl << message;

      cin >> reponseUtilisateur;
      
      saisieOK = ( (reponseUtilisateur == 'O') || (reponseUtilisateur == 'N') || (reponseUtilisateur == 'o') || (reponseUtilisateur == 'n') );

      if (!saisieOK){
         cin.clear();
         cout << "Votre saisie n'est pas valide." << endl << endl;
      }
      // Si la saisie est valide, on va initialiser le flag qui détermine si le
      // programme doit recommencer.
      else{
         autoriser = (reponseUtilisateur == 'O') || (reponseUtilisateur == 'o');
      }
      VIDER_BUFFER;
      
   }while (!saisieOK);
   
   return autoriser ;
}

int saisir(const int& valeurMin, const int& valeurMax, const string& message) 
{
   int valeurSaisie;
   bool erreur;
   
   do 
   {
      erreur = false;
      
      cout << endl << message << "[" << valeurMin << ".." << valeurMax << "] : ";
      cin >> valeurSaisie;
      
      // si l'utilisateur entre une valeur qui ne peut pas être comparée en int
      // on gére l'erreur
      if(cin.fail() || controleSaisie(valeurSaisie, valeurMin, valeurMax)) 
      {
         valeurSaisie = numeric_limits<int>::min(); // cas d'erreur 
         cout << "Valeur incorrecte ! ";
         cin.clear();
         erreur = true;
      }
      
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  
      
   } while(erreur);
   
   return valeurSaisie;
}
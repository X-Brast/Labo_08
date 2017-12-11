/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : map.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "map.h"
#include "simulation.h"

void ReinitialiserCarte(int tab[][LARGEUR_MAP])
{
   for(int x = 0; x < LONGUEUR_MAP; ++x)
   {
      for(int y = 0; y < LARGEUR_MAP; ++y)
      {
         tab[x][y] = ListeObjet::TERRE;
      }
   }
}

void afficherMap(int tab[][LARGEUR_MAP])
{
   for(int x = 0; x < LONGUEUR_MAP; ++x)
   {
      cout << endl << " | ";
      
      for(int y = 0; y < LARGEUR_MAP; ++y)
      {
         cout << tab[x][y] << " | ";
      }
   }
}

void creationCarte(int map[][LARGEUR_MAP], int nbObjet, int tabUtilisateur[][ATTRIBUTS])
{
   initialiserAleatoire();
   
   switch(ListeObjet(nbObjet))
   {
      case ListeObjet::LAC:
         creationLac(map,3,3);
         
      case ListeObjet::TRESOR:
         creationTresor(map);
         
      case ListeObjet::UTILISATEUR:
         emplacementUtilisateur(map, NB_UTILISATEUR+1 ,tabUtilisateur);
         
      default:
         break;
   }
}

void creationLac(int tab[][LARGEUR_MAP], int rayon, int nbLac)
{
   if(rayon > 0)
   {
      // nous avons définit que le rayon 0 vaut 0 case dans le tableau
      rayon--;
      
      for(int nbIteration = 0; nbIteration < nbLac; ++nbIteration)
      {
         int posX_Lac = nombreAleatoire(LONGUEUR_MAP);
         int posY_Lac = nombreAleatoire(LONGUEUR_MAP);
         
         // verification du centre avant de lancer toutes les vérifications du lac
         if(tab[posX_Lac][posY_Lac] != 0)
         {
            nbIteration--;
            continue;
         }

         if(!verificationObjetLargeMap(tab, posX_Lac, posY_Lac, rayon))
         {
            nbIteration--;
            continue;
         }
         
         for(int x = 0-rayon; x <= rayon; ++x)
         {
            for(int y = 0-rayon; y <= rayon; ++y)
            {
               if(abs(x) + abs(y) <= rayon)
               {
                  if((posX_Lac + x) >= 0 && (posX_Lac + x) < LONGUEUR_MAP && (posY_Lac + y) >= 0 && (posY_Lac + y) < LARGEUR_MAP)
                  {
                     tab[posX_Lac + x][posY_Lac + y] = (int)ListeObjet::LAC;
                  }
               }
            }
         }
      }
   }
}

void creationTresor(int tab[][LARGEUR_MAP], int nbTresor)
{
   for(int nbIteration = 0; nbIteration < nbTresor; ++nbIteration)
   {
      int posX_Tresor = nombreAleatoire(LONGUEUR_MAP);
      int posY_Tresor = nombreAleatoire(LONGUEUR_MAP);

      if(tab[posX_Tresor][posY_Tresor] != 0)
      {
         nbIteration--;
         continue;
      }

      tab[posX_Tresor][posY_Tresor] = (int)ListeObjet::TRESOR;
   }
}

void emplacementUtilisateur(int tab[][LARGEUR_MAP], int nbUtilisateur, int tabUtilisateur[][ATTRIBUTS])
{
   for(int nbIteration = 0; nbIteration < nbUtilisateur; ++nbIteration)
   {
      int posX_Utilisateur = nombreAleatoire(LONGUEUR_MAP);
      int posY_Utilisateur = nombreAleatoire(LONGUEUR_MAP);

      if(tab[posX_Utilisateur][posY_Utilisateur] != 0)
      {
         nbIteration--;
         continue;
      }
      
      tabUtilisateur[nbIteration][Attributs::positionX]     = posX_Utilisateur;
      tabUtilisateur[nbIteration][Attributs::positionY]     = posY_Utilisateur;
      tabUtilisateur[nbIteration][Attributs::status]        = Status::OK;
      tabUtilisateur[nbIteration][Attributs::nbMouvement]   = 0;
   }
}

bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon)
{
   for(int x = 0-rayon; x <= rayon; ++x)
   {
      for(int y = 0-rayon; y <= rayon; ++y)
      {
         if(abs(x) + abs(y) <= rayon)
         {
            if((posX + x) >= 0 && (posX + x) < LONGUEUR_MAP && (posY + y) >= 0 && (posY + y) < LARGEUR_MAP && tab[posX + x][posY + y])
            {
               return false;
            }
         }
      }
   }
   
   return true;
}
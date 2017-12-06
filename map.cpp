
#include "map.h"

// vérifier la rayon mimimal dans la formule

void creationCarte(int tab[][LARGEUR_MAP], int nbObjet)
{
   initialiserAleatoire();
   
   switch(ListeObjet(nbObjet))
   {
      case ListeObjet::LAC:
         creationLac(tab,3,3);
         
      case ListeObjet::TRESOR:
         creationTresor(tab);
         
      case ListeObjet::UTILISATEUR:
         emplacementUtilisateur(tab);
         
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
         int posX_Lac = nombreAleatoire(LONGEUR_MAP);
         int posY_Lac = nombreAleatoire(LONGEUR_MAP);
         
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
                  if((posX_Lac + x) >= 0 && (posX_Lac + x) < LONGEUR_MAP && (posY_Lac + y) >= 0 && (posY_Lac + y) < LARGEUR_MAP)
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
      int posX_Tresor = nombreAleatoire(LONGEUR_MAP);
      int posY_Tresor = nombreAleatoire(LONGEUR_MAP);

      if(tab[posX_Tresor][posY_Tresor] != 0)
      {
         nbIteration--;
         continue;
      }

      tab[posX_Tresor][posY_Tresor] = (int)ListeObjet::TRESOR;
   }
}

void emplacementUtilisateur(int tab[][LARGEUR_MAP], int nbUtilisateur)
{
   for(int nbIteration = 0; nbIteration < nbUtilisateur; ++nbIteration)
   {
      int posX_Utilisateur = nombreAleatoire(LONGEUR_MAP);
      int posY_Utilisateur = nombreAleatoire(LONGEUR_MAP);

      if(tab[posX_Utilisateur][posY_Utilisateur] != 0)
      {
         nbIteration--;
         continue;
      }

      tab[posX_Utilisateur][posY_Utilisateur] = (int)ListeObjet::UTILISATEUR;
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
            if((posX + x) >= 0 && (posX + x) < LONGEUR_MAP && (posY + y) >= 0 && (posY + y) < LARGEUR_MAP && tab[posX + x][posY + y])
            {
               return false;
            }
         }
      }
   }
   
   return true;
}
/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : map.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : permet de créer un map avec different objet 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "map.h"
#include "simulation.h"


void ReinitialiserCarte(int map[][LARGEUR_MAP])
{
   for(int posX = 0; posX < LONGUEUR_MAP; ++posX)
   {
      for(int posY = 0; posY < LARGEUR_MAP; ++posY)
      {
         // on tamisse la map avec de la terre ainsi il n'y aura plus d'autre objet
         map[posX][posY] = ListeObjet::TERRE;
      }
   }
}

void afficherMap(int map[][LARGEUR_MAP])
{
   for(int posX = 0; posX < LONGUEUR_MAP; ++posX)
   {
      cout << endl << " | ";
      
      for(int posY = 0; posY < LARGEUR_MAP; ++posY)
      {
         cout << map[posX][posY] << " | ";
      }
   }
   cout << endl;
}

void creationCarte(int map[][LARGEUR_MAP], int nbObjet, int tabUtilisateur[][Attributs::NB_ATTRIBUTS])
{
   // on initilise l'aleatoire car nous allons l'utiliser plusieur fois dans cette fonction   
   initialiserAleatoire();
   
   // on définit le nombre de lacs voulu
   int nbLacs = 3;
   
   // on a utilisé un switch afin de permettre dans le futur de choisir combien d'objet on voudrait.
   // on devra commencé par creer les objets terrain (ex: lac) avant de creer les objets matériels.
   // ATTENTION !!! seul contraint est que l'utilisateur doit être creer en dernier car il ne sera pas representer dans la map
   switch(ListeObjet(nbObjet))
   {
      case ListeObjet::LAC:
         creationLac(map, nbLacs);
         
      case ListeObjet::TRESOR:
         creationTresor(map);
         
      // toujours faire en dernier
      case ListeObjet::UTILISATEUR:
         creationUtilisateur(map ,tabUtilisateur);
   }
}

void creationLac(int tab[][LARGEUR_MAP], int rayon, int nbLac)
{
   // nous vérifions que le rayon n'est pas nulle avant créer des lacs
   if(rayon > 0)
   {
      // nous desincrementons le rayon car nous allons définir un centre plus bas et qu'ildeviendra la distance avec ce centre
      rayon--;
      
      // création de plusieur lacs
      for(int nbIteration = 0; nbIteration < nbLac; ++nbIteration)
      {
         // nous générons les positions des lacs en X et Y
         int posX_Lac = nombreAleatoire(LONGUEUR_MAP - 1);
         int posY_Lac = nombreAleatoire(LARGEUR_MAP - 1);
         
         // verifie si la position du centre du lacs n'a pas déjà un objet
         if(tab[posX_Lac][posY_Lac])
         {
            // la création de ce lac a été un echec alors on recommence
            nbIteration--;
            continue;
         }

         // verifie si la futur position du lac n'a pas déjà des objets
         if(!verificationObjetLargeMap(tab, posX_Lac, posY_Lac, rayon))
         {
            // la création de ce lac a été un echec alors on recommence
            nbIteration--;
            continue;
         }
         
         // nous parcourons toutes les cellules de la map par raport au rayon du lac
         for(int posX = 0-rayon; posX <= rayon; ++posX)
         {
            for(int posY = 0-rayon; posY <= rayon; ++posY)
            {
               // nous vérifions si l'insertion n'est pas à l'extérieur de la map 
               // et que la somme des positions en valeur absolu est inférieur ou égal au rayon car nous voulons representer un cercle pixeliser
               if(abs(posX) + abs(posY) <= rayon && (posX_Lac + posX) >= 0 && (posX_Lac + posX) < LONGUEUR_MAP && (posY_Lac + posY) >= 0 && (posY_Lac + posY) < LARGEUR_MAP)
               {
                  tab[posX_Lac + posX][posY_Lac + posY] = (int)ListeObjet::LAC;
               }
            }
         }
      }
   }
}

void creationLac(int tab[][LARGEUR_MAP], int nbLac)
{
   int rayon = 0;
   
   // créations de plusieurs lacs
   for(int numLac = 1; numLac <= nbLac; ++numLac)
   {
      // nous allons générer le rayon par rapport au plus petit des cotés de la map
      if(LONGUEUR_MAP < LARGEUR_MAP)
      {
         rayon = nombreAleatoire(((int)LONGUEUR_MAP / 3) + 1, 1);
         creationLac(tab, rayon, 1);
      }
      else
      {
         rayon = nombreAleatoire(((int)LARGEUR_MAP / 3) + 1, 1);
         creationLac(tab, rayon, 1);
      }
   }
}

void creationTresor(int tab[][LARGEUR_MAP], int nbTresor)
{
   // création de plusieur trésor
   for(int nbIteration = 0; nbIteration < nbTresor; ++nbIteration)
   {
      // on génére la position futur du tresor en X et Y
      int posX_Tresor = nombreAleatoire(LONGUEUR_MAP - 1);
      int posY_Tresor = nombreAleatoire(LARGEUR_MAP - 1);

      // on vérifie si un objet existe à cette position
      if(tab[posX_Tresor][posY_Tresor])
      {
         // la création de ce tresor a été un echec alors on recommence
         nbIteration--;
         continue;
      }

      // on insert le tresor sur la map
      tab[posX_Tresor][posY_Tresor] = (int)ListeObjet::TRESOR;
   }
}

void creationUtilisateur(int map[][LARGEUR_MAP], int tabUtilisateur[][Attributs::NB_ATTRIBUTS], int nbUtilisateur)
{
   // création de plusieur utilisateur
   for(int nbIteration = 0; nbIteration < nbUtilisateur; ++nbIteration)
   {
      // nous générons la position de l'utilisateur en X et Y
      int posX_Utilisateur = nombreAleatoire(LONGUEUR_MAP -1);
      int posY_Utilisateur = nombreAleatoire(LONGUEUR_MAP -1);

      // on vérifie si un objet existe à cette position
      if(map[posX_Utilisateur][posY_Utilisateur]/* || caseUtiliserParUtilisateur(tabUtilisateur, posX_Utilisateur, posY_Utilisateur)*/)
      {
         // la création de cet utilisateur a été un echec alors on recommence
         nbIteration--;
         continue;
      }
      
      // on insert la position initial de l'utilisateur dans un tableau et on initialise son status et nombre de pas
      tabUtilisateur[nbIteration][Attributs::positionX]     = posX_Utilisateur;
      tabUtilisateur[nbIteration][Attributs::positionY]     = posY_Utilisateur;
      tabUtilisateur[nbIteration][Attributs::status]        = Status::OK;
      tabUtilisateur[nbIteration][Attributs::nbMouvement]   = 0;
   }
}

// non utiliser dans ce projet
bool caseUtiliserParUtilisateur(const int tabUtilisateur[][Attributs::NB_ATTRIBUTS], const int posX, const int posY, const int nbUtilisateur)
{
   // on parcourt le tableau utilisateur 
   for(int nbIteration = 0; nbIteration < nbUtilisateur; ++nbIteration)
   {
      // on vérifie si un utilisateur n'existe pas déjà à cette emplacement
      if(tabUtilisateur[nbIteration][Attributs::positionX] == posX && tabUtilisateur[nbIteration][Attributs::positionY] == posY)
      {
         return true;
      }
   }
   
   return false;
}

bool verificationObjetLargeMap(const int tab[][LARGEUR_MAP], const int& posX, const int& posY, const int& rayon)
{
   // nous parcourons toutes les cellules de la map par raport au rayon du lac
   for(int x = 0-rayon; x <= rayon; ++x)
   {
      for(int y = 0-rayon; y <= rayon; ++y)
      {
         // on verifie que la somme des positions en valeur absolu est inférieur ou égal au rayon car nous voulons representer un cercle pixeliser
         if(abs(x) + abs(y) <= rayon)
         {
            // nous vérifions qu'il n'existe pas des objets sur la map
            if((posX + x) >= 0 && (posX + x) < LONGUEUR_MAP && (posY + y) >= 0 && (posY + y) < LARGEUR_MAP && tab[posX + x][posY + y])
            {
               return false;
            }
         }
      }
   }
   
   return true;
}
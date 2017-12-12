/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : statistique.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Affiche les statistiques à partir d'un tableau

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "statistique.h"
#include "saisie.h"

void afficherStatistique(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation)
{
   int      nombrePasMoyen       = 0;
   double   MoyenneEtat          = 0;
   
   // On va afficher selon utilisateur, les statistiques détaillés de chaque chercheur
   bool afficherStatChercheur = DemandeAutorisationFonctionnalite("Voulez-vous afficher les stats de chaque chercheur ?  ");
   
   cout << endl << "STATS:  " << endl ;
   
   if(afficherStatChercheur)
   {
      // on affiche les informations de chaque utilisateur
      afficherTabStat(tabStatPartie, nbSimulation);
      
      cout << endl;
   }
   
   // Affiche la moyenne de l'état PERDU
   MoyenneEtat = moyenneEtatUtilisateurs(tabStatPartie, nbSimulation, Status::PERDU ,nombrePasMoyen);
   cout << "Il y a eu " << MoyenneEtat << "% de chercheur qui se sont perdus en chemin." << endl;
   if(MoyenneEtat) // on affiche le nombre de pas uniquement si minumum un chercheur est dans cet état
   {
      cout << "Le nombre de pas moyen pour se perdre fut de " << nombrePasMoyen << " pas." << endl;
   }
   cout << endl;
   
   // Affiche la moyenne de l'état NOYé
   MoyenneEtat = moyenneEtatUtilisateurs(tabStatPartie, nbSimulation, Status::NOYE ,nombrePasMoyen);
   cout << "Il y a eu " << MoyenneEtat << "% de chercheur qui sont mort noyes." << endl;
   if(MoyenneEtat) // on affiche le nombre de pas uniquement si minumum un chercheur est dans cet état
   {
      cout << "Le nombre de pas moyen pour se noyer fut de " << nombrePasMoyen << " pas." << endl;
   }
   cout << endl;
   
   // Affiche la moyenne de l'état éPUISSéE
   MoyenneEtat = moyenneEtatUtilisateurs(tabStatPartie, nbSimulation, Status::EPUISE ,nombrePasMoyen);
   cout << "Il y a eu " << MoyenneEtat << "% de chercheur qui sont mort de faim ou de fatigue." << endl;
   if(MoyenneEtat) // on affiche le nombre de pas uniquement si minumum un chercheur est dans cet état
   {
      cout << "Le nombre de pas moyen pour se fatiguer fut de " << nombrePasMoyen << " pas." << endl;
   }
   cout << endl;
   
   // Affiche la moyenne de l'état RICHE
   MoyenneEtat = moyenneEtatUtilisateurs(tabStatPartie, nbSimulation, Status::RICHE ,nombrePasMoyen);
   if(MoyenneEtat) // on affiche le nombre de pas uniquement si minumum un chercheur est dans cet état
   {
      cout << "Il y a eu " << MoyenneEtat << "% de chercheur qui ont trouve le tresor." << endl;
      cout << "Le nombre de pas moyen pour trouver le tresor fut de " << nombrePasMoyen << " pas." << endl;
   }
   else
   {
      cout << "Malheureusement, personne n'a trouve le tresor sur cette ile." << endl;
      cout << "Ils auront plus de chance la prochaine fois" << endl;
   }
}

double moyenneEtatUtilisateurs(const int tabStatPartie[][StatEvent::NB_STAT], int nbElement, int etat, int& nombrePasMoyen)
{
   // nombre chercheur affectée par l'état mis en parametre
   int nbChercheurAffecte = 0;
   // nombre de pas totale effectuer par chaque chercheur affecté
   int nombrePas = 0;
  
   // on cherche les chercheurs affecté par l'état
   for(int pos = 0; pos < nbElement; ++pos)
   {
      if(tabStatPartie[pos][1] == etat)
      {
         nbChercheurAffecte ++;
         nombrePas += tabStatPartie[pos][2];
      }
   }
   
   // permet d'eviter un division par zéro
   if(nbChercheurAffecte)
   {
      nombrePasMoyen = ceil((double)nombrePas/nbChercheurAffecte);
   }
   else
   {
      nombrePasMoyen = 0;
   }
   
   // calcule de la moyenne
   double moy = (double)nbChercheurAffecte / (double)nbElement;
   
   return moy * 100;
}

void afficherTabStat(const int tabStatPartie[][StatEvent::NB_STAT], int nbSimulation)
{
   // permet de rendre agréable la lecture des statistiques
   int espacement = longueurNombre(nbSimulation);
   
   // parcourt tous le taleau des statistiques
   for(int ligne = 0; ligne < nbSimulation; ++ligne)
   {
      cout << endl << "le " << setw(espacement) << ligne+1 << " ieme chercheur ";
      
      // on différencie chaque état par un message personnalisé
      switch(tabStatPartie[ligne][1])
      {
         case Status::EPUISE :
            cout << "est mort de fatigue ou de faim ";
            break;
         case Status::RICHE :
            cout << "a trouve le tresor de l'ile    ";
            break;
         case Status::NOYE :
            cout << "est mort noye dans un des lacs ";
            break;
         case Status::PERDU :
            cout << "s'est perdu sur l'ile sauvage  ";
            break;
      }
      
      cout << "apres avoir accumule " << tabStatPartie[ligne][2] << " pas.";
   }
   
   cout << endl;
}

int longueurNombre(int nombre)
{
   // permet de savoir quelle puissance est le nombre
   // 1: unité; 2: dizaine; 3: centaine; etc...
   int puissance = 0;
   
   while(nombre)
   {
      puissance++;
      nombre /= 10;
   }
   
   return puissance;
}
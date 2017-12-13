/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : main.cpp
 Auteur(s)   : Alexandre Marques & Maurice Lehmann
 Date        : 05.12.2017

 But         : Programme permettant de simuler un explorateur en quete de trésors.
 *             Le programme génère une carte 2 dimensions ( un tableau ), contenant différentes
 *             valeurs : la terre ferme ( par défaut ) , des lacs , un trésor.
 *             L'utilisateur est invité à entrer un nombre n de simulations, correspondant
 *             au nombre d' "essai" d'un unique explorateur.
 *             
 *             Les données relatives au parcours de l'explorateur sont finalement anaylisées
 *             et affichées. Cela comprend :
 *             - La probabilité pour un explorateur de trouver le trésor.
 *             - Le nombre moyen de pas nécessaires de ceux qui l’ont trouvé


 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <stdlib.h>
#include "constante.h"
#include "simulation.h"
#include "statistique.h"
#include "saisie.h"
#include "map.h"

int main() 
{

   //Tableau d'information de l'explorateur :
   int explorateur[NB_UTILISATEUR][Attributs::NB_ATTRIBUTS] ;
     
   //Initialisation de la carte
   int map[LONGUEUR_MAP][LARGEUR_MAP] = {};
   
   // La terre n'étant pas un objet, on la retire
   int nbObjet = ListeObjet::NB_OBJET - 1;
   
   cout << "=======================================================================" << endl
   << "Chasse au tresor ! Ce programme simule un explorateur en quete de richesse !" << endl
   << "Il affichera le nombre de pas que les explorateurs " << endl 
   << "les plus vailliants ont fait pour atteindre le tresor !" << endl
   << "=======================================================================" << endl << endl ;
   
   do
   {
      //Saisie utilisateur
      int nbSimulation = saisir(1,100000, "Veuillez inserer le nombre de simluation voulu");
      int historiqueEvenement[nbSimulation][StatEvent::NB_STAT];
      
      //On réinitialise la carte
      ReinitialiserCarte(map);
      
      //On crée la carte, avec les positions des objets 
      creationCarte(map, nbObjet, explorateur);
      
      //Affichage de la carte
      afficherMap(map);
      
      //Affichage des coordonees initiales de l'explorateur
      cout << "Coordonees initiales (x ; y) de l'explorateur : ( " << explorateur[0][0] << " ; " << explorateur[0][1] << " )" << endl;
      
      //On lance la simulation, un nombre n fois ( nbSimulation )
      lancerSimulation( explorateur , map , historiqueEvenement , nbSimulation );
      
      //On affiche finalement les statistiques
      afficherStatistique( historiqueEvenement , nbSimulation ) ;
      
   //Si l'utilisateur veut recommencer le programme
   }while(recommencerProgramme());
  
   return EXIT_SUCCESS;
}


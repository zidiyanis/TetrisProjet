#include"fonction.h"
#include"fonctionMain.h"


void initialisation(tetris_s* tetris){
  initialisationGrille(tetris);
  tetris->fin = 0;                          //Initalisation du jeu
  tetris->score=0;
}

void affichage(tetris_s* tetris){    
  afficheGrille(tetris);                    //Affichage grille
}


void miseJour(tetris_s* tetris){
  placement(tetris);
  enleverLigne(tetris);                   //Mise a jour jeu
  fin(tetris);
}

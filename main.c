#include"fonctionMain.h"
#include"fonction.h"

int main(){					// timer
  time_t t_debut, s_fin;
  t_debut=time(NULL);
  srand(time(NULL));
  tetris_s tetris;
  initialisation(&tetris);
  while(tetris.fin==0){
    affichage(&tetris);
    miseJour(&tetris);
    s_fin=time(NULL);
    tetris.temps=(unsigned long)s_fin-t_debut;
        if(tetris.temps>((tetris.largeur*tetris.hauteur)*2)){
        tetris.fin=1;
      }
  }
  affichage(&tetris);
}
    

#include "fonction.h"

void flush() {                     
                                   // elimination d'element
  int e;
  char f;
  do {
    e = scanf("%c", &f);
  } while (e == 1 && f != '\n');
}

void verification(void *u, int v) {                  
  if (u == NULL) {
    printf("%d ERREUR EHH OHHHH\n", v); 
    exit(v);
  }
}

void initialisationGrille(
    tetris_s *tetris) {                               
                                                    // Construis la grille
  do {
    printf("Choisissez la hauteur\n");
    scanf("%d", &tetris->hauteur);
    flush();
    printf("Choisissez la largeur\n");
    scanf("%d", &tetris->largeur);
    flush();
  } while (tetris->largeur > 32 || tetris->largeur < 4 ||
           tetris->hauteur > 32 || tetris->hauteur < 4);
  tetris->hauteur += 4;
  tetris->grille = malloc(sizeof(int *) * tetris->hauteur);
  for (int i = 0; i < tetris->hauteur; i++) {
    tetris->grille[i] = malloc(sizeof(int) * tetris->largeur);
    for (int j = 0; j < tetris->largeur; j++) {
      tetris->grille[i][j] = 0;
    }
  }
}

void creerPiece(tetris_s *tetris)                               // creer une piece 
                           
{
  verification(tetris->grille, 2);
  if (tetris->piece.numero >= 0 && tetris->piece.numero < 6) {
    if (tetris->piece.numero == 0) {
      tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
      tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
      tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
      tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
      tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
      tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
      tetris->piece.couleur.violet = 255;
      tetris->piece.couleur.noir = 255;
      tetris->piece.couleur.orange = 0;
    } else if (tetris->piece.numero == 1) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 3;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.couleur.violet = 0;
        tetris->piece.couleur.orange = 0;
        tetris->piece.couleur.noir = 255;

      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 3;
        tetris->piece.couleur.violet = 0;
        tetris->piece.couleur.noir = 255;
        tetris->piece.couleur.orange = 0;
      }
    } else if (tetris->piece.numero == 2) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 128;
      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 128;
      }
    } else if (tetris->piece.numero == 3) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.couleur.violet = 0;
        tetris->piece.couleur.noir = 255;
        tetris->piece.couleur.orange = 255;
      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.couleur.violet = 0;
        tetris->piece.couleur.noir = 255;
        tetris->piece.couleur.orange = 255;
      }
    } else if (tetris->piece.numero == 4) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 128;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 128;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 3) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 128;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 4) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 128;
        tetris->piece.couleur.orange = 0;
      }
    } else if (tetris->piece.numero == 5) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 3) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 0;
      } else if (tetris->piece.orientation == 4) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.couleur.violet = 255;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 0;
      }
    } else if (tetris->piece.numero == 6) {
      if (tetris->piece.orientation == 1) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 120;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 255;
      } else if (tetris->piece.orientation == 2) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 2;
        tetris->piece.couleur.violet = 120;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 255;
      } else if (tetris->piece.orientation == 3) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 2;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne + 1;
        tetris->piece.couleur.violet = 120;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 255;
      } else if (tetris->piece.orientation == 4) {
        tetris->piece.tab[1].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[1].colonne = tetris->piece.tab[0].colonne;
        tetris->piece.tab[2].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[2].colonne = tetris->piece.tab[0].colonne - 1;
        tetris->piece.tab[3].ligne = tetris->piece.tab[0].ligne - 1;
        tetris->piece.tab[3].colonne = tetris->piece.tab[0].colonne - 2;
        tetris->piece.couleur.violet = 120;
        tetris->piece.couleur.noir = 0;
        tetris->piece.couleur.orange = 255;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    tetris->modele[i].numero = i;
  }
}

int aleaPiece() { 
return rand() % 6; 		// appelle une piece au hasard
}



char cube(
    int colonne) {                               // permet de changer les 0 en espace et les 1 en @
  switch (colonne) {
  case 0:
    return ' ';
    break;
  case 1:
    return '@';
    break;
  case 2:
    return '@';
    break;
  case 3:
    return '@';
    break;
  case 4:
    return '@';
    break;
  case 5:
    return '@';
    break;
  case 6:
    return '@';
    break;
  case 7:
    return '@';
    break;
  case -1:
    return '*';
    break;
  }
}

void couleurPiece(tetris_s *tetris) {
  for (int i = 4; i < tetris->hauteur; i++) {
    for (int j = 0; j < tetris->largeur; j++) {
      if (j < tetris->largeur - 1) {
        if (tetris->grille[i][j] == 1) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;255;0m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 2) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;255;0m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 3) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;0;128m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 4) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;255;255m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 5) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;128;0m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 6) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;0;0m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 7) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;0;255m");
          printf("%c", cube(tetris->grille[i][j]));
        } else if (tetris->grille[i][j] == 0) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;255;255m");
          printf("%c", cube(tetris->grille[i][j]));
        }
      }

      else {
        if (tetris->grille[i][j] == 1) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;255;0m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 2) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;255;0m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 3) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;0;128m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 4) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;255;255m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 5) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;128;0m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 6) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;0;0m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 7) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;0;0;255m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        } else if (tetris->grille[i][j] == 0) {
          printf("\33[38;2;255;255;255m");
          printf("|");
          printf("\33[38;2;255;255;255m");
          printf("%c", cube(tetris->grille[i][j]));
          printf("\33[38;2;255;255;255m");
          printf("|");
        }
      }
    }
    printf("\n");
  }
}

void afficheGrille(tetris_s *tetris) {                       // affiche la calandre avec les chiffres ci-dessus et les pièces

  verification(tetris->grille, 3);
  printf(" ");
  for (int i = 0; i < tetris->largeur; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < tetris->largeur; j++) {
      tetris->grille[i][j] == 0;
      printf(" %c", cube(tetris->grille[i][j]));
    }
    printf("\n");
  }
  couleurPiece(tetris);
}

void montrerPiece(tetris_s *tetris) {                    // permet de montrer au joueur la piece  qu'il devra jouer et ses orientations
                                                      
  printf("\n");
  if (tetris->piece.numero == 0) {
    printf("  @@\n  @@\n");
  } else if (tetris->piece.numero == 1) {
    printf("  1     2\n  @  @ @ @ @\n  @\n  @\n  @\n");
  } else if (tetris->piece.numero == 2) {
    printf("    1     2\n    @ @   @\n  @ @     @ @\n            @\n");
  } else if (tetris->piece.numero == 3) {
    printf("   1       2\n         @\n @ @     @ @\n   @ @     @\n");
  } else if (tetris->piece.numero == 4) {
    printf("    1     2      3      4\n    @     @    @ @ @    @\n  @ @ @   @ "
           "@    @    @ @\n          @             @\n");
  } else if (tetris->piece.numero == 5) {
    printf("  1    2       3   4\n  @          @ @\n  @    @ @ @   @   @\n  @ "
           "@  @       @   @ @ @\n");
  } else if (tetris->piece.numero == 6) {
    printf("  1     2       3        4\n    @           @ @\n    @   @       @ "
           "   @ @ @\n  @ @   @ @ @   @        @\n");
  }
  printf("\n");
}



void fin(tetris_s *tetris) {                         // tetris->fin = 1 if a piece goes si hors de la grille
  for (int i = 0; i < 4; i++) {
    if (tetris->piece.tab[i].ligne < 4) {
      tetris->fin = 1;
    }
  }
}

int impossible(tetris_s *tetris) {                     // retourne 1 si la case est pas disponible
  for (int i = 0; i < 4; i++) {
    if (tetris->piece.tab[i].colonne < 0 ||
        tetris->piece.tab[i].colonne > tetris->largeur - 1) {
      printf("Impossible de choisir cette colonne %i\n", i);
      return 1;
    }
  }
  return 0;
}

int sens(tetris_s *tetris) {                      			 // voir si orientation est valide
  if (tetris->piece.numero == 1 || tetris->piece.numero == 2 ||
      tetris->piece.numero == 3) {
    if (tetris->piece.orientation == 1 || tetris->piece.orientation == 2) {
      return 1;
    } else {
      return 0;
    }
  } else if (tetris->piece.numero == 4 || tetris->piece.numero == 5 ||
             tetris->piece.numero == 6) {
    if (tetris->piece.orientation == 1 || tetris->piece.orientation == 2 ||
        tetris->piece.orientation == 3 || tetris->piece.orientation == 4) {
      return 1;
    } else {
      return 0;
    }
  }
}

int lireCase(int grille[TAILLE][TAILLE], int ligne, int colonne) { 
  if (grille[ligne][colonne] == 0) {
    return 0;                                                            // voir si la case est libre
  } else {
    return 1;
  }
}

int largeurPiece(tetris_s tetris) {                         // retourne la largeur des pieces
  if (tetris.piece.numero == 0) {
    return 2;
  } else if (tetris.piece.numero == 1) {
    if (tetris.piece.orientation == 1) {
      return 1;
    } else if (tetris.piece.orientation == 2) {
      return 4;
    }
  } else if (tetris.piece.numero == 2 || tetris.piece.numero == 3) {
    if (tetris.piece.orientation == 1) {
      return 3;
    } else if (tetris.piece.orientation == 2) {
      return 2;
    }
  } else if (tetris.piece.numero == 4) {
    if (tetris.piece.orientation % 2 == 1) {
      return 3;
    } else if (tetris.piece.orientation % 2 == 0) {
      return 2;
    }
  } else if (tetris.piece.numero == 5 || tetris.piece.numero == 6) {
    if (tetris.piece.orientation % 2 == 1) {
      return 2;
    } else if (tetris.piece.orientation % 2 == 0) {
      return 3;
    }
  }
}

int hauteurPiece(tetris_s tetris) {                         // retourne la hauteur des pieces
  if (tetris.piece.numero == 0) {
    return 2;
  } else if (tetris.piece.numero == 1) {
    if (tetris.piece.orientation == 1) {
      return 4;
    } else if (tetris.piece.orientation == 2) {
      return 1;
    }
  } else if (tetris.piece.numero == 2 || tetris.piece.numero == 3) {
    if (tetris.piece.orientation == 1) {
      return 2;
    } else if (tetris.piece.orientation == 2) {
      return 3;
    }
  } else if (tetris.piece.numero == 4) {
    if (tetris.piece.orientation % 2 == 1) {
      return 2;
    } else if (tetris.piece.orientation % 2 == 0) {
      return 3;
    }
  } else if (tetris.piece.numero == 5 || tetris.piece.numero == 6) {
    if (tetris.piece.orientation % 2 == 1) {
      return 3;
    } else if (tetris.piece.orientation % 2 == 0) {
      return 2;
    }
  }
}

int verif(tetris_s *tetris) {                               // pour voir si toutes les cases 									sont utlisés
  int c = 0;
  for (int i = 0; i < 4; i++) {
    while (tetris->grille[tetris->piece.tab[i].ligne]
                         [tetris->piece.tab[i].colonne] == 0 &&
           tetris->piece.tab[0].ligne < tetris->hauteur - 1 && c < i + 1) {
      c++;
      if (c == 4) {
        return 1;
      }
    }
    if (tetris->grille[tetris->piece.tab[i].ligne]
                      [tetris->piece.tab[i].colonne] != 0) {
      if (tetris->piece.tab[i].ligne < 0) {
        tetris->fin = 1;
      } else {
        tetris->piece.tab[0].ligne--;
        creerPiece(tetris);
      }
      return 0;
    }
  }
}

void addition(tetris_s *tetris) {             // ajoute +1 a la ligne pour mettre des @
  verification(tetris->grille, 5);
  for (int k = 0; k < 7; k++) {
    if (tetris->piece.numero == k) {
      for (int i = 0; i < 4; i++) {
        if (tetris->piece.tab[i].ligne > 3) {
          tetris->grille[tetris->piece.tab[i].ligne]
                        [tetris->piece.tab[i].colonne] = k + 1;
        } else {
          tetris->grille[tetris->piece.tab[i].ligne]
                        [tetris->piece.tab[i].colonne] = -1;
        }
      }
    }
  }
}

void ligneMax(tetris_s *tetris) {                   // allows to make the collisions
  tetris->piece.tab[0].ligne = hauteurPiece(*tetris) - 1;
  creerPiece(tetris);
  while (verif(tetris) != 0) {
    tetris->piece.tab[0].ligne++;
    creerPiece(tetris);
  }
}

void placement(tetris_s *tetris) {                     // general function of the piece placement,
                                                       // including all functions above
  time_t debut;
  verification(tetris->grille, 5);
  tetris->piece.numero = aleaPiece();
  printf("\33[38;2;255;255;255m");
  montrerPiece(tetris);
  printf("Ton score est %d\n\n", tetris->score);
  debut = time(NULL);
  if (tetris->piece.numero != 0) {
    do {
      printf("Choisis le sens de la pièce :\n\n");
      scanf("%d", &tetris->piece.orientation);
      flush();
    } while (sens(tetris) == 0);
  }
  do {
    printf("Choisie la colonne :\n");
    tetris->piece.tab[0].colonne = -1;
    if (scanf("%d", &(tetris->piece.tab[0].colonne)) == 1) {
      time_t finColonne = time(NULL);
      tetris->place_temps = (unsigned long)finColonne - debut;
      if (tetris->place_temps > 15) {
        printf("%lu sec\n", tetris->place_temps);
        printf("Il ne te reste plus beaucoup de temps \n");
        tetris->piece.tab[0].colonne =
            rand() % (tetris->largeur - hauteurPiece(*tetris));
        printf("La colonne aléatoire choisie est  %d\n",
               tetris->piece.tab[0].colonne);
      }
      ligneMax(tetris);
      creerPiece(tetris);
    }
  } while (impossible(tetris));
  fin(tetris);
  addition(tetris);
}

int lignePleine(int **grille, int hauteur, int largeur,
                int ligne) {                               // voir si la ligne est pleine
  if (ligne >= 0 && ligne < hauteur) {
    for (int i = 0; i < largeur; i++) {
      if (grille[ligne][i] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int plein(tetris_s *tetris) {                             // retourner la ligne qui est pleine
  for (int i = 0; i < tetris->hauteur; i++) {
    if (lignePleine(tetris->grille, tetris->hauteur, tetris->largeur, i) == 1) {
      return i;
    }
  }
  return 0;
}

void enleverLigne(tetris_s *tetris) {                   /*supprimer une ligne et fait descendre toutes les lignes au-dessus*/
  verification(tetris->grille, 7);
  tetris->compte_ligne = 0;
  while ((plein(tetris) != 0)) {
    tetris->compte_ligne++;
    for (int i = plein(tetris) - 1; i > 0; i--) {
      for (int j = 0; j < tetris->largeur; j++) {
        tetris->grille[i + 1][j] = tetris->grille[i][j];
        tetris->grille[0][j] = 0;
      }
    }
  }
  if (tetris->compte_ligne == 0) {
    tetris->score = tetris->score;
  } else if (tetris->compte_ligne == 1) {
    tetris->score = tetris->score + 10;
  } else if (tetris->compte_ligne == 2) {
    tetris->score = tetris->score + 50;
  } else if (tetris->compte_ligne == 3) {
    tetris->score = tetris->score + 100;
  } else {
    tetris->score = tetris->score + 1000;
  }
}

void record(tetris_s tetris) {
  printf("Il te reste  %ld sec\n", tetris.temps);
  printf("Donne moi ton nom BG ;) : \n");
  scanf("%s", tetris.nom);
  FILE *fichier = fopen("record.txt", "r");
  if (fichier == NULL) {
    exit(1);
  }
  fscanf(fichier, "%s %d", tetris.record[0].nom, &tetris.record[0].score);
  fclose(fichier);
  if (tetris.score > tetris.record[0].score) {
    printf("TU ES LE NOUVEAU CHAMPION \n");
    fichier = fopen("record.txt", "w");
    fseek(fichier, 0, SEEK_SET);
    fprintf(fichier, "%s %d\n", tetris.nom, tetris.score);
    fseek(fichier, 0, SEEK_SET);
    fclose(fichier);
  }
  fichier = fopen("record.txt", "r");
  fscanf(fichier, "%s %d", tetris.record[0].nom, &tetris.record[0].score);
  printf("\n Le record est détenu par:\nname : %s\nscore : %d\n",
         tetris.record[0].nom, tetris.record[0].score);
  fclose(fichier);
}

#ifndef FILE_FONCTION_H

    #define FILE_FONCTION_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define TAILLE 10

   

    typedef struct {
        int orange;
        int noir;
        int violet;
        }couleur_s;

    typedef struct {
      int ligne;
      int colonne;
    }coordonnee_s;

   

    typedef struct{
      coordonnee_s tab[4];
      couleur_s couleur;
      int largeur;
      int numero;
      int orientation;
      int hauteur;
    }piece_s;

    typedef struct {
    int score;    
    char nom[15];
    }record_s;

 typedef struct {
      piece_s modele[7];
      piece_s piece;
      record_s record[10];
      int score;
      int fin;
      int largeur;
      char nom[15];
      int hauteur;
      int colonne;
      int **grille;
      int ligne;
      int compte_ligne;
      long unsigned temps;
      long unsigned place_temps;
    }tetris_s;

    void creerGrille(tetris_s* tetris);
    int aleaPiece();
    char cube(int colonne);
    void initialisationGrille(tetris_s* teris);
    void montrerPiece(tetris_s* tetris);
    void fin(tetris_s* tetris);
    int hauteurPiece(tetris_s tetris);
    int sens(tetris_s* tetris);
    int lireCase(int grille[TAILLE][TAILLE],int ligne,int colonne);
    int largeurPiece(tetris_s tetris);
    void placement(tetris_s* tetris);
    int verif(tetris_s* tetris);
    void record(tetris_s tetris);
    void addition(tetris_s* tetris);
    void ligneMax(tetris_s* tetris);
    void enleverLigne(tetris_s* tetris);
    int lignePleine(int** grille, int hauteur,int largeur,int ligne);
    int plein(tetris_s* tetris);
    void afficheGrille(tetris_s* tetris);
    int impossible(tetris_s* tetris);

#endif 

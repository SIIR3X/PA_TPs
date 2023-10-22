#pragma once

typedef enum{ TXT, BIN } file_mode_t;

/** @brief une matrice de dimensions nbLigXnbCol
  * est modélisée par un vecteur mémoire
  * <values> de taille n*m.
  *
  * Il est donc nécessaire de définir des
  * fonctions de mise en correspondance
  * entre les indices (l,c) de ligne et de
  * colonne de la matrice et les indices k
  * du vecteur mémoire <values>
  */
typedef struct {
  double * values ;
  int nbLig, nbCol ;
} matrix_t;

/** @brief Effectuter l'allocation mémoire
  * d'une matrice de dimensions nXm
  */
matrix_t * consMatrix( int nbLig, int nbCol );

/** @brief Faire une copie exacte
  * (mais distincte) de la matrice
  * référencée par M
  */
matrix_t * cpyMatrix( matrix_t * M );

/** @brief Désallouer la mémoire référencée par M */
void freeMatrix( matrix_t ** ptrM );

/** @brief Lecture au clavier d'une matrice */
matrix_t * scanMatrix();

/** @brief Visualiser la matrice référencée par M */
void printMatrix( matrix_t * M, char * entete );

/**. @brief Chargement d'une matrice */
matrix_t * readMatrix( char * filename, file_mode_t mode );

/** @brief Sauvegarde d'une matrice */
void writeMatrix( matrix_t *M, char * filename, file_mode_t mode );

/** @brief Renvoie une nouvelle matrice C = A+B */
matrix_t * matrixAdd ( matrix_t * A, matrix_t * B );

/** @brief Renvoie une nouvelle matrice C = AB */
matrix_t * matrixMult( matrix_t * A, matrix_t * B );
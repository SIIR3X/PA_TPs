#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "matrix.h"

int main ( int argc, char ** argv ) {
  if ( argc < 3 ) {
    perror ( "Manque les fichiers des données des 2 matrices" );
    exit ( -1 );
  }
  matrix_t * A = readMatrix(argv[1], TXT);
  matrix_t * B = readMatrix(argv[2], TXT);

  printMatrix(A, "matrice A :");
  printMatrix(B, "matrice B :");

  if(A->nbLig == B->nbLig && A->nbCol == B->nbCol) {
    matrix_t * C = matrixAdd(A, B);
    printMatrix(C, "A + B :");
    writeMatrix(C, "data/C.bin", BIN);
    freeMatrix( &C );
    C = readMatrix("data/C.bin", BIN);
    printMatrix(C, "A + B :");
    freeMatrix( &C );
  }
  if(A->nbCol == B->nbLig) {
    matrix_t * D = matrixMult(A, B);
    printMatrix(D, "A . B :");
    writeMatrix(D, "data/D.bin", BIN);
    freeMatrix(&D);
    D = readMatrix("data/D.bin", BIN);
    printMatrix(D, "A . B :");
    freeMatrix(&D);
  }
  return EXIT_SUCCESS;
}

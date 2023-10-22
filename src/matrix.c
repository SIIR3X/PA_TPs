#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "matrix.h"

matrix_t * consMatrix(int nbLig, int nbCol){
  assert(nbLig > 0 && nbCol > 0);
  matrix_t * M = calloc( 1, sizeof(matrix_t));
  assert(M);
  M->nbLig = nbLig;
  M->nbCol = nbCol;
  M->values = calloc(nbLig*nbCol, sizeof(double));
  assert(M->values);
  return M;
}

matrix_t * cpyMatrix(matrix_t * M){
  assert(M);
  matrix_t * N = consMatrix(M->nbLig,M->nbCol);

  for(int k = 0; k < M->nbLig*M->nbCol; k += 1){
    N->values[k] = M->values[k];
  }
  return N;
}

void freeMatrix(matrix_t ** ptrM){
  assert(ptrM && *ptrM);
  free((*ptrM)->values);
  free(*ptrM);
  *ptrM = NULL;
}

matrix_t * scanMatrix(){
  int nbLig, nbCol;
  do
  {
    printf("Nombres de lignes et de colonnes ? ");
    scanf(" %d %d", &nbLig, &nbCol);
  } while (nbLig <= 0 || nbCol <= 0);

  matrix_t * M = consMatrix(nbLig, nbCol);
  for(int l=0; l<nbLig; l+=1){
    for(int c=0; c<nbCol; c+=1){
      printf("M[%d,%d] = ",l,c);
      scanf(" %lf",M->values+(l*M->nbCol+c));
    }
  }
  return M;
}

void printMatrix(matrix_t * M, char * entete){
  assert(M);

  printf("%s\n", entete);
  for(int l = 0; l < M->nbLig; l += 1){
    printf("\t");
    for(int c = 0; c < M->nbCol; c += 1){
      int k = l * M->nbCol + c;
      printf("%'.2lf\t", M->values[k]);
    }
    printf("\n");
  }
}

matrix_t * readMatrix(char * filename, file_mode_t mode){
  FILE *fd;
  int nbLig, nbCol;
  matrix_t *M;
  if(mode == TXT){
    fd = fopen(filename, "rt");
    assert(fd);

    fscanf(fd, "%d %d", &nbLig, &nbCol);
    M = consMatrix(nbLig, nbCol);
    for(int k = 0; k < nbLig*nbCol; k += 1){
      fscanf(fd, "%lf", &(M->values[k]));
    }
  }else{
    fd = fopen(filename, "rb");
    assert(fd);

    fread(&nbLig, sizeof(double), 1, fd);
    fread(&nbCol, sizeof(double), 1, fd);
    M = consMatrix(nbLig, nbCol);
    fread(M->values, sizeof(double), M->nbLig * M->nbCol, fd);
  }
  fclose(fd);
  return M;
}

void writeMatrix(matrix_t *M, char * filename, file_mode_t mode){
  FILE *fd;
  if(mode == TXT) {
    fd = fopen (filename, "wt");
    assert(fd);

    fprintf (fd, "%d %d\n", M->nbLig, M->nbCol);
    for(int k = 0; k < M->nbLig * M->nbCol; k+=1){
      fprintf (fd, "%lf ", M->values[k]);
    }
    fprintf (fd, "\n");
  }else{
    fd = fopen(filename, "wb");
    assert(fd);

    fwrite(&(M->nbLig), sizeof(double), 1, fd);
    fwrite(&(M->nbCol), sizeof(double), 1, fd);
    fwrite(M->values, sizeof(double), M->nbLig*M->nbCol, fd);
  }
  fclose (fd);
}

matrix_t * matrixAdd(matrix_t * A, matrix_t * B){
  assert(A->nbLig == B->nbLig && A->nbCol == B->nbCol);

  matrix_t * C = consMatrix(A->nbLig, A->nbCol);

  for ( int k = 0; k < C->nbLig*C->nbCol; k += 1 ) {
    C->values[k] = A->values[k] + B->values[k];
  }
  return C;
}

matrix_t * matrixMult(matrix_t * A, matrix_t * B){
  assert(A->nbCol == B->nbLig);
  
  matrix_t * C = consMatrix(A->nbLig, B->nbCol);
  int K = A->nbCol;

  for(int l = 0; l < C->nbLig; l += 1){
    for(int c = 0; c < C->nbCol; c += 1){
      int kC = l * C->nbCol + c;
      // C->values[kC] = 0;                CETTE INSTRUCTION EST INUTILE GRÂCE À CALLOC()
      for(int k = 0; k < K; k += 1 ){
        int kA = l * A->nbCol + k;
        int kB = k * B->nbCol + c;
        C->values[kC] += A->values[kA] * B->values[kB];
      }
    }
  }
  return C;
}
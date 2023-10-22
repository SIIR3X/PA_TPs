#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


matrix_t * consMatrix(int nLig, int nCol){
    if (nLig <= 0 || nCol <= 0) return NULL;

    matrix_t* matrix = (matrix_t*)malloc(sizeof(matrix_t));
    if (!matrix) return NULL;

    matrix->values = (double*)malloc(sizeof(double) * nLig * nCol);
    if (!matrix->values){
        free(matrix);
        return NULL;
    }
    
    matrix->nbLig = nLig;
    matrix->nbCol = nCol;

    return matrix;
}


matrix_t * cpyMatrix(matrix_t * M ){
    if (M == NULL) return NULL;

    matrix_t* newMatrix = (matrix_t*)malloc(sizeof(matrix_t));
    if (!newMatrix) return NULL;

    newMatrix->values = (double*)malloc(sizeof(double) * M->nbLig * M->nbCol);
    if (!newMatrix->values){
        free(newMatrix);
        return NULL;
    }

    newMatrix->nbLig = M->nbLig;
    newMatrix->nbCol = M->nbCol;

    return newMatrix;
}


void freeMatrix(matrix_t ** ptrM ){
    if (ptrM == NULL || *ptrM == NULL) return;

    free((*ptrM)->values);
    
    free(*ptrM);
    *ptrM = NULL;
}


void printMatrix(matrix_t * M, char * entete) {
    if (M == NULL || M->values == NULL) {
        return;
    }

    int i, j;

    printf("%s\n", entete);

    for (i=0; i < M->nbLig; i++) {
        printf(" ");
        for (j=0; j < M->nbCol; j++) {
            printf("%.2lf  ", M->values[i * M->nbCol + j]);
        }
        printf("\n");
    }

    printf("\n");
}


matrix_t * scanMatrix(){
    int nbLig, nbCol, i, j;

    do{
        printf(" Nombre de lignes : ");
        scanf("%d", &nbLig);

        if (nbLig < 1 || nbLig > NBCOMPMAX){
            printf(" %d n'est pas valide.\n", nbLig);
        }
    } while (nbLig < 1 || nbLig > NBCOMPMAX);

    do{
        printf( " Nombre de colonnes : ");
        scanf("%d", &nbCol);

        if (nbCol < 1 || nbCol > NBCOMPMAX){
            printf(" %d n'est pas valide.\n", nbLig);
        }
    } while (nbCol < 1 || nbCol > NBCOMPMAX);

    matrix_t* M = consMatrix(nbLig, nbCol);
    if (!M) return NULL;

    for(i=0; i < M->nbLig; i++){
        for(j=0; j < M->nbCol; j++){
            printf(" M[%d][%d] : ", i+1, j+1);
            scanf("%lf", &M->values[i * nbCol + j]);
        }
    }

    return M;
}


matrix_t * addMatrix (matrix_t * A, matrix_t * B){
    if (A == NULL || A->values == NULL) return NULL;
    if (B == NULL || B->values == NULL) return NULL;
    if (A->nbLig != B->nbLig || A->nbCol != B->nbCol) return NULL;

    int i, j;

    matrix_t* C = consMatrix(A->nbLig, A->nbCol);
    if (!C) return NULL;

    for(i=0; i < C->nbLig; i++){
        for(j=0; j < C->nbCol; j++){
            C->values[i * C->nbCol + j] = A->values[i * A->nbCol + j] + B->values[i * B->nbCol + j];
        }
    }

    return C;
}


matrix_t * multMatrix(matrix_t * A, matrix_t * B){
    if (A == NULL || A->values == NULL) return NULL;
    if (B == NULL || B->values == NULL) return NULL;
    if (A->nbCol != B->nbLig) return NULL;

    int i, j, k;

    matrix_t* C = consMatrix(A->nbLig, B->nbCol);
    if (!C) return NULL;

    for(i=0; i < C->nbLig * C->nbCol; i++){
        C->values[i] = 0.0;
    }

    for(i=0; i < A->nbLig; i++){
        for(j=0; j < B->nbCol; j++){
            for(k=0; k < A->nbCol; k++){
                C->values[i * C->nbCol + j] += A->values[i * A->nbCol + k] * B->values[k * B->nbCol + j];
            }
        }
    }

    return C;
}
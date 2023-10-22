#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

vector_t scanVector () {
    vector_t V;

    do {
        printf (" Donnez le nombre de composantes du vecteur (≤ %d) : ", NBCOMPMAX);
        scanf ("%d", &V.nbComp);
    } while (V.nbComp < 1 || V.nbComp > NBCOMPMAX);

    for(int c = 0; c < V.nbComp; c += 1) {
        printf(" V[%d] ? ", c);
        scanf(" %lf", &(V.values[c]));
    }

    return V;
}

void printVector (vector_t M) {
    printf ("[");
    for (int c = 0; c < M.nbComp; c += 1) {
        printf (" %2.2lf", M.values[c]);
    }
    printf (" ]\n ");
}

double prodScal(vector_t V1, vector_t V2){
    assert(V1.nbComp == V2.nbComp);

    int i;
    double p = 0;

    for(i=0 ; i < V1.nbComp ; i++){
        p += (V1.values[i] * V2.values[i]);
    }

    return p;
}

vector_t prodInt(vector_t V, double lambda){
    assert(V.values != NULL);

    int i;
    vector_t lV;

    lV.nbComp = V.nbComp;

    for(i=0 ; i < lV.nbComp ; i++){
        lV.values[i] = V.values[i] * lambda;
    }

    return lV;
}
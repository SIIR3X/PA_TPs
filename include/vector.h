#pragma once

#define NBCOMPMAX 20

typedef struct vector {
  int nbComp;
  double values[NBCOMPMAX];
} vector_t;

vector_t scanVector();
void printVector (vector_t V);
double prodScal(vector_t V1, vector_t V2);
vector_t prodInt(vector_t V, double lambda);
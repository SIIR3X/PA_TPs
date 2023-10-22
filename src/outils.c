#include <stdlib.h>
#include <stdio.h>

#define EPSILON 0.0000001

void printInteger(int * i){
  printf("La valeur est entière et vaut : %d\n", (*i));
}
void rmInteger(int * i){
  free(i);
}
int cmpInteger(int * i, int * j){
  return (*i) - (*j);
}
void printDouble(double * d){
  printf("La valeur est réelle et vaut : %lf\n", (*d));
}

void rmDouble(double * d){
  free(d);
}
int cmpDouble(double * u, double * v){
  if((*u) < (*v)) return -1;
  if((*u) - (*v) < EPSILON) return 0;
  return +1;
}

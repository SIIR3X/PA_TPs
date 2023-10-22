#include "vector.h"
#include <stdio.h>

int main() {
  vector_t V = scanVector();
  printVector(V);

  double lambda;
  printf("lambda ? ");
  scanf(" %lf", &lambda);

  vector_t V2 = prodInt(V,lambda);
  printVector(V2);
  printf(" prod scal = %lf\n", prodScal(V,V2));
  return 0;
}
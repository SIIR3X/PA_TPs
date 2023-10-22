#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"


int choice(int min, int max){
    int number;

    do{
        printf(" Entrez votre choix (%d - %d): ", min, max);
        scanf("%d", &number);

        if (number < min || number > max){
            printf(" Choix invalide.\n");
        }
    } while(number < min || number > max);

    return number;
} 


int checkDimensions(matrix_t* A, matrix_t* B){
    int somm;

    somm = 0;

    if (A->nbLig == B->nbLig && A->nbCol == B->nbCol) somm++;
    if (A->nbCol == B->nbLig) somm++;

    return somm;
}



int main(){
    int number;

    do{
        printf("\n     Application     \n\n");
        printf(" 1. Vecteurs\n");
        printf(" 2. Matrices\n");
        printf(" 0. Quitter\n\n");
        number = choice(0, 2);

        if (number == 1){
            printf("\n\n");
            
            double lambda;
            vector_t V1;
            vector_t V2;
            vector_t V3;

            printf(" 1. Multiplier un vecteur par une constante\n");
            printf(" 2. Produit scalaire\n");
            printf(" 0. Quitter\n\n");

            number = choice(0, 2);

            if (number == 1){
                printf("\n       Vecteur V1 :\n");
                V1 = scanVector();
                printf("\n Vecteur : ");
                printVector(V1);

                printf("\n Lambda : ");
                scanf("%lf", &lambda);

                V3 = prodInt(V1, lambda);
                printf("\n Vecteur multiplié : ");
                printVector(V3);
            }
            else if (number == 2){
                printf("\n       Vecteur V1 :\n");
                V1 = scanVector();

                printf("\n       Vecteur V2 :\n");
                V2 = scanVector();

                printf("\n V1 : ");
                printVector(V1);
                printf("\n V2 : ");
                printVector(V2);

                if (V1.nbComp != V2.nbComp){
                    printf("\n Nombre de coordonnées différent.\n");
                }
                else{
                    printf("\n Produit scalaire : %.2lf\n", prodScal(V1, V2));
                }
            }
        }
        else if (number == 2){
            printf("\n\n");

            int i;
            matrix_t* A;
            matrix_t* B;
            matrix_t* C = NULL;
            matrix_t* D = NULL;

            printf("     Matrice A\n");
            A = scanMatrix();

            printf("\n     Matrice B :\n");
            B = scanMatrix();

            printf("\n\n");
            printMatrix(A, "     Matrice A");
            printMatrix(B, "     Matrice B");
            printf("\n");

            i = 1;

            int canAdd = (A->nbLig == B->nbLig && A->nbCol == B->nbCol);
            int canMultiply = (A->nbCol == B->nbLig);

            if (canAdd) {
                printf(" %d. Additionner les matrices\n", i++);
            }

            if (canMultiply) {
                printf(" %d. Multiplier les matrices\n", i++);
            }

            if (i == 3) {
                printf(" %d. Additionner et Multiplier\n", i);
            } else if (i == 1) {
                printf(" Aucune opération n'est possible.\n");
            }

            if (i > 1) {
                printf("\n");
                number = choice(1, i);
                printf("\n");
            }

            if (i == 3) {
                if (number == 1) {
                    C = addMatrix(A, B);
                } else if (number == 2) {
                    D = multMatrix(A, B);
                } else if (number == 3) {
                    C = addMatrix(A, B);
                    D = multMatrix(A, B);
                }
            } else {
                if (canAdd && number == 1) {
                    C = addMatrix(A, B);
                } else if (canMultiply && number == 1) {
                    D = multMatrix(A, B);
                }
            }

            if (C && canAdd) printMatrix(C, " Matrice Addition :");
            if (D && canMultiply) printMatrix(D, " Matrice Multiplication :");

            if (A) freeMatrix(&A);
            if (B) freeMatrix(&B);
            if (C) freeMatrix(&C);
            if (D) freeMatrix(&D);
        }

        if (number != 0){
            printf("\n\n |--------------|");
            printf("\n | Continuer ?  |\n");
            printf(" | 0. Non       |\n");
            printf(" | 1. Oui       |\n");
            printf(" |______________|\n\n");
            number = choice(0, 1);

            if (number == 1){
                printf("\n\n");
            }
        }
    } while (number != 0);

    return 0;
}
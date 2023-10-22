#include <stdlib.h>
#include <stdio.h>
#include "outils.h"
#include "elmlist.h"
#include "list.h"

/**
 *
 * ALGORITHME (FONCTION PRINCIPALE)
 *
 * Deux versions possibles : mainHétéroet mainHomo.
 *
 * La première repose sur la notion de
 *  liste **générique hétérogène** dont les
 *  données peuvent être de types différents.
 * Il faut alors connaître le type de chaque donnée.
 * Et il n'est évidemment pas possible de définir
 *  une fonction de visualisation des données ni
 *  une fonction de suppression de liste
 *  dans la "bibliothèque" <list>
 * Cette approche est lourde et complexe.
 * À utiliser qu'en cas de nécessité.
 *
 * La seconde repose sur la notion de
 *  liste **générique homogène** dont toutes
 *  les données sont de même type.
 * On peut alors définir :
 *  (+) une **unique** fonction de visualisation,
 *  (+) une **unique** fonction de suppression.
 * grâce à la notion avancée de pointeur de fonction.
 *
 * Je vous encourage vivement à utiliser
 * la seconde approche dans vos projets.
 */


void mainHetero ();
void mainHomo ();
void listehomoentiere ();
void listehomoreelle ();

int main() {
  mainHomo();
  mainHetero ();
  return EXIT_SUCCESS;
}

void mainHomo () {
  listehomoentiere();
  listehomoreelle();
}

void listehomoreelle() {
  /** @brief
   * Déclaration des pointeurs de fonctions
   * + d'affichage ptrPrintI
   * + de libération ptrRmI
   * + de comparaison ptrIntcmp
   * pour le type réel
   */
  void (*ptrF_print)(double *) = &printDouble;
  void (*ptrF_rm)(double *) = &rmDouble;
  int (*ptrF_cmp)(double *, double *) = &cmpDouble;

  list_t * L = new_list();
  do {
    double * v = calloc(1,sizeof(double));

    printf("Entrez un réel (0 pour s'arrêter): ");
    scanf("%lf", v);
    if(*v == 0){
      free(v);
      break;
    }
    // cons(L,v);
    insert_ordered(L, v, ptrF_cmp);
  }while(true);
  view_list(L, ptrF_print);
  del_list(&L, ptrF_rm);
}

void listehomoentiere() {
  /** @brief
   * Déclaration des pointeurs de fonctions
   *  (+) d'affichage ptrPrintI
   *  (+) de libération ptrRmI
   *  (+) de comparaison ptrIntcmp
   * pour le type entier
   */
  void (*ptrF_print)(int *) = &printInteger;
  void (*ptrF_rm)(int *) = &rmInteger;
  int (*ptrF_cmp)(int *, int*) = &cmpInteger;

  list_t * L = new_list();
  do{
    int * v = calloc(1,sizeof(int));

    printf("Entrez un entier (0 pour s'arrêter): ");
    scanf("%d", v);
    if(*v == 0) {
      free(v);
      break;
    }
    // cons(L,v);
    insert_ordered(L, v, ptrF_cmp);
  }while(true);
  view_list(L, ptrF_print);
  del_list(&L, ptrF_rm);
}


void mainHetero () {
  int a = 8, b = 4, * ptra = &a, * ptrb = &b;
  double x = 5.4, y = 3.14, * ptrx = &x, * ptry = &y;
  list_t * L = new_list();

  cons(L, ptra); // un entier
  cons(L, ptrb); // un entier
  cons(L, ptrx); // un réel
  cons(L, ptry); // un réel
  /* La liste vaut alors : [ 3.14 ; 5.4 ; 4 ; 8 ] */

  /* Afficher cette liste ==> Il faut se souvenir du type de chaque élément !!! */
  elmlist_t * E;
  int cmpt;
  for(cmpt = 0, E = get_head(L) ; cmpt < get_numelm(L) ; cmpt += 1, E = get_suc(E)){
    if(cmpt < 2) {
      double * d = get_data(E);
      printf("La valeur est réelle et vaut : %lf\n",*d);
    } else {
      int * d = get_data(E);
      printf("La valeur est entière et vaut : %d\n",*d);
    }
  }
  del_list(&L, NULL);
}
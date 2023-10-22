#include <stdlib.h>
#include <assert.h>

#include "elmlist.h"

/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/
elmlist_t * new_elmlist(void * d){
  elmlist_t * E = calloc(1,sizeof(elmlist_t));
  assert(E);
  E->datum = d;
  return E;
}

void del_elmlist(elmlist_t ** ptrE, void(*ptrF_del)()){
  assert(ptrE && *ptrE);
  if(ptrF_del) (*ptrF_del)((*ptrE)->datum);
  free(*ptrE);
  *ptrE = NULL;
}

void * get_data(elmlist_t * E){
  assert(E);
  return E->datum;
}

elmlist_t * get_suc(elmlist_t * E){
  assert(E);
  return E->suc;
}

void set_data(elmlist_t * E, void * d ){
  assert(E);
  E->datum = d;
}

void set_suc(elmlist_t * E, elmlist_t * S){
  assert(E);
  E->suc = S;
}

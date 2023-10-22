#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie booléenne
#include <assert.h> // librairie d'assertions

#include "list_elm.h"

/**
 * @brief DÉFINITION DES FONCTIONS PUBLIQUES
 * 
 */

list_elm_t * new_list_elm(int v){
	list_elm_t * E = calloc(1,sizeof(list_elm_t)); // mémoire mise à 0 (NULL)
	assert(E);
	set_x(E,v);
	return E;
}

void del_elmlist(list_elm_t ** ptrE){
	assert(ptrE && *ptrE);
	free(*ptrE);
	*ptrE = NULL;
}

int get_x(list_elm_t * E){
	assert(E);
	return E->x;
}

void set_x(list_elm_t * E, int v){
	assert(E);
	E->x = v;
}

list_elm_t * get_suc(list_elm_t * E){
	assert(E);
	return E->suc;
}

void set_suc(list_elm_t * E, list_elm_t * S){
	assert(E);
	E->suc = S;
}

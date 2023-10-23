#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions

#include "outils.h"
#include "elmlist.h"
#include "list.h"

/*********************************
DÉCLARATIONS DES FONCTIONS PRIVÉES
*********************************/
/** `insert_after` insère la donnée pointée par `d` dans la liste `L`
		après l'élément pointée par `P` dans cette liste.
*/
void insert_after(list_t * L, void * d, elmlist_t * place);


/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/
bool empty_list(list_t * L ) {
	assert(L);
	return L->numelm == 0;
}

list_t * new_list() {
	list_t * L = calloc(1, sizeof(list_t));
	assert(L);
	return L;
}

void del_list(list_t ** ptrL, void(*ptrF)(void*)){
	assert(ptrL && *ptrL);

	if(ptrF){
		for(elmlist_t * E = (*ptrL)->head; E ; ){
			elmlist_t * T = E;
			E = E->suc;
			(*ptrF)(T->datum);
			free(T);
		}
	} else {
		for(elmlist_t * E = (*ptrL)->head; E ; ){
			elmlist_t * T = E;
			E = E->suc;
			free(T);
		}
	}
	(*ptrL)->head = NULL;
	free(*ptrL);
	*ptrL = NULL;
}


elmlist_t * get_head(list_t * L) {
	assert(L);
	return L->head;
}
void set_head( list_t * L, elmlist_t * E) {
	assert(L);
	L->head = E;
}

elmlist_t * get_tail(list_t * L) {
	assert(L);
	return L->tail;
}

void set_tail( list_t * L, elmlist_t * E) {
	assert(L);
	L->tail = E;
}

int get_numelm(list_t * L) {
	assert(L);
	return L->numelm;
}

void incrnumelm( list_t * L) {
	assert(L);
	L->numelm++;
}

void decrnumelm( list_t * L) {
	assert(L);
	L->numelm--;
}

void cons(list_t * L, void * d) {
	elmlist_t * E = calloc(1, sizeof(elmlist_t));
	assert(L && E);
	set_data(E, d);
	set_suc(E, L->head);
	set_head(L, E);
	if(empty_list(L)) L->tail = E;
	L->numelm += 1;
}

void queue(list_t * L, void * d){
	assert(L && d);

	elmlist_t * newElm = new_elmlist(d);
	if (!newElm){
		fprintf(stderr, "Queue : la création de elmlist_t d à échouée.\n");
		return;
	}
	set_suc(newElm, NULL);

	if (empty_list(L)){
		set_head(L, newElm);
	}
	else{
		set_suc(get_tail(L), newElm);
	}
	set_tail(L, newElm);

	L->numelm++;
}

void view_list (list_t * L, void(*ptrF)()){
	assert(L && ptrF);
	for(elmlist_t * E = L->head; E; E = get_suc(E)){
		void * d = E->datum;
		(*ptrF)(d);
	}
}

void insert_ordered(list_t * L, void * d, int (*ptrF_cmp)()){
	assert (L && d && ptrF_cmp);

	if (empty_list(L) || ptrF_cmp(get_data(get_head(L)), d) >= 0){
		cons(L, d);
	}
	else if (ptrF_cmp(get_data(get_tail(L)), d) <= 0) {
		queue(L, d);
	}
	else{
		elmlist_t * current = get_head(L);

		while(current && get_suc(current) && ptrF_cmp(get_data(get_suc(current)), d) < 0){
			current = get_suc(current);
		}
		
		insert_after(L, d, current);
	}
}


/***********************************
 * Définitions des fonctions privées
 ***********************************/

void insert_after(list_t * L, void * d, elmlist_t * place) {
	if(empty_list(L) || !place){
		cons(L, d);
	}else if(place == get_tail(L)){
		queue(L, d);
	}else{
		elmlist_t * E = calloc(1, sizeof(elmlist_t));
		set_data(E, d);
		set_suc(E, get_suc(place));
		set_suc(place, E);
		L->numelm += 1;
	}
}
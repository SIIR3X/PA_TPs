#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie booléenne
#include <assert.h> // librairie d'assertions

#include "list_elm.h"
#include "list.h"

/***********************************
 DÉCLARATIONS DES FONCTIONS PRIVÉES
***********************************/

/**
 * @brief Insérer v après place dans L
 * 
 * @param L :: la liste L
 * @param v :: la valeur à insérer
 * @param place :: l'élément de liste après lequel v doit être insérée
 */
void insert_after(list_t * L, int v, list_elm_t * place);


/************************************
 DÉFINITIONS DES FONCTIONS PUBLIQUES
************************************/

bool empty_list(list_t * L){
	assert(L);
	return get_numelm(L) == 0;
}

list_t * new_list(){
	list_t * L = calloc(1,sizeof(list_t));
	assert(L);
	return L;
}

void cons(list_t * L, int v){
	/* calloc fonction de manière identique à malloc
	   qui plus est met à NULL(0) tous les octets alloués */
	assert(L);
	#ifdef _DEBUG_
		printf("cons :: on est au tout début de cons\n");
	#endif
 	list_elm_t * E = new_list_elm(v);
	#ifdef _DEBUG_
		printf("cons :: le nouvel élément a été créé\n");
	#endif
 	set_suc(E, get_head(L));
 	set_head(L, E);
 	if(empty_list(L)) set_tail(L, E);
 	plus_one(L);
}

void queue(list_t * L, int v){
	assert(L);
	list_elm_t * E = new_list_elm(v);
	if(empty_list(L)){
		set_head(L,E);
	} else {
		set_suc(get_tail(L),E);
	}
	set_tail(L,E);
	plus_one(L);
}

void del_list(list_t ** ptrL){
	assert(ptrL && *ptrL);
	for(list_elm_t * E = get_head(*ptrL); E; ){
		list_elm_t * T = E;
		E = get_suc(E);
		free(T);
	}
	free(*ptrL);
	*ptrL = NULL;
}

list_elm_t * get_head(list_t * L){
	assert(L);
	return L->head;
}

void set_head(list_t * L, list_elm_t * E){
	assert(L);
	L->head = E;
}

list_elm_t * get_tail(list_t * L){
	assert(L);
	return L->tail;
}

void set_tail(list_t * L, list_elm_t * E){
	assert(L);
	L->tail = E;
}

int get_numelm(list_t * L){
	assert(L);
	return L->numelm;
}

void set_numelm(list_t * L, int v){
	assert(L);
	L->numelm = v;
}

void plus_one(list_t * L){
	assert(L);
	L->numelm++;
}

void insert_ordered(list_t * L, int v){
	assert(L);
	if(empty_list(L) || v <= get_x(get_head(L))){
		cons(L, v);
	} else if(v >= get_x(get_tail(L))){
		queue(L, v);
	} else {
		/**
		 * @brief Dans les autres cas de figure,
		 * 	trouver la place après laquelle insérer le nouvel élément
		 */
    list_elm_t * place = get_head(L);
    while(get_suc(place) && get_x(get_suc(place)) < v){
    	place = get_suc(place);
    }
    insert_after(L, v, place);
  }
}

void view_list(list_t * L ) {
	assert(L);
	printf("[ ");
	for(list_elm_t * E = get_head(L); E; E = get_suc(E)){
    	printf("%d ", get_x(E));
	}
	printf("]\n\n");
}


/**********************************
 DÉFINITIONS DES FONCTIONS PRIVÉES
**********************************/

void insert_after(list_t * L, int v, list_elm_t * place){
	assert(L);
 	if(empty_list(L) || !place){
	    cons(L,v);
	}else{
		list_elm_t * E = new_list_elm(v);
		set_suc(E, get_suc(place));
		set_suc(place, E);
		set_numelm(L, get_numelm(L)+1);
	}
}

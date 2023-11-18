#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "friendship.h"
#include "person.h"
#include "list.h"

// #define LG 40

/**
	@note une zone tampon utile aux fichiers binaires
*/
typedef struct {
	char nameA[LG];
	char forenameA[LG];
	char nameB[LG];
	char forenameB[LG];
} buffer_t;

friendship_t * new_friendship(){
	friendship_t * F = calloc(1, sizeof(friendship_t));
	assert(F);
	return F;
}

friendship_t * scan_friendship(list_t * Lpers){
	person_t * P = scan_person();
	person_t * P1 = find(Lpers, P, &cmp_person);
	free_person(P, true);
	assert(P1);

	person_t * P = scan_person();
	person_t * P2 = find(Lpers, P, &cmp_person);
	free_person(P, true);
	assert(P2);

	friendship_t * F = new_friendship();

	F->A = P1;
	F->B =  P2;

	Cons(P1->friends, P2);
	Cons(P2->friends, P1);

	return F;
}

void free_friendship(friendship_t ** ptrFriend, bool del_persons){
	assert(ptrFriend && *ptrFriend);

	person_t * P1 = find((*ptrFriend)->A->friends, (*ptrFriend)->B, &cmp_person);
	assert(P1);

	if ( P1 ){
		/**
			@todo
		*/
	}
}

int cmp_friendship(friendship_t *F1, friendship_t *F2) {
    assert(F1 && F2);

    if ( (cmp_person(F1->A, F2->A) == 0) && (cmp_person(F1->B, F2->B) == 0) ) {
        return 0;
    }

    if ( (cmp_person(F1->A, F2->B) == 0) && (cmp_person(F1->B, F2->A) == 0) ) {
        return 0;
    }

    return 1;
}


void print_friendship(friendship_t * F){
	printf("___________Friendship___________\n");
	print_person(F->A);
	printf("\n");
	print_person(F->B);
	printf("\t\t\t\tS'AIMENT D'AMOUR\n");
	printf("________Friendship ended________\n");
}

friendship_t * friendship_from_stream(FILE * stream, stream_mode_t mode, list_t * Lpers){
	/**
	@todo
	*/
}
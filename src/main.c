#include <stdio.h>
#include <ctype.h>

#include "list.h"
#include "person.h"
#include "friendship.h"
#include "io.h"


int main(int argc, char *argv[]){
	person_t * P1 = new_person();
	person_t * P2 = new_person();

	*P1->name = "FAGIOLI";
	*P2->name = "FAGIOLI";

	*P1->forename = "Lucas";
	*P2->forename = "Lucas";

	P1->birth_date.day = 8;
	P2->birth_date.day = 8;

	P1->birth_date.month = 4;
	P2->birth_date.month = 4;

	P1->birth_date.year = 2004;
	P2->birth_date.year = 2005;

	if (cmp_person(P1, P2) == 0){
		printf("Même personnes.\n");
	}
	else{
		printf("Personnes différentes.\n");
	}

	friendship_t * F1 = new_friendship();
	friendship_t * F2 = new_friendship();

	F1->A = P2;
	F1->B = P1;

	F2->A = P1;
	F2->B = P2;

	if ( cmp_friendship(F1, F2) == 0 ){
		printf("Même amitié.\n");
	}
	else{
		printf("Amitié différente.\n");
	}

	return 0;
}




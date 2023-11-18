#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "person.h"
#include "friendship.h"
#include "io.h"

person_t * new_person(){
	person_t * P = calloc(1, sizeof(person_t));
	assert(P);
	return P;
}

person_t * scan_person(){
	person_t * P = new_person();
	assert(P);

	printf("Entrez le nom de la personne : ");
	scanf("%s", P->name);

	printf("Entrez le prénom de la personne : ");
	scanf("%s", P->forename);

	printf("Entrez la date de la personne (jj mm aaaa) : ");
	scanf("%d %d %d", &P->birth_date.day, &P->birth_date.month, &P->birth_date.year);

	return P;
}

void free_person(person_t ** ptrP, bool del_friends){
	assert(ptrP && *ptrP);

	free(*ptrP);
	*ptrP = NULL;
}

int cmp_person (person_t * P1, person_t * P2 ){
    assert(P1 && P2);

    if (strcmp(P1->name, P2->name) != 0) {
        return 1;
    }

    if (strcmp(P1->forename, P2->forename) != 0) {
        return 1;
    }

    if (memcmp(&P1->birth_date, &P2->birth_date, sizeof(P1->birth_date)) != 0) {
        return 1;
    }

    return 0;
}


void print_person(person_t * P){
	assert(P);

	printf("___________Person___________\n");
	printf("Nom : %s\n", P->name);
	printf("Prénom : %s\n", P->forename);
	printf("Date de naissance : %d %d %d\n", P->birth_date.day, P->birth_date.month, P->birth_date.year);
	printf("________Person ended________\n");
}

person_t * person_from_stream(FILE * stream, stream_mode_t mode){
	/**
	@todo
	*/
}

// void fprint_person ( person_t * P, FILE * fd, stream_mode_t mode ) {
// }
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "list.h"

int main(){
	char choix;
	do{
		printf("Quel type d'ajout ?\n\tEn tête (T)\n\tEn queue (Q)\n\tDans l'ordre croissant (O)\n");
		scanf(" %s",&choix);
		choix = toupper(choix);
	} while(choix!='T'&&choix!='Q'&&choix!='O');

	int v;
	list_t * L = new_list();
	
	printf("on va demander un entier\n");
	scanf( "%d", &v );
	while( v > 0 ) {
			if(choix=='T')
	    	cons(L,v);
			else if(choix=='Q')
				queue(L,v);
			else
				insert_ordered(L,v);
	    printf("on va demander un entier\n");
    	scanf("%d",&v);
	}
	printf("on va visualiser la liste\n");
	view_list(L);
	del_list(&L);
	return EXIT_SUCCESS;
}

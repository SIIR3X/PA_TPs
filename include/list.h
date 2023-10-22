#pragma once

#include <stdbool.h>
#include "elmlist.h"

/**************
TYPES ABSTRAITS
**************/
/** @brief Le type d'un élément de liste :
 * + `head` un *pointeur* sur le premier élément de la liste
 * + `tail` un *pointeur* sur le dernier élément de la liste
 * + `numelm` le nombre d'éléments rangés dans la liste
 */
typedef struct {
  elmlist_t * head;
  elmlist_t * tail;
  int numelm;
} list_t;

/***********************************
DÉCLARATIONS DES FONCTIONS PUBLIQUES
***********************************/

/** @brief Créer une liste vide */
list_t * new_list();

/** @brief Supprimer une liste signifie :
 * (a) Soit `ptrF == NULL` et l'on veut supprimer **uniquement** la structure de liste
 * (b) Soit `ptrF != NULL` et l'on veut supprimer la structure de liste _et_ les éléments qu'elle contient
 * Les listes étant **génériques** et **homogènes**,
 * on utilise alors le  _pointeur de fonction_ `ptrF` pour indiquer à `rmList`
 * la fonction de suppression qui correspond aux données stockées dans la liste:
 * + `rmInteger`
 * + `rmDouble`
 */
void del_list ( list_t ** ptrL, void (*ptrF)());

/** @brief Vérifie si la liste est vide ou pas */
bool empty_list( list_t * L );

/** @brief Ajoute en tête de la liste un nouvel élément dont la donnée est `d` */
void cons( list_t * L, void * d);

/** @brief Ajoute en queue de la liste un nouvel élément dont la donnée est `d` */
void queue( list_t * L, void * d);

/** @brief Consulte/Modifie la tête de la liste */
elmlist_t * get_head( list_t * L);
void set_head( list_t * L, elmlist_t * E);

/** @brief Consulte/Modifie la queue de la liste */
elmlist_t * get_tail( list_t * L);
void set_head( list_t * L, elmlist_t * E);

/** @brief Consulte/Incrémente/Décrémente le nombre d'éléments rangés dans la liste */
int get_numelm( list_t * L);
void incrnumelm( list_t * L);
void decrnumelm( list_t * L);

/** @brief Visualiser les éléments de la liste L.
 * Les listes étant **génériques** et **homogènes**,
 * on utilise alors un  pointeur de fonction:
 * + `ptrPrintI`
 * + `ptrPrintD`
 * qui permet de transmettre à `viewList`
 * la fonction d'affichage qui correspond aux données stockées dans la liste :
 * + `printInteger`
 * + `printDouble`
 */
void view_list ( list_t * L, void (*ptrF)() );

/** @brief Insertion suivant l'ordre croissant indiqué par le _pointeur de fonction_  `ptrF`
 * pointant sur la fonction de comparaison qui correspond aux données stockées dans la liste :
 * + `intcmp`
 * + `reelcmp`
 */
void insert_ordered ( list_t * L, void * d, int(*ptrF_cmp)());
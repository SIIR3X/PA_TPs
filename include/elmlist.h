#pragma once

/**************
TYPES ABSTRAITS
**************/

/** @brief Le type d'un élément de liste :
 * + `x` un *pointeur* sur une donnée,
 * + `suc` un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
typedef struct elmlist {
  void * datum;
  struct elmlist * suc;
} elmlist_t;

/***********************************
DÉCLARATIONS DES FONCTIONS PUBLIQUES
***********************************/

/** @brief Créer un nouvel élément de liste */
elmlist_t * new_elmlist(void * d);

/** @brief Supprimer un élément de liste et possiblement sa donnée */
void del_elmlist( elmlist_t ** ptrE, void(*ptrF_del)());

/** @brief Récupérer la *donnée* d'un élément de liste */
void * get_data( elmlist_t * E);

/** @brief Récupérer le *successeur* d'un élément de liste */
elmlist_t * get_suc( elmlist_t * E);

/** @brief Modifier la *donnée* d'un élément de liste */
void set_data( elmlist_t * E, void * d);

/** @brief Modifier le *successeur* d'un élément de liste */
void set_suc( elmlist_t * E, elmlist_t * S);

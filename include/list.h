#pragma once

#include <stdbool.h>

#include "list_elm.h"

/** @brief TA d'une liste d'entiers:
  * + une tête de liste
  * + une queue de liste
  * + le nombre d'éléments
  */
typedef struct {
	list_elm_t * head;
	list_elm_t * tail;
	int numelm;
} list_t;
	
/**
 * @brief L est-elle vide
 * 
 * @param L  :: la liste
 * @return true 
 * @return false 
 */
bool empty_list(list_t * L );

/**
 * @brief Créer une nouvelle liste vide
 * 
 * @return list_t* 
 */
list_t * new_list();

/**
 * @brief Ajouter en tête de liste une nouvelle valeur entière
 * 
 * @param L :: la liste
 * @param v :: la valeur entière
 */
void cons(list_t * L, int v);

/**
 * @brief Insérer en queue de liste une nouvelle valeur entière
 * 
 * @param L :: la liste
 * @param v :: la valeur entière
 */
void queue(list_t * L, int v);

/**
 * @brief Libérer la mémoire occupée par la liste
 * @remarks 
 *  - Le pointeur en argument lors de l'appel à cette fonction est mis à NULL par effet de bord
 *  - Toute la mémoire est libérée : la liste et les éléments de liste
 * 
 * @param ptrL :: l'adresse de l'adresse de la liste
 */
void del_list(list_t ** ptrL);

/**
 * @brief Get the head object
 * 
 * @param L :: la liste
 * @return list_elm_t* 
 */
list_elm_t * get_head(list_t * L);

/**
 * @brief Set the head object
 * 
 * @param L :: La liste
 * @param E :: La nouvelle tête
 */
void set_head(list_t * L, list_elm_t * E);

/**
 * @brief Get the tail object
 * 
 * @param L :: La liste
 * @return list_elm_t* 
 */
list_elm_t * get_tail(list_t * L);

/**
 * @brief Set the tail object
 * 
 * @param L :: La liste
 * @param E :: La nouvelle queue de liste
 */
void set_tail(list_t * L, list_elm_t * E);

/**
 * @brief Get the numelm object
 * 
 * @param L :: La liste
 * @return int 
 */
int get_numelm(list_t * L);

/**
 * @brief Set the numelm object
 * 
 * @param L :: La liste
 * @param v :: La nouvelle valeur
 */
void set_numelm(list_t * L, int v);

/**
 * @brief Incrémenter de 1 numelm
 * 
 * @param L :: La liste
 */
void plus_one(list_t * L);

/**
 * @brief Insèrer l'entier v dans la liste L suivant l'ordre croissant
 * 
 * @param L :: La liste
 * @param v :: La valeur à insérer
 */
void insert_ordered(list_t * L, int v);

/**
 * @brief Visualiser les valeurs entières de la liste
 * 
 * @param L :: La liste
 */
void view_list(list_t * L);

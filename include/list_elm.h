#pragma once

/** @brief Le TA d'un élément de liste :
* 	x :: un entier,
* suc :: un pointeur sur son successeur (ou NULL s'il n'y en a pas)
*/
typedef struct list_elm {
	int x;
	struct list_elm * suc;
} list_elm_t ;

/**
 * @brief Constructeur d'élément de liste d'entiers
 * 
 * @param v :: la valeur entière à ranger dans le nouvel élément
 * @return list_elm_t* :: l'adresse (qui ne peut être NULL) de l'élément créé
 */
list_elm_t * new_list_elm(int v);

/**
 * @brief Destructeur d'un élément de liste.
 * @remark Le pointeur passé en argument lors de l'appel à cette fonction est mis à NULL par effet de bord.
 *
 * @param ptrE :: l'adresse de l'adresse de l'élément de liste d'entiers à supprimer
 */
void del_list_elm(list_elm_t ** ptrE);

/**
 * @brief Get the x object
 * 
 * @param E :: l'élément de liste concerné
 * @return int 
 */
int get_x(list_elm_t * E);

/**
 * @brief Set the x object
 * 
 * @param E :: l'élément de liste concerné
 * @param v :: la nouvelle valeur entière
 */
void set_x(list_elm_t * E, int v);

/**
 * @brief Get the suc object
 * 
 * @param E :: l'élément de liste concerné
 * @return list_elm_t* 
 */
list_elm_t * get_suc(list_elm_t * E);

/**
 * @brief Set the suc object
 * 
 * @param E :: l'élément de lsite concerné
 * @param S :: la valeur du nouveau successeur
 */
void set_suc(list_elm_t * E, list_elm_t * S);
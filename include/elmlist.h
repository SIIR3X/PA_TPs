#pragma once

/**
Abstract type modeling a list element containing
- a form
- 2 pointers to its predecessor  and successor
*/
typedef struct  list_elm {
  void * datum;
  struct  list_elm * suc;
  struct  list_elm * pred; // Get Back To The ...
} list_elm_t;

/** Create a new list element around datum */
list_elm_t * new_list_elm(void * datum);

/* Delete list element and its data */
void del_list_elm(list_elm_t ** ptrE, void (*ptrf) ());

/** Who's next ? */
list_elm_t * get_suc(list_elm_t * E);

/** Who's before ? */
list_elm_t * get_pred(list_elm_t * E);

/** What is the data ? */
void * get_data(list_elm_t * E);

/** Set list element's successor to S */
void set_suc(list_elm_t * E, list_elm_t * S);

/** Set list element's predecessor to S */
void set_pred(list_elm_t * E, list_elm_t * P);

/** Set list element's datum to datum */
void set_data(list_elm_t * E, void * datum);
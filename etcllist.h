#ifndef __ETCLLIST_H
#define __ETCLLIST_H
/**
 * << ETCLinkedList >>
 * An ADT to work with Singly linked lists
 * 
 * Functions prefix: etcllist_
 * 
 * @author MVellosa
 * @date 12/2021
 * @version 1.0
*/

#include "stddef.h"

/* opaque type for the linked list */
typedef struct __linkedlist * ETCLinkedList; 

/**
 * Constructor for the linked list
 * It has to be called before any operation can be made with the linked list
 * 
 * @return initialized linked list
*/
ETCLinkedList etcllist_create();


/**
 * getter for the linked list size
 * @param llist linked list in which the operation will take place
 * @return linked list size
*/
size_t etcllist_size(ETCLinkedList llist);

/**
 * insert an element to the linked list at <index>
 * 
 * @param llist linked list in which the operation will take place
 * @param element element being added to the list
 * @param index position of the list in which the element will be
*/
void etcllist_insert(ETCLinkedList llist, void *element, size_t index);
/**
 * insert an element at the front of the linked list 
 * 
 * @param llist linked list in which the operation will take place
 * @param element element being added to the list
*/
void etcllist_insertfront(ETCLinkedList llist, void *element);
/**
 * insert an element at the end of the linked list 
 * 
 * @param llist linked list in which the operation will take place
 * @param element element being added to the list
*/
void etcllist_insertback(ETCLinkedList llist, void *element);

/**
 * get an element from the linked list
 * @param llist linked list in which the operation will take place
 * @param index index of the element to be retrieved
 * @return element in the specified position or NULL if the position is not valid
*/
void *etcllist_get(ETCLinkedList llist, size_t index);

/**
 * remove an element from the linked list
 * @param llist linked list in which the operation will take place
 * @param index index of the element to be removed
 * @return removed element in the specified position or NULL if the position is not valid
*/
void *etcllist_removeat(ETCLinkedList llist, size_t index);

/**
 * Destructor for the linked list
 * Frees the allocated memory
 * @param llist linked list in which the operation will take place
*/
void etcllist_destroy(ETCLinkedList llist);

#endif


#include <malloc.h>

#include "etcllist.h"

struct __node {
    void *data;
    struct __node *next;
};

struct __linkedlist{
    struct __node *first;
    struct __node *last;
    size_t count;
};

/* internal function to create a node */
static struct __node *initnode(void *data){
    struct __node *newNode = malloc(sizeof(*newNode));
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

struct __linkedlist *etcllist_create(){
    struct __linkedlist *newllist = malloc(sizeof(*newllist));
    
    newllist->first = NULL;
    newllist->last = NULL;
    newllist->count = 0;

    return newllist;
}

size_t etcllist_size(struct __linkedlist *llist){
    return llist->count;
}

void etcllist_insert(struct __linkedlist *llist, void *element, size_t index){
    if (index < 0 || index > llist->count){
        return;
    }

    struct __node *newNode = initnode(element);
    llist->count++;

    if (index == 0){
        newNode->next = llist->first;
        llist->first = newNode;

        if (llist->last == NULL){
            llist->last = newNode;
        }
        return;
    }

    struct __node *traveler = llist->first;

    while(index-- > 1){
        traveler = traveler->next;
    }
    newNode->next = traveler->next;
    traveler->next = newNode;

}

void etcllist_insertfront(struct __linkedlist *llist, void *element){
    struct __node *newNode = initnode(element);
    
    llist->count++;

    newNode->next = llist->first;
    llist->first = newNode;

    if (llist->last == NULL){
        llist->last = newNode;
    }
}

void etcllist_insertback(struct __linkedlist *llist, void *element){
    struct __node *newNode = initnode(element);
    
    llist->count++;

    if (llist->last == NULL){
        llist->first = newNode;
        llist->last = newNode;
        return;
    }

    llist->last->next = newNode;
    llist->last = newNode;

}


void *etcllist_get(struct __linkedlist *llist, size_t index){
    if (index < 0 || index > llist->count){
        return NULL;
    }

    struct __node *traveler = llist->first;

    while(index-- > 0){
        traveler = traveler->next;
    }
    return traveler->data;
}


void *etcllist_removeat(struct __linkedlist *llist, size_t index){
    void *deletedNodeData = NULL;

    if (index < 0 || index > llist->count){
        return deletedNodeData; /* NULL */
    }
    
    llist->count--;

    struct __node *traveler = llist->first;

    struct __node *nodeToDelete;

    if (index == 0){
        nodeToDelete = llist->first;
        deletedNodeData = nodeToDelete->data;

        if (llist->last == llist->first){
            llist->first = NULL;
            llist->last = NULL;

        } else{
            llist->first = llist->first->next;
        }

    } else{
        while(index-- > 1){
            traveler = traveler->next;
        }
        
        nodeToDelete = traveler->next;
        traveler->next = traveler->next->next;
    }

    free(nodeToDelete);
    return deletedNodeData;

}

void etcllist_destroy(struct __linkedlist *llist){
    while(llist->first != NULL){
        struct __node *aux = llist->first;
        llist->first = llist->first->next;
        free(aux);
    }
    free(llist);
}
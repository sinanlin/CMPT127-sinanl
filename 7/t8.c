#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>



void list_add_node(list_t *list, element_t *newNode){
    if (newNode != NULL) {
        newNode->next = NULL;
        if (list->tail ==NULL) {
            assert(list->head == NULL);
            list->head = newNode;
            list->tail = newNode;
        }
        else{
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }
    
}



void list_catenate(list_t *l1, list_t *l2){
    if (l2->head == NULL) {
        assert(l2->tail == NULL);
    }
    else if(l1->head == NULL){
        assert(l1->tail == NULL );
        *l1=*l2;
    }
    else{
        l1->tail->next= l2->head;
        l1->tail= l2->tail;
    }
    free(l2);
}


void list_sort( list_t* list ){
    
    if (list->head == list->tail) {
        return;
    }
    
    // remove the head from intlist (pivot)
    int pivot = list->head->val;
    element_t *pivot_element = list->head;
    list->head = list->head->next;
    
    
    list_t *first = list_create();
    list_t *second = list_create();
    
    element_t *curr = list->head;
    element_t *next;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            list_add_node(first, curr);
        }
        else{
            list_add_node(second, curr);
        }
        curr = next;
    }
    
    list->head = NULL;
    list->tail = NULL;
    
    list_sort(first);
    list_sort(second);
    
    list_catenate(list, first);
    list_add_node(list, pivot_element);
    list_catenate(list, second);
}














/* Insertion Sort. 
 
void LLinsertElement(list_t* list,element_t * element){
    //list empty
    if (list->head == NULL) {
        assert(list->tail == NULL);
        list->head = element;
        list->tail = element;
        element->next = NULL;
    }
    else if(list->head->val >= element->val ){
        //new head
        element->next = list->head;
        list->head = element;
    }
    else{
        element_t *prev = list->head;
        element_t *curr = list->head->next;
        while (curr != NULL && curr->val < element->val) {
            curr = curr->next;
            prev = prev->next;
        }
        element->next = curr;
        prev->next = element;
        
        if (curr == NULL) {
            list->tail = element;
        }
        
    }
}

void list_sort( list_t* list ){
    // create a new [empty] list
    list_t* newlist = list_create();
    
    element_t *curr = list->head;
    
    // scan through all items and insert 'em

    while (curr != NULL) {
        element_t * next = curr->next;
        LLinsertElement(newlist,curr);
        curr=next;
    }
    
    // recycle old list
    // swap
    list_t tmp;
    tmp = *list;
    *list = *newlist;
    *newlist = tmp;
    list_destroy(newlist);
}
*/
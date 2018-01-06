#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#include "list.h"

//Task 1.
int test_element_create(void){
    int value = 1024; //Some random value.
    
    //The ideas is to allocate a memoery space. Free it. Then set it again. Then check.
    element_t* el= (element_t*)malloc(sizeof(element_t));
    assert(el);
    memset( el, 0xFF, sizeof( element_t ) );
    free(el);
    
    el = element_create(value);
    assert(el);
    
    if (el->next) {
        puts("element_create is BUG for not setting tail\n");
        return 1;
    }
    
    if (el->val != value) {
        puts("element_create is BUG for not setting right value\n");
        return 1;
    }
    return 0;
}

int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  //1.Testing list_create;
  //1.1 head and tail is NULL and list is non-null.
    if (list) {
        //
    }
    else{
        puts("list is NULL");
        return 1;
    }
    
    if (list && list->head == NULL && list->tail == NULL) {
        //puts("list_create is GOOD\n");
        //return 0;
    }
    else{
        //Containing Bug
        puts("list_create contating Bug\n");
        return 1;
    }

    
    for( int i=-1; i>-5; i-- ){
        list_prepend( list, i );
      /*
        //3.Testing list_prepend;
        //All the list_prepend test if el is NULL
        //3.1)Corner case: if empty list, does list_prepend set both head and tail == to i and the tail->next == NULL?
        if (list->head->val == i && list->tail->val == i ) {
            if (list->tail->next == NULL) {
                //puts("list_prepend is GOOD with prepending in the empty list case \n");
                //    return 0;
            }
            else{
                puts("list_prepend is BUG with prepending in the empty list case \n");
                return 1;
            }
        }
        
        //When appending to the front.
        //3.2)Check if the head is properly set
        //3.3)Check if the next is NON-NUll value.
        else if(list->head->val == i){
            if (list->head->next && list->tail->next == NULL) {
                //puts("list_prepend is GOOD with prepending to the list\n");
                //   return 0;
            }
            else{
                puts("list_prepend is BUG with prepending to the list in seting headt->next \n");
                return 1;
            }
        }
        //3.4 Wrong pre-append
        else{
            puts("list_prepend is BUG with prepending to the list \n");
            return 1;
        }
       */
    }

    if (list->tail == NULL) {
        puts("list_prepend is BUG ");
        return 1;
    }

    

    for( int i=0; i<5; i++ ){
        list_append( list, i );
        //2.Testing list_append;
        //2.1)Corner case. head and tail both null. Check if setting both to new element
        
        if (list->head->val == i) {
            if(list->tail->val == i && list->tail->next == NULL){
                //puts("list_append is GOOD in the empty list situation.\n");
                //   return 0;
            }
            else{
                puts("list_append is BUG in the empty list situation.\n");
                return 1;
            }
        }
        
        //2.2)appending to the end of the list. 1. Check if the end value equal to i. 2.2)Check the tail if NULL.
        else if (list->tail->val == i) {
            if (list->tail->next == NULL) {
                //puts("list_append is GOOD with appending to the end\n");
                //    return 0;
            }
            else{
                puts("list_append is BUG with setting tail\n");
                return 1;
            }
            
        }
        
        //2.3)Wrong append
        else{
            puts("list_append is BUG with appending to the list\n");
            return 1;
        }
    }

    
    
    
    list_t* test= (list_t*)malloc(sizeof(list_t ));
    test->tail = (element_t*)malloc(2);
    free(test->tail);
    free(test);
    test = list_create();
    
    if (test->tail) {
        puts("list_create is BUG");
        return 1;
    }
    
    
    //5. Make the head NULL and test if the indext still go through.

    
    //Make a false case and test if the list_index return NULL
   

  int index = 2;
  element_t* el = list_index( list, index );
    
    /*
    if (list_index( list, index ) != NULL) {
        puts("list_index doesn't test the list->head NULL case ");
        return 1;
    }
    
    */
    
    
    //5.Testing for list_index.
    //Find out what the return value shoud be.
    int value;
    element_t *cur = list->head;

    
    for (int i=0; i<=index; i++) {
        value= cur->val;
        cur=cur->next;
    }

    
    //5.1 The index is smaller than 0 or bigger the then array len.
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
    //5.2 Now that we can assum index is within the array. We should
    //check if the funciting returning the right value.
    
   if( el->val == value ){
      //puts("index value founded \n");
  }
    //The function is returing the wrong value.
   else {
      puts("list_index is BUG for giving wrong value. \n");
      return 1;
  }
    //5.3  When the head is NULL, t3 will casue a seg fault.
    
    list_destroy(list);
    list = list_create();
    element_t * result = list_index( list, index );
    
    if (result != NULL) {
        puts("list_index is BUG");
        return 1;
    }
    

    
    
    
    //6.Testing for list_print. Make sure it prints out all the value.
    list_print( list );
    
    
    
     //7.Testing for list_destroy.
    // The memory address of el before freeing the memory.
    
  list_destroy( list );

    
    
    //8. Testing element_create.
    if(test_element_create() == 1){
        puts("element_create is BUG\n");
        return 1;
    }


  return 0; // tests pass
}

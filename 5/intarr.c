#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include "intarr.h"

#include <assert.h>

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
    
    intarr_t *p= malloc(sizeof(intarr_t));
    
    if (p) {
        p->len=len;
        p->data=malloc(sizeof(int)*len);
    }
    else{
        return NULL;
    }
    
    return p;
    
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
    
    if (ia) {
        free(ia->data);
        free(ia);
    }
    else{
        return;
    }
}


/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia,
                           unsigned int index,
                           int val ){
    
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    if ( index < ia->len) {
        ia->data[index]=val;
        return INTARR_OK;
    }
    else{
        return INTARR_BADINDEX;
    }
    
}



// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
                           unsigned int index,
                           int* i ){
    
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    if (index < ia->len && i!=NULL) {
        *i= ia->data[index];
        return INTARR_OK;
    }
    else{
        return INTARR_BADINDEX;
    }
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ){
    
    
    intarr_t *duplicate = malloc(sizeof(intarr_t));
    
    if (ia==NULL) {
        return NULL;
    }
    if (duplicate) {
        duplicate->data=malloc(sizeof(int)*(ia->len));
        memcpy(duplicate->data, ia->data, ia->len*(sizeof(int)));
        duplicate->len=ia->len;
    }
    else{
        return NULL;
    }

    return duplicate;
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
    //If ia is null, return
    // INTARR_BADARRAY.
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    
    int *A=ia->data;
    
    
    unsigned int ALen=ia->len;
    
    int p;
    int i;
    int tmp;
    
    
    for (p=1; p<ALen; p++) {
        tmp=A[p];
        for (i=p; i>0 && A[i-1] > tmp; i--) {
            A[i]=A[i-1];
        }
        A[i]=tmp;
    }
    return INTARR_OK;
}


/* LAB 5 TASK 5 */

//If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
    //If ia is
    // null, return INTARR_BADARRAY.
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    
    //// Find the first occurance of the target in the array, searching from
    // index 0. If the target is found and i is non-null, set *i to the
    // location index and return INTARR_OK.
    
    int j;
    
    for (j=0; j< ia->len; j++) {
        
        if (ia->data[j]==target) {
            *i=j;
            return INTARR_OK;
        }
        
    }
    
    return INTARR_NOTFOUND;
}


/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.

intarr_result_t intarr_push( intarr_t* ia, int val ){
    //If ia is
    // null, return INTARR_BADARRAY.

    if(ia == NULL)
        return INTARR_BADARRAY;
    else
    {
        unsigned int len = ia->len;
        int newarr[len];
        int i;
        for(i=0;i<len;i++)
            newarr[i] = ia->data[i];
        intarr_destroy(ia);
        ia = intarr_create(len+1);
        if(ia!= NULL || ia->data != NULL)
        {
            for(i = 0; i<len;i++)
                ia->data[i] = newarr[i];
            ia->data[i] = val;
            return INTARR_OK;
        }
        else
            return INTARR_BADARRAY;
    }
    
    
/*    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    
    intarr_t *p = (intarr_t*)malloc(sizeof(int)*(ia->len+1));
    p->len=(ia->len)+1;
    
    if (p) {
        
        //Copy the array into p;
        memcpy(p->data,ia->data,sizeof(int)*(ia->len));
        //Set the last position;
        p->data[ia->len]=val;
        //Destroy ia;
        int len=ia->len;
        intarr_destroy(ia);
        //Create a new ia;
        ia= intarr_create(len+1);
        //Let ia point to the new array.
        ia=p;
        return INTARR_OK;
    }
    else{
        return INTARR_BADALLOC;
    }
 */
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
    //If ia is null, return INTARR_BADARRAY.
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    //If the array is not empty,
    if (ia->data != NULL && ia->len != 0 ) {
        if (i) {
            //if i is non-null, set *i to the removed value,
            // then return INTARR_OK.
            *i= ia->data[ia->len-1];
        }
        ia->len--;
        return INTARR_OK;
    }
    //If the array is empty, leave *i unmodified
    // and return INTARR_BADINDEX.
    else{
        return INTARR_BADINDEX;
    }
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values.   otherwise return INTARR_BADALLOC.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
        int i;
        int* newarr = realloc(ia->data, newlen*sizeof(int));
        if(ia == NULL)
            return INTARR_BADARRAY;
        else
        {
            if(!newarr)
                return INTARR_BADALLOC;
            else
            {
                ia->data = newarr;
                for(i = ia->len; i < newlen; i++)
                    newarr[i] = 0;
            }
            ia->len = newlen;
            return INTARR_OK;
        }
    }
    /*
    {// If ia is null, return
    // INTARR_BADARRAY.
    if (ia==NULL) {
        return INTARR_BADARRAY;
    }
    
    
    if (newlen > ia->len) {
        // If newlen is greater than the original array length, intialize all the new integers to zero.
        //copy the old list;
        intarr_t *copy = intarr_copy( ia );
        //Destroy the old list
        intarr_destroy(ia);
        //Create a new list
        ia= intarr_create(newlen);
        if (ia) {
            //If the allocation is successful, return
            // INTARR_OK,
            //put in the data
            int i;
            for (i=0; i<newlen; i++) {
                if (i < copy->len) {
                    ia->data[i] = copy->data[i];
                }
                else{
                    ia->data[i] = 0;
                }
            }
           return INTARR_OK;
        }
        else{
            return INTARR_BADALLOC;
        }
    }
    
    else {
        //If newlen is less than the
        // original array length, the end of the array is discarded.
        int lendifference = ia->len - newlen;
        int i;
        for (i=0; i<newlen; i++) {
            ia->len--;
        }
        return INTARR_OK;
    }
    
}
*/

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia,
                               unsigned int first,
                               unsigned int last ){
    if(ia == NULL || last<first || last >= ia->len )
    {
    return NULL;
    }
    
    int newlen = last - first+1;
    intarr_t* newarr = (intarr_t*)malloc(sizeof(intarr_t));


    if (newarr) {
        newarr->len=newlen;
        newarr->data = malloc(newarr->len * sizeof(int));
        int i,j;
        for (i=first,j=0; i<=last; i++,j++) {
            newarr->data[j]=ia->data[i];
        }
        return newarr;
    }
    else{
        return NULL;
    }
}

















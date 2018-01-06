#include <stdlib.h>
#include "point_array.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

//Task 1.

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
    assert(pa);
    
    pa->len=0;
    pa->points=NULL;
    pa->reserved=0;
    
}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
    assert(pa);
    
    if (pa->points) {
        memset(pa->points,0,sizeof(point_t)*(pa->len));
    }
    pa->points=NULL;
    
}


// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
    assert(pa);
    assert(p);
    
    if (pa->len==pa->reserved) {
        size_t newlen=(pa->len * 2) + 1;
        pa->points=realloc(pa->points,sizeof(point_t)*(newlen));
        pa->reserved=newlen;
    }
    //setting the pointer to the last.
    pa->points[pa->len]=*p;
    //Now the len is not long enough
    pa->len++;
    
    return 0;
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
    assert(pa);
    
    //Bounds check;
    if (i>=pa->len) {
        return 1;
    }
    
    //
    if (i< pa->len-1) {
        
        pa->points[i]=pa->points[pa->len-1];
    }
    
    pa->len--;
    
    return 0;
}
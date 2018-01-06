
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
    memset( array, 0, cols * rows * sizeof(uint8_t) );
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
    uint8_t *ret=malloc(cols*rows*sizeof(uint8_t));
    if (ret==0) {
        perror("Failed to allocate memory\n");
        return NULL;
    }
    
    memcpy(ret, array, cols * rows * sizeof(uint8_t));
    free(ret);
    return ret;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
    // your code here
    int i=0;
    int min=array[0];
    int len=cols*rows;
    
    for (i=0; i<len; i++) {
        if (array[i]<min) {
            min=array[i];
        }
    }
    
    return min;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
    // your code here
    int i=0;
    int max=array[0];
    int len=cols*rows;
    
    for (i=0; i<len; i++) {
        if (array[i]>max) {
            max=array[i];
        }
    }
    return max;
    return 0;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[],
                   unsigned int cols,
                   unsigned int rows,
                   uint8_t pre_color,
                   uint8_t post_color )
{
    // your code here
    int i=0;
    int len=cols*rows;
    
    for (i=0; i<len; i++) {
        if (array[i]==pre_color) {
            array[i]=post_color;
        }
    }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[],
                     unsigned int cols,
                     unsigned int rows )
{
    // your code here
    
    int x,y;
    uint8_t temp;

    for(x = 0; x < rows; x++)
    {
        for(y = 0; y < cols/2; y++)
        {
            //swap the first and the last of every row.
            temp = array[y + x*cols] ;
            array[y + x*cols] = array[(cols-y-1) + x*cols];
            array[(cols-y-1) + x*cols] = temp;
        }
    }
    
}


// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    // your code here
    int y,x;
    
    uint8_t temp;
    
    
    for(x = 0; x < rows/2; x++)
    {
        for(y = 0; y < cols; y++)
        {
            //Swap the top and the bottom
            int temp = array[y + x*cols];
            array[y + x*cols] = array[y + (rows - 1 -x) *cols];
            array[y + (rows - 1 -x) *cols] = temp;
            
        }
    }
}


/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
    int j;
    int i;

    for (i=0; i<rows; i++) {

        for(j=0;j<cols;j++){
            
            if (array[j + i*cols]==color) {
                //x is col
                *x=j;
                //y is row
                *y=i;
                return 1;
            }
        }
    }
    
    return 0;
    
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
    int i,j;
    
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            array[j+i*cols]=255-array[j+i*cols];
        }
    }
    
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
    // your code here
    int y;
    int x;
    
    for(x = 0; x < cols; x++)
    {
        for(y = 0; y < rows; y++)
        {
            int brightness = round(scale_factor * (double)(array[x + y*cols]));
            //if it is bigger than 255, set it into 255.
            if(brightness >= 255)
                array[x + y*cols] = 255;
            
            else
                array[x + y*cols] = (uint8_t)brightness;
        }
    }
    
    
}
/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
               unsigned int cols,
               unsigned int rows )
{
//your code here
    //move the entire array to base 0.
    int x=0,y=0;
    int S= min(array, x, y);
    int L= max(array,x,y);

    for (x=0; x<cols; x++) {
        for (y=0; y<rows; y++) {
            array[x + y*cols] -= S;
        }
    }
    

    //shift and scale
    scale_brightness(array, x, y, 255 / (L-S));
}


/*
 {
    // your code here
    int y =0;
    int x = 0;
    int small  = min(array, x ,y);
    
    int large= max(array, x ,y);
    
    for(x = 0; x < cols; x++)
    {
        for(y = 0; y < rows; y++)
        {
            if (small<0) {
                array[x + y*cols] -= small;
            }
        }
    }
    
    scale_brightness( array, x ,y, 255/(large-small));
}
 */


/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
              unsigned int cols,
              unsigned int rows )
{
    // your code here
		  
    int i,j;
    int x = rows/2;
    int y = cols/2;
    int val;
    uint8_t* half_array = malloc(x*y*sizeof(uint8_t));
    assert(half_array);
    for (i=0; i<x; i++)
    {
        for (j=0; j<y; j++)
        {
            val = array[(i*2)*cols+(j*2)];
            val += array[(i*2)*cols+(j*2+1)];
            val += array[(i*2+1)*cols+(j*2)];
            val += array[(i*2+1)*cols+(j*2+1)];
            half_array[i*y+j] = round(val/4.0);
        }
    }
    return half_array;

}
/*{
    // your code here
    
    int x,y;
    int number=(cols/2)*(rows/2);
    int *p=(int*)malloc(number*sizeof(int));
    int i=0;
    
    for (y=0; y<rows/2; y++) {
        for (x=0; x<cols/2;x++,i++) {
            p[i]=(array[2*x+2*y*cols]+array[2*x+1+2*y*cols]+array[2*x+1+2*y*cols+cols]+array[2*x+2*y*cols+cols])/4.0;
        }
    }
    
    
    free(p);
    return NULL;
}
 */




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[],
                unsigned int cols,
                unsigned int rows,
                unsigned int left,
                unsigned int top,
                unsigned int right,
                unsigned int bottom,
                uint8_t color )
{
    // your code here
    int y,x;
    if(top != bottom|| left != right )
    {
        for(y = top; y < bottom; y++)
        {
            for(x = left; x < right; x++)
                array[x + y*cols] = color;
            
        }
    }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[],
                                   unsigned int cols,
                                   unsigned int rows,
                                   unsigned int left,
                                   unsigned int top,
                                   unsigned int right,
                                   unsigned int bottom )
{
    // your code here
    assert(left != right || top != bottom);
    int x,y;
    unsigned long sum=0;
    
    for (y=top; y<bottom; y++) {
        for (x=left; x<right; x++) {
            sum=sum+array[x+cols*y];
        }
    }
    return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[],
                     unsigned int cols,
                     unsigned int rows,
                     unsigned int left,
                     unsigned int top,
                     unsigned int right,
                     unsigned int bottom )
{
    int i,j;
    int p = bottom-top;
    int q = right-left;
    if (p*q == 0)
        return NULL;
    uint8_t* cpy = malloc(p*q*sizeof(uint8_t));
    if (!cpy)
        return NULL;
    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            cpy[i*q+j] = array[(i+top)*cols+(j+left)];
        }
    }
	return cpy;
}




/*
{
    // your code here
    assert(left != right || top != bottom);
    
    
    int numbers=(right-left)*(bottom-top);
    uint8_t *p=(uint8_t*)malloc(numbers*sizeof(int));
    int x,y;
    int i=0;
    
    if (!p) {
        return NULL;
    }
    else{
        for (y=top; y<bottom; y++) {
            for (x=left; x<right; x++,i++) {
                p[i]=array[x+cols*y];
            }
        }
        
        free(p);
        return NULL;
    }
}
*/


#include <stdio.h>
#include "intarr.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* LAB 6 TASK 1 */

/*
 Save the entire array ia into a file called 'filename' in a binary
 file format that can be loaded by intarr_load_binary(). Returns
 zero on success, or a non-zero error code on failure. Arrays of
 length 0 should produce an output file containing an empty array.
 */
int intarr_save_binary( intarr_t* ia, const char* filename ){
    //Check if ia is null
    if (!ia) {
        return 1;
    }
    
    //open a file
    FILE *f = fopen(filename, "w" );
    
    if (f == NULL) {
        puts("Failed to open the file for writing.");
        return 1;
    }
    
    unsigned int hdr[1];
    hdr[0]= ia->len;
    
    fwrite(hdr,sizeof(unsigned int),1,f);
    
    if (fwrite(hdr,sizeof(unsigned int),1,f)!= 1) {
        puts("Fail to write in the len");
        return 2;
    }
    
    unsigned int len= ia->len;
    
    fwrite(ia->data,sizeof(int),len,f);
    
    if (fwrite(ia->data,sizeof(int),len,f) != len) {
        puts("Fail to write in array");
        return 3;
    }
    
    fclose(f);
    return 0;
}
/*
 //Check if ia is null
 assert(ia);
 assert(ia->data);
 //open a file
 FILE *f = fopen(filename, "w" );
 
 if (f == NULL) {
 puts("Failed to open the file for writing.");
 return 1;
 }
 //Create a new struct p, write in the data
 
 intarr_t *p= intarr_create(ia->len);
 memcpy(p->data,ia->data,sizeof(int)*(ia->len));
 
 //Check if the data writing is sucessfule.
 if (fwrite(p->data, sizeof(int), ia->len, f ) != ia->len ) {
 puts("Failed to write the array");
 return 2;
 }
 //write in the len
 p->len= ia->len;
 if(fwrite(p->len, sizeof(unsigned int), 1 , f ) != 1){
 puts("Failed to write the len");
 return 3;
 }
 fclose(f);
 return 0;
 }
 */

/*
 Load a new array from the file called 'filename', that was
 previously saved using intarr_save_binary(). Returns a pointer to a
 newly-allocated intarr_t on success, or NULL on failure.
 */
intarr_t* intarr_load_binary( const char* filename ){
    
    //open file
    FILE* f = fopen( filename, "r" );
    if( f == NULL )
    {
        puts( "Failed to open image file for reading" );
        return NULL;
    }
    unsigned int b;
    //read the file for len.
    
    fread(&b, sizeof(unsigned int), 1 , f);
    
    if (fread(&b, sizeof(unsigned int), 1 , f) != 1 ) {
        puts("Failed to read the len");
        return NULL;
    }
    //Create a intarr_t and allocate memory and len.
    intarr_t *p= (intarr_t *) malloc(sizeof(intarr_t));
    p->data=(int*)malloc(sizeof(int)*(b));
    p->len=b;
    //Check.
    assert(p);
    assert(p->data);
    
    fread(p->data , sizeof(int) , b, f );
    
    if (fread(p->data , sizeof(int) , b, f ) != b ) {
        puts("Fail to read the array");
        return NULL;
    }
    
    fclose(f);
    return p;
}








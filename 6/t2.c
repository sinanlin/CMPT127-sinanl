#include <stdio.h>
#include "intarr.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* LAB 6 TASK 2 */

/*
 fscanf(FILE *restrict stream, const char *restrict format, ...);
 fscanf() reads input from the stream pointer stream
 
 fprintf(FILE * restrict stream, const char * restrict format, ...);
 fprintf() and vfprintf() write output
 to the given output stream
 
 int
 snprintf(char * restrict str, size_t size, const char * restrict format,
 ...);
 The snprintf() and vsnprintf() functions will write at most size-1 of the
 characters printed into the output string (the size'th character then
 gets the terminating `\0'); if the return value is greater than or equal
 to the size argument, the string was too short and some of the printed
 characters were discarded.  The output is always null-terminated, unless
 size is 0.

 
 
 Save the entire array ia into a file called 'filename' in a JSON
 text file array file format that can be loaded by
 intarr_load_json(). Returns zero on success, or a non-zero error
 code on failure. Arrays of length 0 should produce an output file
 containing an empty array.
 
 The JSON output should be human-readable.
 
 Examples:
 
 The following line is a valid JSON array:
 [ 100, 200, 300 ]
 
 The following lines are a valid JSON array:
 [
 100,
 200,
 300
 ]
 */
int intarr_save_json( intarr_t* ia, const char* filename ){
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
    
    fprintf(f, "[");
    
    int i;
    unsigned int len= ia->len;
    
    for (i=0; i<len; i++) {
       fprintf(f, " %d",ia->data[i]);
        if (i<len-1) {
            fprintf(f, ",");
        }
    }
    
    fprintf(f, "]\n");
    
    fclose(f);
    return 0;
}

/*
 Load a new array from the file called 'filename', that was
 previously saved using intarr_save(). The file may contain an array
 of length 0. Returns a pointer to a newly-allocated intarr_t on
 success (even if that array has length 0), or NULL on failure.
 */
intarr_t* intarr_load_json( const char* filename ){
    //open file
    FILE* f = fopen( filename, "r" );
    if( f == NULL )
    {
        puts( "Failed to open image file for reading" );
        return NULL;
    }
 
    unsigned int len = 0;
    fseek(f,1,SEEK_SET);
    int arr;
    while(fscanf(f,"%d,",&arr))
        len++;
    intarr_t* ia = intarr_create(len);
    if(!ia)
        return NULL;
    if(len > 0)
    {
        fseek(f,1,SEEK_SET);
        int j;
        for(j = 0; j < len-1; j++)
            fscanf(f,"%d,",&ia->data[j]);
        fscanf(f,"%d",&ia->data[j]);
    }
    fclose(f);
    return ia;
}


















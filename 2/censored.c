#include <stdio.h>
#include <string.h>
#include <string.h>

/*     size_t
 fread(void *restrict ptr, size_t size, size_t nitems,
 FILE *restrict stream);
 
 The function fread() reads nitems objects, each size bytes long, from the
 stream pointed to by stream, storing them at the location given by ptr.
 
 The functions fread() and fwrite() advance the file position indicator
 for the stream by the number of bytes read or written.  They return the
 number of objects read or written.  If an error occurs, or the end-of-
 file is reached, the return value is a short object count (or zero).
 
 The function fread() does not distinguish between end-of-file and error;
 callers must use feof(3) and ferror(3) to determine which occurred.  The
 function fwrite() returns a value less than nitems only if a write error
 has occurred.
 
 int
 fgetc(FILE *stream);

 */



int main(int argc, char* argv[]) {
    
    char arr[128];
    char ch;
    int target=0;;
    unsigned long int i;
    unsigned long int letters=0;
    
    while((ch=getchar())!=EOF) {
        if ((ch<39||ch>39)&&(ch<65||ch>90)&&(ch<97||ch>122)) {
            arr[letters]='\0';
            for(i=1; i<argc; i++) {
                if (strcmp(argv[i], arr)==0){
                    target=i;
                    if (i>0)
                        i=argc;
                }
                else
                    target=0;
            }
            if (target==0)
                printf("%s",arr);
            else
                printf("CENSORED");
            printf("%c", ch);
            letters=0;
        }else{
            arr[letters]=ch;
            letters++;
        }
    }
    return 0;
}
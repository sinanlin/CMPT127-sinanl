#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    unsigned long charcount=0;
    unsigned long wordcount=0;
    unsigned long linecount=0;
    int flag = 0 ;
    
    
    while(1){
        
        int c=getchar();
//Write a C program that counts the number of characters, words and lines read from standard input until EOF is reached.
        
       if(c==EOF){
           printf("%lu %lu %lu\n", charcount, wordcount, linecount);
           break;
        }
//Every byte read from stdin counts as a character except EOF.
        charcount++;
        
//Lines are defined as contiguous sequences of characters separated by newline characters ('\n').
        
        if(c=='\n'){
            linecount++;
        }
//Words are defined as contiguous sequences of letters (a through z, A through Z) and the apostrophe ( ', value 39 decimal) separated by any character outside these ranges.
        
        if( isalpha(c) || c==39){
  
            if (flag == 0) {
                wordcount++;
            }
            flag = 1;
        }
        else {
            flag = 0;
        }
        
    }
    return 0;
}
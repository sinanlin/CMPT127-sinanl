#include <stdio.h>


int main(int argc, char* argv[]){
    
    int c;
    int arr[26];
    int i;
    float count=0;
    
    for (i=0; i<26; i++) {
        arr[i]=0;
    }
    while ((c=getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            arr[c-'A']++;
            count++;

        }
        else if(c >= 'a' && c <= 'z') {
            arr[c-'a']++;
            count++;
        }
    }

    for (i=0, c='a'; i<26; ++c,i++) {
        if (arr[i]/count > 0) {
            printf( "%c %.4f\n",c , arr[i]/count);
        }
    }
    
    
    return 0;
}
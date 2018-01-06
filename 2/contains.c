#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[] ){
    int i=0;
    int j=0;
    int x=0;
    int a=strlen(argv[1]);
    int b=strlen(argv[2]);
    int count=0;
    int found=0;
//Check the fitst character
    for (i=0; i<a; i++) {
        if(argv[2][0]==argv[1][i]){
//Once it works, check for the rest.
            x=i;
            for (j=0; j<b; j++) {
                if (argv[2][j]==argv[1][x]) {
                    x++;
                    count++;
		//check b contains in a, oncec does. Print and break.
                    if (count==b) {
                        printf("true\n");
			found=1;
			break;
                    }
                }
                
            }
	//Settiing count to 0 for the next check.
	 count=0;
        }

    }
//Once exit the for loop, it means it is not found. Print false then. 
   if(found==0){
      printf("false\n");
   }
    
    
    
    
}

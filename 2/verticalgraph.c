#include <stdio.h>

int main() {
    int i, j, input,count=0, size=80,arr[size],max =-1;

    while(scanf("%d", &input)==1){
        
        arr[count]=input;
        if (max<arr[count])
            max=arr[count];
        count++;
    }
    
    while(max>0) {
        for(j=0; j<count; j++) {
            if (arr[j]>=max)
                printf("#");
            else
                printf(" ");
            
        }
        max--;
        printf("\n");
    }
    
    return 0;
    
}

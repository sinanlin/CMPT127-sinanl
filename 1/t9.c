#include <stdio.h>
#include <math.h>

int main (){
    int i, j, x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    
    
    for(i = z-1; i >= 0; i--) {
        for (j= 0; j <= x-1; j++) {
            // printf("i =%d ",i);
            // printf("x =%d ",x);
            // printf("z =%d ",z);
            int L = floor(i * (x/(2.0*z)) );
            int R = ceil( (x-1)-i * (x/(2.0*z)) );
            // printf("L =%d ",L);
            // printf("R =%d \n",R);
            if (i<=0 || (j == L || j==R))
                printf("#");
            else {
                if (j < L)
                    printf(" ");
                else {
                    if (i == z-1 && (j<R))
                        printf("#");
                    else
                        if ((j>L) && (j<R))
                            printf(".");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

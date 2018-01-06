#include <stdio.h>
#include <math.h>

int main(void)
{
    int a=0;
    float i=0;
    
    a=scanf("%f",&i);
    
    if(a==1)
    {
        printf("%.0f ",floor(i));
        printf("%.0f ",round(i));
        printf("%.0f\n",ceil(i));
        return 0;
    }
    
    else
    {
        printf("scanf error: (%.0f)\n",i);
    }
    
}

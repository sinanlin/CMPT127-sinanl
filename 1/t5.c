#include<stdio.h>
#include<math.h>

int main(void)
{
    float i=0;
    int result=0;
    result=scanf("%f",&i); //result check if the user finished input
    
    
    while(result!=EOF)  //while the user still giving input
    {
        printf("%.0f ",floor(i));
        printf("%.0f ",round(i));
        printf("%.0f\n",ceil(i));
        
        result=scanf("%f",&i);//scanf a new input
        
    }
    
    printf("Done.\n");
    
    return 0;
}
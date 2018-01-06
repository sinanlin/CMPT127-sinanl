#include<stdio.h> 

int main(void)
{
 int i=0;      
 int result=0; 
 result=scanf("%d",&i); //result check if the user finished input
 

while(result!=EOF)  //while the user still giving input
 {



 for(i=i;i>0;i--)
  {
  printf("#");
  }
 printf("\n"); //Give a new line after each input  
 result=scanf("%d",&i);//scanf a new input

 }


return 0;
}

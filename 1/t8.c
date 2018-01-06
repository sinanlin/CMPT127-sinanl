#include<stdio.h> 

int main(void)
{
 int x=0;
 int y=0;
 int z=0;
 scanf("%d",&x);
 scanf("%d",&y);
 scanf("%d",&z);
 int width=x;
 int breadth=y;


for(y=breadth;y>0;y--)
 {
 if(y==breadth || y==1) // The first line or the last line
  {
  for(x=width;x>0;x--)
   {
    printf("#");
   }
  printf("\n");//Give a new line
  }
 else //The line in the middle 
 {
 for(x=width;x>0;x--)
  {
  if(x==width || x==1)
   {
    printf("#");
   } //The first or last Character will be #
  else
   {
    printf(".");
   } //The Character in the middle will be . 
  }
 printf("\n");//Give a new line 
 }

 }

 


return 0;
}

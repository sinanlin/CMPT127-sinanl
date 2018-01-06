#include<stdio.h> 
#include<math.h>

int main(void)
{
 float num=0;
 float max=0;
 float min=0;
 float mean=0;
 float sum=0;
 float total=0;
 int result=0; 
 result=scanf("%f",&num); //result check if the user finished input

while(result!=EOF)  //while the user still giving input
 {
 
 if(total==0) //When there is only one input
  {
  max=num;
  min=num;
  }
 else if(max<num) //Find the max
 {
 max=num;
 }
 else if(min>num) //Find the min
 {
 min=num;
 }
 total++;
 sum=sum+num;
 mean=sum/total;
 result=scanf("%f",&num);

 }

printf("%.2f ",min);
printf("%.2f ",max);
printf("%.2f\n",mean);

return 0;
}

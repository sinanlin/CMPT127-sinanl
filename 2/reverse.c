void reverse(int a[], unsigned int len )
{
int tmp=0;
int i=0;

for(i=0;i<len/2;i++)
 {
 tmp=a[i];
 a[i]=a[len-1-i];
 a[len-1-i]=tmp;
 }

}

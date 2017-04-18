#include<stdio.h>

int main()
{
 int a[10];
 int i,j,k,t;
 for(k=0; k<10; k++)
 {
  printf("\nEnter %d number : ",k+1);
  scanf("%d",&a[k]);
 }
 for(i=10/2; i>0; i=i/2)
 {
   for(j=i; j<10; j++)
   {
     for(k=j-i; k>=0; k=k-i)
     {
      if(a[k+i]>=a[k])
      break;
      else
      {
        t=a[k];
        a[k]=a[k+i];
        a[k+i]=t;
      }
     }
   }
 }
 for(k=0; k<10; k++)
 printf("%d\t",a[k]);
 return 0;
}

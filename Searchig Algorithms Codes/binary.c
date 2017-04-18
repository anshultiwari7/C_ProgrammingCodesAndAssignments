#include<stdio.h>
int main()
{
int a[10],f=0,m,x,l=0,i,h=9;
for(i=0;i<=9;i++)
scanf("%d",&a[i]);
printf("Enter number to be searched..  ");
scanf("%d",&x);

while(l<=h)
{
m=(l+h)/2;
if(x==a[m])
{
f=1;
break;
}
else
if(x>a[m])
{
l=m+1;
}
else
h=m-1;
}
if(f==1)
printf("Found");
else
printf("Not Found");
return 0;
}

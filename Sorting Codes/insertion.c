#include<stdio.h>
void insertionsort(int a[],int n)
{
int x,i,j,t;
for(i=1;i<=n-1;i++)
{
j=i;
while((j>0)&&(a[j]<a[j-1]))
{
t=a[j];
a[j]=a[j-1];
a[j-1]=t;
j--;
}
}

for(i=0;i<=9;i++)
printf("%d\t",a[i]);
}


int main()
{
int i,a[10];
printf("Enter array elements.\n");
for(i=0;i<=9;i++)
{
printf("%d:",i+1);
scanf("%d",&a[i]);
}
insertionsort(a,10);
return 0;
}

#include<conio.h>
#include<stdio.h>


void selection(int a[])
{
int i,pos,j;
for(i=0;i<=9;i++)
{
pos=i;
for(j=i+1;j<=9;j++)
if(a[pos]>a[j])
pos=j;

if(pos!=i)
{
a[pos]=a[pos]+a[i];
a[i]=a[pos]-a[i];
a[pos]=a[pos]-a[i];
}
}
for(i=0;i<=9;i++)
printf("%d\t",a[i]);
}


void main()
{
int a[10],i;
clrscr();
for(i=0;i<=9;i++)
scanf("%d",&a[i]);

bubble(a);
//selection(a);
//insertion(a);

getch();
}
#include<conio.h>
#include<stdio.h>


void bubble(int a[])
{
int i,j;
for(i=0;i<=9;i++)
 for(j=0;j<=9-i-1;j++)
   if(a[j]>a[j+1])
   {
   a[j+1]=a[j+1]+a[j];
   a[j]=a[j+1]-a[j];
   a[j+1]=a[j+1]-a[j];
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
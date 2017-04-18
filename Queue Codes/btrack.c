#include<stdio.h>
int i=0,j=0,p,q;
int a[6][6];

int find(int i,int j)
{
a[i][j]=0;
if(i==p && j==q)
return 0;
else
{
if(i+1<6 && a[i+1][j]==1)
//find(i+1,j);
if(i-1>0 && a[i-1][j]==1)
//find(i-1,j);
if(j+1<6 && a[i][j+1]==1)
//find(i,j+1);
if(j-1>0 && a[1][j-1]==1)
//find(i,j-1);
}
return 1;
}


int main()
{
int x,y;
printf("Enter array 6x6 with 1 for open path and zero for closed one : ");
for(i=0;i<=5;i++)
for(j=0;j<=5;j++)
scanf("%d",&a[i][j]);
printf("Enter start point (x,y) : ");
scanf("%d%d",&x,&y);
printf("Enter destination indices (x,y) : ");
scanf("%d%d",&p,&q);
if(find(x,y))
printf("True :) ");
else
printf("False :( ");
return 0;
}
